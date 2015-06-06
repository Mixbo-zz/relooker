#include "visualizer.h"

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

    this->mousey = 0;

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
    this->mousey = y;
}

int Visualizer::getIndex()
{
    return this->index;
}

void Visualizer::set2(TwoDimension* tdim)
{
    this->tdim = tdim;
    this->index = 0;

    this->createPixmap();
    
}

void Visualizer::createPixmap()
{
    if(this->tdim)
    {
        QColor * items = this->tdim->getArray(this->mode);
        int size = this->tdim->getSize();


        int h = size/16*5;
        int w = 16*5;



        //this->im = QImage(w,h,QImage::Format_ARGB32_Premultiplied);
        this->im = QPixmap(w,h);
        //this->im.fill(Qt::red);

        if(items)
        {
            QPainter painter(&this->im);
            QPen framepen(Qt::black);
            framepen.setWidth(1);

        //     //painter.fillRect(this->map.rect(),Qt::yellow);
        //     if(this->mode == 1)
        //     {
        //         int i;
        //         for(i = 0;i< size;++i)
        //         {
        //            switch(items[i])
        //            {
        //                 case 0:
        //                         framepen.setColor(Qt::black);
        //                         painter.setBrush(Qt::black);
        //                         break;
        //                 case 1:
        //                         framepen.setColor(Qt::white);
        //                         painter.setBrush(Qt::white);
        //                         break;
        //                 case 2:
        //                         framepen.setColor(Qt::blue);
        //                         painter.setBrush(Qt::blue);
        //                         break;
        //                 case 3:
        //                         framepen.setColor(Qt::green);
        //                         painter.setBrush(Qt::green);
        //                         break;
        //                 case 4:
        //                         framepen.setColor(Qt::magenta);
        //                         painter.setBrush(Qt::magenta);
        //                         break;
        //            }
        //            // paint each square
        //            painter.setPen(framepen);
        //            painter.drawRect(QRectF(i%this->itemsCol * this->itemSize, i/this->itemsCol*this->itemSize,this->itemSize,this->itemSize));
        //         }
        //     }
        //     else if (this->mode == 2)
        //     {
        //         for(int i = 0;i< size;++i)
        //         {
        //             //cout << "Index de la couleur = " << items[i] << "\tIteration = "<< i <<"\n";
        //             framepen.setColor(QColor(items[i]));
        //             painter.setBrush(QColor(items[i]));

        //             painter.setPen(framepen);
        //             painter.drawRect(QRectF(i%this->itemsCol * this->itemSize, i/this->itemsCol*this->itemSize,this->itemSize,this->itemSize));
        //         }
        //     }
        //     // this->im.save("/Users/what/Pictures/qtoutput.png");

            for(int i=0;i<size;i++)
            {
                framepen.setColor(items[i]);
                painter.setBrush(items[i]);
                painter.setPen(framepen);
                painter.drawRect(QRectF(i%this->itemsCol * this->itemSize, i/this->itemsCol*this->itemSize,this->itemSize,this->itemSize));
            }
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
        QPen pen = QPen(Qt::red);
        pen.setWidth(2);
        painter.setPen(pen);
        //painter.setBrush(Qt::NoBrush);
        painter.setBrush(QColor(255,255,255,100));
        int y = this->mousey - this->mousey%5;
        y -= 21;
        if (y < 0)
        {
            y = 0;
        }
        painter.drawRect(0,y,80,80);
    }
}
