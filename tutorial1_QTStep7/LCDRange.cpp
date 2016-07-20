//---------------------------------------------------------------------------
#include "LCDRange.h"
//---------------------------------------------------------------------------
#include <QSlider.h>
#include <QLCDNumber.h>
//---------------------------------------------------------------------------
QLCDRange::QLCDRange( QWidget *parent, char *name )
	: QVBox( parent, name )
{
	QLCDNumber *m_iLCD = new QLCDNumber( 2, this, "lcd" );
	m_iSlider = new QSlider( Horizontal, this, "slider" );
	m_iSlider->setRange( 0, 99 );
	m_iSlider->setValue( 0 );
	connect( m_iSlider, SIGNAL( valueChanged( int ) ), m_iLCD, SLOT( display( int ) ) );
	connect( m_iSlider, SIGNAL( valueChanged( int ) ), SIGNAL( valueChanged( int ) ) );
}
//---------------------------------------------------------------------------
void QLCDRange::setValue( int value )
{
	m_iSlider->setValue( value );
}
//---------------------------------------------------------------------------
int QLCDRange::value( void ) const
{
	return m_iSlider->value();
}
//---------------------------------------------------------------------------
