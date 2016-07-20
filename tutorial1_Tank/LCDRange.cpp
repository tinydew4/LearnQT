//---------------------------------------------------------------------------
#include "LCDRange.h"
//---------------------------------------------------------------------------
#include <assert.h>
#include <QSlider.h>
#include <QLCDNumber.h>
#include <QLabel.h>
#include <QLayout.h>
//---------------------------------------------------------------------------
QLCDRange::QLCDRange( QWidget *parent, const char *name )
	: QWidget( parent, name )
{
	init();
}
//---------------------------------------------------------------------------
QLCDRange::QLCDRange( const char *s, QWidget *parent, const char *name )
	: QWidget( parent, name )
{
	init();
	setText( s );
}
//---------------------------------------------------------------------------
void QLCDRange::init( void )
{
	lcd = new QLCDNumber( 2, this, "lcd" );

	slider = new QSlider( Horizontal, this, "slider" );
	slider->setRange( 0, 99 );
	slider->setValue( 0 );

	label = new QLabel( " ", this, "label" );
	label->setAlignment( AlignCenter );

	QObject::connect( slider, SIGNAL( valueChanged( int ) ), lcd, SLOT( display( int ) ) );
	QObject::connect( slider, SIGNAL( valueChanged( int ) ), SIGNAL( valueChanged( int ) ) );

	setFocusProxy( slider );

	QVBoxLayout *l = new QVBoxLayout( this );
	l->addWidget( lcd, 1 );
	l->addWidget( slider );
	l->addWidget( label );
}
//---------------------------------------------------------------------------
int QLCDRange::value( void ) const
{
	return slider->value();
}
//---------------------------------------------------------------------------
const char * QLCDRange::text( void ) const
{
	return label->text();
}
//---------------------------------------------------------------------------
void QLCDRange::setValue( int value )
{
	if ( slider->value() != value )
	{
		slider->setValue( value );
	}
}
//---------------------------------------------------------------------------
void QLCDRange::setRange( int minVal, int maxVal )
{
	if ( minVal <0 || maxVal > 99 || minVal > maxVal )
	{
		qWarning( "LCDRange::setRange(%d,%d)\n"
					"\tRange must be 0..99\n"
					"\tand minVal must not be greater than maxVal",
					minVal, maxVal);
	}
	else
	{
		slider->setRange( minVal, maxVal );
	}
}
//---------------------------------------------------------------------------
void QLCDRange::setText( const char *s )
{
	if ( label->text().compare( (QString)(s) ) )
	{
		label->setText( s );
	}
}
//---------------------------------------------------------------------------
void QLCDRange::addStep( void )
{
	setValue( value() + 1 );
}
//---------------------------------------------------------------------------
void QLCDRange::subtractStep( void )
{
	setValue( value() - 1 );
}
//---------------------------------------------------------------------------
