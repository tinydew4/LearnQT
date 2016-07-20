//---------------------------------------------------------------------------
#ifndef Box3DH
#define Box3DH
//---------------------------------------------------------------------------
#include <QGL.h>
//---------------------------------------------------------------------------
class QBox3D : public QGLWidget
{
	Q_OBJECT

private:
	GLuint object;
	GLfloat rotX, rotY, rotZ;

public:
	QBox3D( QWidget *parent = 0, const char *name = 0 );
	~QBox3D( void );

protected:
	virtual void initializeGL( void );
	virtual void paintGL( void );
	virtual void resizeGL( int w, int h );
	virtual GLuint makeObject( void );

public slots:
	void setRotationX( int deg )
	{
		rotX = deg;
		updateGL();
	}
	void setRotationY( int deg )
	{
		rotY = deg;
		updateGL();
	}
	void setRotationZ( int deg )
	{
		rotZ = deg;
		updateGL();
	}

};
//---------------------------------------------------------------------------
#endif
