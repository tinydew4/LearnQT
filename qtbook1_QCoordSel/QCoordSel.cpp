//---------------------------------------------------------------------------
#include "QCoordSel.h"
//---------------------------------------------------------------------------
#include <QPainter.h>
#include <QFontMetrics.h>
//---------------------------------------------------------------------------
QCoordSel::QCoordSel( QWidget *parent, const char *name, WFlags flags)
	: QWidget( parent, name, flags )
{
	_xrange.setRange( 0, 100 );
	_yrange.setRange( 0, 100 );

	_xrange.setValue( 0 );
	_yrange.setValue( 0 );

	_labelheight = labelHeight();

	setCursor( crossCursor );
}
//---------------------------------------------------------------------------
QCoordSel::~QCoordSel( void )
{
}
//---------------------------------------------------------------------------
int QCoordSel::xMinValue( void ) const
{
	return _xrange.minValue();
}
//---------------------------------------------------------------------------
int QCoordSel::xMaxValue( void ) const
{
	return _xrange.maxValue();
}
//---------------------------------------------------------------------------
int QCoordSel::yMinValue( void ) const
{
	return _yrange.minValue();
}
//---------------------------------------------------------------------------
int QCoordSel::yMaxValue( void ) const
{
	return _yrange.maxValue();
}
//---------------------------------------------------------------------------
QPoint QCoordSel::value( void ) const
{
	return QPoint( _xrange.value(), _yrange.value() );
}
//---------------------------------------------------------------------------
void QCoordSel::setXMinValue( int value )
{
	_xrange.setRange( value, _xrange.maxValue() );
}
//---------------------------------------------------------------------------
void QCoordSel::setXMaxValue( int value )
{
	_xrange.setRange( _xrange.minValue(), value );
}
//---------------------------------------------------------------------------
void QCoordSel::setYMinValue( int value )
{
	_yrange.setRange( value, _yrange.maxValue() );
}
//---------------------------------------------------------------------------
void QCoordSel::setYMaxValue( int value )
{
	_yrange.setRange( _yrange.minValue(), value );
}
//---------------------------------------------------------------------------
void QCoordSel::setValue( int x, int y )
{
	_xrange.setValue( x );
	_yrange.setValue( y );
}
//---------------------------------------------------------------------------
void QCoordSel::setValue( const QPoint &point )
{
	_xrange.setValue( point.x() );
	_yrange.setValue( point.y() );
}
//---------------------------------------------------------------------------
void QCoordSel::resizeEvent( QResizeEvent * )
{
	computeRatio();
}
//---------------------------------------------------------------------------
void QCoordSel::paintEvent( QPaintEvent *e )
{
	QPainter painter( this );
	painter.drawLine( 0, height() - _labelheight, width(), height() - _labelheight );
	QString coordstext;
	coordstext.sprintf( "%d x %d, %d, %d",  _tempvalue.x(), _tempvalue.y(), _xratio, _yratio );
	painter.drawText( 0,  height(), coordstext );
}
//---------------------------------------------------------------------------
void QCoordSel::mousePressEvent( QMouseEvent *e )
{
	_tempvalue = mouseToLogical( e->pos() );
	repaint();
}
//---------------------------------------------------------------------------
void QCoordSel::mouseReleaseEvent( QMouseEvent *e )
{
	if ( rect().contains( e->pos() ) )
	{
		QPoint coords = mouseToLogical( e->pos() );
		emit valueChanged( coords.x(), coords.y() );
		_xrange.setValue( coords.x() );
		_yrange.setValue( coords.y() );
		_tempvalue.setX( coords.x() );
		_tempvalue.setY( coords.y() );
		repaint();
	}
}
//---------------------------------------------------------------------------
void QCoordSel::mouseMoveEvent( QMouseEvent *e )
{
	QPoint oldtempvalue = _tempvalue;
	_tempvalue = mouseToLogical( e->pos() );

	if ( _tempvalue.x() < _xrange.minValue() )
	{
		_tempvalue.setX( _xrange.minValue() );
	}
	if ( _tempvalue.y() < _yrange.minValue() )
	{
		_tempvalue.setY( _yrange.minValue() );
	}
	if ( _tempvalue.x() > _xrange.maxValue() )
	{
		_tempvalue.setX( _xrange.maxValue() );
	}
	if ( _tempvalue.y() > _yrange.maxValue() )
	{
		_tempvalue.setY( _yrange.maxValue() );
	}

	repaint();
}
//---------------------------------------------------------------------------
void QCoordSel::setFont( const QFont &font )
{
	QWidget::setFont( font );
	_labelheight = labelHeight();
	repaint();
}
//---------------------------------------------------------------------------
QPoint QCoordSel::mouseToLogical( QPoint point )
{
	return QPoint( point.x() * _xratio + _xrange.minValue(),
				   point.y() * _yratio + _yrange.minValue() );
}
//---------------------------------------------------------------------------
int QCoordSel::labelHeight( void )
{
	QFontMetrics fm( font() );
	return fm.height();
}
//---------------------------------------------------------------------------
void QCoordSel::computeRatio( void )
{
	_xratio = ( double )( _xrange.maxValue() - _xrange.minValue() ) / ( double )width();
	_yratio = ( double )( _yrange.maxValue() - _yrange.minValue() ) / ( double )( height() - _labelheight );
}
//---------------------------------------------------------------------------
QSize QCoordSel::sizeHint( void ) const
{
	return QSize( _xrange.maxValue() - _xrange.minValue(), _yrange.maxValue() - _yrange.minValue() + _labelheight );
}
//---------------------------------------------------------------------------
