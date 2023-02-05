/*
HAZE CASINO
DEVELOPED BY MIRAJ LIMBU

working:

Players chooses one of the two sides "cashier" or "player". the computer
draws two cards to each. the sum near to 9 wins.

when the sum of first two cards is greater then 9, then the computer draws one additional 
card and the remainder when divided by 10 is the last sum. if two card sum to 8 or 9,
the computer doesnot draws additional card.

*/

#include <iostream>
#include <string>
using namespace std;


class Number {
    public:
        int num1,num2,sum,extracard;

};

void printcard1 (int num1,int num2,int num3,int sum);
void printcard2 (int num1,int num2,int sum);
bool playagain (char x ,int money);
int winnerfunction (int cashiercard,int playercard );  
int declarewinner (int winner,int decision,int bet);

int main()
{
    string name ;
    char play;
    int date,decision,winner,prize,bet;
    bool logic=true;
    int money=100000;


    cout<<"---------------------------------"<<endl;
    cout<<"To start please enter your name:"<<endl;
    getline (cin,name);
    cout<<endl<<"Goodevening "<<name<<endl;
    cout<<"-------------"<<endl;
    cout<<"Welcome to HAZE Casino game"<<endl;
    cout<<"-------------"<<endl;


    do {
        cout<<"Your current balance is:"<<money<<endl;
        cout<<"1.cashier"<<endl<<"2.player"<<endl;
        cout<<"Choose your bet:"<<endl;

        while (!(cin>>decision)||(decision<1||decision>2)){
            cin.clear();
            cout<<"Choose your bet:"<<endl;
            cout<<"1.cashier"<<endl<<"2.player"<<endl;
        }

        do {
            cout<<"Place your bet:";
            cin>>bet;

        }while (bet>money);

        cout<<"---------------"<<endl;
        cout<<"   ="<<" cashier's card"<<"="<<endl;
        cout<<"--------------"<<endl;

        Number cashier;
        cashier.num1=rand()%10+1;
        cashier.num2=rand()%10+1;
        cashier.sum=cashier.num1+cashier.num2;
        cashier.sum=cashier.sum%10;

        if (cashier.sum!=9 && cashier.sum!=8){
            cashier.extracard=rand()%10+1;
            cashier.sum+=cashier.extracard   ;
            cashier.sum=cashier.sum%10;
            printcard1 (cashier.num1,cashier.num2,cashier.extracard,cashier.sum);

        }
        else{
            printcard2 (cashier.num1,cashier.num2,cashier.sum);

        }

        cout<<"---------------"<<endl;
        cout<<"   ="<<" players's card"<<"="<<endl;
        cout<<"--------------"<<endl;

        Number player;
        player.num1=rand()%10+1;
        player.num2=rand()%10+1;
        player.sum=player.num1+player.num2;
        player.sum=player.sum%10;

        if (player.sum!=9 && player.sum!=8){
            player.extracard=rand()%10+1;
            player.sum+=player.extracard   ;
            player.sum=player.sum%10;
            printcard1 (player.num1,player.num2,player.extracard,player.sum);

        }
        else{
            printcard2 (player.num1,player.num2,player.sum);

        }
        winner=winnerfunction(cashier.sum,player.sum);

        prize=declarewinner(winner,decision,bet);
        cout<<"gold:"<<prize<<endl;
        money+=prize;
        cout<<"current money,gold:"<<money<<endl;


        cout<<"play again? y/n"<<endl;
        cin>>play;
        logic=playagain(play,money);


        


    }while (logic!=false);

    
}

void printcard1(int num1,int num2,int num3,int sum){
    cout<<"------------------"<<endl;
    cout<<"     "<<endl;
    cout<<"|  "<<sum<<"  |"<<endl;
    cout<<"     "<<endl;
    cout<<"------------------"<<endl;
    cout<<"first card= "<<num1<<endl;
    cout<<"second card= "<<num2<<endl;
    cout<<"extracard= "<<num3<<endl;

}

void printcard2(int num1,int num2,int sum){
    cout<<"------------------"<<endl;
    cout<<"     "<<endl;
    cout<<"|  "<<sum<<"  |"<<endl;
    cout<<"     "<<endl;
    cout<<"------------------"<<endl;
    cout<<"this is a clear win."<<endl;
    cout<<"first card= "<<num1<<endl;
    cout<<"second card= "<<num2<<endl;
    
}

bool playagain (char x,int money){
    if (money>0){
        if (x == 'y' || x== 'Y'){
            return true;
        }
        else if(x=='n'|| x== 'N'){
            cout<<"thank you for playing"<<endl;
            return false;
        }
    } 
    else{
        cout<<"insufficient gold"<<endl;
        return false;

    }
}

int winnerfunction (int cashiercard,int playercard){
    if (cashiercard>playercard){
        cout<<"cashier win"<<endl;
        return 1;

    }
    else if (cashiercard<playercard){
        cout<<"player win"<<endl;
        return 2;
    }
    else if (cashiercard == playercard){
        cout<<"its a draw."<<endl;
        return 3;
    }
}

int declarewinner(int winner, int decision , int bet){
    if(winner==decision){
        cout<<"You win. "<<endl;
        return bet;
    }
    if(winner==3){
        cout<<"tie game "<<endl;
        return 0;
    }
    else{
        cout<<"you lose."<<endl;
        bet*=-1;
        return bet;
    }
}