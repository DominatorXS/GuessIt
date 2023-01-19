#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
class Player
{
    private:
        int defaultNumberOfCoins;
    public:
        int coins;
        int gamesPlayed;
        void initCoins(void);
        void updateCoins(int t_coins);
};

inline void Player::initCoins()
{
    defaultNumberOfCoins = 10000;
    ifstream coinsFile;
    coinsFile.open("serialize.bin");
    if(!coinsFile)
    {
        ofstream coinsFile;
        coinsFile.open("serialize.bin");
        coinsFile<<defaultNumberOfCoins;
        coinsFile.close();
        initCoins();
    }
    if(coinsFile)
    {
        string numberOfCoins;
        coinsFile >> numberOfCoins;
        coins = stoi(numberOfCoins);
    }
}

inline void Player::updateCoins(int t_coins)
{
    ofstream coinsFile("serialize.bin");
    stringstream ss;
    coins += t_coins;
    ss << coins;
    coinsFile << ss.str();
    coinsFile.close();
    
}
