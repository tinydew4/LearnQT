/*
필요 : 바람, hit 시 shot 폭발, 멀티 shot

space invader 게임을 작성하라

새로운 연습문제는 탈출 게임을 작성하는 것이다
마지막 권고: 지금 즉시 forth 로 가라 그리고 프로그래밍 예술의 걸작을 만들어라
*/
//---------------------------------------------------------------------------
#include <QApplication.h>
//---------------------------------------------------------------------------
#include "Tank.h"
//---------------------------------------------------------------------------
int main( int argc, char **argv )
{
	QApplication::setColorSpec( QApplication::CustomColor );

	QApplication App( argc, argv );
	QTank Tank;

	App.setName( "Cannon Tank" );
	App.setMainWidget( & Tank );
	Tank.show();

	return App.exec();
}
//---------------------------------------------------------------------------
