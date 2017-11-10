#ifndef DEF_FICHIER
#define DEF_FICHIER

#include <fstream>
#include <string>
#include <iostream>


class fichier
{
    // ATTRIBTUS
    private:
        static fichier* instance;
        
    // METHODES
    public:
        void ecrire(std::string coin_hash, std::string coin);
        static fichier* getInstance();
    private:
        fichier();
};
#endif