#ifndef TWODIMENSION_H
#define TWODIMENSION_H
#include <iostream>

class TwoDimension
{
public:
    TwoDimension();
    void setContent(char *,int);
    int * getArray(int);
    int * getRange();
    int * getEntropy();
    int getSize();
private:
    char * content;
    int size;
};

#endif
