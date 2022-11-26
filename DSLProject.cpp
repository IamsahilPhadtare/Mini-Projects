#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int number;

int rule(char p, char c){
    if (p == c){
        return 0;
    }

    if (p == 'r' && c == 'p'){
        return -1;
    }
    else if (p == 's' && c == 'p'){
        return 1;
    }
    else if (p == 'p' && c == 'r'){
        return 1;
    }
    else if (p == 's' && c == 'r'){
        return -1;
    }
    else if (p == 'r' && c == 's'){
        return 1;
    }
    else if (p == 'p' && c == 's'){
        return -1;
    }
    // else if((p != 'r') || (p != 's') || (p != 'p')) {
    //     cout<<"Invalid"<<endl;
    //     return 0;
    // }
}
void display(){

    char computer;
    // number = rand() % 100;
        if (number < 33)
        {
            computer = 'r';
            cout<<"\t\t\t\t";
            cout<<"Computer : Rock"<<endl;
        }
        else if (number > 66)
        {
            computer = 's';
            cout<<"\t\t\t\t";
            cout<<"Computer : Scissor"<<endl;
        }
        else
        {
            computer = 'p';
            cout<<"\t\t\t\t";
            cout<<"Computer : Paper"<<endl;
        }
}
int main(){

    char computer;
    char player;
    char playmore;
    cout << "\t\t\t\t";
    for(int i = 0; i < 60; i++){
        cout << "-";
    }
    cout << endl;
    cout << "\t\t\t\t";
    cout << "\t \e[1m Welcome to Rock, Paper and Scissors Game \e[0m" << endl;
    cout << "\t\t\t\t";
    for(int i = 0; i < 60; i++){
        cout << "-";
    }
    cout << endl;
    cout << "\t\t\t\t";
    cout << "\t Preference : " << endl;
    cout << "\t\t\t\t";
    cout << "\t\t r : Rock" << endl << "\t\t\t\t" << "\t\t p : Paper" << endl << "\t\t\t\t" << "\t\t s : Scissor" << endl << "\t\t\t\t"<< endl;
    cout << "\t\t\t\t";
    for(int i = 0; i < 60; i++){
        cout << "-";
    }
    cout << endl;
    do{
        number = 0;
        srand(time(0));        // initialized time to 0
        number = rand() % 100; // will choose a number in range 0 - 99
        // r - for rock
        // p - for paper
        // s - for scissors
        if (number < 33)
        {
            computer = 'r';
        }
        else if (number > 66)
        {
            computer = 's';
        }
        else
        {
            computer = 'p';
        }
        // cout << "Note: \"r\" for \"Rock\", \"p\" for \"Paper\", \"s\" for \"Scissor\"." << endl;
         cout << "\t\t\t\t";
        cout << "Enter your choice: ";
        cin >> player;
        // do
        // {
       
        // cout<<"\t\t\t\t"<<player<<" is not a valid entry. Try Again !!!"<<endl;
        // cout<<"\t\t\t\t"<<endl;
        // for(int i = 0; i < 60; i++){
        // cout << "-";
        // }
        // }
        // while ((player != 'r') || (player != 's') || (player != 'p'));
       

        int result = rule(player, computer);
        

        if(result == 1){
            display();
            cout << "\t\t\t\t";
            cout << "You won! Hurray" << endl;
        }
        else if(result == -1){
           display();
            cout << "\t\t\t\t";
            cout << "You lose! Bad Luck" << endl;
        }
        else{
            display();
            cout << "\t\t\t\t";
            cout << "Woah! That's Tie!" << endl;
        }
        cout << "\t\t\t\t";
        cout << "Do you want to Play Again?(y/n)" << endl;
        cout << "\t\t\t\t";
        cin >> playmore;
        cout << "\t\t\t\t";
        for(int i = 0; i < 50; i++){
            cout << "-";
        }
        cout << endl;
    }while(playmore == 'y');

    return 0;
}
