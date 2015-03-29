#ifndef TWODIMENSION_H
#define TWODIMENSION_H
#include <iostream>
#include <string>

class TwoDimension
{
public:
    TwoDimension(char*,int);
    int * getRange();
private:
    int * range;
};

#endif
