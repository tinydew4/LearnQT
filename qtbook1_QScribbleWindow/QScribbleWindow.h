//---------------------------------------------------------------------------
#ifndef QScribbleWindowH
#define QScribbleWindowH
//---------------------------------------------------------------------------
#include <QWidget.h>
//---------------------------------------------------------------------------
class QMenuBar;
class QPopupMenu;
class QAction;
class QScrollView;
class QScribbleArea;
//---------------------------------------------------------------------------
enum MenuIDs
{
	COLOR_MENU_ID_BLACK,
	COLOR_MENU_ID_RED,
	COLOR_MENU_ID_BLUE,
	COLOR_MENU_ID_GREEN,
	COLOR_MENU_ID_YELLOW,
	PEN_MENU_ID_1,
	PEN_MENU_ID_2,
	PEN_MENU_ID_3,
	PEN_MENU_ID_4,
	PEN_MENU_ID_5
};
//---------------------------------------------------------------------------
class QScribbleWindow : public QWidget
{
	Q_OBJECT

private:
	QMenuBar *_menubar;
	QPopupMenu *_filemenu;
	QPopupMenu *_colormenu;
	QPopupMenu *_widthmenu;
	QPopupMenu *_helpmenu;

	QScrollView *_scrollview;
	QScribbleArea *_scribblearea;

	QAction *_action;

public:
	QScribbleWindow( QWidget *parent = 0, const char *name = 0 );
	virtual ~QScribbleWindow( void );

signals:
	void colorChanged( QColor );
	void widthChanged( int );
	void fileLoad( const char * );
	void fileSave( const char * );

private slots:
	void About( void );
	void ColorMenu( int );
	void WidthMenu( int );
	void load( void );
	void save( void );
	void setTitle( const char *title = "unnamed" );

protected:
	virtual void resizeEvent( QResizeEvent * );
	virtual void keyPressEvent( QKeyEvent * );

};
//---------------------------------------------------------------------------
#endif
