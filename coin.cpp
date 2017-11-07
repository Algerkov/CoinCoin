#include "coin.hpp"
using namespace std;

coin::coin()
{
    m_nonce = "12345678912345678912345678912345";
    m_triOwn = "FDU";
    m_proto = "CC1.0";
    m_reserved = "0f0f0f";
    
    time_t seconds;
    time(&seconds);
    std::stringstream ss;
    ss << seconds;
    m_time = ss.str();    
}

coin::~coin() {}

void coin::gen_nonce(string acceptes)
{
    int v1 = rand() % 27;
    std::string tmp = "";

    for(size_t i=0;i<3;i++)
    {
        size_t pos = rand()%68;//j'ai 72 caractères dans acceptes
        tmp+=acceptes[pos];
    }
    m_nonce.replace(v1, 3, tmp);
}

string coin::create_coin()
{
    std::string coin_final = m_nonce + "-" + m_triOwn + "-" + m_proto + "-" + m_time + "-" + m_reserved; 
    return coin_final;
}

