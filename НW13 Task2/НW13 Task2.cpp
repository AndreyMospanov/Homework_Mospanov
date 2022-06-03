#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <time.h>
using namespace std;
/*Игра "Пятнашки"
1. Создаём массив
2. Перемешиваем его
3. Реализуем выбор кубика
4. Реализуем его перемещение
5. Проверяем условие победы*/
void CreateNewBoard(string board[16])
{
    board[0] = " ";
	for (int i = 1; i < 16; i++)
	{       
        stringstream ss;
        ss << i;
        board[i] = ss.str(); 
	}
    srand(time(NULL));
	random_shuffle(board, board + 16);
}
template <typename T>
void PrintArr(T arr[16])
{
    for (int i = 0; i < 16; i++)
    {   
        cout.width(3);
        cout << arr[i] << " ";
        if ((i + 1) % 4 == 0)
        {
            cout << endl;
        }
    }
    cout << "---------------\n";
}
void Move(string board[16], int line, int row)
{
    char whereToMove;
    cout << "Enter direction by w s a d buttons\n";
    cin >> whereToMove;
    if (whereToMove == 'w')
    {
        if (line > 0 && board[(line - 1) * 4 + row] == " ")
        {
            swap(board[line*4 + row], board[(line - 1)*4 + row]);
        }
        else
        {
            cout << "impossible turn\n";
        }
    }
    else if (whereToMove == 's')
    {
        if (line < 3 && board[(line + 1) * 4 + row] == " ")
        {
            swap(board[line * 4 + row], board[(line + 1) * 4 + row]);
        }
        else
        {
            cout << "impossible turn\n";
        }
    }
    else if(whereToMove == 'a')
    {
        if (row > 0 && board[(line) * 4 + row - 1] == " ")
        {
            swap(board[line * 4 + row], board[(line) * 4 + row - 1]);
        }
        else
        {
            cout << "impossible turn\n";
        }
    }
    else if (whereToMove == 'd')
    {
        if (row < 3 && board[(line) * 4 + row + 1] == " ")
        {
            swap(board[line * 4 + row], board[(line) * 4 + row + 1]);
        }
        else
        {
            cout << "impossible turn\n";
        }
    }
    else
    {
        cout << "wrong control\n";
    }
}

void Turn(string board[16])
{
    int line, row;
    cout << "Next Turn\nChoose square to move\n";
    PrintArr(board);
    cout << "Enter it's line(0123) & row(0123)\n";
    cin >> line >> row;
    Move(board, line, row);    
}
 
bool Win(string board[16])
{
    cout << "winCheck\n";
    int boardToInt[16];
    for (int i = 0; i < 16; i++)
    {
        if (board[i] != " ")
        {
            boardToInt[i] = stoi(board[i]);            
            if (i != boardToInt[i])
            {
                return false;
            }
            if ((i + 1) != boardToInt[i])
            {
                return false;
            }
        }        
    }
    return true;
}
int main()
{    
    string board[16];
    CreateNewBoard(board);
    while(true)
    {
        Turn(board);
        if (Win(board))
        {
            cout << "You WIN!\n";
            break;
        }        
    }
}
