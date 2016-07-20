//---------------------------------------------------------------------------
#include <QApplication.h>
#include <QPushButton.h>
//---------------------------------------------------------------------------
#include "QHTTPMirrorServer.h"
//---------------------------------------------------------------------------
#pragma comment( exestr, "Coded by Lloyd von Reuenthal" )
//---------------------------------------------------------------------------
int main( int argc, char** argv )
{
	QApplication App( argc, argv );

	QPushButton quit( "&Quit", NULL, "quit" );
	QObject::connect( &quit, SIGNAL( clicked() ), &App, SLOT( quit() ) );

	QHTTPMirrorServer server;

	App.setMainWidget( &quit );
	quit.show();

	return App.exec();
}
//---------------------------------------------------------------------------
