//---------------------------------------------------------------------------
#include <QApplication.h>
//---------------------------------------------------------------------------
#include "QCoordSel.h"
#include "QReceiver.h"
//---------------------------------------------------------------------------
int main( int argc, char** argv )
{
	QApplication App( argc, argv );

	QCoordSel selector;
	selector.resize( 200, 200 );
	selector.setXMinValue( 20 );
	selector.setXMaxValue( 130 );
	selector.setYMinValue( 50 );
	selector.setYMaxValue( 150 );
	selector.show();

	QReceiver receiver;
	QObject::connect( &selector, SIGNAL( valueChanged( int, int ) ), &receiver, SLOT( received( int, int ) ) );

	App.setMainWidget( &selector );

	return App.exec();
}

//---------------------------------------------------------------------------
