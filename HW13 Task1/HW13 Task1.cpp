#include <iostream>

using namespace std;
const int arrLength = 6;

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
void MoveHorse(int chess[arrLength][arrLength], int i, int j, int count = 0)
{
	chess[i][j] += 1;
	count++;
	cout << i << " " << j << endl;
	
	if (i + 1 < arrLength && j - 2 > 0 && chess[i + 1][j - 2] == 0)//up right
	{
		MoveHorse(chess, i + 1, j - 2, count);
		return;
	}
	else if (i + 2 < arrLength && j - 1 >= 0 && chess[i + 2][j - 1] == 0)//right up
	{
		MoveHorse(chess, i + 2, j - 1, count);
		return;
	}
	else if (i + 2 < arrLength && j + 1 < arrLength && chess[i + 2][j + 1] == 0)//right down
	{
		MoveHorse(chess, i + 2, j + 1, count);
		return;
	}
	else if (i + 1 < arrLength && j + 2 < arrLength && chess[i + 1][j + 2] == 0)//down right
	{
		MoveHorse(chess, i + 1, j + 2, count);
		return;
	}
	else if (i - 1 >= 0 && j + 2 < arrLength && chess[i - 1][j + 2] == 0)//down left
	{
		MoveHorse(chess, i - 1, j + 2, count);
		return;
	}
	else if (i - 2 >= 0 && j + 1 < arrLength && chess[i - 2][j + 1] == 0)//left down
	{
		MoveHorse(chess, i - 2, j + 1, count);
		return;
	}
	else if (i - 2 >= 0 && j - 1 >= 0 && chess[i - 2][j - 1] == 0)//left up
	{
		MoveHorse(chess, i - 2, j - 1, count);
		return;
	}
	else if (i - 1 >= 0 && j - 2 >= 0 && chess[i - 1][j - 2] == 0)//up left
	{
		MoveHorse(chess, i - 1, j - 2, count);
		return;
	}
	else
	{
		cout << "end. count = " << count << endl;
	}
}
int main()
{
	int chessBoard[arrLength][arrLength];
	CreateEmptyArr(chessBoard);
	MoveHorse(chessBoard, 0, 0);
	PrintArr(chessBoard);
}
