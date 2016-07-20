//---------------------------------------------------------------------------
#ifndef QStep1H
#define QStep1H
//---------------------------------------------------------------------------
#include <QApplication.h>
#include <QVBox.h>
#include <QLCDNumber.h>
#include <QSlider.h>
#include <QSpinBox.h>
//---------------------------------------------------------------------------
typedef unsigned int UINT;
//---------------------------------------------------------------------------
class QStep1 : public QVBox
{
	Q_OBJECT
private:
	QLCDNumber *m_iLcd;
	QSlider *m_iSlider;
	QSpinBox *m_iSpinBox;
	UINT m_iLimit;
	void showDialog( void );

public:
	QStep1( UINT value = 0, UINT minimum = 0, UINT maximum = 99,
		UINT limit = 99, QWidget *parent = 0, const char *name = 0 );

public slots:
	void checkValue( int value );

};
//---------------------------------------------------------------------------
#endif
