//---------------------------------------------------------------------------
#include "QStep2.h"
//---------------------------------------------------------------------------
#include <QFont.h>
#include <stdlib.h>
#include <time.h>
//---------------------------------------------------------------------------
QStep2::QStep2( QWidget *parent, const char *name )
	: QVBox( parent, name )
{
	int limit = 95;
	srand( (unsigned int)time( NULL ) );

	m_iGrid = new QGrid( 4, this );

	for ( int i = 15; i >= 0; --i )
	{
		m_iStep1[i] = new QStep1( rand() % limit, 0, 99, limit, m_iGrid );
	}

	m_iBtnExit = new QPushButton( "E&xit", this, "Exit" );
	m_iBtnExit->setFont( QFont( "Times", 18, QFont::Bold ) );

	QObject::connect( m_iBtnExit, SIGNAL( clicked() ), qApp, SLOT( quit() ) );
}
//---------------------------------------------------------------------------
