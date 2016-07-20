//---------------------------------------------------------------------------
#include "QBrowserBox.h"
//---------------------------------------------------------------------------
#include <QApplication.h>
#include <QString.h>
#include <QPixmap.h>
#include <QKeyCode.h>
#include <QPainter.h>
#include <QDrawUtil.h>
//---------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>
//---------------------------------------------------------------------------
QBrowserBox::QBrowserBox( int x, int y, QWidget *parent, const char *name, WFlags f )
	: QTableView( parent, name, WType_Popup )
{
	setNumCols( x );
	setNumRows( y );
	setCellWidth( width() / x );
	setCellHeight( height() / y );
	setTableFlags( Tbl_clipCellPainting );

	_texts = new QString[ x * y ];
	_pixmaps = new QPixmap[ x * y ];

	_activecell.setX( -1 );
	_activecell.setY( -1 );
	setMouseTracking( true );
	setFrameStyle( ( style() == MotifStyle ? QFrame::Panel : QFrame::WinPanel ) | QFrame::Sunken );
}
//---------------------------------------------------------------------------
QBrowserBox::~QBrowserBox( void )
{
	delete [] _texts;
	delete [] _pixmaps;
}
//---------------------------------------------------------------------------
int QBrowserBox::coordsToIndex( int x, int y )
{
	if ( x < 0 || x > numCols() || y < 0 || y > numRows() )
	{
		debug( "coordsToIndex: invalid coords (%d, %d)\n", x, y );
	}

	return y * numCols() + x;
}
//---------------------------------------------------------------------------
void QBrowserBox::insertItem( const char *text, int x, int y )
{
	_texts[ coordsToIndex( x, y ) ] = text;
}
//---------------------------------------------------------------------------
void QBrowserBox::insertItem( QPixmap pixmap, int x, int y )
{
	_pixmaps[ coordsToIndex( x, y ) ] = pixmap;
}
//---------------------------------------------------------------------------
void QBrowserBox::removeItem( int x, int y )
{
	_texts[ coordsToIndex( x, y ) ] = "";
	_pixmaps[ coordsToIndex( x, y ) ].resize( 0, 0 );
}
//---------------------------------------------------------------------------
void QBrowserBox::clear( void )
{
	for ( int x = numCols() - 1; x >= 0; --x )
	{
		for ( int y = numRows() - 1; y >= 0; --y )
		{
			removeItem( x, y );
		}
	}
}
//---------------------------------------------------------------------------
QString QBrowserBox::text( int x, int y )
{
	if ( x < 0 || x >= numCols() || y < 0 || y >= numRows() )
	{
		return "";
	}

	return _texts[ coordsToIndex( x, y ) ];
}
//---------------------------------------------------------------------------
QPixmap QBrowserBox::pixmap( int x, int y )
{
	static QPixmap empty;

	if ( x < 0 || x == numCols() || y < 0 || y >= numRows() )
	{
		return empty;
	}

	return _pixmaps[ coordsToIndex( x, y ) ];
}
//---------------------------------------------------------------------------
int QBrowserBox::exec( const QPoint &pos )
{
	return exec( pos.x(), pos.y() );
}
//---------------------------------------------------------------------------
int QBrowserBox::exec( const QWidget *trigger )
{
	QPoint globalpos = trigger->parentWidget()->mapToGlobal( trigger->pos() );

	return exec(
		globalpos.x() + width() < QApplication::desktop()->width() ? globalpos.x() : globalpos.x() - width() - 1,
		globalpos.y() + trigger->height() + height() + 1 < QApplication::desktop()->height() ? globalpos.y() + trigger->height() + 1 : globalpos.y() - height() - 1
	);
}
//---------------------------------------------------------------------------
int QBrowserBox::exec( int x, int y )
{
	_firstrelease = true;

	move( x, y );
	show();
	repaint();
	qApp->enter_loop();
	hide();

	if ( _activecell.x() != -1 && _activecell.y() != -1 )
	{
		return _activecell.x() + _activecell.y() * numCols();
	}
	else
	{
		return -1;
	}
}
//---------------------------------------------------------------------------
void QBrowserBox::keyPressEvent( QKeyEvent *e )
{
	if ( e->key() == Key_Escape )
	{
		qApp->exit_loop();
	}
}
//---------------------------------------------------------------------------
void QBrowserBox::mouseReleaseEvent( QMouseEvent * )
{
	if ( _firstrelease )
	{
		_firstrelease = false;
	}
	else
	{
		emit selected( _activecell.x(), _activecell.y() );
		qApp->exit_loop();
	}
}
//---------------------------------------------------------------------------
void QBrowserBox::paintCell( class QPainter *painter, int y, int x )
{
	bool ispixmap = false;

	if ( ! ( _pixmaps[ coordsToIndex( x, y ) ].isNull() ) )
	{
		painter->drawPixmap( 0, 0, _pixmaps[ coordsToIndex( x, y ) ] );
		ispixmap = true;
	}

	bool bActive = ( ( _activecell.x() == x ) && ( _activecell.y() == y ) );

	if ( style() == MotifStyle )
	{
		if ( bActive )
		{
			qDrawShadeRect( painter, 0, 0, cellWidth(), cellHeight(), colorGroup(), false, 2 );
		}
		else
		{
			qDrawPlainRect( painter, 0, 0, cellWidth(), cellHeight(), colorGroup().background(), 2 );
		}
	}
	else if ( bActive )
	{
		qDrawShadeRect( painter, 0, 0, cellWidth(), cellHeight(), colorGroup(), false, 1 );
	}

	if ( ! _texts[ coordsToIndex( x, y ) ].isEmpty() )
	{
		painter->drawText( 0, 0, cellWidth(), cellHeight(), AlignCenter, _texts[ coordsToIndex( x, y ) ] );
	}
}
//---------------------------------------------------------------------------
void QBrowserBox::resizeEvent( QResizeEvent * )
{
	setCellWidth( width() / numCols() );
	setCellHeight( height() / numRows() );
}
//---------------------------------------------------------------------------
void QBrowserBox::mouseMoveEvent( QMouseEvent *e )
{
	int x = e->pos().x();
	int y = e->pos().y();

	int cellx, celly;

	if ( x < 0 || y < 0 || x > width() || y > height() )
	{
		cellx = -1;
		celly = -1;
	}
	else
	{
		cellx = ( int )floor( ( ( double ) x ) / ( ( double )cellWidth() ) );
		celly = ( int )floor( ( ( double ) y ) / ( ( double )cellHeight() ) );
	}

	if ( ( _activecell.x() != cellx ) || ( _activecell.y() != celly ) )
	{
		int oldactivecellx = _activecell.x();
		int oldactivecelly = _activecell.y();

		_activecell.setX( cellx );
		_activecell.setY( celly );

		updateCell( oldactivecelly, oldactivecellx );
		updateCell( _activecell.y(), _activecell.x() );
	}
}
//---------------------------------------------------------------------------
