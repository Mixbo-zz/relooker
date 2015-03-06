#include "fichier.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
Fichier::Fichier(std::string s)
{
	this->path = s;
    this->openFile();
}

void Fichier::openFile()
{
	streampos size;

	ifstream file (this->path.c_str(), ios::in|ios::binary|ios::ate);
	if (file.is_open())
	{
	    size = file.tellg();
		this->size = size;
	    content = new char [size];
	    file.seekg (0, ios::beg);
	    file.read (content, size);
	    file.close();
	}
}

char * Fichier::getContent()
{
	return this->content;
}
unsigned int Fichier::getSize()
{
	return this->size;
}