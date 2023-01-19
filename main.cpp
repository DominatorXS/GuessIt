// A note to future self:
// if you have forgotten how this works, then you are stupid. utterly stupid!
// anyways, if you do then good.
// also, how is life going? --Draco Silver 20:34, 17/1/2023

#include <iostream>
#include <ostream>
#include <string>
#include "player.h"
#include <random>

void init();
void baseLoop(int gamemode);
int generateRandom();
void selectGamemode();
void bankrupt();

Player our_player;

int main()
{
    our_player.initCoins();
    init();
    return 0;
}

void init()
{
    system("cls");
    std::cout<<"######################################\n";
    std::cout<<"Welcome to the guessing game! \n";
    std::cout<<"Rules: \n";
    std::cout<<"In tis game, you have to guess a 1 digit number, if you guess correctly you win and get money.\n";
    std::cout<<"If you loose, you loose money.\n";
    std::cout<<"\n";
    std::cout<<"Number of coins: "<<our_player.coins<<std::endl;
    std::cout<<"Enter 'p' to play \n";
    std::cout<<"Enter 'q' to quit \n";
    std::cout<<"######################################\n";
    char userselection;
    std::cin>>userselection;

    if(userselection == 'q'){ exit(0);}
    if(userselection == 'p'){selectGamemode();}
    else {init();}
}

int generateRandom()
{
    int random_two_digit_number = 0;
    srand ( time(NULL) );
    random_two_digit_number = rand() % 9 + 1;
    return random_two_digit_number;
}

void selectGamemode()
{
    system("cls");
    std::cout<<"######################################\n";
    std::cout<<"Select a mode: \n";
    std::cout<<"[1] Requires 50 coins. If you loose you get -400 coins.\n";
    std::cout<<"[2] Requires 250 coins. If you loose you get -800 coins.\n";
    std::cout<<"[3] Requires 500 coins. If you loose you get -1200 coins.\n";
    std::cout<<"\n";
    std::cout<<"Enter the mode number, 1, 2 or 3. \n";
    std::cout<<"######################################\n";
    int selectedMode = 0;
    std::cin>>selectedMode;

    if (selectedMode == 1){baseLoop(1);}
    else if (selectedMode == 2){ baseLoop(2);}
    else if (selectedMode == 3){ baseLoop(3);}
    else {selectGamemode();}
}

void baseLoop(int gamemode)
{   
    if(gamemode == 1)
    {
        if(our_player.coins >= 50)
        {
            system("cls");   
            our_player.updateCoins(-50);
            std::cout<<"Welcome to mode [1]!\n";
            std::cout<<"There will be 3 rounds, each round costs (50/3) coins, which you have already paid.\n";
            std::cout<<"Winning 1 round will give you 300 coins, loosing 1 round will give -400 coins (minus 400!)";
            for(int i = 1; i <= 3; i++)
            {
                int guessedNum = 0;
                int randomNumber = generateRandom();
                std::cout<<"\n";
                std::cout<<"Round : "<<i<<std::endl;
                std::cout<<"Guess a 1 digit number: "<<std::endl;
                std::cin>>guessedNum;
                if(guessedNum == randomNumber)
                {
                    std::cout<<"You won!\n";
                    our_player.updateCoins(300);
                }
                else 
                {
                    std::cout<<"Brrr, you lost. XD\n";
                    std::cout<<"Generated number was: "<<randomNumber<<std::endl;
                    our_player.updateCoins(-400);
                }
            }
            init();
        }
        else {
        bankrupt();
        }
    }
    
    else if(gamemode == 2)
    {
        if(our_player.coins >= 250)
        {
            system("cls");
            our_player.updateCoins(-250);   
            std::cout<<"Welcome to mode [2]!\n";
            std::cout<<"There will be 3 rounds, each round costs (250/3) coins, which you have already paid.\n";
            std::cout<<"Winning 1 round will give you 550 coins, loosing 1 round will give -800 coins (minus 800!)";
            for(int i = 1; i <= 3; i++)
            {
                int guessedNum = 0;
                int randomNumber = generateRandom();
                std::cout<<"\n";
                std::cout<<"Round : "<<i<<std::endl;
                std::cout<<"Guess a 1 digit number: "<<std::endl;
                std::cin>>guessedNum;
                if(guessedNum == randomNumber)
                {
                    std::cout<<"You won!\n";
                    our_player.updateCoins(550);
                }
                else 
                {
                    std::cout<<"Brrr, you lost. XD\n";
                    std::cout<<"Generated number was: "<<randomNumber<<std::endl;
                    our_player.updateCoins(-800);
                }
            }
            init();
        }
        else {
            if(our_player.coins <= 49)
            {
                bankrupt();
            }
            else 
            {
                std::cout<<"Not enough coins! \n";
                std::cout<<"p to select different mode. \n";
                char p;
                cin>>p;
                selectGamemode();
          }
        }
    }

    else
    {
        if(our_player.coins >= 500)
        {
            system("cls");   
            our_player.updateCoins(-500);
            std::cout<<"Welcome to mode [3]!\n";
            std::cout<<"There will be 3 rounds, each round costs (500/3) coins, which you have already paid.\n";
            std::cout<<"Winning 1 round will give you 700 coins, loosing 1 round will give -1000 coins (minus 800!)";
            for(int i = 1; i <= 3; i++)
            {
                int guessedNum = 0;
                int randomNumber = generateRandom();
                std::cout<<"\n";
                std::cout<<"Round : "<<i<<std::endl;
                std::cout<<"Guess a 1 digit number: "<<std::endl;
                std::cin>>guessedNum;
                if(guessedNum == randomNumber)
                {
                    std::cout<<"You won!\n";
                    our_player.updateCoins(700);
                }
                else 
                {
                    std::cout<<"Brrr, you lost. XD\n";
                    our_player.updateCoins(-1000);
                    std::cout<<"Generated number was: "<<randomNumber<<std::endl;
                }
            }
            init();
        }

        else 
        {
            if(our_player.coins <= 49)
            {
                bankrupt();
            }
            else 
            {
                std::cout<<"Not enough coins! \n";
                std::cout<<"p to select different mode. \n";
                char p;
                cin>>p;
                selectGamemode();
          }
        }
    }
}

void bankrupt()
{
    std::cout<<"Out of money? Ask the creator for help. \n";
    std::cout<<"Made by Draco Silver\n";
    std::cout<<"q to quit\n";
    char quit;
    cin>>quit;
}
