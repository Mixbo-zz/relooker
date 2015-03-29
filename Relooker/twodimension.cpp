#include "twodimension.h"

#include <iostream>
#include <iomanip>

using namespace std;

TwoDimension::TwoDimension(char* content, int size)
{
    char b;
    for(int i=0;i<size;++i)
    {
        b = content[i];
        cout << b << ":";
        cout << uppercase << setw(2) << setfill('0')<< hex << int(b) << endl;
    }
}
