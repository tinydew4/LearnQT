//---------------------------------------------------------------------------
#include "QScribbleArea.h"
//---------------------------------------------------------------------------
#include <QPainter.h>
#include <QPopupMenu.h>
#include <QMessageBox.h>
//---------------------------------------------------------------------------
QScribbleArea::QScribbleArea( QPopupMenu *colormenu, QPopupMenu *widthmenu,
	QWidget *parent, const char *name )
	: QWidget( parent, name ), _modified( false )
{
	_currentpen.setColor( black );
	_currentpen.setWidth( 1 );

	setBackgroundMode( NoBackground );

	_editmenu = new QPopupMenu( this );
	_editmenu->insertItem( "&Clear", this, SLOT( clearArea() ) );

	_penmenu = new QPopupMenu( this );
	_penmenu->insertItem( "&Color", colormenu );
	_penmenu->insertItem( "&Width", widthmenu );

	_popupmenu = new QPopupMenu( this );
	_popupmenu->insertItem( "&Edit", _editmenu );
	_popupmenu->insertItem( "&Pen",  _penmenu );
}
//---------------------------------------------------------------------------
QScribbleArea::~QScribbleArea( void )
{
	if ( _popupmenu )
	{
		delete _popupmenu;
	}
}
//---------------------------------------------------------------------------
void QScribbleArea::setColor( QColor new_color )
{
	_currentpen.setColor( new_color );
}
//---------------------------------------------------------------------------
void QScribbleArea::setWidth( int new_width )
{
	_currentpen.setWidth( new_width );
}
//---------------------------------------------------------------------------
void QScribbleArea::clearArea( void )
{
	_buffer.fill( white );
	repaint();
}
//---------------------------------------------------------------------------
void QScribbleArea::load( const char *filename )
{
	if ( ! _buffer.load( filename ) )
	{
		QMessageBox::warning( 0, "Load error", "Could not load file" );
	}
	else
	{
		setGeometry( _buffer.rect() );
		_modified = false;
		emit fileChanged( filename );
	}
	repaint();
}
//---------------------------------------------------------------------------
void QScribbleArea::save( const char *filename )
{
	QString tmpString;
	char temp[255];

	strcpy( temp, filename + strlen( filename ) - 4 );
	strcpy( temp, tmpString.sprintf( "%s%s", filename, ( strcmp( strupr( temp ), ".BMP" ) != 0 ? ".bmp" : "" ) ) );

	if ( ! _buffer.save( temp, "BMP" ) )
	{
		QMessageBox::warning( 0, "Save error", "Could not save file" );
	}
	else
	{
		_modified = false;
		emit fileChanged( temp );
	}
}
//---------------------------------------------------------------------------
void QScribbleArea::mousePressEvent( QMouseEvent *event )
{
	if ( event->button() == RightButton )
	{
		_popupmenu->exec( QCursor::pos() );
	}
	else
	{
		_last = event->pos();
	}
}
//---------------------------------------------------------------------------
void QScribbleArea::mouseMoveEvent( QMouseEvent *event )
{
	QPainter windowpainter;
	QPainter bufferpainter;

	windowpainter.begin( this );
	bufferpainter.begin( & _buffer );

	windowpainter.setPen( _currentpen );
	bufferpainter.setPen( _currentpen );

	windowpainter.drawLine( _last, event->pos() );
	bufferpainter.drawLine( _last, event->pos() );

	windowpainter.end();
	bufferpainter.end();

	_last = event->pos();

	if ( ! _modified )
	{
		_modified = true;
	}
}
//---------------------------------------------------------------------------
void QScribbleArea::paintEvent( QPaintEvent *event )
{
	bitBlt( this, 0, 0, & _buffer );
}
//---------------------------------------------------------------------------
void QScribbleArea::resizeEvent( QResizeEvent *event )
{
	QPixmap save( _buffer );
	_buffer.resize( event->size() );
	_buffer.fill( white );
	bitBlt( & _buffer, 0, 0, & save );
}
//---------------------------------------------------------------------------
bool QScribbleArea::isModified( void )
{
	return _modified;
}
//---------------------------------------------------------------------------
