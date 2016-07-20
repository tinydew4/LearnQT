//---------------------------------------------------------------------------
#ifndef AnalogClockH
#define AnalogClockH
//---------------------------------------------------------------------------
#include <QWidget.h>
//---------------------------------------------------------------------------
class QAnalogClock : public QWidget
{
public:
	QAnalogClock( QWidget *parent = 0, const char *name = 0 );

protected:
	virtual void timerEvent( QTimerEvent * );
	virtual void paintEvent( QPaintEvent * );

};
//---------------------------------------------------------------------------
#endif
