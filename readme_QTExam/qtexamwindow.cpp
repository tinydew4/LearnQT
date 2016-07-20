#include "qtexamwindow.h"
#include "qtexamdlg1impl.h"

#include <qaction.h>
#include <qpopupmenu.h>
#include <qmenubar.h>

QTExamWindow::QTExamWindow( QWidget* parent, const char* name, WFlags f )
	: QMainWindow( parent, name, f )
{
	setCaption("QTExam");

	QAction *actFileNew  = new QAction( "New", "&New", CTRL+Key_N, this, "new" );
	QAction *actFileQuit = new QAction( "Quit", "&Quit", CTRL+Key_Q, this, "quit" );

	connect( actFileNew,  SIGNAL( activated() ), this, SLOT( newDocument() ) );
	connect( actFileQuit, SIGNAL( activated() ), qApp, SLOT( quit() ) );

	QPopupMenu *menuFile = new QPopupMenu( this );
	actFileNew->addTo( menuFile );
	menuFile->insertSeparator();
	actFileQuit->addTo( menuFile );

	QMenuBar *menuMain = menuBar();
	menuMain->insertItem( "&File", menuFile );

	table = new QTable( 52, 12, this );
	table->setFocus();
	setCentralWidget( table );
}

void QTExamWindow::newDocument()
{
    QTExamDlg1 *docDlg = new QTExamDlg1( this, "new", TRUE );
    if ( docDlg->exec() ) {
        ; // user clicked OK
    }
    else {
        ; // user clicked Cancel
    }
    delete docDlg;
}
