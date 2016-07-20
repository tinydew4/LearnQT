/****************************************************************************
** QLCDRange meta object code from reading C++ file 'LCDRange.h'
**
** Created: Thu Mar 13 13:51:23 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_QLCDRange
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "LCDRange.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *QLCDRange::className() const
{
    return "QLCDRange";
}

QMetaObject *QLCDRange::metaObj = 0;

void QLCDRange::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("QLCDRange","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString QLCDRange::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("QLCDRange",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* QLCDRange::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(QLCDRange::*m1_t0)(int);
    typedef void(QLCDRange::*m1_t1)(int,int);
    typedef void(QLCDRange::*m1_t2)(const char*);
    typedef void(QLCDRange::*m1_t3)();
    typedef void(QLCDRange::*m1_t4)();
    m1_t0 v1_0 = Q_AMPERSAND QLCDRange::setValue;
    m1_t1 v1_1 = Q_AMPERSAND QLCDRange::setRange;
    m1_t2 v1_2 = Q_AMPERSAND QLCDRange::setText;
    m1_t3 v1_3 = Q_AMPERSAND QLCDRange::addStep;
    m1_t4 v1_4 = Q_AMPERSAND QLCDRange::subtractStep;
    QMetaData *slot_tbl = QMetaObject::new_metadata(5);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(5);
    slot_tbl[0].name = "setValue(int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "setRange(int,int)";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "setText(const char*)";
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl_access[2] = QMetaData::Public;
    slot_tbl[3].name = "addStep()";
    slot_tbl[3].ptr = *((QMember*)&v1_3);
    slot_tbl_access[3] = QMetaData::Public;
    slot_tbl[4].name = "subtractStep()";
    slot_tbl[4].ptr = *((QMember*)&v1_4);
    slot_tbl_access[4] = QMetaData::Public;
    typedef void(QLCDRange::*m2_t0)(int);
    m2_t0 v2_0 = Q_AMPERSAND QLCDRange::valueChanged;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "valueChanged(int)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"QLCDRange", "QWidget",
	slot_tbl, 5,
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

// SIGNAL valueChanged
void QLCDRange::valueChanged( int t0 )
{
    activate_signal( "valueChanged(int)", t0 );
}
