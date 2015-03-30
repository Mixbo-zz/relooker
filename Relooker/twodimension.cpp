#include "twodimension.h"

#include <iostream>
#include <iomanip>

using namespace std;

TwoDimension::TwoDimension(char* content, int size)
{
    this->content = content;
    this->size = size;
}
int TwoDimension::getSize()
{
    return size;
}

int * TwoDimension::getRange()
{
    int value; 
    int * range = new int[this->size];
    int b;
    for(int i=0;i<this->size;++i)
    {
        value = 0;
        b = (int)this->content[i];
        //cout << b << ":";
        //cout << uppercase << setw(2) << setfill('0')<< hex << int(b) << endl;

        if(b != 0)
        {
            if(b == 255)
                value = 1;
            else if(b == 9 || b == 10 || b == 13 || (b >= 32 && b <= 127)) 
                value = 2;
            else if(b < 32)
                value = 3;
            else if(b > 127)
                value = 4;
        }
        range[i] = value;
    }
    return range;

}
