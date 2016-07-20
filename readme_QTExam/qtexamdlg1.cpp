/****************************************************************************
** Form implementation generated from reading ui file '.\qtexamdlg1.ui'
**
** Created: Fri Feb 28 19:20:27 2003
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "qtexamdlg1.h"

#include <qbuttongroup.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a QTExamDlg1Base which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
QTExamDlg1Base::QTExamDlg1Base( QWidget* parent,  const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "QTExamDlg1Base" );
    resize( 283, 142 ); 
    setCaption( tr( "QTExamDlg1" ) );
    setSizeGripEnabled( TRUE );
    QTExamDlg1BaseLayout = new QVBoxLayout( this ); 
    QTExamDlg1BaseLayout->setSpacing( 6 );
    QTExamDlg1BaseLayout->setMargin( 11 );

    ButtonGroup1 = new QButtonGroup( this, "ButtonGroup1" );
    ButtonGroup1->setTitle( tr( "ButtonGroup1" ) );
    ButtonGroup1->setColumnLayout(0, Qt::Vertical );
    ButtonGroup1->layout()->setSpacing( 0 );
    ButtonGroup1->layout()->setMargin( 0 );
    ButtonGroup1Layout = new QHBoxLayout( ButtonGroup1->layout() );
    ButtonGroup1Layout->setAlignment( Qt::AlignTop );
    ButtonGroup1Layout->setSpacing( 6 );
    ButtonGroup1Layout->setMargin( 11 );

    Layout2 = new QVBoxLayout; 
    Layout2->setSpacing( 6 );
    Layout2->setMargin( 0 );

    RadioButton1 = new QRadioButton( ButtonGroup1, "RadioButton1" );
    RadioButton1->setText( tr( "RadioButton1" ) );
    Layout2->addWidget( RadioButton1 );

    RadioButton2 = new QRadioButton( ButtonGroup1, "RadioButton2" );
    RadioButton2->setText( tr( "RadioButton2" ) );
    Layout2->addWidget( RadioButton2 );

    RadioButton3 = new QRadioButton( ButtonGroup1, "RadioButton3" );
    RadioButton3->setText( tr( "RadioButton3" ) );
    Layout2->addWidget( RadioButton3 );
    ButtonGroup1Layout->addLayout( Layout2 );
    QTExamDlg1BaseLayout->addWidget( ButtonGroup1 );

    Layout1 = new QHBoxLayout; 
    Layout1->setSpacing( 6 );
    Layout1->setMargin( 0 );

    buttonHelp = new QPushButton( this, "buttonHelp" );
    buttonHelp->setText( tr( "&Help" ) );
    buttonHelp->setAutoDefault( TRUE );
    Layout1->addWidget( buttonHelp );
    QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout1->addItem( spacer );

    buttonOk = new QPushButton( this, "buttonOk" );
    buttonOk->setCaption( tr( "" ) );
    buttonOk->setText( tr( "&OK" ) );
    buttonOk->setAutoDefault( TRUE );
    buttonOk->setDefault( TRUE );
    Layout1->addWidget( buttonOk );

    buttonCancel = new QPushButton( this, "buttonCancel" );
    buttonCancel->setText( tr( "&Cancel" ) );
    buttonCancel->setAutoDefault( TRUE );
    Layout1->addWidget( buttonCancel );
    QTExamDlg1BaseLayout->addLayout( Layout1 );

    // signals and slots connections
    connect( buttonOk, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( buttonCancel, SIGNAL( clicked() ), this, SLOT( reject() ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
QTExamDlg1Base::~QTExamDlg1Base()
{
    // no need to delete child widgets, Qt does it all for us
}

