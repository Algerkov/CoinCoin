#ifndef DEF_COIN
#define DEF_COIN

#include <string>
#include <iostream>
#include <ctime>
#include <sstream>



class coin
{
    // ATTRIBTUS
    private:
        std::string m_nonce;
        std::string m_triOwn;
        std::string m_proto;
        std::string m_reserved;
        std::string m_time;
        
    // METHODES
    public:
        coin();
        ~coin();
        void gen_nonce(std::string);
        std::string create_coin();        
};
#endif