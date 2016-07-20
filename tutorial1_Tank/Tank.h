//---------------------------------------------------------------------------
#ifndef TankH
#define TankH
//---------------------------------------------------------------------------
#include <QWidget.h>
//---------------------------------------------------------------------------
class QLCDNumber;
class QLCDRange;
class QPushButton;
class QCannonField;
class QAccel;
//---------------------------------------------------------------------------
class QTank : public QWidget
{
	Q_OBJECT

private:
	QLCDNumber *hits;
	QLCDNumber *shotsLeft;
	QLCDRange *angle;
	QLCDRange *force;
	QPushButton *exit;
	QPushButton *cheat;
	QPushButton *shoot;
	QPushButton *restart;
	QCannonField *cannonField;
	QAccel *accel;

private slots:
	void fire( void );
	void hit( void );
	void missed( void );
	void newGame( void );

public:
	QTank( QWidget *parent = 0, const char *name = 0 );
};
//---------------------------------------------------------------------------
#endif
