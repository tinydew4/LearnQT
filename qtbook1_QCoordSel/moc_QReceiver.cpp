/****************************************************************************
** QReceiver meta object code from reading C++ file 'QReceiver.h'
**
** Created: Sat Apr 19 12:15:21 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_QReceiver
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "QReceiver.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *QReceiver::className() const
{
    return "QReceiver";
}

QMetaObject *QReceiver::metaObj = 0;

void QReceiver::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("QReceiver","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString QReceiver::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("QReceiver",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* QReceiver::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(QReceiver::*m1_t0)(int,int);
    m1_t0 v1_0 = Q_AMPERSAND QReceiver::received;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "received(int,int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"QReceiver", "QObject",
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
