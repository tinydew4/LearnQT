/*
�ʿ� : �ٶ�, hit �� shot ����, ��Ƽ shot

space invader ������ �ۼ��϶�

���ο� ���������� Ż�� ������ �ۼ��ϴ� ���̴�
������ �ǰ�: ���� ��� forth �� ���� �׸��� ���α׷��� ������ ������ ������
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
