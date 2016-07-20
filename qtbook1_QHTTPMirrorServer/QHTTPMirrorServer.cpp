//---------------------------------------------------------------------------
#include "QHTTPMirrorServer.h"
//---------------------------------------------------------------------------
#define PORT 8080
//---------------------------------------------------------------------------
#include <QString.h>
#include <QMessageBox.h>
//---------------------------------------------------------------------------
QHTTPMirrorServer::QHTTPMirrorServer( void )
{
	_serversocket = new QMirrorServerSocket( PORT );

	_notifier = new QSocketNotifier( _serversocket->handle(), QSocketNotifier::Read );

	QObject::connect( _notifier, SIGNAL( activated( int ) ), this, SLOT( connectionWanted( int ) ) );
}
//---------------------------------------------------------------------------
QHTTPMirrorServer::~QHTTPMirrorServer( void )
{
	if ( _notifier )
	{
		delete _notifier;
	}
	if ( _serversocket )
	{
		delete _serversocket;
	}
}
//---------------------------------------------------------------------------
void QHTTPMirrorServer::connectionWanted( int )
{
	QMirrorSocket *socket = _serversocket->accept();
	int handle = socket->handle();

	_socketlist.insert( handle, socket );

	QSocketNotifier *dataNotifier = new QSocketNotifier( handle, QSocketNotifier::Read );
	QObject::connect( dataNotifier, SIGNAL( activated( int ) ), this, SLOT( dataArrived( int ) ) );

	_notifierlist.insert( handle, dataNotifier );
}
//---------------------------------------------------------------------------
void QHTTPMirrorServer::dataArrived( int handle )
{
	QMirrorSocket *socket = _socketlist.take( handle );

	if ( socket )
	{
		QString line;
		socket->read( line );

		while ( ! line.isEmpty() )
		{
			line += '\n';
			socket->write( line );
			socket->read( line );
		}

		delete socket;
		delete _notifierlist.take( handle );
	}
}
//---------------------------------------------------------------------------
