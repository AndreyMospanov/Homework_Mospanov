#include <iostream>
#include "Reservoir.h"
/*Разработать класс Резервуар и интерфейc для работы с ним*/
using namespace std;
void Print(Reservoir* arr, int arrSize)
{
	if (arrSize != 0)
	{
		for (int i = 0; i < arrSize; i++)
		{
			arr[i].Print();
			cout << endl;
		}
	}	
}

bool CheckCorrect(int index, int arrSize)
{
	if (index < arrSize && index > -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int CorrectIndex(int arrSize)
{
	int index;
	bool correct = false;
	do
	{		
		cin >> index;
		index--;
		correct = CheckCorrect(index, arrSize);
		if (correct)
		{
			return index;
		}
		else
		{
			cout << "index is out of range. Try again\n";			
		}
	} while (!correct);
}

int main()
{
	Reservoir* arr;
	int arrSize;
	int choice;
	arr = new Reservoir[100];
	arrSize = 0;
	
	cout << "Welcome to reservoir program\n";
	do
	{
		cout << "Choose action \n";
		cout << "0. Exit\n1. Add reservoir\n2. Edit reservoir\n3. Compare reservoirs \n4. Calculate parameters\n5. Delete reservoir\n6. Add demo reservoirs\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			Reservoir temp;
			cout << "new reservoir\n";
			temp.Edit();
			arr[arrSize] = temp;
			arrSize++;
			break;
		}
		case 2:
		{
			int index;
			Print(arr, arrSize);
			cout << "choose number of object to edit\n";
			index = CorrectIndex(arrSize);
			arr[index].Edit();			
			break;
		}
		case 3:
		{
			int toCompare;
			int temp = -1;
			bool correct = false;
			Print(arr, arrSize);
			for (int i = 0; i < 2; i++)
			{
				cout << i + 1 << ". Choose number of objects to compare\n";				
				toCompare = CorrectIndex(arrSize);

				if (temp == -1)
				{
					temp = toCompare;
				}
				else
				{
					if (strcmp(arr[temp].GetType(), arr[toCompare].GetType()) == 0)
					{
						cout << "types are the same: " << arr[temp].GetType() << endl;
					}
					else
					{
						cout << "types are different: " << arr[temp].GetType() << " and " << arr[toCompare].GetType() << endl;
					}
				}	
			}
			break;			
		}
		case 4:
		{
			int index;
			cout << "choose number of object to calculate\n";
			Print(arr, arrSize);
			index = CorrectIndex(arrSize);
			cout << "Square = " << arr[index].Square() << ". Volume = " << arr[index].Volume() << endl;
			break;
		}
		case 5:
		{
			int index;			
			cout << "choose number of object to delete\n";
			Print(arr, arrSize);
			index = CorrectIndex(arrSize);

			for (int i = index; i < arrSize - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			arrSize--;
			break;			
		}
		case 6:
		{
			Reservoir r1("Volga", "river", 3000000, 50, 20);
			Reservoir r2("Ob'", "river", 3500000, 30, 25);
			Reservoir r3("Baikal", "lake", 700000, 20000, 2000);
			arr[arrSize] = r1;
			arrSize++;
			arr[arrSize] = r2;
			arrSize++;
			arr[arrSize] = r3;
			arrSize++;
			break;
		}
		default:
			break;
		}
		system("pause");
		system("cls");
	} while (choice != 0);
	delete[] arr;
}