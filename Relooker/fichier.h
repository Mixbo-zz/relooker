#ifndef FICHIER_H
#define FICHIER_H
#include <iostream>
#include <string>

class Fichier
{
public:
    Fichier(std::string);
    void openFile();
    char * getContent();
	unsigned int getSize();
private:
	char * content;
	std::string path;
	unsigned int size;
};

#endif // FICHIER_H
