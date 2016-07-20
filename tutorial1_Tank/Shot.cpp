//---------------------------------------------------------------------------
#include "Shot.h"
//---------------------------------------------------------------------------
#include <QPainter.h>
#include <QRegion.h>
#include <QBrush.h>
//---------------------------------------------------------------------------
#include <math.h>
//---------------------------------------------------------------------------
QShot::QShot( int angle, int force, int interval, int start,
	QObject *parent, const char *name )
	: QObject( parent, name ),
	  ang( angle ), f( force ), startLoc( start ), timerCount( 0 )
{
	parentWidget = ( ( QWidget *)( parent ) );
	parentHeight = parentWidget->height();

	autoShootTimer = new QTimer( this, "movement handler" );

	QObject::connect( autoShootTimer, SIGNAL( timeout() ), SLOT( moveShot() ) );
	QObject::connect( this, SIGNAL( moving( QShot *, QRegion ) ),   parentWidget, SLOT( checkCrush( QShot *, QRegion ) ) );
	QObject::connect( this, SIGNAL( crushing( QRegion ) ), parentWidget, SLOT( repaint( QRegion, false ) ) );

	autoShootTimer->start( interval );
}
//---------------------------------------------------------------------------
void QShot::moveShot( void )
{
	QRegion shotR = shotRect();

	++timerCount;

	emit moving( this, shotR.unite( shotRect() ) );
}
//---------------------------------------------------------------------------
QRegion QShot::shotRect( void ) const
{
	const double gravity = ( double )( 4.0 );
	double time     = ( double )( timerCount ) / ( double )( 4.0 );
	double radians  = ( double )( ang ) * ( double )( 0.0174532925 );
	double seed     = ( double )( startLoc ) + ( double )( f ) * time;

	QRect r( 0, 0, 6, 6 );

	r.moveCenter( QPoint( qRound( seed * cos( radians ) ), parentHeight - qRound( seed * sin( radians ) - gravity * time * time / ( double )( 2 ) ) ) );
	
	return QRegion( r, QRegion::Ellipse );
}
//---------------------------------------------------------------------------
void QShot::paint( QPainter *p, QRect *updateR )
{
	if ( shotRect().contains( * updateR ) )
	{
		if ( isActive() )
		{
			p->setBrush( black );
			p->setPen( NoPen );
			p->drawEllipse( shotRect().boundingRect() );
		}
	}
}
//---------------------------------------------------------------------------
