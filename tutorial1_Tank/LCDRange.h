//---------------------------------------------------------------------------
#ifndef LCDRangeH
#define LCDRangeH
//---------------------------------------------------------------------------
#include <QWidget.h>
//---------------------------------------------------------------------------
class QLCDNumber;
class QSlider;
class QLabel;
//---------------------------------------------------------------------------
class QLCDRange : public QWidget
{
	Q_OBJECT

private:
	QLCDNumber *lcd;
	QSlider *slider;
	QLabel *label;

	void init( void );

public slots:
	void setValue( int value );
	void setRange( int minVal, int maxVal );
	void setText( const char *s );

	void addStep( void );
	void subtractStep( void );

signals:
	void valueChanged( int );

public:
	QLCDRange( QWidget *parent = 0, const char *name = 0 );
	QLCDRange( const char *s, QWidget *parent = 0, const char *name = 0 );

	int value( void ) const;
	const char *text() const;

};
//---------------------------------------------------------------------------
#endif // LCDRangeH
