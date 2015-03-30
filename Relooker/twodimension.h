#ifndef TWODIMENSION_H
#define TWODIMENSION_H
#include <iostream>

class TwoDimension
{
public:
    TwoDimension(char*,int);
    int * getRange();
    int getSize();
private:
    int * range;
    char * content;
    int size;
};

#endif
