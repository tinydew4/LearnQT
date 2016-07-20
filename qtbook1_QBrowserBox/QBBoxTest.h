//---------------------------------------------------------------------------
#ifndef QBBoxTestH
#define QBBoxTestH
//---------------------------------------------------------------------------
#include <QWidget.h>
//---------------------------------------------------------------------------
class QPushButton;
//---------------------------------------------------------------------------
class QBBoxTest : public QWidget
{
	Q_OBJECT

private:
	QPushButton *quit;

public slots:
	void buttonClicked( void );

public:
	QBBoxTest( QWidget *parent = 0, const char *name = 0, WFlags flags = 0 );
};
//---------------------------------------------------------------------------
#endif
