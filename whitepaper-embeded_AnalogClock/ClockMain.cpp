//---------------------------------------------------------------------------
#include <QApplication.h>
//---------------------------------------------------------------------------
#include "AnalogClock.h"
//---------------------------------------------------------------------------
int main( int argc, char **argv )
{
	QApplication App( argc, argv );
	QAnalogClock clock;

	App.setName( "Clock" );
	App.setMainWidget( & clock );
	clock.show();

	return App.exec();
}
//---------------------------------------------------------------------------
