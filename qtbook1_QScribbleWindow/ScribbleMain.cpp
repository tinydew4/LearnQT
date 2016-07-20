//---------------------------------------------------------------------------
#include <QApplication.h>
#include <QMotifPlusStyle.h>
//---------------------------------------------------------------------------
#include "QScribbleWindow.h"
//---------------------------------------------------------------------------
int main( int argc, char **argv )
{
	QApplication::setStyle( new QMotifPlusStyle );

	QApplication App( argc, argv );
	QScribbleWindow ScribbleWindow;

	ScribbleWindow.setGeometry( 50, 50, 400, 400 );
	App.setMainWidget( & ScribbleWindow );
	ScribbleWindow.show();

	return App.exec();
}
//---------------------------------------------------------------------------
