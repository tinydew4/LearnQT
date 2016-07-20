//---------------------------------------------------------------------------
#include "Cannon.h"
#include "Shot.h"
//---------------------------------------------------------------------------
#include <QGlobal.h>
#include <QPainter.h>
#include <QPixmap.h>
#include <QTimer.h>
#include <QDateTime.h>
#include <QMessageBox.h>
//---------------------------------------------------------------------------
#include <math.h>
#include <stdlib.h>
//---------------------------------------------------------------------------
#define TARGET_INDENT( I ) ( 200 + ( I ) )
#define TARGET_RANGE( WIDTH ) ( ( WIDTH ) - TARGET_INDENT( 15 ) )
#define TARGET_STEP ( 5 )
//---------------------------------------------------------------------------
static QRect barrelRect( 33, -4, 3, 8 );
//---------------------------------------------------------------------------
QCannonField::QCannonField( QWidget *parent, const char *name )
	: QWidget( parent, name ),
	  ang( 45 ), f( 9 ), shotIdx( 0 ), shot( NULL ),
	  gameEnded( false ), barrelPressed( false )
{
	setMinimumSize( 400, 300 );
	target = QPoint( 0, 0 );

	autoTargetTimer  = new QTimer( this, "target handler" );
	autoTrajectTimer = new QTimer( this, "trajectory handler" );

	QObject::connect( autoTargetTimer,  SIGNAL( timeout() ), SLOT( moveTarget() ) );
	QObject::connect( autoTrajectTimer, SIGNAL( timeout() ), SLOT( repaint() ) );

	QWidget::setPalette( QPalette( QColor( 250, 250, 200 ) ) );

	QTime midnight( 0, 0, 0 );
	srand( midnight.secsTo( QTime::currentTime() ) );

	newTarget();

	autoTargetTimer->start( 100 );
}
//---------------------------------------------------------------------------
void QCannonField::paintEvent( QPaintEvent *e )
{
	QRect updateR = e->rect();
	QPainter p( this );

	if ( gameEnded )
	{
		p.setPen( black );
		p.setFont( QFont( "Courier", 48, QFont::Bold ) );
		p.drawText( rect(), AlignCenter, "Game Over" );
	}

	if ( updateR.intersects( cannonRect() ) )
	{
		paintCannon( & p );
	}

	if ( updateR.intersects( barrierRect() ) )
	{
		paintBarrier( & p );
	}

	if ( isShooting() )
	{
		shot->paint( & p, & updateR );
	}

	if ( ! gameEnded && updateR.intersects( targetRect() ) )
	{
		paintTarget( & p );
	}

	if ( autoTrajectTimer->isActive() )
	{
		paintTrajectory( & p );
	}
}
//---------------------------------------------------------------------------
QSize QCannonField::sizeHint( void ) const
{
	return QSize( 400, 300 );
}
//---------------------------------------------------------------------------
QSizePolicy QCannonField::sizePolicy( void ) const
{
	return QSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Control
//---------------------------------------------------------------------------
void QCannonField::setAngle( int degrees )
{
	degrees = ( degrees < 5 ? 5 : ( degrees > 70 ? 70 : degrees ) );

	if ( ang != degrees )
	{
		ang = degrees;

		if ( autoTrajectTimer->isActive() )
		{
			repaint();
		}
		else
		{
			repaint( cannonRect(), false );
		}

		emit angleChanged( ang );
	}
}
//---------------------------------------------------------------------------
void QCannonField::setForce( int newton )
{
	newton = ( newton < 0 ? 0 : ( newton > 50 ? 50 : newton ) );

	if ( f != newton )
	{
		f = newton;

		barrelRect.setWidth( ( ( f / 10 ) + 1) * 3 );

		if ( autoTrajectTimer->isActive() )
		{
			repaint();
		}
		else
		{
			repaint( cannonRect(), false );
		}

		emit forceChanged( f );
	}
}
//---------------------------------------------------------------------------
void QCannonField::setGameOver( void )
{
	if ( ! gameEnded )
	{
		if ( isShooting() )
		{
			shotRelease( shot );
		}

		gameEnded = true;

		repaint();
		emit canShoot( false );

	}
}
//---------------------------------------------------------------------------
void QCannonField::restartGame( void )
{
	if ( isShooting() )
	{
		shotRelease( shot );
	}
	gameEnded = false;

	repaint();

	emit canShoot( true );
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Shot relative
//---------------------------------------------------------------------------
void QCannonField::shoot( void )
{
	if ( ! isShooting() )
	{
		++shotIdx;
		shot = new QShot( ang, f, 50, barrelRect.right() + 5, this, "shot" );

		emit canShoot( false );

		if ( autoTrajectTimer->isActive() )
		{
			autoTrajectTimer->stop();
			repaint();
		}
		else
		{
			repaint( cannonRect() );
		}
	}
}
//---------------------------------------------------------------------------
void QCannonField::endShot( QShot *Sender, QRegion *r )
{
	shotRelease( Sender );
	( * r ) = ( * r ).unite( QRegion( cannonRect() ) );
	emit canShoot( true );
}
//---------------------------------------------------------------------------
void QCannonField::checkCrush( QShot *Sender, QRegion r )
{
	if ( r.contains( targetRect() ) )
	{
		endShot( Sender, & r );
		emit hit();
	}
	else if ( isShotMissed( r.boundingRect() ) )
	{
		endShot( Sender, & r );
		emit missed();
	}

	repaint( r );
}
//---------------------------------------------------------------------------
void QCannonField::shotRelease( QShot *Target )
{
	if ( Target != NULL )
	{
		delete Target;
		Target = NULL;

		--shotIdx;
	}
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Cannon
//---------------------------------------------------------------------------
void QCannonField::paintCannon( QPainter *p )
{
	QRect cr = cannonRect();
	QPixmap pix( cr.size() );

	pix.fill( this, cr.topLeft() );

	QPainter tmp( & pix );

	tmp.setBrush( ( isShooting() && shot && shot->isActive() ? red : blue ) );
	tmp.setPen( NoPen );

	tmp.translate( 0, pix.height() - 1 );
	tmp.drawPie( -36, -35, 70, 70, 0, 1440 );
	tmp.rotate( -ang );
	tmp.drawRect( barrelRect );
	tmp.end();

	p->drawPixmap( cr.topLeft(), pix );
}
//---------------------------------------------------------------------------
QRect QCannonField::cannonRect( void ) const
{
	static MaxForce = f;

	if ( MaxForce < f )
	{
		MaxForce = f;
	}

	int CannonLength = 35 + ( MaxForce / 10 * 3 );

	QRect r( 0, 0, CannonLength, CannonLength );
	r.moveBottomLeft( rect().bottomLeft() );
	return r;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Target
//---------------------------------------------------------------------------
void QCannonField::newTarget( void )
{
	QRegion r( targetRect() );

	target = QPoint( TARGET_INDENT( rand() % ( TARGET_RANGE( width() ) << 1 ) ), 10 + rand() % 255 );

	repaint( r.unite( targetRect() ) );
}
//---------------------------------------------------------------------------
void QCannonField::moveTarget( void )
{
	QRegion r( targetRect() );

	target.setX( TARGET_INDENT( ( ( target.x() - TARGET_INDENT( - TARGET_STEP ) ) % ( TARGET_RANGE( width() ) << 1 ) ) ) );

	repaint( r.unite( QRegion( targetRect() ) ) );
}
//---------------------------------------------------------------------------
void QCannonField::paintTarget( QPainter *p )
{
	p->setBrush( red );
	p->setPen( black );
	p->drawRect( targetRect() );
}
//---------------------------------------------------------------------------
QRect QCannonField::targetRect( void ) const
{
	QRect r( 0, 0, 20, 10 );

	int x = target.x();
	int total_range = TARGET_INDENT( TARGET_RANGE( width() ) );
	r.moveCenter( QPoint( ( x < total_range ? x : ( total_range << 1 ) - x), height() - target.y() ) );

	return r;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Trajectory
//---------------------------------------------------------------------------
void QCannonField::showTrajectory( void )
{
	if ( ! autoTrajectTimer->isActive() )
	{
		autoTrajectTimer->start( 5000, true );
		repaint();
	}
}
//---------------------------------------------------------------------------
void QCannonField::paintTrajectory( QPainter *p )
{
	int i = 0;
	QRect shotR = trajRect( i++ );

	while ( ! shotR.intersects( targetRect() ) && ! isShotMissed( shotR ) )
	{
		p->setBrush( red );
		p->setPen( NoPen );
		p->drawEllipse( trajRect( i++ ) );

		shotR = trajRect( i++ );
	}
}
//---------------------------------------------------------------------------
QRect QCannonField::trajRect( int tcount ) const
{

	const double gravity = ( double )( 4.0 );
	double time     = ( double )( tcount ) / ( double )( 4.0 );
	double radians  = ( double )( ang ) * ( double )( 0.0174532925 );
	double seed     = ( double )( barrelRect.right() + 5 ) + ( double )( f ) * time;

	QRect r( 0, 0, 6, 6 );
	r.moveCenter( QPoint( qRound( seed * cos( radians ) ), height() - qRound( seed * sin( radians ) - gravity * pow( time, 2 ) / ( double )( 2 ) ) ) );
	
	return r;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Barrel
//---------------------------------------------------------------------------
bool QCannonField::barrelHit( const QPoint &p ) const
{
	QWMatrix mtx;
	mtx.translate( 0, height() - 1 );
	mtx.rotate( - ang );
	mtx = mtx.invert();
	return barrelRect.contains( mtx.map( p ) );
}
//---------------------------------------------------------------------------
void QCannonField::paintBarrier( QPainter *p )
{
	p->setBrush( yellow );
	p->setPen( black );
	p->drawRect( barrierRect() );
}
//---------------------------------------------------------------------------
QRect QCannonField::barrierRect( void ) const
{
	return QRect( 145, height() - 100, 15, 100 );
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Mouse Event
//---------------------------------------------------------------------------
void QCannonField::mousePressEvent( QMouseEvent *e )
{
	if ( e->button() == LeftButton )
	{
		if ( barrelHit( e->pos() ) )
		{
			barrelPressed = true;
		}
	}
}
//---------------------------------------------------------------------------
void QCannonField::mouseMoveEvent( QMouseEvent *e )
{
	if ( barrelPressed )
	{
		QPoint pnt = e->pos();

		int xConv = pnt.x();
		if ( xConv <= 0 )
		{
			xConv = 1;
		}
		int yConv = rect().bottom() - ( pnt.y() < height() ? pnt.y() : height() - 1 );

		setAngle( qRound( atan( ( double )( yConv ) / ( double )( xConv ) ) / 0.0174532925 ) );
		setForce( qRound( sqrt( pow( xConv, 2 ) + pow( yConv, 2 ) ) - 35 ) << 2 );
	}
}
//---------------------------------------------------------------------------
void QCannonField::mouseReleaseEvent( QMouseEvent *e )
{
	if ( e->button() == LeftButton )
	{
		barrelPressed = false;
	}
}
//---------------------------------------------------------------------------
