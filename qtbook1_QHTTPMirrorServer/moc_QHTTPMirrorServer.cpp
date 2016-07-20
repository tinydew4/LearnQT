/****************************************************************************
** QHTTPMirrorServer meta object code from reading C++ file 'QHTTPMirrorServer.h'
**
** Created: Thu Apr 24 16:15:39 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_QHTTPMirrorServer
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "QHTTPMirrorServer.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *QHTTPMirrorServer::className() const
{
    return "QHTTPMirrorServer";
}

QMetaObject *QHTTPMirrorServer::metaObj = 0;

void QHTTPMirrorServer::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("QHTTPMirrorServer","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString QHTTPMirrorServer::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("QHTTPMirrorServer",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* QHTTPMirrorServer::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(QHTTPMirrorServer::*m1_t0)(int);
    typedef void(QHTTPMirrorServer::*m1_t1)(int);
    m1_t0 v1_0 = Q_AMPERSAND QHTTPMirrorServer::connectionWanted;
    m1_t1 v1_1 = Q_AMPERSAND QHTTPMirrorServer::dataArrived;
    QMetaData *slot_tbl = QMetaObject::new_metadata(2);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(2);
    slot_tbl[0].name = "connectionWanted(int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Private;
    slot_tbl[1].name = "dataArrived(int)";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"QHTTPMirrorServer", "QObject",
	slot_tbl, 2,
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
