#include <qmainwindow.h>
#include <qapplication.h>
#include <qtable.h>

class QTExamWindow : public QMainWindow
{
	Q_OBJECT
private:
	QTable *table;
public slots:
    void newDocument();
public:
	QTExamWindow( QWidget* parent = 0, const char* name = 0, WFlags f = WType_TopLevel );
};

