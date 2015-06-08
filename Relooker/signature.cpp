#include "signature.h"
#include <iostream>
#include <string>

using namespace std;

signature::signature()
{
}

void signature::findSignature(char * content)
{
	std::string needle ("\0x25\0x50\0x44\0x46");
	std::string haystack (content,content+4);

	std::size_t found = haystack.find(needle);

	if (found!=std::string::npos)
    	cout << "This is a pdf";
    else
    	cout << "Unknown file";

}