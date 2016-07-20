//---------------------------------------------------------------------------
#include "QMirrorSocket.h"
//---------------------------------------------------------------------------
#include <QFile.h>
#include <QTextStream.h>

#ifdef _WS_X11_
	#include <netinet/in.h>
	#include <sys/socket.h>
	#include <sys/types.h>
	#include <unistd.h>
	#pragma	message( "_WS_X11_ defined." )
#else ifdef _WS_WIN_
	#include <winsock2.h>
	#include <io.h>
	#pragma	message( "_WS_WIN_ defined." )
#endif
//---------------------------------------------------------------------------

//- QMirrorSocket -----------------------------------------------------------------
QMirrorSocket::QMirrorSocket( void )
	: _file( NULL ), _tstream( NULL ), _fd( -1 )
{
    WSADATA wsaData;
	WSAStartup( MAKEWORD( 2, 2 ), ( LPWSADATA )( &wsaData ) );
}
//---------------------------------------------------------------------------
QMirrorSocket::~QMirrorSocket( void )
{
	close();
	closefile();
    WSACleanup();
}
//---------------------------------------------------------------------------
void QMirrorSocket::close( void )
{
	::close( _fd );
	_file->close();
}
//---------------------------------------------------------------------------
void QMirrorSocket::closefile( void )
{
	if ( _file )
	{
		delete _file;
		_file = NULL;
	}
	if ( _tstream )
	{
		delete _tstream;
		_tstream = NULL;
	}
}
//---------------------------------------------------------------------------
void QMirrorSocket::setFd( int newfd )
{
	_fd = newfd;

	closefile();

	_file = new QFile();
	_file->open( IO_ReadWrite, newfd );

	_tstream = new QTextStream( _file );
}
//---------------------------------------------------------------------------
void QMirrorSocket::read( QString &text )
{
	text = "";

	if ( _tstream )
	{
		text = _tstream->readLine();
	}
}
//---------------------------------------------------------------------------
void QMirrorSocket::write( const char *text )
{
	if ( _tstream )
	{
		( *_tstream ) << text;
	}
}
//---------------------------------------------------------------------------

//- QServerSocket -----------------------------------------------------------
QMirrorServerSocket::QMirrorServerSocket( int port )
	: QMirrorSocket()
{
	int newfd = socket( AF_INET, SOCK_STREAM, 0 );

	struct sockaddr_in serverAddress;
	memset( &serverAddress, 0, sizeof( serverAddress ) );
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl( INADDR_ANY );
	serverAddress.sin_port = htons( port );

	bind( newfd, ( sockaddr * )( &serverAddress ), sizeof( serverAddress ) );

	listen( newfd, 5 );

	setFd( newfd );
}
//---------------------------------------------------------------------------
QMirrorSocket* QMirrorServerSocket::accept( void )
{
	struct sockaddr client_addr;

	int len = sizeof( SOCKADDR );
	int newfd = ::accept( handle(), &client_addr, &len );
	QMirrorSocket *newSocket = new QMirrorSocket();
	newSocket->setFd( newfd );

	return newSocket;
}
//---------------------------------------------------------------------------
