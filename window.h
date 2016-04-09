#ifndef WINDOW_H
#define WINDOW_H


#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_text_label.h>

#include <QBoxLayout>

#include "adcreader.h"
 
// class definition 'Window'
class Window : public QWidget
{
	// must include the Q_OBJECT macro for for the Qt signals/slots framework to work with this class
	Q_OBJECT

public:
	Window(); // default constructor - called when a Window is declared without arguments

	~Window();

	void timerEvent( QTimerEvent * );

public slots:
	void setFunc(double func);

// internal variables for the window class
private:

	QwtPlot      *plot;
	QwtPlotCurve *curve;
	// layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
	QHBoxLayout  *hLayout;  // horizontal layout

	static const int plotDataSize = 1000;
	// data arrays for the plot
	double xData[plotDataSize];
	double yData[plotDataSize];
	ADCreader *adcreader;
};

#endif // WINDOW_H
