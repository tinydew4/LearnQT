/****************************************************************************
** Form implementation generated from reading ui file '.\step1eventdlg.ui'
**
** Created: Sun Mar 2 16:19:29 2003
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "step1eventdlg.h"

#include <qframe.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a QStep1EventDlg which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
QStep1EventDlg::QStep1EventDlg( QWidget* parent,  const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "QStep1EventDlg" );
    resize( 190, 95 ); 
    QFont f( font() );
    f.setFamily( "Fixedsys" );
    setFont( f ); 
    setCaption( tr( "Step1EventDlg" ) );
    setSizeGripEnabled( TRUE );
    QStep1EventDlgLayout = new QVBoxLayout( this ); 
    QStep1EventDlgLayout->setSpacing( 6 );
    QStep1EventDlgLayout->setMargin( 11 );

    Frame3 = new QFrame( this, "Frame3" );
    Frame3->setFrameShape( QFrame::StyledPanel );
    Frame3->setFrameShadow( QFrame::Raised );
    Frame3Layout = new QGridLayout( Frame3 ); 
    Frame3Layout->setSpacing( 6 );
    Frame3Layout->setMargin( 11 );

    TextLabel1 = new QLabel( Frame3, "TextLabel1" );
    QFont TextLabel1_font(  TextLabel1->font() );
    TextLabel1_font.setFamily( "굴림" );
    TextLabel1->setFont( TextLabel1_font ); 
    TextLabel1->setText( tr( "Want to exit process?" ) );

    Frame3Layout->addWidget( TextLabel1, 0, 0 );
    QStep1EventDlgLayout->addWidget( Frame3 );

    Layout1 = new QHBoxLayout; 
    Layout1->setSpacing( 6 );
    Layout1->setMargin( 0 );

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
    QStep1EventDlgLayout->addLayout( Layout1 );

    // signals and slots connections
    connect( buttonOk, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( buttonCancel, SIGNAL( clicked() ), this, SLOT( reject() ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
QStep1EventDlg::~QStep1EventDlg()
{
    // no need to delete child widgets, Qt does it all for us
}

/*  
 *  Main event handler. Reimplemented to handle application
 *  font changes
 */
bool QStep1EventDlg::event( QEvent* ev )
{
    bool ret = QDialog::event( ev ); 
    if ( ev->type() == QEvent::ApplicationFontChange ) {
	QFont TextLabel1_font(  TextLabel1->font() );
	TextLabel1_font.setFamily( "굴림" );
	TextLabel1->setFont( TextLabel1_font ); 
    }
    return ret;
}

