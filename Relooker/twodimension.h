#ifndef TWODIMENSION_H
#define TWODIMENSION_H
#include <iostream>

class TwoDimension
{
public:
    TwoDimension();
    void setContent(char *,int);
    int * getArray(int); // Get an array of color value
    int * getRange(); // Get byte range -> color
    float * getRangeOccurence();
    int * getEntropy(); // get array of entropy -> color
    int getSize();
private:
    char * content;
    float * rangeOccurence;
    int size;
};

#endif
