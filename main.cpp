#include "sha1.hpp"
#include "fichier.hpp"
#include "coin.hpp"

#include <string>
#include <iostream>
#include <time.h>
#include <pthread.h>

using std::string;
using std::cout;
using std::endl;

int main(int argc, const char *argv[])
{
    std::string acceptes="abcdefghijklmnopqrstuvwyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890./=+-*$#";
    //clock_t deb, fin; /*Permet de mesurer le temps, voir l'exemple dans le cour "BACA" de Complexité */
    //deb = clock(); 
    //int i = 0;
    while(1)
    {
        // NEW
        coin* coin_at_sha = new coin();
        fichier* test_fichier = fichier::getInstance();

        // COIN STRING AT HASH 
        coin_at_sha->gen_nonce(acceptes);
        string string_coin_at_sha = coin_at_sha->create_coin();
    
        // Hash SHA1
        SHA1 checksum;
        checksum.update(string_coin_at_sha);
        const string hash = checksum.final();
        //cout << "The SHA-1 of \"" << string_coin_at_sha << "\" is: " << hash << endl;

        // WRITE IN A PURSE
        test_fichier->ecrire(string_coin_at_sha);
        delete coin_at_sha;  
        //i++;      
    }
    //fin = clock();
    //double duree = ((double)(fin - deb)) / CLOCKS_PER_SEC;
    //printf("\n Resolution en %f Secondes\n",duree);      
    
    return 0;
}
