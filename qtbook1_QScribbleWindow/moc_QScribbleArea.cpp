/****************************************************************************
** QScribbleArea meta object code from reading C++ file 'QScribbleArea.h'
**
** Created: Wed Mar 26 10:28:53 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_QScribbleArea
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "QScribbleArea.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *QScribbleArea::className() const
{
    return "QScribbleArea";
}

QMetaObject *QScribbleArea::metaObj = 0;

void QScribbleArea::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("QScribbleArea","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString QScribbleArea::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("QScribbleArea",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* QScribbleArea::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(QScribbleArea::*m1_t0)(QColor);
    typedef void(QScribbleArea::*m1_t1)(int);
    typedef void(QScribbleArea::*m1_t2)();
    typedef void(QScribbleArea::*m1_t3)(const char*);
    typedef void(QScribbleArea::*m1_t4)(const char*);
    m1_t0 v1_0 = Q_AMPERSAND QScribbleArea::setColor;
    m1_t1 v1_1 = Q_AMPERSAND QScribbleArea::setWidth;
    m1_t2 v1_2 = Q_AMPERSAND QScribbleArea::clearArea;
    m1_t3 v1_3 = Q_AMPERSAND QScribbleArea::load;
    m1_t4 v1_4 = Q_AMPERSAND QScribbleArea::save;
    QMetaData *slot_tbl = QMetaObject::new_metadata(5);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(5);
    slot_tbl[0].name = "setColor(QColor)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "setWidth(int)";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "clearArea()";
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl_access[2] = QMetaData::Public;
    slot_tbl[3].name = "load(const char*)";
    slot_tbl[3].ptr = *((QMember*)&v1_3);
    slot_tbl_access[3] = QMetaData::Public;
    slot_tbl[4].name = "save(const char*)";
    slot_tbl[4].ptr = *((QMember*)&v1_4);
    slot_tbl_access[4] = QMetaData::Public;
    typedef void(QScribbleArea::*m2_t0)(const char*);
    m2_t0 v2_0 = Q_AMPERSAND QScribbleArea::fileChanged;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "fileChanged(const char*)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"QScribbleArea", "QWidget",
	slot_tbl, 5,
	signal_tbl, 1,
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

// SIGNAL fileChanged
void QScribbleArea::fileChanged( const char* t0 )
{
    activate_signal( "fileChanged(const char*)", t0 );
}
