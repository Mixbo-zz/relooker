#ifndef FICHIER_H
#define FICHIER_H
#include <iostream>
#include <string>

class Fichier
{
public:
    Fichier(std::string);
    void openFile();
    std::string getContent();
    bool setContent(std::string s);
private:
	char * content;
	std::string path;
};

#endif // FICHIER_H
