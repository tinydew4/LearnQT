//---------------------------------------------------------------------------
#include <QApplication.h>
#include <QSlider.h>
#include <QVBox.h>
//---------------------------------------------------------------------------
#include "Box3D.h"
//---------------------------------------------------------------------------
void create_slider( QWidget *parent, QBox3D *box3d, const char *slot )
{
	QSlider *slider = new QSlider( 0, 360, 60, 0, QSlider::Horizontal, parent );
	slider->setTickmarks( QSlider::Below );
	QObject::connect( slider, SIGNAL( valueChanged( int ) ), box3d, slot );
}
//---------------------------------------------------------------------------
int main( int argc, char **argv )
{
	QApplication::setColorSpec( QApplication::CustomColor );

	QApplication App( argc, argv );

	if ( ! QGLFormat::hasOpenGL() )
	{
		qFatal( "This system has no OpenGL support" );
	}

	QVBox *parent = new QVBox;
	parent->setCaption( "OpenGL Box" );
	parent->setMargin( 11 );
	parent->setSpacing( 6 );

	QBox3D *box3d = new QBox3D( parent );
	create_slider( parent, box3d, SLOT( setRotationX( int ) ) );
	create_slider( parent, box3d, SLOT( setRotationY( int ) ) );
	create_slider( parent, box3d, SLOT( setRotationZ( int ) ) );

	App.setMainWidget( parent );
	parent->resize( 250, 250 );
	parent->show();

	return App.exec();
}
//---------------------------------------------------------------------------
