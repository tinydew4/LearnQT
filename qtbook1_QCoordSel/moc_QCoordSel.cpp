/****************************************************************************
** QCoordSel meta object code from reading C++ file 'QCoordSel.h'
**
** Created: Sat Apr 19 12:10:38 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_QCoordSel
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "QCoordSel.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *QCoordSel::className() const
{
    return "QCoordSel";
}

QMetaObject *QCoordSel::metaObj = 0;

void QCoordSel::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("QCoordSel","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString QCoordSel::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("QCoordSel",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* QCoordSel::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(QCoordSel::*m1_t0)(int);
    typedef void(QCoordSel::*m1_t1)(int);
    typedef void(QCoordSel::*m1_t2)(int);
    typedef void(QCoordSel::*m1_t3)(int);
    typedef void(QCoordSel::*m1_t4)(int,int);
    typedef void(QCoordSel::*m1_t5)(const QPoint&);
    m1_t0 v1_0 = Q_AMPERSAND QCoordSel::setXMinValue;
    m1_t1 v1_1 = Q_AMPERSAND QCoordSel::setXMaxValue;
    m1_t2 v1_2 = Q_AMPERSAND QCoordSel::setYMinValue;
    m1_t3 v1_3 = Q_AMPERSAND QCoordSel::setYMaxValue;
    m1_t4 v1_4 = Q_AMPERSAND QCoordSel::setValue;
    m1_t5 v1_5 = Q_AMPERSAND QCoordSel::setValue;
    QMetaData *slot_tbl = QMetaObject::new_metadata(6);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(6);
    slot_tbl[0].name = "setXMinValue(int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "setXMaxValue(int)";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "setYMinValue(int)";
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl_access[2] = QMetaData::Public;
    slot_tbl[3].name = "setYMaxValue(int)";
    slot_tbl[3].ptr = *((QMember*)&v1_3);
    slot_tbl_access[3] = QMetaData::Public;
    slot_tbl[4].name = "setValue(int,int)";
    slot_tbl[4].ptr = *((QMember*)&v1_4);
    slot_tbl_access[4] = QMetaData::Public;
    slot_tbl[5].name = "setValue(const QPoint&)";
    slot_tbl[5].ptr = *((QMember*)&v1_5);
    slot_tbl_access[5] = QMetaData::Public;
    typedef void(QCoordSel::*m2_t0)(int,int);
    m2_t0 v2_0 = Q_AMPERSAND QCoordSel::valueChanged;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "valueChanged(int,int)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"QCoordSel", "QWidget",
	slot_tbl, 6,
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

// SIGNAL valueChanged
void QCoordSel::valueChanged( int t0, int t1 )
{
    // No builtin function for signal parameter type int,int
    QConnectionList *clist = receivers("valueChanged(int,int)");
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
