#include "fichier.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
Fichier::Fichier(std::string s)
{
    this->size = 0;
	this->path = s;
    this->openFile();
}

void Fichier::openFile()
{
    std::ifstream is(this->path.c_str());
    if (is.is_open())
    {
        is.seekg(0, std::ios_base::end);
        std::size_t size=is.tellg();
        this->size = size;
        is.seekg(0,is.beg);
        this->content = new char[size];
        is.read(this->content, size);
        is.close();
    }
}


char * Fichier::getContent()
{
	return this->content;
}
int Fichier::getSize()
{
	return this->size;
}
