//---------------------------------------------------------------------------
#ifndef QBrowserBoxH
#define QBrowserBoxH
//---------------------------------------------------------------------------
#include <QWidget.h>
#include <QTableView.h>
#include <QArray.h>
//---------------------------------------------------------------------------
class QString;
class QPainter;
class QPixmap;
//---------------------------------------------------------------------------
class QBrowserBox : public QTableView
{
	Q_OBJECT

private:
	int coordsToIndex( int x, int y );

	QString *_texts;
	QPixmap *_pixmaps;
	QPoint _activecell;
	bool _firstrelease;

signals:
	void selected( int, int );

public:
	QBrowserBox( int x, int y, QWidget *parent = 0, const char *name = 0, WFlags f = 0 );
	~QBrowserBox( void );

	void insertItem( const char *text, int x, int y );
	void insertItem( QPixmap pixmap, int x, int y );
	void removeItem( int x, int y );
	void clear( void );

	QString text( int x, int y );
	QPixmap pixmap( int x, int y );

	int exec( const QPoint &pos );
	int exec( int x, int y );
	int exec( const QWidget *trigger );

protected:
	virtual void keyPressEvent( QKeyEvent *e );
	virtual void resizeEvent( QResizeEvent *e );
	virtual void mouseReleaseEvent( QMouseEvent *e );
	virtual void mouseMoveEvent( QMouseEvent *e );
	virtual void paintCell( QPainter *, int, int );

};
//---------------------------------------------------------------------------
#endif