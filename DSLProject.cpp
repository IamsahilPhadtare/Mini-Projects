#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct queue
{
 int arr[50];
 int front=-1;
 int rear=-1;   
}q;

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
}
void display(){

    char computer;
        if (number < 33)
        {
            computer = 'r';
            
            cout<<"\t\t\t\tComputer : Rock"<<endl;
        }
        else if (number > 66)
        {
            computer = 's';
            
            cout<<"\t\t\t\tComputer : Scissor"<<endl;
        }
        else
        {
            computer = 'p';
           
            cout<<"\t\t\t\tComputer : Paper"<<endl;
        }
}
void scoreboard(int r,int count)
{
    if(r==-1)
        string m=
    q.arr[++q.rear]=;
   
    
        
}
int main(){

    char computer;
    char player;
    char playmore;
    int count=0;
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
    cout << "\t Reference : " << endl;
    cout << "\t\t\t\t";
    cout << "\t\t r : Rock" << endl << "\t\t\t\t" << "\t\t p : Paper" << endl << "\t\t\t\t" << "\t\t s : Scissor" << endl << "\t\t\t\t"<< endl;
    cout << "\t\t\t\t";
    for(int i = 0; i < 60; i++){
        cout << "-";
    }
    cout << endl;

    do{
        number = 0;
        srand(time(0));        
        number = rand() % 100; 
        
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

        cout << "\t\t\t\tEnter your choice :  ";
        cin>>player;
        cout<<"\t\t\t\t";
        for(int i = 0; i < 60; i++){
        cout << "-";}
        cout<<endl;
        
        while ((player != 'r') && (player != 's') && (player != 'p'))
        {
        cout<<"\t\t\t\t"<<player<<" is not a valid entry. Try Again !!!"<<endl;
        cout<<"\t\t\t\t"<<endl;
        cout<<"\t\t\t\tEnter your choice : ";
        cin>>player;
        cout<<"\t\t\t\t";
        for(int i = 0; i < 60; i++){
        cout << "-";}
        }
        cout<<endl;
        
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
        count++;
        scoreboard(result,count);
        cout << "\t\t\t\t";
        cout << "Do you want to Play Again?(y/n)" << endl;
        cout << "\t\t\t\t";
        cin >> playmore;
        cout << "\t\t\t\t";
        for(int i = 0; i < 60; i++){
            cout << "-";
        }
        cout << endl;
    }while(playmore == 'y');

    return 0;
}
