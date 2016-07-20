//---------------------------------------------------------------------------
#ifndef LCDRangeH
#define LCDRangeH
//---------------------------------------------------------------------------
#include <QVBox.h>
//---------------------------------------------------------------------------
class QLCDNumber;
class QSlider;
//---------------------------------------------------------------------------
class QLCDRange : public QVBox
{
	Q_OBJECT
private:
	QLCDNumber *m_iLCD;
	QSlider *m_iSlider;

public slots:
	void setValue( int );

signals:
	void valueChanged( int );

public:
	QLCDRange( QWidget *parent = 0, char *name = 0 );
	int value( void ) const;

};
//---------------------------------------------------------------------------
#endif
