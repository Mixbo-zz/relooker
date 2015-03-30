#include "hexvisu.h"
#include <QPainter>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
HexVisu::HexVisu(QWidget *parent) :
    QWidget(parent)
{
    this->content = NULL;
}

void HexVisu::setContent(char *content,int size)
{
    this->content = content;
    this->size = size;
}

void HexVisu::paintEvent(QPaintEvent *)
{
    if(this->content)
    {
        QPainter painter(this);
        QPen framepen(Qt::red);
        framepen.setWidth(1);

        QFont font=painter.font() ;
        font.setPointSize ( 12 );
        font.setWeight(QFont::DemiBold);
        painter.setFont(font);
        painter.setPen(framepen);
        painter.setBrush(Qt::red);

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
                    characterInt = (int)(unsigned char)this->content[baseIndex+j*16+i];

                    hexValue = QString::number( characterInt ,16).toUpper();
                    if(characterInt > 32 && characterInt < 125)
                        charValue = this->content[baseIndex+j*16+i];
                    else
                        charValue = ".";

                    if (hexValue.size() == 1)
                        hexValue = "0"+hexValue;

                    painter.drawText(20*i, j*30+30, hexValue);
                    painter.drawText(20*i+350, j*30+30, charValue);
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
