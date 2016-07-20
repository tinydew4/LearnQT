//---------------------------------------------------------------------------
#ifndef QMirrorSocketH
#define QMirrorSocketH
//---------------------------------------------------------------------------
class QString;
class QFile;
class QTextStream;
//---------------------------------------------------------------------------
class QMirrorSocket
{
private:
	int _fd;
	QFile *_file;
	QTextStream *_tstream;

	void closefile( void );

public:
	QMirrorSocket( void );
	virtual ~QMirrorSocket( void );

	void close( void );
	int handle( void )
	{
		return _fd;
	}
	void read( QString &text );
	void write( const char *text );

	void setFd( int fd );
};
//---------------------------------------------------------------------------
class QMirrorServerSocket : public QMirrorSocket
{
public:
	QMirrorServerSocket( int port );

	QMirrorSocket *accept( void );
};
//---------------------------------------------------------------------------
#endif
