//---------------------------------------------------------------------------
#include <QDateTime.h>
#include <QPainter.h>
//---------------------------------------------------------------------------
#include <math.h>
//---------------------------------------------------------------------------
#include "AnalogClock.h"
//---------------------------------------------------------------------------
#pragma intrinsic(sin)
#pragma intrinsic(cos)
//---------------------------------------------------------------------------
QAnalogClock::QAnalogClock( QWidget *parent, const char *name )
	: QWidget( parent, name )
{
	startTimer( 1000 );
	resize( 140, 140 );
	setFont( QFont( "Times", 8, QFont::Normal ) );
}
//---------------------------------------------------------------------------
void QAnalogClock::timerEvent( QTimerEvent * )
{
	update();
}
//---------------------------------------------------------------------------
void QAnalogClock::paintEvent( QPaintEvent * )
{
	QPainter painter( this );

	painter.setWindow( -60, -60, 120, 120 );
	painter.setBrush( black );

	QString temp;
	double Loc;
	for ( int i = 11; i >= 0; --i )
	{
		Loc = ( double )( ( ( i + 3 ) % 12 ) * 30 ) / ( double )( 57.2 );
		
		painter.drawText(
			( int )( sin(Loc) * 55 ) - 3,
			( int )( cos(Loc) * -55 ) + 4,
			temp.sprintf( "%d", ( ( i + 3 ) % 12 ) )
		);
	}
	for ( i = 11; i >= 0; --i )
	{
		painter.drawLine( 44, 0, 46, 0 );
		painter.rotate( 30 );
	}

	QTime time = QTime::currentTime();

	QCOORD hourHand[8] = { 2, 0, 0, 2, -2, 0, 0, -25 };
	int minute = time.minute();
	painter.save();
	painter.rotate( ( time.hour() % 12 ) *  30 + ( minute >> 1 ) );
	painter.drawPolygon( QPointArray( 4, hourHand ) );
	painter.restore();

	QCOORD minuteHand[8] = { 2, 0, 0, 2, -2, 0, 0, -40 };
	int second = time.second();
	painter.save();
	painter.rotate( minute * 6 + second / 10 );
	painter.drawPolygon( QPointArray( 4, minuteHand ) );
	painter.restore();

	painter.save();
	painter.rotate( second * 6 );
	painter.setPen( red );
	painter.drawLine( 0, 0, 0, -35 );
	painter.restore();
}
//---------------------------------------------------------------------------
