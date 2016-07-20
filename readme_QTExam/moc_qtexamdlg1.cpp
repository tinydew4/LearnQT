/****************************************************************************
** QTExamDlg1Base meta object code from reading C++ file 'qtexamdlg1.h'
**
** Created: Fri Feb 28 19:20:27 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_QTExamDlg1Base
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "qtexamdlg1.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *QTExamDlg1Base::className() const
{
    return "QTExamDlg1Base";
}

QMetaObject *QTExamDlg1Base::metaObj = 0;

void QTExamDlg1Base::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QDialog::className(), "QDialog") != 0 )
	badSuperclassWarning("QTExamDlg1Base","QDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString QTExamDlg1Base::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("QTExamDlg1Base",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* QTExamDlg1Base::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"QTExamDlg1Base", "QDialog",
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
