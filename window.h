#ifndef WINDOW_H
#define WINDOW_H


#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_text_label.h>

#include <QBoxLayout>

#include "adcreader.h"
 
class Window : public QWidget
{
	
	Q_OBJECT

public:
	Window(); 

	~Window();

	void timerEvent( QTimerEvent * );


private:

	QwtPlot      *plot;
	QwtPlotCurve *curve;
	QHBoxLayout  *hLayout;  

	static const int plotDataSize = 1000;

	double xData[plotDataSize];
	double yData[plotDataSize];
	ADCreader *adcreader;
};

#endif
