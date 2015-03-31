#include "hexvisu.h"
#include <iostream>
#include <QPainter>

using namespace std;
HexVisu::HexVisu(QWidget *parent) :
    QWidget(parent)
{
    this->content = NULL;
    this->index = 0;
}

void HexVisu::setContent(char *content,int size)
{
    this->content = content;
    this->index = 0;
    this->size = size;
}

void HexVisu::paintEvent(QPaintEvent *)
{
    if(this->content)
    {
        QPainter painter(this);
        QPen framepen(Qt::white);
        QPen asciipen(Qt::red);
        framepen.setWidth(1);

        QFont font=painter.font() ;
        //font.setPointSize ( 8 );
        font.setPixelSize(10);
        font.setWeight(QFont::DemiBold);

        painter.setFont(font);
        painter.setPen(framepen);
        painter.setBrush(Qt::white);

        QString hexValue;
        QString charValue;
        int baseIndex = this->index;
        int characterInt;

        baseIndex -= 64;

        if(baseIndex < 0)
            baseIndex = 0;
        else
            baseIndex -= baseIndex%16;

        for(int j = 0; j<16; ++j)
        {
            for(int i = 0;i<16;++i)
            {
                if(i < this->size)
                {
                    cout << baseIndex+j*16+i << endl;
                    characterInt = (int)(unsigned char)this->content[baseIndex+j*16+i];

                    hexValue = QString::number( characterInt ,16).toUpper();
                    if(characterInt > 32 && characterInt < 125)
                    {
                        charValue = this->content[baseIndex+j*16+i];
                        painter.setPen(asciipen);
                    }
                    else
                        charValue = ".";

                    if (hexValue.size() == 1)
                        hexValue = "0"+hexValue;

                    painter.drawText(20*i, j*30+30, hexValue);
                    painter.drawText(20*i+350, j*30+30, charValue);
                    painter.setPen(framepen);
                }
            }
        }
    }
}
void HexVisu::setIndex(int index)
{
    this->index = index;
    this->update();
}
