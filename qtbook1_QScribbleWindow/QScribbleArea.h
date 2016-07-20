//---------------------------------------------------------------------------
#ifndef QScribbleAreaH
#define QScribbleAreaH
//---------------------------------------------------------------------------
#include <QWidget.h>
#include <QPixmap.h>
#include <QPen.h>
//---------------------------------------------------------------------------
class QPopupMenu;
//---------------------------------------------------------------------------
class QScribbleArea : public QWidget
{
	Q_OBJECT

private:
	QPoint _last;
	QPen _currentpen;
	QPixmap _buffer;
	QPopupMenu *_popupmenu;
	QPopupMenu *_editmenu;
	QPopupMenu *_penmenu;
	bool _modified;

public:
	QScribbleArea( QPopupMenu *colormenu, QPopupMenu *widthmenu,
		QWidget *parent = 0, const char *name = 0 );
	virtual ~QScribbleArea( void );

	bool isModified( void );

signals:
	void fileChanged( const char * );

public slots:
	void setColor( QColor );
	void setWidth( int );
	void clearArea( void );
	void load( const char * );
	void save( const char * );

protected:
	virtual void mousePressEvent( QMouseEvent * );
	virtual void mouseMoveEvent( QMouseEvent * );
	virtual void paintEvent( QPaintEvent * );
	virtual void resizeEvent( QResizeEvent * );

};
//---------------------------------------------------------------------------
#endif
