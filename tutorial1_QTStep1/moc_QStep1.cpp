/****************************************************************************
** QStep1 meta object code from reading C++ file 'QStep1.h'
**
** Created: Sun Mar 2 15:15:56 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_QStep1
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "QStep1.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *QStep1::className() const
{
    return "QStep1";
}

QMetaObject *QStep1::metaObj = 0;

void QStep1::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QVBox::className(), "QVBox") != 0 )
	badSuperclassWarning("QStep1","QVBox");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString QStep1::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("QStep1",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* QStep1::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QVBox::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(QStep1::*m1_t0)(int);
    m1_t0 v1_0 = Q_AMPERSAND QStep1::checkValue;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "checkValue(int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"QStep1", "QVBox",
	slot_tbl, 1,
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
