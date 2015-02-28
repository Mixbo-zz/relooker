#ifndef FICHIER_H
#define FICHIER_H
#include <iostream>
#include <string>

class Fichier
{
public:
    Fichier();
    std::string getContent();
    bool setContent(std::string s);
};

#endif // FICHIER_H
