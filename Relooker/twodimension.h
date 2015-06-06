#ifndef TWODIMENSION_H
#define TWODIMENSION_H
#include <QColor>
#include <iostream>

class TwoDimension
{
public:
    TwoDimension();
    void setContent(char *,int);
    QColor * getArray(int); // Get an array of color value
    QColor * getRange(); // Get byte range -> color
    float * getRangeOccurence();
    QColor * getEntropy(); // get array of entropy -> color
    int getSize();
private:
    char * content;
    float * rangeOccurence;
    int size;
    double courbeur(double);
    double shannon(int);

};

#endif
