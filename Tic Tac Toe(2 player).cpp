#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
char box[3][3]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void display()
{
    for(int i=0;i<3;i++)
    {
        cout<<"\t\t\t   "<<box[i][0]<<"   | "<<"   "<<box[i][1]<<"   | "<<"   "<<box[i][2]<<"  "<<endl;
        if(i<2)
        {
            cout<<"\t\t\t--------------------------"<<endl;
        }
    }
}

bool win()
{
    for(int k = 0;k < 3 ; k++)
    {
        if(box[k][0] == box[k][1] && box[k][1] == box[k][2])
            return true;
        else if(box[0][k] == box[1][k] && box[1][k] == box[2][k])
            return true;
    }
    if(box[0][0] == box[1][1] && box[1][1] == box[2][2])
        return true;
    else if(box[0][2] == box[1][1] && box[1][1] == box[2][0])
        return true;
    else
        return false;
}

bool place_is_right(int place)
{
    int row,col;
    row = place%3 == 0 ? (place/3)-1 : (place/3);
    col = place%3 == 0 ? 2 : (place%3) - 1;

    if(box[row][col] == 'X' || box[row][col] == 'O' || box[row][col] == 'x' || box[row][col] == 'o')
    {
        return false;
    }
    else
        return true;
}

void place_mark(int place,char mark)
{
    int row,col;
    row = place%3 == 0 ? (place/3)-1 : (place/3);
    col = place%3 == 0 ? 2 : (place%3) - 1;
    box[row][col] = mark;
}

int change_player(int player)
{
    if(player == 1)
        return 2;
    else
        return 1;
}

void game(string player1,string player2,char player1_mark,char player2_mark)
{
    //system("CLS");
    int player = 1;
    int place,j;
    for(j = 0 ; j < 9 ; j++)
    {
        if(player == 1)
        {
            cout<<"Player name:- "<<player1<<"\t Player mark:- "<<player1_mark<<endl;
        }
        else
        {
            cout<<"Player name:- "<<player2<<"\t Player mark:- "<<player2_mark<<endl;
        }
        cout<<"Enter place :- ";
        cin>>place;
        cout<<endl;
        if(!place_is_right(place))
        {
            cout<<"Ooops,please Enter place one more time..."<<endl;
            j--;
            continue;
        }
        if(player == 1)
        {
            place_mark(place,player1_mark);
        }
        else
        {
            place_mark(place,player2_mark);
        }
        display();
        if(win())
        {
            cout<<"congratulations... player "<<player<<" is a Winner."<<endl;
            break;
        }
        player = change_player(player);
    }
    if(j == 9)
    {
        cout<<"Match is Tie....."<<endl;
    }
}

int main()
{
    string player1,player2;
    char player1_mark,player2_mark;
    cout<<"\t\t\t\t\"Tic-Tac-Toe Game\""<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"Enter 1st Player Name:- ";
    cin>>player1;
    cout<<"Enter 1st Player Mark(O or X):-";
    cin>>player1_mark;
    cout<<"Enter 2st Player Name:- ";
    cin>>player2;
    if(player1_mark == 'X' || player1_mark == 'x')
    {
        player2_mark = 'O';
    }
    else{
        player2_mark = 'X';
    }
    cout<<"2st Player Mark(O or X):- "<<player2_mark<<endl;
    cout<<endl;
    display();
    game(player1,player2,player1_mark,player2_mark);
    return 0;
}
