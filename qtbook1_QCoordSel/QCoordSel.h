//---------------------------------------------------------------------------
#ifndef QCoordSelH
#define QCoordSelH
//---------------------------------------------------------------------------
#include <QWidget.h>
#include <QRangeControl.h>
#include <QPoint.h>
//---------------------------------------------------------------------------
class QCoordSel : public QWidget
{
	Q_OBJECT

private:
	QRangeControl _xrange;
	QRangeControl _yrange;
	QPoint _tempvalue;
	int _labelheight;
	double _xratio;
	double _yratio;

public slots:
	void setXMinValue( int );
	void setXMaxValue( int );
	void setYMinValue( int );
	void setYMaxValue( int );
	void setValue( int, int );
	void setValue( const QPoint & );

signals:
	void valueChanged( int, int );

public:
	QCoordSel( QWidget *parent = 0, const char *name = 0, WFlags flags = 0 );
	virtual ~QCoordSel( void );

	int xMinValue( void ) const;
	int xMaxValue( void ) const;
	int yMinValue( void ) const;
	int yMaxValue( void ) const;
	QPoint value( void ) const;

	virtual QSize sizeHint( void ) const;
	virtual void setFont( const QFont & );

protected:
	virtual void paintEvent( QPaintEvent * );
	virtual void mousePressEvent( QMouseEvent * );
	virtual void mouseReleaseEvent( QMouseEvent * );
	virtual void mouseMoveEvent( QMouseEvent * );
	virtual void resizeEvent( QResizeEvent * );

	QPoint mouseToLogical( QPoint );
	int labelHeight( void );
	void computeRatio( void );

};
//---------------------------------------------------------------------------
#endif
