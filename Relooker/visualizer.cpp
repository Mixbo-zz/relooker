#include "visualizer.h"
#include <qDebug>

using namespace std;
Visualizer::Visualizer(QWidget *parent) :
    QWidget(parent)
{
    setMouseTracking(true);

    this->mode = -1; // Set mode to unset
    this->tdim = NULL;
    this->index = 0;
    this->itemsCol = 16;
    this->itemSize = 5;

}

int Visualizer::getHeight() // Height of the 2d representation used to resize widget
{
    int height = 0;

    if(this->mode != -1)
    {
        if(this->tdim)
        {
            int size = this->tdim->getSize();       
            height = size/this->itemsCol*this->itemSize+50;
        }
    }
    return height;
}

void Visualizer::setMode(int mode)
{
    this->mode = mode;
    this->update();
}

void Visualizer::paintEvent(QPaintEvent *)
{
    if(this->tdim)
    {
        this->paintTwoD();
    }
    else
        this->paintDefault(); // At the opening. Show default screen
}
void Visualizer::mouseMoveEvent(QMouseEvent* event)
{
    int x = event->x();
    int y = event->y();
    //cout << x << ":" << y << endl;
    int index = x/5 + y/5*16;
    //cout << index<<endl;
    this->index = index;
}

int Visualizer::getIndex()
{
    return this->index;
}

void Visualizer::set2(TwoDimension* tdim)
{
    this->tdim = tdim;
    this->index = 0;

    if(this->tdim)
    {
        int * items = this->tdim->getArray(this->mode);
        int size = this->tdim->getSize();

        qDebug()<< "Content dans func"<<items;

        int h = size/16*5;
        int w = 16*5;


        //qDebug()<< h;

        //this->im = QImage(w,h,QImage::Format_ARGB32_Premultiplied);
        this->im = QPixmap(w,h);
        //this->im.fill(Qt::red);

        qDebug()<<items;
        if(items)
        {
            QPainter painter(&this->im);
            QPen framepen(Qt::black);
            framepen.setWidth(1);

            //painter.fillRect(this->map.rect(),Qt::yellow);

            qDebug()<< "La size: " << size;
            int i;
            for(i = 0;i< size;++i)
            {
               switch(items[i])
               {
                    case 0:
                            framepen.setColor(Qt::black);
                            painter.setBrush(Qt::black);
                            break;
                    case 1:
                            framepen.setColor(Qt::white);
                            painter.setBrush(Qt::white);
                            break;
                    case 2:
                            framepen.setColor(Qt::blue);
                            painter.setBrush(Qt::blue);
                            break;
                    case 3:
                            framepen.setColor(Qt::green);
                            painter.setBrush(Qt::green);
                            break;
                    case 4:
                            framepen.setColor(Qt::magenta);
                            painter.setBrush(Qt::magenta);
                            break;
               }
               // paint each square
               painter.setPen(framepen);
               painter.drawRect(QRectF(i%this->itemsCol * this->itemSize, i/this->itemsCol*this->itemSize,this->itemSize,this->itemSize));
            }
            qDebug() << i;
            // this->im.save("/Users/what/Pictures/qtoutput.png");
        }
    }    
}

void Visualizer::paintDefault() // Default screen
{

}

void Visualizer::paintTwoD() // Paint the 2 dimentional representation
{
    if(this->tdim)
    {
        QPainter painter(this);
        painter.drawPixmap( QPoint(0,0), this->im );
    }
}
