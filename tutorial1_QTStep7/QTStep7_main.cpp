//---------------------------------------------------------------------------
#include <QApplication.h>
#include "QStep7.h"
//---------------------------------------------------------------------------
int main( int argc, char **argv )
{
	QApplication App( argc, argv );
	QStep7 Step7;

	App.setMainWidget( & Step7 );
	Step7.show();

	return App.exec();
}
//---------------------------------------------------------------------------
