#include "qtexamdlg1impl.h"

/* 
 *  Constructs a QTExamDlg1 which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
QTExamDlg1::QTExamDlg1( QWidget* parent,  const char* name, bool modal, WFlags fl )
    : QTExamDlg1Base( parent, name, modal, fl )
{
}

/*  
 *  Destroys the object and frees any allocated resources
 */
QTExamDlg1::~QTExamDlg1()
{
    // no need to delete child widgets, Qt does it all for us
}

