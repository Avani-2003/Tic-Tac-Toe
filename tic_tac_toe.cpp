#include<iostream>
#include <string>
using namespace std;

void rule()
{
    cout<<"\n\n\nRULES FOR TIC-TAC-TOE.\n1.The game is played on a grid that's 3 squares by 3 squares.\n";
    cout<<"2.Player 1 will X and Player 2 will O.\n";
    cout<<"3.The first player to get 3 of her/his marks in a row (up, down, across, or diagonally) is the winner.\n";
    cout<<"4.When all 9 squares are full, the game is over.\n";
    cout<<"5.Choose a cell numbered from 1 to 9 as below & play.\n\n";
    cout<<"\t\t 1 | 2 | 3\n"<<"\t\t---+---+--\n"<<"\t\t 4 | 5 | 6\n"<<"\t\t---+---+--\n"<<"\t\t 7 | 8 | 9\n";
    cout<<"\n\n----------------LET'S GET STARTED----------------\n";
    cout<<"        JUST PLAY.HAVE FUN.ENJOY THE GAME.\n";
}

char display(char table[3][3])
{
    cout<<"\n\t\t "<<table[0][0]<<" | "<<table[0][1]<<" | "<<table[0][2];
    cout<<endl<<"\t\t---+---+--";
    cout<<"\n\t\t "<<table[1][0]<<" | "<<table[1][1]<<" | "<<table[1][2];
    cout<<endl<<"\t\t---+---+--";
    cout<<"\n\t\t "<<table[2][0]<<" | "<<table[2][1]<<" | "<<table[2][2];
}

int decision(int a,int b,char table[3][3])
{
    char ox=table[a][b];
    if((table[a][0]==table[a][1]&&table[a][0]==table[a][2])||(table[0][b]==table[1][b]&&table[0][b]==table[2][b]))
    return 1;
    else{
        if(a==b||a==0&&b==2||a==2){
            if((table[0][0]==ox&&table[1][1]==ox&&table[2][2]==ox)||(table[0][2]==ox&&table[1][1]==ox&&table[2][0]==ox))
            return 1;
        }

    }
    return 0;
}

int check(int cell, char table[3][3], int player)
{
    int i,j,c=0;
    if(cell%3==0)
    {
        i=(cell/3)-1;
        j=2;
    } 
    else
    {
        i=cell/3;
        j=(cell%3)-1;        
    }   
    if(table[i][j]=='O'||table[i][j]=='X'||cell>9&&cell>0)
    {
        cout<<"\nEnter Valid Cell Number: ";
        cin>>cell;
        check(cell,table,player);
        c++;
    }
    if(player%2==0)
    table[i][j]='O';
    else
    table[i][j]='X';
    if(c==0)
    display(table);
    if(decision(i,j,table)==1)
    return player;
    return 0;
}

int game(string player1, string player2,char table[3][3])
{
    int cell,count,player=1;
    for(count=9;count>0;count--)
    {
        if(count%2==0)
        cout<<"\n"<<player2<<"'s  turn.";
        else
        cout<<"\n"<<player1<<"'s  turn.";
        cout<<"\nChoose Cell number :";
        cin>>cell;
        if(check(cell, table, count)!=0)
        {
            player=0;
            if(count%2==0){
                cell=2;
                cout<<"\n\n"<<player2<<" is WINNER.";
            }
            else{
                cell=1;
                cout<<"\n\n"<<player1<<" is WINNER.";
            }
            return cell;
        }       
    }
    if(player==1&&count==0)
    cout<<"\n\nTHE GAME IS DRAW";
    return 0;
}

int main()
{
    int n=1,a=0,b=0,i=1,p1=0,p2=0,temp;
    string player1,player2;
    cout<<endl<<"\t-------- Welcome to Tic Tac Toe in C++ --------"<<endl<<"\t----------- Created by Avani Ambekar ----------";
    rule();
    cout<<"\nEnter name of Player 1: ";
    cin>>player1;
    cout<<"\nEnter name of Player 2: ";
    cin>>player2;
    cout<<"\n\n--------------------******--------------------\n";
    do{
        char table[3][3]={{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
        cout<<"\n\t\tROUND "<<i<<endl;
        temp=game(player1,player2,table);
        if(temp==1)
        p1++;
        else{
            if(temp==2)
            p2++;
        }
        cout<<"\n\n----------------------------------------------";
        cout<<"\n\n\t\t   POINTS\n\n";
        cout<<"\t  "<<player1<<": "<<p1<<"\t"<<player2<<": "<<p2<<endl;
        cout<<"\n\n----------------------------------------------\n";
        cout<<endl<<"\nDo You Want To Continue Game?\n"<<"1.Yes\n"<<"2.No\n"<<"Enter Your Choice:";
        cin>>n;
        i++;
        }while(n==1);
    return 0;
}