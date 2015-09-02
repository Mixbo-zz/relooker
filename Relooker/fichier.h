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
    int getSize();
    std::string getPath();
private:
	char * content;
	std::string path;
	int size;
};

#endif // FICHIER_H
