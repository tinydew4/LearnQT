/****************************************************************************
** QCannonField meta object code from reading C++ file 'Cannon.h'
**
** Created: Thu Mar 13 14:33:48 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_QCannonField
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "Cannon.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *QCannonField::className() const
{
    return "QCannonField";
}

QMetaObject *QCannonField::metaObj = 0;

void QCannonField::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("QCannonField","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString QCannonField::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("QCannonField",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* QCannonField::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(QCannonField::*m1_t0)();
    typedef void(QCannonField::*m1_t1)(int);
    typedef void(QCannonField::*m1_t2)(int);
    typedef void(QCannonField::*m1_t3)();
    typedef void(QCannonField::*m1_t4)();
    typedef void(QCannonField::*m1_t5)();
    typedef void(QCannonField::*m1_t6)(QShot*,QRegion);
    typedef void(QCannonField::*m1_t7)();
    typedef void(QCannonField::*m1_t8)();
    m1_t0 v1_0 = Q_AMPERSAND QCannonField::moveTarget;
    m1_t1 v1_1 = Q_AMPERSAND QCannonField::setAngle;
    m1_t2 v1_2 = Q_AMPERSAND QCannonField::setForce;
    m1_t3 v1_3 = Q_AMPERSAND QCannonField::shoot;
    m1_t4 v1_4 = Q_AMPERSAND QCannonField::newTarget;
    m1_t5 v1_5 = Q_AMPERSAND QCannonField::showTrajectory;
    m1_t6 v1_6 = Q_AMPERSAND QCannonField::checkCrush;
    m1_t7 v1_7 = Q_AMPERSAND QCannonField::setGameOver;
    m1_t8 v1_8 = Q_AMPERSAND QCannonField::restartGame;
    QMetaData *slot_tbl = QMetaObject::new_metadata(9);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(9);
    slot_tbl[0].name = "moveTarget()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Private;
    slot_tbl[1].name = "setAngle(int)";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "setForce(int)";
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl_access[2] = QMetaData::Public;
    slot_tbl[3].name = "shoot()";
    slot_tbl[3].ptr = *((QMember*)&v1_3);
    slot_tbl_access[3] = QMetaData::Public;
    slot_tbl[4].name = "newTarget()";
    slot_tbl[4].ptr = *((QMember*)&v1_4);
    slot_tbl_access[4] = QMetaData::Public;
    slot_tbl[5].name = "showTrajectory()";
    slot_tbl[5].ptr = *((QMember*)&v1_5);
    slot_tbl_access[5] = QMetaData::Public;
    slot_tbl[6].name = "checkCrush(QShot*,QRegion)";
    slot_tbl[6].ptr = *((QMember*)&v1_6);
    slot_tbl_access[6] = QMetaData::Public;
    slot_tbl[7].name = "setGameOver()";
    slot_tbl[7].ptr = *((QMember*)&v1_7);
    slot_tbl_access[7] = QMetaData::Public;
    slot_tbl[8].name = "restartGame()";
    slot_tbl[8].ptr = *((QMember*)&v1_8);
    slot_tbl_access[8] = QMetaData::Public;
    typedef void(QCannonField::*m2_t0)(int);
    typedef void(QCannonField::*m2_t1)(int);
    typedef void(QCannonField::*m2_t2)();
    typedef void(QCannonField::*m2_t3)();
    typedef void(QCannonField::*m2_t4)(bool);
    m2_t0 v2_0 = Q_AMPERSAND QCannonField::angleChanged;
    m2_t1 v2_1 = Q_AMPERSAND QCannonField::forceChanged;
    m2_t2 v2_2 = Q_AMPERSAND QCannonField::hit;
    m2_t3 v2_3 = Q_AMPERSAND QCannonField::missed;
    m2_t4 v2_4 = Q_AMPERSAND QCannonField::canShoot;
    QMetaData *signal_tbl = QMetaObject::new_metadata(5);
    signal_tbl[0].name = "angleChanged(int)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    signal_tbl[1].name = "forceChanged(int)";
    signal_tbl[1].ptr = *((QMember*)&v2_1);
    signal_tbl[2].name = "hit()";
    signal_tbl[2].ptr = *((QMember*)&v2_2);
    signal_tbl[3].name = "missed()";
    signal_tbl[3].ptr = *((QMember*)&v2_3);
    signal_tbl[4].name = "canShoot(bool)";
    signal_tbl[4].ptr = *((QMember*)&v2_4);
    metaObj = QMetaObject::new_metaobject(
	"QCannonField", "QWidget",
	slot_tbl, 9,
	signal_tbl, 5,
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

// SIGNAL angleChanged
void QCannonField::angleChanged( int t0 )
{
    activate_signal( "angleChanged(int)", t0 );
}

// SIGNAL forceChanged
void QCannonField::forceChanged( int t0 )
{
    activate_signal( "forceChanged(int)", t0 );
}

// SIGNAL hit
void QCannonField::hit()
{
    activate_signal( "hit()" );
}

// SIGNAL missed
void QCannonField::missed()
{
    activate_signal( "missed()" );
}

// SIGNAL canShoot
void QCannonField::canShoot( bool t0 )
{
    activate_signal_bool( "canShoot(bool)", t0 );
}
