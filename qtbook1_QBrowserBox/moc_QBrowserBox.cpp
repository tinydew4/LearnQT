/****************************************************************************
** QBrowserBox meta object code from reading C++ file 'QBrowserBox.h'
**
** Created: Sat Apr 19 22:39:44 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_QBrowserBox
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "QBrowserBox.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *QBrowserBox::className() const
{
    return "QBrowserBox";
}

QMetaObject *QBrowserBox::metaObj = 0;

void QBrowserBox::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QTableView::className(), "QTableView") != 0 )
	badSuperclassWarning("QBrowserBox","QTableView");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString QBrowserBox::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("QBrowserBox",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* QBrowserBox::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QTableView::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    typedef void(QBrowserBox::*m2_t0)(int,int);
    m2_t0 v2_0 = Q_AMPERSAND QBrowserBox::selected;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "selected(int,int)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"QBrowserBox", "QTableView",
	0, 0,
	signal_tbl, 1,
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

// SIGNAL selected
void QBrowserBox::selected( int t0, int t1 )
{
    // No builtin function for signal parameter type int,int
    QConnectionList *clist = receivers("selected(int,int)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef RT0 *PRT0;
    typedef void (QObject::*RT1)(int);
    typedef RT1 *PRT1;
    typedef void (QObject::*RT2)(int,int);
    typedef RT2 *PRT2;
    RT0 r0;
    RT1 r1;
    RT2 r2;
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
	    case 2:
		r2 = *((PRT2)(c->member()));
		(object->*r2)(t0, t1);
		break;
	}
    }
}
