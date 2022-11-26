/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include<conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
struct LL
{
 string gameno;
 string res;
 struct LL *next;
}*head,*list;

int number;

int rule(string p, string c){
    if (p == c){
        return 0;
    }

    if (p == "r" && c == "p"){
        return -1;
    }
    else if (p == "s" && c == "p"){
        return 1;
    }
    else if (p == "p" && c == "r"){
        return 1;
    }
    else if (p == "s" && c == "r"){
        return -1;
    }
    else if (p == "r" && c == "s"){
        return 1;
    }
    else if (p == "p" && c == "s"){
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
struct LL* create_game(struct LL *head, int r,int count, string playr, string comp)
{
    struct LL *p, *newnode, *x;
    x=head;
    newnode=new(struct LL);
    string temp="Game "+to_string(count);
    newnode->gameno=temp;
    temp="";
    if(r==-1)
    {
        if(comp=="r")
            temp="Computer won by rock over "+playr;
        else if(comp=="p")
            temp="Computer won by paper over "+playr;
        else
            temp="Computer won by scissor over "+playr;
    }
    else if(r==1)
    {
        if(playr=="r")
            temp="Player won by rock over "+comp;
        else if(playr=="p")
            temp="Player won by paper over "+comp;
        else
            temp="Player won by scissor over "+comp;
    }
    else
    {
        temp="It was a Tie!";
    }
    newnode->res=temp;
    if(head==NULL)
    {
        head=newnode;
        //p=head;
    }
    else
    {
        while(x->next!=NULL)
            x=x->next;
        x->next=newnode;
    }
    return head;
}
void showboard(struct LL* h)
{
    struct LL *p;
    p=h;
    while(p!=NULL)
    {
        cout<<"\n\t\t\t"<<p->gameno<<": \t"<<p->res;
        p=p->next;
    }
}
int main(){
    head=NULL;
    string computer;
    string player;
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
        char scr;
        number = 0;
        srand(time(0));        
        number = rand() % 100; 
        
        if (number < 33)
        {
            computer = "r";
        }
        else if (number > 66)
        {
            computer = "s";
        }
        else
        {
            computer = "p";
        }

        cout << "\t\t\t\tEnter your choice :  ";
        cin>>player;
        cout<<"\t\t\t\t";
        for(int i = 0; i < 60; i++){
        cout << "-";}
        cout<<endl;
        
        while ((player != "r") && (player != "s") && (player != "p"))
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
        head=create_game(head,result,count,player,computer);
        cout << "\n\n\t\t\t\t";
        cout << "Do you want to Play Again?(y/n)" << endl;
        cout << "\t\t\t\t";
        cin >> playmore;
        cout << "\t\t\t\t";
        cout<<"\n\tShow Scoreboard? (type 's' or any char): ";
        cout << "\t\t\t\t";
        cin>>scr;
        if(scr=='s'||scr=='S')
        {
            showboard(head);
            cout<<"\n\n";
        }
        for(int i = 0; i < 60; i++){
            cout << "-";
        }
        cout << endl;
    }while(playmore == 'y' || playmore=='Y');

    return 0;
}
