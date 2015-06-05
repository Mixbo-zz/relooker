#include "piechartwidget.h"

#include <QPainter>

pieChartWidget::pieChartWidget(QWidget *parent) :
    QWidget(parent)
{
	this->rangeOccurence = NULL;
}

void pieChartWidget::paintEvent(QPaintEvent *)
{
	if(this->rangeOccurence)
	{

		int a = this->rangeOccurence[0]*360/100*16;
		int b = this->rangeOccurence[3]*360/100*16;
		int c = this->rangeOccurence[2]*360/100*16;
		int d = this->rangeOccurence[4]*360/100*16;
		int e = this->rangeOccurence[1]*360/100*16;

	    QPainter painter(this);
	    painter.setRenderHint(QPainter::Antialiasing);
	    QRectF size = QRectF(10,10,this->width()-10,this->width()-10);

	    painter.setBrush(Qt::black);
	    painter.drawPie(size,0,a);

	    painter.setBrush(Qt::green);
	    painter.drawPie(size,a,b);

		painter.setBrush(Qt::blue);
	    painter.drawPie(size,a+b,c);

		painter.setBrush(Qt::magenta);
	    painter.drawPie(size,a+b+c,d);

	   	painter.setBrush(Qt::white);
	    painter.drawPie(size,a+b+c+d,e);
	}
}

void pieChartWidget::setOccurence(float * occurence)
{
	this->rangeOccurence = occurence;
}
