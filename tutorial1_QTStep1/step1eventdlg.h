/****************************************************************************
** Form interface generated from reading ui file '.\step1eventdlg.ui'
**
** Created: Sun Mar 2 16:19:29 2003
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef QSTEP1EVENTDLG_H
#define QSTEP1EVENTDLG_H

#include <qvariant.h>
#include <qdialog.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QFrame;
class QLabel;
class QPushButton;

class QStep1EventDlg : public QDialog
{ 
    Q_OBJECT

public:
    QStep1EventDlg( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QStep1EventDlg();

    QFrame* Frame3;
    QLabel* TextLabel1;
    QPushButton* buttonOk;
    QPushButton* buttonCancel;

protected:
    QVBoxLayout* QStep1EventDlgLayout;
    QGridLayout* Frame3Layout;
    QHBoxLayout* Layout1;
    bool event( QEvent* );
};

#endif // QSTEP1EVENTDLG_H
