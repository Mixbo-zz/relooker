#include "algo.h"
#include <math.h>

Algo::Algo()
{

}

/*
i = starting point
size = size of the whole content
content = source content (char array)
blocksize = size of the block to use shannon on
*/
double Algo::shannon(int i, int size, char* content, int blocksize)
{
    int b;
    unsigned char c;
    int * mapper = new int[256];

    for (int j=0;j<256;++j)
        mapper[j] = 0;

    int start = i - blocksize / 2;

    if(start < 0)
        start = 0;
    else if (i > size-blocksize/2)
        start = size - blocksize;

    for (int j = 0; j < blocksize; ++j)
    {
        b = c = content[start+j];
        mapper[b] += 1;
    }

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
    return entropy;
}