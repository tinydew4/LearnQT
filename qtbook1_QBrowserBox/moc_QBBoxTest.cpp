/****************************************************************************
** QBBoxTest meta object code from reading C++ file 'QBBoxTest.h'
**
** Created: Sat Apr 19 23:25:39 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_QBBoxTest
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "QBBoxTest.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *QBBoxTest::className() const
{
    return "QBBoxTest";
}

QMetaObject *QBBoxTest::metaObj = 0;

void QBBoxTest::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("QBBoxTest","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString QBBoxTest::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("QBBoxTest",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* QBBoxTest::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(QBBoxTest::*m1_t0)();
    m1_t0 v1_0 = Q_AMPERSAND QBBoxTest::buttonClicked;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "buttonClicked()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"QBBoxTest", "QWidget",
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
