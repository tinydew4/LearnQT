/****************************************************************************
** QTExamDlg1 meta object code from reading C++ file 'qtexamdlg1impl.h'
**
** Created: Fri Feb 28 19:06:14 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_QTExamDlg1
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "qtexamdlg1impl.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *QTExamDlg1::className() const
{
    return "QTExamDlg1";
}

QMetaObject *QTExamDlg1::metaObj = 0;

void QTExamDlg1::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QTExamDlg1Base::className(), "QTExamDlg1Base") != 0 )
	badSuperclassWarning("QTExamDlg1","QTExamDlg1Base");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString QTExamDlg1::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("QTExamDlg1",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* QTExamDlg1::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QTExamDlg1Base::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"QTExamDlg1", "QTExamDlg1Base",
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
