#include <qapplication.h>
#include "qtexamwindow.h"


int main( int argc, char** argv )
{
	QApplication app( argc, argv );

	QTExamWindow window;
	app.setMainWidget(&window);

	window.show();

	return app.exec();
}

