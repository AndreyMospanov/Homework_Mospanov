#include <iostream>
/*Посчитать, сколько есть вариантов прохождения шахматного коня по всем клеткам*/
using namespace std;
<<<<<<< HEAD

const int arrLength = 6;
int myCount = 0;
=======
const int arrLength = 5;
int MyCount = 0;
>>>>>>> 40cd3458e27209efce93b09fe4c0a93442550103

void CreateEmptyArr(int arr[arrLength][arrLength])
{
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			arr[i][j] = 0;
		}
	}
}

template <typename T>
void PrintArr(T arr[arrLength][arrLength])
{
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------------------\n";
}
<<<<<<< HEAD
bool CheckArr(int chess[arrLength][arrLength])
{
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			if (chess[i][j] == 0)
			{
				return false;
			}
		}
		return true;		
	}
}
void CopyArray(int original[arrLength][arrLength], int copy[arrLength][arrLength])
{
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			copy[i][j] = original[i][j];
		}
	}
}

void MoveHorse(int chess[arrLength][arrLength], int i, int j)
{
	chess[i][j] += 1;
	
	if (CheckArr(chess))
	{
		myCount++;
	}
	
	if (i + 1 < arrLength && j - 2 > 0 && chess[i + 1][j - 2] == 0)//up right
	{
		int copy[arrLength][arrLength];
		CopyArray(chess, copy);
		MoveHorse(copy, i + 1, j - 2);		
	}
	if (i + 2 < arrLength && j - 1 >= 0 && chess[i + 2][j - 1] == 0)//right up
	{
		int copy[arrLength][arrLength];
		CopyArray(chess, copy);
		MoveHorse(copy, i + 2, j - 1);		
	}
	if (i + 2 < arrLength && j + 1 < arrLength && chess[i + 2][j + 1] == 0)//right down
	{
		int copy[arrLength][arrLength];
		CopyArray(chess, copy);
		MoveHorse(copy, i + 2, j + 1);		
	}
	if (i + 1 < arrLength && j + 2 < arrLength && chess[i + 1][j + 2] == 0)//down right
	{
		int copy[arrLength][arrLength];
		CopyArray(chess, copy);
		MoveHorse(copy, i + 1, j + 2);		
	}
	if (i - 1 >= 0 && j + 2 < arrLength && chess[i - 1][j + 2] == 0)//down left
	{
		int copy[arrLength][arrLength];
		CopyArray(chess, copy);
		MoveHorse(copy, i - 1, j + 2);		
	}
	if (i - 2 >= 0 && j + 1 < arrLength && chess[i - 2][j + 1] == 0)//left down
	{
		int copy[arrLength][arrLength];
		CopyArray(chess, copy);
		MoveHorse(copy, i - 2, j + 1);		
	}
	if (i - 2 >= 0 && j - 1 >= 0 && chess[i - 2][j - 1] == 0)//left up
	{
		int copy[arrLength][arrLength];
		CopyArray(chess, copy);
		MoveHorse(copy, i - 2, j - 1);		
	}
	if (i - 1 >= 0 && j - 2 >= 0 && chess[i - 1][j - 2] == 0)//up left
	{
		int copy[arrLength][arrLength];
		CopyArray(chess, copy);
		MoveHorse(copy, i - 1, j - 2);		
	}
	
=======

bool Check(int chess[arrLength][arrLength])
{
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			if (chess[i][j] == 0)
				return false;
		}
	}
	return true;
}
void CopyArr(int original[arrLength][arrLength], int copy[arrLength][arrLength])
{
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			copy[i][j] = original[i][j];
		}		
	}
}
void MoveHorse(int chess[arrLength][arrLength], int i, int j)
{
	chess[i][j] = 1;
	if (Check(chess))
	{
		MyCount++;
		return;
	}	
	
	if (i + 1 < arrLength && j - 2 >= 0 && chess[i + 1][j - 2] == 0)//up right
	{
		int copy[arrLength][arrLength];
		CopyArr(chess, copy);
		MoveHorse(copy, i + 1, j - 2);
	}
	if (i + 2 < arrLength && j - 1 >= 0 && chess[i + 2][j - 1] == 0)//right up
	{
		int copy[arrLength][arrLength];
		CopyArr(chess, copy);
		MoveHorse(copy, i + 2, j - 1);		
	}
	if (i + 2 < arrLength && j + 1 < arrLength && chess[i + 2][j + 1] == 0)//right down
	{
		int copy[arrLength][arrLength];
		CopyArr(chess, copy);
		MoveHorse(copy, i + 2, j + 1);		
	}
	if (i + 1 < arrLength && j + 2 < arrLength && chess[i + 1][j + 2] == 0)//down right
	{
		int copy[arrLength][arrLength];
		CopyArr(chess, copy);
		MoveHorse(copy, i + 1, j + 2);		
	}
	if (i - 1 >= 0 && j + 2 < arrLength && chess[i - 1][j + 2] == 0)//down left
	{
		int copy[arrLength][arrLength];
		CopyArr(chess, copy);
		MoveHorse(copy, i - 1, j + 2);		
	}
	if (i - 2 >= 0 && j + 1 < arrLength && chess[i - 2][j + 1] == 0)//left down
	{
		int copy[arrLength][arrLength];
		CopyArr(chess, copy);
		MoveHorse(copy, i - 2, j + 1);		
	}
	if (i - 2 >= 0 && j - 1 >= 0 && chess[i - 2][j - 1] == 0)//left up
	{
		int copy[arrLength][arrLength];
		CopyArr(chess, copy);
		MoveHorse(copy, i - 2, j - 1);		
	}
	if (i - 1 >= 0 && j - 2 >= 0 && chess[i - 1][j - 2] == 0)//up left
	{
		int copy[arrLength][arrLength];
		CopyArr(chess, copy);
		MoveHorse(copy, i - 1, j - 2);
	}	
>>>>>>> 40cd3458e27209efce93b09fe4c0a93442550103
}
int main()
{
	int chessBoard[arrLength][arrLength];
	int x, y;	
	CreateEmptyArr(chessBoard);
<<<<<<< HEAD
	int x, y;
	cout << " enter coordinates\n";
	cin >> x >> y;
	MoveHorse(chessBoard, x, y);
	cout << myCount;
=======
	cout << "Enter coordinates. Two numbers < " << arrLength << endl;
	cin >> x >> y;
	MoveHorse(chessBoard, x, y);	
	cout << MyCount << " variants\n";
>>>>>>> 40cd3458e27209efce93b09fe4c0a93442550103
}
