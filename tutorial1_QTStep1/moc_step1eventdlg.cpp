/****************************************************************************
** QStep1EventDlg meta object code from reading C++ file 'step1eventdlg.h'
**
** Created: Sun Mar 2 16:19:29 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_QStep1EventDlg
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "step1eventdlg.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *QStep1EventDlg::className() const
{
    return "QStep1EventDlg";
}

QMetaObject *QStep1EventDlg::metaObj = 0;

void QStep1EventDlg::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QDialog::className(), "QDialog") != 0 )
	badSuperclassWarning("QStep1EventDlg","QDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString QStep1EventDlg::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("QStep1EventDlg",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* QStep1EventDlg::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"QStep1EventDlg", "QDialog",
	0, 0,
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
