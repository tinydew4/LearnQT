//---------------------------------------------------------------------------
#ifndef QStep2H
#define QStep2H
//---------------------------------------------------------------------------
#include <QVBox.h>
#include <QPushButton.h>
#include <QGrid.h>
#include "QStep1.h"
//---------------------------------------------------------------------------
class QStep2 : public QVBox
{
private:
	QPushButton *m_iBtnExit;
	QGrid *m_iGrid;
	QStep1 *m_iStep1[16];

public:
	QStep2( QWidget *parent = 0, const char *name = 0 );
};
//---------------------------------------------------------------------------
#endif
