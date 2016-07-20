//---------------------------------------------------------------------------
#ifndef QHTTPMirrorServerH
#define QHTTPMirrorServerH
//---------------------------------------------------------------------------
#include <QObject.h>
#include <QIntDict.h>
#include <QSocketNotifier.h>
//---------------------------------------------------------------------------
#include "QMirrorSocket.h"
//---------------------------------------------------------------------------
class QHTTPMirrorServer : QObject
{
	Q_OBJECT

private:
	QMirrorServerSocket *_serversocket;
	QSocketNotifier *_notifier;
	QIntDict<QMirrorSocket> _socketlist;
	QIntDict<QSocketNotifier> _notifierlist;

private slots:
	void connectionWanted( int );
	void dataArrived( int );

public:
	QHTTPMirrorServer( void );
	~QHTTPMirrorServer( void );
};
//---------------------------------------------------------------------------
#endif