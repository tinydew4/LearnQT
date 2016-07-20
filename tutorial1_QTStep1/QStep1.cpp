//---------------------------------------------------------------------------
#include "QStep1.h"
#include "step1eventdlg.h"
//---------------------------------------------------------------------------
QStep1::QStep1( UINT value, UINT minimum, UINT maximum,
	UINT limit, QWidget *parent, const char *name )
	: QVBox( parent, name ), m_iLimit(limit)
{
	m_iLcd = new QLCDNumber( 2, this, "lcd" );
	m_iSlider = new QSlider( Horizontal, this, "slider" );
	m_iSlider->setRange( minimum, maximum );
	m_iSpinBox = new QSpinBox( minimum, maximum, 1, this, "spinbox" );

	QObject::connect( m_iSlider,  SIGNAL( valueChanged( int ) ), m_iSpinBox, SLOT( setValue( int ) ) );
	QObject::connect( m_iSpinBox, SIGNAL( valueChanged( int ) ), m_iSlider,  SLOT( setValue( int ) ) );
	QObject::connect( m_iSlider,  SIGNAL( valueChanged( int ) ), m_iLcd,     SLOT( display( int ) ) );

	QObject::connect( m_iLcd,     SIGNAL( overflow() ),          qApp,       SLOT( quit() ) );
	QObject::connect( m_iSlider,  SIGNAL( valueChanged( int ) ), SLOT( checkValue( int ) ) );

	m_iSlider->setValue( value );
}
//---------------------------------------------------------------------------
void QStep1::showDialog( void )
{
	QStep1EventDlg *eDlg = new QStep1EventDlg( this, "new", TRUE );

	if (eDlg)
	{
		if ( eDlg->exec() )
		{
			QApplication::exit();
		}

		delete eDlg;
	}
}
//---------------------------------------------------------------------------
void QStep1::checkValue( int value )
{
	static bool prevChecked = false;

	if ( (UINT)value > m_iLimit )
	{
		if ( ! prevChecked )
		{
			prevChecked = true;

			showDialog();
		}
	}
	else
	{
		prevChecked = false;
	}
}
//---------------------------------------------------------------------------
