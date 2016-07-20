/****************************************************************************
** QTank meta object code from reading C++ file 'Tank.h'
**
** Created: Thu Mar 13 14:15:26 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_QTank
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "Tank.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *QTank::className() const
{
    return "QTank";
}

QMetaObject *QTank::metaObj = 0;

void QTank::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("QTank","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString QTank::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("QTank",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* QTank::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(QTank::*m1_t0)();
    typedef void(QTank::*m1_t1)();
    typedef void(QTank::*m1_t2)();
    typedef void(QTank::*m1_t3)();
    m1_t0 v1_0 = Q_AMPERSAND QTank::fire;
    m1_t1 v1_1 = Q_AMPERSAND QTank::hit;
    m1_t2 v1_2 = Q_AMPERSAND QTank::missed;
    m1_t3 v1_3 = Q_AMPERSAND QTank::newGame;
    QMetaData *slot_tbl = QMetaObject::new_metadata(4);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(4);
    slot_tbl[0].name = "fire()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Private;
    slot_tbl[1].name = "hit()";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Private;
    slot_tbl[2].name = "missed()";
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl_access[2] = QMetaData::Private;
    slot_tbl[3].name = "newGame()";
    slot_tbl[3].ptr = *((QMember*)&v1_3);
    slot_tbl_access[3] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"QTank", "QWidget",
	slot_tbl, 4,
	0, 0,
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
