/****************************************************************************
** QScribbleWindow meta object code from reading C++ file 'QScribbleWindow.h'
**
** Created: Wed Mar 26 10:55:28 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_QScribbleWindow
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "QScribbleWindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *QScribbleWindow::className() const
{
    return "QScribbleWindow";
}

QMetaObject *QScribbleWindow::metaObj = 0;

void QScribbleWindow::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("QScribbleWindow","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString QScribbleWindow::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("QScribbleWindow",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* QScribbleWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(QScribbleWindow::*m1_t0)();
    typedef void(QScribbleWindow::*m1_t1)(int);
    typedef void(QScribbleWindow::*m1_t2)(int);
    typedef void(QScribbleWindow::*m1_t3)();
    typedef void(QScribbleWindow::*m1_t4)();
    typedef void(QScribbleWindow::*m1_t5)(const char*);
    m1_t0 v1_0 = Q_AMPERSAND QScribbleWindow::About;
    m1_t1 v1_1 = Q_AMPERSAND QScribbleWindow::ColorMenu;
    m1_t2 v1_2 = Q_AMPERSAND QScribbleWindow::WidthMenu;
    m1_t3 v1_3 = Q_AMPERSAND QScribbleWindow::load;
    m1_t4 v1_4 = Q_AMPERSAND QScribbleWindow::save;
    m1_t5 v1_5 = Q_AMPERSAND QScribbleWindow::setTitle;
    QMetaData *slot_tbl = QMetaObject::new_metadata(6);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(6);
    slot_tbl[0].name = "About()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Private;
    slot_tbl[1].name = "ColorMenu(int)";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Private;
    slot_tbl[2].name = "WidthMenu(int)";
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl_access[2] = QMetaData::Private;
    slot_tbl[3].name = "load()";
    slot_tbl[3].ptr = *((QMember*)&v1_3);
    slot_tbl_access[3] = QMetaData::Private;
    slot_tbl[4].name = "save()";
    slot_tbl[4].ptr = *((QMember*)&v1_4);
    slot_tbl_access[4] = QMetaData::Private;
    slot_tbl[5].name = "setTitle(const char*)";
    slot_tbl[5].ptr = *((QMember*)&v1_5);
    slot_tbl_access[5] = QMetaData::Private;
    typedef void(QScribbleWindow::*m2_t0)(QColor);
    typedef void(QScribbleWindow::*m2_t1)(int);
    typedef void(QScribbleWindow::*m2_t2)(const char*);
    typedef void(QScribbleWindow::*m2_t3)(const char*);
    m2_t0 v2_0 = Q_AMPERSAND QScribbleWindow::colorChanged;
    m2_t1 v2_1 = Q_AMPERSAND QScribbleWindow::widthChanged;
    m2_t2 v2_2 = Q_AMPERSAND QScribbleWindow::fileLoad;
    m2_t3 v2_3 = Q_AMPERSAND QScribbleWindow::fileSave;
    QMetaData *signal_tbl = QMetaObject::new_metadata(4);
    signal_tbl[0].name = "colorChanged(QColor)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    signal_tbl[1].name = "widthChanged(int)";
    signal_tbl[1].ptr = *((QMember*)&v2_1);
    signal_tbl[2].name = "fileLoad(const char*)";
    signal_tbl[2].ptr = *((QMember*)&v2_2);
    signal_tbl[3].name = "fileSave(const char*)";
    signal_tbl[3].ptr = *((QMember*)&v2_3);
    metaObj = QMetaObject::new_metaobject(
	"QScribbleWindow", "QWidget",
	slot_tbl, 6,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL colorChanged
void QScribbleWindow::colorChanged( QColor t0 )
{
    // No builtin function for signal parameter type QColor
    QConnectionList *clist = receivers("colorChanged(QColor)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef RT0 *PRT0;
    typedef void (QObject::*RT1)(QColor);
    typedef RT1 *PRT1;
    RT0 r0;
    RT1 r1;
    QConnectionListIt it(*clist);
    QConnection   *c;
    QSenderObject *object;
    while ( (c=it.current()) ) {
	++it;
	object = (QSenderObject*)c->object();
	object->setSender( this );
	switch ( c->numArgs() ) {
	    case 0:
		r0 = *((PRT0)(c->member()));
		(object->*r0)();
		break;
	    case 1:
		r1 = *((PRT1)(c->member()));
		(object->*r1)(t0);
		break;
	}
    }
}

// SIGNAL widthChanged
void QScribbleWindow::widthChanged( int t0 )
{
    activate_signal( "widthChanged(int)", t0 );
}

// SIGNAL fileLoad
void QScribbleWindow::fileLoad( const char* t0 )
{
    activate_signal( "fileLoad(const char*)", t0 );
}

// SIGNAL fileSave
void QScribbleWindow::fileSave( const char* t0 )
{
    activate_signal( "fileSave(const char*)", t0 );
}
