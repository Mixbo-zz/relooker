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
    int * getEntropy(); // get array of entropy -> color
    int getSize();
private:
    char * content;
    int size;
};

#endif
