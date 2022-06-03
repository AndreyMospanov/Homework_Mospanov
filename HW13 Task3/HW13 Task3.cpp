#include <iostream>
/*Игра крестики-нолики без  Ai */
using namespace std;
void CreateEmptyArr(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = '-';
        }
    }
}
template <typename T>
void PrintArr(T arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }  
    cout << "---------------\n";
}

void Turn(char sign, char board[3][3])
{
    int x, y;
    cout << "Your Turn\nEnter coordinates: line & row\n";
    cin >> x >> y;
    board[x][y] = sign;
    PrintArr(board);
}

bool CheckHorizontal(char board[3][3], char sign, int x, int y)
{
    if (x == 0 && board[x + 1][y] == sign && board[x + 2][y] == sign)
    {
        return true;
    }
    return false;
}
bool CheckVertical(char board[3][3], char sign, int x, int y)
{
    if (y == 0 && board[x][y + 1] == sign && board[x][y + 2] == sign)
    {
        return true;
    }
    return false;
}
bool CheckCrest(char board[3][3], char sign, int x, int y)
{
    if (x == 0 && y == 0 && board[x + 1][y + 1] == sign && board[x + 2][y + 2] == sign)
    {
        return true;
    }
    if (x == 0 && y == 2 && board[x + 1][y - 1] == sign && board[x + 2][y - 2] == sign)
    {
        return true;
    }
    return false;
}

bool CheckWin(char board[3][3], char x)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == x)
            {                
                if (CheckHorizontal(board, x, i, j) || CheckVertical(board, x, i, j) || CheckCrest(board, x, i, j))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    char board[3][3];
    CreateEmptyArr(board);
    
    while (true)
    {
        Turn('X', board);
        if (CheckWin(board, 'X'))
        {
            cout << "X win!\n";
            break;
        }
        Turn('O', board);
        if (CheckWin(board, 'X'))
        {
            cout << "O win!\n";
            break;
        }
    }
}
