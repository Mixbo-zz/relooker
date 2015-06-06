#include "twodimension.h"

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

TwoDimension::TwoDimension()
{
    this->content = NULL;
    this->rangeOccurence = NULL;
    this->size = 0;
}
void TwoDimension::setContent(char * content,int size)
{
    this->content = content;
    this->size = size;
}

int *TwoDimension::getArray(int mode) // Ask for array of type mode
{
    int* returnValue = NULL;
    switch (mode)
    {
        case 1:
            returnValue = this->getRange(); // get byte range representation
            break;
        case 2:
            returnValue = this->getEntropy(); // get entropy representation
            break;
    }
    return returnValue;
}

int TwoDimension::getSize()
{
    return size;
}

int * TwoDimension::getRange()
{
    int value; 
    int * range = new int[this->size];
    this->rangeOccurence = new float[5];
    for (int i = 0; i < 5; ++i)
    {
        this->rangeOccurence[i] = 0;
    }
    int b;
    unsigned char c;
    for(int i=0;i<this->size;++i)
    {
        value = 0;
        b = c = this->content[i];
        //cout << c << ":" << b << endl;
        //cout << uppercase << setw(2) << setfill('0')<< hex << int(b) << endl;

        if(b != 0) // null byte = black
        {
            if(b == 255)// FF = white
                value = 1;
            else if(b == 9 || b == 10 || b == 13 || (b >= 32 && b <= 127)) // ASCII = Blue
                value = 2;
            else if(b < 32) // Low Byte = Green
                value = 3;
            else if(b > 127) // High Byte = Magenta
                value = 4;
        }
        this->rangeOccurence[value] +=1;
        range[i] = value;
    }
    return range;

}
float * TwoDimension::getRangeOccurence()
{
    for (int i = 0; i < 5; ++i)
    {
        this->rangeOccurence[i] = this->rangeOccurence[i]*100.00/this->size;
    }
    return this->rangeOccurence;
}

int *TwoDimension::getEntropy() // Returns color matrix representing entropy (not implemented)
{
    double * entropy = new double[this->size];
    int * colors = new int[this->size];
    for (int i = 0; i < this->size; ++i)
    {
        colors[i] = 10;
    }



    for(int i=0;i<this->size;++i)
    {
        entropy[i] = this->shannon(i);

        double r;
        double b;

        if(entropy[i] > 0.5)
            r = this->courbeur(entropy[i]-0.5);
        else
            r = 0;

        b = pow(entropy[i],2);

        r = r*255;
        b = b*255;
        //cout << entropy[i];

        cout << "r: " <<r<<" b: "<<b<<" e: "<<entropy[i];
    }
    return colors;
}

double TwoDimension::courbeur(double v)
{
    double f = pow((4 * v - 4 * pow(v,2)),4);
    if (f > 0)
        return f;
    else
        return 0.0;
}

double TwoDimension::shannon(int i)
{
    int b;
    unsigned char c;
    int * mapper = new int[256];

    for (int j=0;j<256;++j)
        mapper[j] = 0;

    int blocksize = 32;
    int start = i - blocksize / 2;

    if(start < 0)
        start = 0;
    else if (i > this->size-blocksize/2)
        start = this->size - blocksize;

    for (int j = 0; j < blocksize; ++j)
    {
        b = c = this->content[start+j];
        //cout << b;
        mapper[b] += 1;
    }

    //cout << '\n';

    double entropy = 0.0;
    double frequence;

    for (int j = 0; j < 256; ++j)
    {
        if(mapper[j] != 0)
        {
            frequence = (double)mapper[j] / (float)blocksize;
            entropy -= frequence * (log(frequence) / log(blocksize));
        }
    }
    cout << "Valeur entropie = "<<entropy << "\n";
    return entropy;
}
