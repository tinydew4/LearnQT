/****************************************************************************
** QBox3D meta object code from reading C++ file 'box3d.h'
**
** Created: Mon Mar 17 23:38:27 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_QBox3D
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "box3d.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *QBox3D::className() const
{
    return "QBox3D";
}

QMetaObject *QBox3D::metaObj = 0;

void QBox3D::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QGLWidget::className(), "QGLWidget") != 0 )
	badSuperclassWarning("QBox3D","QGLWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString QBox3D::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("QBox3D",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* QBox3D::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QGLWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(QBox3D::*m1_t0)(int);
    typedef void(QBox3D::*m1_t1)(int);
    typedef void(QBox3D::*m1_t2)(int);
    m1_t0 v1_0 = Q_AMPERSAND QBox3D::setRotationX;
    m1_t1 v1_1 = Q_AMPERSAND QBox3D::setRotationY;
    m1_t2 v1_2 = Q_AMPERSAND QBox3D::setRotationZ;
    QMetaData *slot_tbl = QMetaObject::new_metadata(3);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(3);
    slot_tbl[0].name = "setRotationX(int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "setRotationY(int)";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "setRotationZ(int)";
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl_access[2] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"QBox3D", "QGLWidget",
	slot_tbl, 3,
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
