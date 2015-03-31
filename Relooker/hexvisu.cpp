#include "hexvisu.h"
#include <iostream>
#include <QPainter>

using namespace std;
HexVisu::HexVisu(QWidget *parent) :
    QWidget(parent)
{
    this->content = NULL;
    this->index = 0;
    this->isHighlight = false;
}

void HexVisu::setContent(char *content,int size)
{
    this->content = content;
    this->index = 0; // The index is set to 0 to display the beginning of the new file
    this->size = size;
}

void HexVisu::highlight(bool checked)
{
    this->isHighlight = checked; // Highlight string if checkbox is checked
}

void HexVisu::paintEvent(QPaintEvent *)
{
    if(this->content)
    {
        QPainter painter(this);
        QPen framepen(Qt::white); // Regular pen is white
        QPen asciipen(Qt::red); // ASCII pen is red to highlight
        framepen.setWidth(1);

        QFont font=painter.font() ;
        //font.setPointSize ( 8 );
        font.setPixelSize(10); // Using pixel size instead of point for an easy platform crossing
        font.setWeight(QFont::DemiBold);

        painter.setFont(font);
        painter.setPen(framepen);
        //painter.setBrush(Qt::white);

        QString hexValue;
        QString charValue;
        QString hexAddress;

        int num = QString::number(this->size,16).size(); // Number of characters of the last address
        int diff = 0;

        int baseIndex = this->index;
        int characterInt;

        baseIndex -= 64; // The base index is reduced to add context

        if(baseIndex < 0) // Can't go passed 0
            baseIndex = 0;
        else
            baseIndex -= baseIndex%16; // Keeping the same formatting as the 2D representation

        for(int j = 0; j<16; ++j)
        {
            for(int i = 0;i<16;++i)
            {
                if(i+j*16 < this->size)
                {
                    //cout << baseIndex+j*16+i << endl;
                    characterInt = (int)(unsigned char)this->content[baseIndex+j*16+i]; // The read character as a number

                    hexValue = QString::number( characterInt ,16).toUpper(); // Converted to hex
                    if(characterInt == 9 || characterInt == 10 || characterInt == 13 ||(characterInt >= 32 && characterInt <= 127)) // If ASCII
                    {
                        charValue = this->content[baseIndex+j*16+i]; // Display Character instead of "."
                        if(this->isHighlight)
                            painter.setPen(asciipen);
                    }
                    else
                        charValue = ".";

                    if (hexValue.size() == 1)
                        hexValue = "0"+hexValue;

                    painter.drawText(20*i+70, j*30+30, hexValue);
                    painter.drawText(10*i+400, j*30+30, charValue);
                    painter.setPen(framepen);
                }
            }
            hexAddress = QString::number(baseIndex+16*j,16);

            diff = num-hexAddress.size();
            for(int i = 0;i<diff;++i)       // Fill address with 0
                hexAddress = "0"+hexAddress;
            hexAddress = "0x"+hexAddress;
            painter.drawText(1,j*30+30,hexAddress.toUpper());
        }
    }
}
void HexVisu::setIndex(int index)
{
    this->index = index;
    this->update();
}
