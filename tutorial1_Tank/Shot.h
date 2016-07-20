//---------------------------------------------------------------------------
#ifndef ShotH
#define ShotH
//---------------------------------------------------------------------------
#include <QWidget.h>
#include <QTimer.h>
//---------------------------------------------------------------------------
class QTimer;
//---------------------------------------------------------------------------
class QShot : public QObject
{
	Q_OBJECT

public:
	QTimer *autoShootTimer;

private:
	float ang;
	float f;
	float startLoc;

	int timerCount;

	int parentHeight;
	QWidget *parentWidget;

	QRegion shotRect( void ) const;

private slots:
	void moveShot( void );

signals:
	void moving( QShot *, QRegion );

public:
	QShot::QShot( int angle, int force, int interval, int start,
		QObject *parent = 0, const char *name = 0 );

	void paint( QPainter *, QRect * );

	bool isActive( void ) const
	{
		return autoShootTimer->isActive();
	}
};
//---------------------------------------------------------------------------
#endif // ShotH
