//---------------------------------------------------------------------------
#include <QApplication.h>
#include "QBBoxTest.h"
//---------------------------------------------------------------------------
int main( int argc, char** argv )
{
	QApplication App( argc, argv );

	QBBoxTest BBoxTest;
	BBoxTest.setGeometry( 100, 100, 200, 120 );

	App.setMainWidget( & BBoxTest );
	BBoxTest.show();

	return App.exec();
}
//---------------------------------------------------------------------------
