//---------------------------------------------------------------------------
#ifndef CannonH
#define CannonH
//---------------------------------------------------------------------------
#include <QWidget.h>
//---------------------------------------------------------------------------
class QTimer;
class QShot;
//---------------------------------------------------------------------------
class QCannonField : public QWidget
{
	Q_OBJECT

private:
	int ang;
	int f;
	int timerCount;
	bool gameEnded;
	bool barrelPressed;

	QTimer *autoTargetTimer;
	QTimer *autoTrajectTimer;

	QPoint target;

	QRect cannonRect( void ) const;
	QRect barrierRect( void ) const;
	QRect targetRect( void ) const;
	QRect trajRect( int tcount ) const;

	void paintCannon( QPainter * );
	void paintBarrier( QPainter * );
	void paintTarget( QPainter * );
	void paintTrajectory( QPainter * = NULL );

	bool barrelHit( const QPoint & ) const;

	QShot *shot;
	int shotIdx;
	void shotRelease( QShot * );
	void endShot( QShot *Sender, QRegion *r );

	bool isShotMissed( QRect shotR ) const
	{
		return shotR.x() > width() || shotR.y() > height() ||
			shotR.intersects( barrierRect() );
	}


private slots:
	void moveTarget( void );

public slots:
	void setAngle( int degrees );
	void setForce( int newton );
	void shoot( void );
	void newTarget( void );
	void showTrajectory( void );
	void checkCrush( QShot *, QRegion );

	void setGameOver( void );
	void restartGame( void );

signals:
	void angleChanged( int );
	void forceChanged( int );
	void hit( void );
	void missed( void );
	void canShoot( bool );

public:
	QCannonField( QWidget *parent = 0, const char *name = 0 );

	QSize sizeHint( void ) const;
	QSizePolicy sizePolicy( void ) const;

	int angle( void ) const
	{
		return ang;
	}
	int force( void ) const
	{
		return f;
	}
	bool gameOver( void ) const
	{
		return gameEnded;
	}
	bool isShooting( void ) const
	{
		return shotIdx > 0;
	}

protected:
	void paintEvent( QPaintEvent * );
	void mousePressEvent( QMouseEvent * );
	void mouseMoveEvent( QMouseEvent * );
	void mouseReleaseEvent( QMouseEvent * );

};
//---------------------------------------------------------------------------
#endif // CannonH
