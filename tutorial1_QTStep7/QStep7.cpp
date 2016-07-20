//---------------------------------------------------------------------------
#include "QStep7.h"
//---------------------------------------------------------------------------
#include <QApplication.h>
#include <QPushButton.h>
#include <QLCDNumber.h>
#include <QFont.h>
#include <QGrid.h>
#include "LCDRange.h"
//---------------------------------------------------------------------------
QStep7::QStep7( QWidget *parent, char *name )
	: QVBox( parent, name )
{
	m_iExit = new QPushButton( "E&xit", this, "exit" );
	m_iExit->setFont( QFont( "Times", 18, QFont::Bold ) );

	connect( m_iExit, SIGNAL( clicked() ), qApp, SLOT( quit() ) );

	m_iBackGrid = new QGrid( 4, this );

	QLCDRange *PrevRange = 0;
	QLCDRange *CurRange  = 0;

	for (int i = 15; i >= 0; --i)
	{
		CurRange = new QLCDRange( m_iBackGrid );

		if ( PrevRange )
		{
			connect( CurRange, SIGNAL( valueChanged( int ) ), PrevRange, SLOT( setValue ( int ) ) );
		}

		PrevRange = CurRange;
	}
}
//---------------------------------------------------------------------------
