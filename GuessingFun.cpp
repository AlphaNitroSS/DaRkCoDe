#include <iostream>
#include <string> 
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
    
void rules();
 ofstream pout; 

int main()
{    
    string playerName;
    int balance;
    int bettingAmount;
    int guess;
    int dice; 
    char choice;
 pout.open("Player_Data.text"); 
    srand(time(0)); 
    cout<< "\n\t\t ======== WELCOME TO GUESSING GAME ======= \n\n";
    
    cout<< "\n\n Enter your Name : ";
    getline(cin, playerName);
    cout << "\n\n Enter the starting balance to play game :  ";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\n\n Your current balance : " << balance << "\n";
        do
        {
            cout << "Hey, " << playerName<<", Enter amount to bet :  ";
            cin >> bettingAmount;
            if(bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"
                       <<"\nRe-enter balance\n ";
        }while(bettingAmount > balance);
        do
        {
            cout << " Guess Any number between 1 & 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "\n Enter Number between 1 to 10\n"
                    <<"Re-enter number:\n ";
        }while(guess <= 0 || guess > 10);
        dice = rand()%10 + 1;
        if(dice == guess)
        {
            cout << "\n\n You are in luck!! You have won Rs." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << " Oops, Better luck next time !! You lost  "<< bettingAmount <<"\n";
            balance = balance - bettingAmount;
        }
        cout << "\n The winning number is: " << dice <<"\n";
        cout << "\n"<<playerName<<", You have balance of  " << balance << "\n";
        if(balance == 0)
        {
            cout << " You have no money to play ";
            break;
        }
        cout << "\n\n--> Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\n Thanks for playing the game. Your balance is:  " << balance << "\n\n";
    pout<<"Player Name: "<<playerName<<endl;
    pout<<"Balance Amount: "<<balance<<endl;
    pout<<"Betting Amount: "<<bettingAmount<<endl;
    pout<<"Player Selected Number: "<<guess<<endl;
    pout<<"Winning Number: "<<dice<<endl;
    pout<<"Player Choice ( y/n )"<<choice<<"\n";
    return 0;
}
void rules()
{
    system("cls");
    cout << "\t\t ====== FUN NUMBER GUESSING ======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";   
}
