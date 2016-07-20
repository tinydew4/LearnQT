//---------------------------------------------------------------------------
#include "Tank.h"
#include "LCDRange.h"
#include "Cannon.h"
//---------------------------------------------------------------------------
#include <QApplication.h>
#include <QPushButton.h>
#include <QLCDNumber.h>
#include <QLayout.h>
#include <QVBox.h>
#include <QFont.h>
#include <QLabel.h>
#include <QAccel.h>
//---------------------------------------------------------------------------
QTank::QTank( QWidget *parent, const char *name )
	: QWidget( parent, name )
{
	exit = new QPushButton( "E&xit", this, "exit" );
	exit->setFont( QFont( "Times", 18, QFont::Bold ) );

	QObject::connect( exit, SIGNAL( clicked() ), qApp, SLOT( quit() ) );


	QVBox *box = new QVBox( this, "cannonFrame" );
	box->setFrameStyle( QFrame::WinPanel | QFrame::Sunken );
	cannonField = new QCannonField( box, "cannonField" );

	QObject::connect( cannonField, SIGNAL( hit() ),    SLOT( hit() ) );
	QObject::connect( cannonField, SIGNAL( missed() ), SLOT( missed() ) );


	angle = new QLCDRange( "ANGLE", this, "angle" );
	angle->setRange( 5, 70 );

	force = new QLCDRange( "FORCE", this, "force" );
	force->setRange( 10, 50 );

	QObject::connect( angle,       SIGNAL( valueChanged( int ) ), cannonField, SLOT( setAngle( int ) ) );
	QObject::connect( cannonField, SIGNAL( angleChanged( int ) ), angle, SLOT( setValue( int ) ) );
	QObject::connect( force,       SIGNAL( valueChanged( int ) ), cannonField, SLOT( setForce( int ) ) );
	QObject::connect( cannonField, SIGNAL( forceChanged( int ) ), force, SLOT( setValue( int ) ) );


	shoot = new QPushButton( "&Shoot", this, "shoot" );
	shoot->setFont( QFont( "Times", 18, QFont::Bold ) );

	QObject::connect( shoot, SIGNAL( clicked() ), this, SLOT( fire() ) );
	QObject::connect( cannonField, SIGNAL( canShoot( bool ) ), shoot, SLOT( setEnabled( bool ) ) );


	cheat = new QPushButton( "&Cheat", this, "cheat" );
	cheat->setFont( QFont( "Times", 18, QFont::Bold ) );

	QObject::connect( cheat, SIGNAL( clicked() ), cannonField, SLOT( showTrajectory() ) );
	QObject::connect( cannonField, SIGNAL( canShoot( bool ) ), cheat, SLOT( setEnabled( bool ) ) );


	restart = new QPushButton( "&New Game", this, "newgame" );
	restart->setFont( QFont( "Times", 18, QFont::Bold ) );

	QObject::connect( restart, SIGNAL( clicked() ), this, SLOT( newGame() ) );


	hits      = new QLCDNumber( 2, this, "hits" );
	shotsLeft = new QLCDNumber( 2, this, "shotsleft" );
	QLabel *hitsL      = new QLabel( "HITS", this, "hitsLabel" );
	QLabel *shotsLeftL = new QLabel( "SHOTS LEFT", this, "shotsleftLabel" );


	accel = new QAccel( this, "accel" );

	accel->connectItem( accel->insertItem( Key_Space  ), this, SLOT( fire() ) );
	accel->connectItem( accel->insertItem( Key_Enter  ), this, SLOT( fire() ) );
	accel->connectItem( accel->insertItem( Key_Return ), this, SLOT( fire() ) );
	accel->connectItem( accel->insertItem( CTRL+Key_Q ), qApp, SLOT( quit() ) );

	accel->connectItem( accel->insertItem( Key_Up    ), angle, SLOT( addStep() ) );
	accel->connectItem( accel->insertItem( Key_Down  ), angle, SLOT( subtractStep() ) );
	accel->connectItem( accel->insertItem( Key_Plus  ), force, SLOT( addStep() ) );
	accel->connectItem( accel->insertItem( Key_Minus ), force, SLOT( subtractStep() ) );

	accel->connectItem( accel->insertItem( Key_Tab       ), NULL, NULL );
	accel->connectItem( accel->insertItem( CTRL+Key_Tab  ), NULL, NULL );
	accel->connectItem( accel->insertItem( SHIFT+Key_Tab ), NULL, NULL );

	accel->connectItem( accel->insertItem( CTRL+Key_Enter  ), cannonField, SLOT( shoot() ) );


	QVBoxLayout *leftBox = new QVBoxLayout;
	leftBox->addWidget( angle );
	leftBox->addWidget( force );

	QHBoxLayout *topBox = new QHBoxLayout;
	topBox->addWidget( cheat );
	topBox->addWidget( shoot );
	topBox->addWidget( hits );
	topBox->addWidget( hitsL );
	topBox->addWidget( shotsLeft );
	topBox->addWidget( shotsLeftL );
	topBox->addStretch( 1 );
	topBox->addWidget( restart );

	QGridLayout *grid = new QGridLayout( this, 2, 2, 10 );
	grid->addWidget( exit, 0, 0 );
	grid->addLayout( topBox, 0, 1 );
	grid->addLayout( leftBox, 1, 0 );
	grid->addWidget( box, 1, 1 );
	grid->setColStretch( 1, 1 );


	angle->setValue( 60 );
	force->setValue( 25 );

	newGame();
}
//---------------------------------------------------------------------------
void QTank::fire( void )
{
	if ( ! ( cannonField->gameOver() || cannonField->isShooting() || shotsLeft->intValue() <= 0) )
	{
		shotsLeft->display( shotsLeft->intValue() - 1 );
		cannonField->shoot();
	}
}
//---------------------------------------------------------------------------
void QTank::hit( void )
{
	hits->display( hits->intValue() + 1 );

	if ( shotsLeft->intValue() <= 0 )
	{
		cannonField->setGameOver();
	}
	else
	{
		cannonField->newTarget();
	}
}
//---------------------------------------------------------------------------
void QTank::missed( void )
{
	if ( shotsLeft->intValue() <= 0 )
	{
		cannonField->setGameOver();
	}
}
//---------------------------------------------------------------------------
void QTank::newGame( void )
{
	shotsLeft->display( 15 );
	hits->display( 0 );
	cannonField->restartGame();
	cannonField->newTarget();
}
//---------------------------------------------------------------------------
