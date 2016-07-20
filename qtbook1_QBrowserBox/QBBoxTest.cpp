//---------------------------------------------------------------------------
#include "QBBoxTest.h"
#include "QBrowserBox.h"
//---------------------------------------------------------------------------
#include <QApplication.h>
#include <QPushButton.h>
#include <QFont.h>
#include <QPixmap.h>
#include <QColor.h>
//---------------------------------------------------------------------------
QBBoxTest::QBBoxTest( QWidget *parent, const char *name, WFlags flags )
	: QWidget( parent, name, flags )
{
	setMinimumSize( 200, 120 );
	setMaximumSize( 200, 120 );

	quit = new QPushButton( "BrowserBox", this, "quit" );
	quit->setGeometry( 47, 40, 105, 30 );
	quit->setFont( QFont( "Times", 14 ) );

	connect( quit, SIGNAL( pressed() ),  this, SLOT( buttonClicked() ) );
}
//---------------------------------------------------------------------------
void QBBoxTest::buttonClicked( void )
{
	QBrowserBox *browserbox = new QBrowserBox( 7, 4 );
	browserbox->resize( 100, 100 );
	browserbox->insertItem( "A", 0, 0 );
	browserbox->insertItem( "B", 0, 1 );
	browserbox->insertItem( "C", 0, 2 );
	browserbox->insertItem( "D", 0, 3 );
	QPixmap pixmap( 32, 32 );
	pixmap.fill( white );
	browserbox->insertItem( pixmap, 1, 0 );
	pixmap.fill( red );
	browserbox->insertItem( pixmap, 1, 1 );
	pixmap.fill( green );
	browserbox->insertItem( pixmap, 1, 2 );
	pixmap.fill( yellow );
	browserbox->insertItem( pixmap, 1, 3 );
	browserbox->insertItem( "I", 2, 0 );
	pixmap.fill( magenta );
	browserbox->insertItem( pixmap, 2, 0 );
	browserbox->insertItem( "J", 2, 1 );
	pixmap.fill( cyan );
	browserbox->insertItem( pixmap, 2, 1 );
	browserbox->insertItem( "K", 2, 2 );
	pixmap.fill( blue );
	browserbox->insertItem( pixmap, 2, 2 );
	browserbox->insertItem( "L", 2, 3 );
	pixmap.fill( darkYellow );
	browserbox->insertItem( pixmap, 2, 3 );
	browserbox->insertItem( "M", 3, 0 );
	browserbox->insertItem( "N", 3, 1 );
	browserbox->insertItem( "O", 3, 2 );
	browserbox->insertItem( "P", 3, 3 );
	browserbox->insertItem( "Q", 4, 0 );
	browserbox->insertItem( "R", 4, 1 );
	browserbox->insertItem( "S", 4, 2 );
	browserbox->insertItem( "T", 4, 3 );
	browserbox->insertItem( "U", 5, 0 );
	browserbox->insertItem( "V", 5, 1 );
	browserbox->insertItem( "W", 5, 2 );
	browserbox->insertItem( "X", 5, 3 );
	browserbox->insertItem( "Y", 6, 0 );
	browserbox->insertItem( "Z", 6, 1 );
	browserbox->insertItem( "!", 6, 2 );
	browserbox->insertItem( "?", 6, 3 );
	int ret = browserbox->exec( quit );
	debug( "Item chosen: %d\n", ret );
	QEvent ev( QEvent::Leave );
	QMouseEvent mev( QEvent::MouseButtonRelease, QCursor::pos(), LeftButton, LeftButton );
	QApplication::sendEvent( quit, &ev );
	QApplication::sendEvent( quit, &mev );
	delete browserbox;
}
//---------------------------------------------------------------------------
