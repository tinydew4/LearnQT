//---------------------------------------------------------------------------
#include "Box3D.h"
#include <QGL.h>
//---------------------------------------------------------------------------
QBox3D::QBox3D( QWidget *parent, const char *name )
	: QGLWidget( parent, name )
{
	object = 0;
	rotX = rotY = rotZ = 0.0;
}
//---------------------------------------------------------------------------
QBox3D::~QBox3D( void )
{
	makeCurrent();
	glDeleteLists( object, 1 );
}
//---------------------------------------------------------------------------
void QBox3D::initializeGL( void )
{
	qglClearColor( darkBlue );
	object = makeObject();
	glShadeModel( GL_FLAT );
}
//---------------------------------------------------------------------------
void QBox3D::paintGL( void )
{
	glClear( GL_COLOR_BUFFER_BIT );
	glLoadIdentity();
	glTranslatef( 0.0, 0.0, -10.0 );
	glRotatef( rotX, 1.0, 0.0, 0.0 );
	glRotatef( rotY, 0.0, 1.0, 0.0 );
	glRotatef( rotZ, 0.0, 0.0, 1.0 );
	glCallList( object );
}
//---------------------------------------------------------------------------
void QBox3D::resizeGL( int w, int h )
{
	glViewport( 0, 0, w, h );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glFrustum( -1.0, 1.0, -1.0, 1.0, 5.0, 15.0 );
	glMatrixMode( GL_MODELVIEW );
}
//---------------------------------------------------------------------------
GLuint QBox3D::makeObject( void )
{
	GLuint list = glGenLists( 1 );
	glNewList( list, GL_COMPILE );
	qglColor( yellow );
	glLineWidth( 2.0 );

	glBegin( GL_LINE_LOOP );
	glVertex3f( ( float )1.5, ( float )1.0, ( float )0.8 );
	glVertex3f( ( float )1.5, ( float )1.0, ( float )-0.8 );
	glEnd();

	glEndList();
	return list;
}
//---------------------------------------------------------------------------
