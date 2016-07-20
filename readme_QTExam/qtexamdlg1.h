/****************************************************************************
** Form interface generated from reading ui file '.\qtexamdlg1.ui'
**
** Created: Fri Feb 28 19:20:27 2003
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef QTEXAMDLG1BASE_H
#define QTEXAMDLG1BASE_H

#include <qvariant.h>
#include <qdialog.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QButtonGroup;
class QPushButton;
class QRadioButton;

class QTExamDlg1Base : public QDialog
{ 
    Q_OBJECT

public:
    QTExamDlg1Base( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QTExamDlg1Base();

    QButtonGroup* ButtonGroup1;
    QRadioButton* RadioButton1;
    QRadioButton* RadioButton2;
    QRadioButton* RadioButton3;
    QPushButton* buttonHelp;
    QPushButton* buttonOk;
    QPushButton* buttonCancel;

protected:
    QVBoxLayout* QTExamDlg1BaseLayout;
    QHBoxLayout* ButtonGroup1Layout;
    QVBoxLayout* Layout2;
    QHBoxLayout* Layout1;
};

#endif // QTEXAMDLG1BASE_H
