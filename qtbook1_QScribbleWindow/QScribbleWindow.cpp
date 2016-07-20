//---------------------------------------------------------------------------
#include "QScribbleWindow.h"
#include "QScribbleArea.h"
//---------------------------------------------------------------------------
#include <QApplication.h>
#include <QMenuBar.h>
#include <QMessageBox.h>
#include <QPopupMenu.h>
#include <QScrollView.h>
#include <QAction.h>
#include <QFileDialog.h>
//---------------------------------------------------------------------------
QScribbleWindow::QScribbleWindow( QWidget *parent, const char *name )
	: QWidget( parent, name )
{
	setTitle();

	_filemenu = new QPopupMenu;
	_filemenu->insertItem( "&Load", this, SLOT( load() ), CTRL+Key_O );
	_filemenu->insertItem( "&Save", this, SLOT( save() ), CTRL+Key_S );
	_filemenu->insertSeparator();
	_filemenu->insertItem( "&Quit", qApp, SLOT( quit() ), CTRL+Key_Q );


	_colormenu = new QPopupMenu;
	QPixmap menupixmap( 70, 16 );

	menupixmap.fill( black );
	_colormenu->insertItem( menupixmap, COLOR_MENU_ID_BLACK );

	menupixmap.fill( red );
	_colormenu->insertItem( menupixmap, COLOR_MENU_ID_RED );

	menupixmap.fill( blue );
	_colormenu->insertItem( menupixmap, COLOR_MENU_ID_BLUE );

	menupixmap.fill( green );
	_colormenu->insertItem( menupixmap, COLOR_MENU_ID_GREEN );

	menupixmap.fill( yellow );
	_colormenu->insertItem( menupixmap, COLOR_MENU_ID_YELLOW );

	QObject::connect( _colormenu, SIGNAL( activated( int ) ), SLOT( ColorMenu( int ) ) );


	_widthmenu = new QPopupMenu;
	menupixmap.fill( lightGray );

	QPen menupen;
	menupen.setColor( black );

	QPainter menupainter;
	menupainter.begin( & menupixmap );

	menupen.setWidth( 1 );
	menupainter.setPen( menupen );
	menupainter.drawLine( QPoint( 0, 8 ), QPoint( 70, 8 ) );
	_widthmenu->insertItem( menupixmap, PEN_MENU_ID_1 );

	menupen.setWidth( 2 );
	menupainter.setPen( menupen );
	menupainter.drawLine( QPoint( 0, 8 ), QPoint( 70, 8 ) );
	_widthmenu->insertItem( menupixmap, PEN_MENU_ID_2 );

	menupen.setWidth( 3 );
	menupainter.setPen( menupen );
	menupainter.drawLine( QPoint( 0, 8 ), QPoint( 70, 8 ) );
	_widthmenu->insertItem( menupixmap, PEN_MENU_ID_3 );

	menupen.setWidth( 4 );
	menupainter.setPen( menupen );
	menupainter.drawLine( QPoint( 0, 8 ), QPoint( 70, 8 ) );
	_widthmenu->insertItem( menupixmap, PEN_MENU_ID_4 );

	menupen.setWidth( 5 );
	menupainter.setPen( menupen );
	menupainter.drawLine( QPoint( 0, 8 ), QPoint( 70, 8 ) );
	_widthmenu->insertItem( menupixmap, PEN_MENU_ID_5 );
	QObject::connect( _widthmenu, SIGNAL( activated( int ) ), SLOT( WidthMenu( int ) ) );


	_helpmenu = new QPopupMenu;
	_helpmenu->insertItem( "&About QtScribble", this, SLOT( About() ) );


	_menubar = new QMenuBar( this );
	_menubar->insertItem( "&File", _filemenu );
	_menubar->insertItem( "&Color", _colormenu );
	_menubar->insertItem( "&Width", _widthmenu );
	_menubar->insertSeparator();
	_menubar->insertItem( "&Help", _helpmenu );

	_scrollview = new QScrollView( this );
	_scrollview->setGeometry( 0, _menubar->height(), width(), height() - _menubar->height() );
	_scribblearea = new QScribbleArea( _colormenu, _widthmenu, _scrollview, "scribblearea" );
	_scribblearea->setGeometry( 0, 0, 1024, 768 );
	_scrollview->addChild( _scribblearea );

	QObject::connect( this, SIGNAL( colorChanged( QColor ) ),   _scribblearea, SLOT( setColor( QColor ) ) );
	QObject::connect( this, SIGNAL( widthChanged( int ) ),      _scribblearea, SLOT( setWidth( int ) ) );
	QObject::connect( this, SIGNAL( fileLoad( const char * ) ), _scribblearea, SLOT( load( const char * ) ) );
	QObject::connect( this, SIGNAL( fileSave( const char * ) ), _scribblearea, SLOT( save( const char * ) ) );
	QObject::connect( _scribblearea, SIGNAL( fileChanged( const char * ) ), SLOT( setTitle( const char * ) ) );
}
//---------------------------------------------------------------------------
QScribbleWindow::~QScribbleWindow( void )
{
}
//---------------------------------------------------------------------------
void QScribbleWindow::resizeEvent( QResizeEvent *event )
{
	_scrollview->setGeometry( 0, _menubar->height(), width(), height() - _menubar->height() );
}
//---------------------------------------------------------------------------
void QScribbleWindow::keyPressEvent( QKeyEvent *event )
{
	int key = event->key();

	int move_x = 0;
	int move_y = 0;

	switch ( key )
	{
		case Key_Up:
			move_y = -10;
			break;
		case Key_Down:
			move_y = 10;
			break;
		case Key_Left:
			move_x = -10;
			break;
		case Key_Right:
			move_x = 10;
			break;
		case Key_PageUp:
			move_y = -100;
			break;
		case Key_PageDown:
			move_y = 100;
			break;
		case Key_Home:
			move_x = -100;
			break;
		case Key_End:
			move_x = 100;
			break;
	}

	_scrollview->scrollBy( move_x, move_y );
}
//---------------------------------------------------------------------------
void QScribbleWindow::About( void )
{
	QMessageBox::information( this, "About QtScribble 2",
		"This is the QtScribble 2 application\n"
		"Copyright 1998 by Matthias Kalle Dalheimer\n"
	);
}
//---------------------------------------------------------------------------
void QScribbleWindow::ColorMenu( int item )
{
	switch ( item )
	{
		case COLOR_MENU_ID_BLACK:
			emit colorChanged( black );
			break;
		case COLOR_MENU_ID_RED:
			emit colorChanged( red );
			break;
		case COLOR_MENU_ID_BLUE:
			emit colorChanged( blue );
			break;
		case COLOR_MENU_ID_GREEN:
			emit colorChanged( green );
			break;
		case COLOR_MENU_ID_YELLOW:
			emit colorChanged( yellow );
			break;
	}
}
//---------------------------------------------------------------------------
void QScribbleWindow::WidthMenu( int item )
{
	switch ( item )
	{
		case PEN_MENU_ID_1:
			emit widthChanged( 1 );
			break;
		case PEN_MENU_ID_2:
			emit widthChanged( 2 );
			break;
		case PEN_MENU_ID_3:
			emit widthChanged( 3 );
			break;
		case PEN_MENU_ID_4:
			emit widthChanged( 4 );
			break;
		case PEN_MENU_ID_5:
			emit widthChanged( 5 );
			break;
	}
}
//---------------------------------------------------------------------------
void QScribbleWindow::load( void )
{
	if ( _scribblearea->isModified() )
	{
		if ( QMessageBox::warning( this, "Save Confirm", "image was modified\r\n" "Want you save it?", "&Yes", "&No" ) == 0 )
		{
			save();
		}
	}

	QString filename = QFileDialog::getOpenFileName( ".", "All Image Files (*.bmp *.png *.xpm *.jpg)\nBitmap (*.bmp\nPortable Network Grapihc (*.png)\n*.xpm\nJPEG (*.jpeg *.jpg)", this );

	if ( ! filename.isEmpty() )
	{
		emit fileLoad( filename );
	}
}
//---------------------------------------------------------------------------
void QScribbleWindow::save( void )
{
	QString filename = QFileDialog::getSaveFileName( ".", "Bitmap (*.bmp)\nPortable Network Graphic (*.png)\n*.xpm\nJPEG (*.jpeg *.jpg)", this );

	if ( ! filename.isEmpty() )
	{
		emit fileSave( filename );
	}
}
//---------------------------------------------------------------------------
void QScribbleWindow::setTitle( const char *title )
{
	QString tmpString;
	setCaption( tmpString.sprintf( "QtScribble:%s", title ) );
}
//---------------------------------------------------------------------------
