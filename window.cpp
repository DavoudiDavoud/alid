#include "window.h"
#include "adcreader.h"

Window::Window()
{

	// set up the initial plot data
	for( int index=0; index<plotDataSize; ++index )
	{
		xData[index] = index;
		yData[index] = 0;
	}

	curve = new QwtPlotCurve;
	plot = new QwtPlot;
	// make a plot curve from the data and attach it to the plot
	curve->setSamples(xData, yData, plotDataSize);
	curve->attach(plot);

	plot->replot();
	plot->show();



	// plot to the left of knob and thermometer
	hLayout = new QHBoxLayout;
	hLayout->addWidget(plot);

	setLayout(hLayout);


	adcreader = new ADCreader();
	adcreader->start();
}

Window::~Window() {
	// tells the thread to no longer run its endless loop
	adcreader->quit();
	// wait until the run method has terminated
	adcreader->wait();
//	delete adcreader;
}

void Window::timerEvent( QTimerEvent * )
{
	int inval;
	double value;
	while(adcreader->read_enable()){
				
		inval=adcreader->get_samples();
		value=(double) inval;
		fprintf(stderr,"int = %d  double = %f     \r",inval,value);

		
		// add the new input to the plot
		memmove( yData, yData+1, (plotDataSize-1) * sizeof(double) );
		yData[plotDataSize-1] = value;
		curve->setSamples(xData, yData, plotDataSize);
		plot->replot();
	}

}



