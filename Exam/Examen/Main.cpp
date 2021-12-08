#include<iostream>
#include"Functions.h"
#pragma warning(disable:4996)

using namespace std;

int main()
{
	user* human = nullptr;
	int size = 0; //Розмір масиву груп структури
	bool job = true; //Булка для меню
	int choise; //Робота в меню
	int index = 0; //Індекс людини зі списку
	char filename[100]; //Буфєр

	while (job)
	{
		cout << " ______________________ \n" 
			"|         MENU         |\n"
			"|1 - Add new user      |\n"
			"|2 - Show              |\n"
			"|3 - Search            |\n"
			"|4 - Edit              |\n"
			"|5 - Delete            |\n"
			"|6 - Sort              |\n"
			"|7 - Fast access       |\n"
			"|8 - Write             |\n"
			"|9 - Read              |\n"
			"|10 - Read and Add     |\n"
			"|0 - Exit              |\n"
			"|______________________|\n"
			"\nYour choise: ";

		cin >> choise; 
		switch (choise)
		{
		case 1:
			cin.ignore();

			Add(human, size);
			break;
		case 2:
			if (size == 0)
			{
				cout << "Empty phone book!" << endl;
				break;
			}

			cout << "Choose:\n1-Show all\n2-Show some group\nYour choise: ";
			cin >> choise;

			if (choise == 1)
			{
				Show(human, size, 0);
			}
			else if (choise == 2)
			{

				cout << "Which group?\n1-Family\n2-Work\n3-Favorites\nYour choise: ";
				cin >> choise;

				if (choise > 0 && choise < 4)
				{
					Show(human, size, choise);
				}
				else
				{
					cout << "Wrong choise, try again!" << endl;
				}
			}
			else
			{
				cout << "Wrong choise, try again!" << endl;
			}
			break;
		case 3:
			if (size == 0)
			{
				cout << "Empty phone book!" << endl;
				break;
			}

			index = Search(human, size);
			break;
		case 4:
			if (size == 0)
			{
				cout << "Empty phone book!" << endl;
				break;
			}

			cout << "What you want to edit?\n1-Name\n2-Phone\n3-Email\n4-Group\nYour choise: ";
			cin >> choise;

			if (choise > 0 && choise < 5)
			{
				do
				{
					cout << "Enter user's index: ";
					cin >> index;
				} while (index < 0 || index > size - 1);

				Editing(human, size, choise, index);

				cout << "Done!" << endl;
			}
			else
			{
				cout << "Wrong choise, try again!" << endl;
			}
			break;
		case 5:
			if (size == 0)
			{
				cout << "Empty phone book!" << endl;
				break;
			}

			cout << "Choose:\n1-Delete with name\n2-Delete with index\nYour choise: ";
			cin >> choise;
			
			if (choise == 1)
			{
				index = Search(human, size);

				if (index != -1)
					Delete(human, size, index);
			}
			else if (choise == 2)
			{
				do
				{
					cout << "Enter user's index: ";
					cin >> index;
				} while (index < 0 || index > size - 1);

				Delete(human, size, index);
			}
			else
			{
				cout << "Wrong choise, try again!" << endl;
			}
			break;
		case 6:
			if (size == 0)
			{
				cout << "Empty phone book!" << endl;
				break;
			}

			Sort(human, size);

			cout << "Done!" << endl;
			break;
		case 7:
			if (size == 0)
			{
				cout << "Empty phone book!" << endl;
				break;
			}

			index = FastAccess(human, size);

			cout << "Done" << endl;

			break;
		case 8:
			if (size == 0)
			{
				cout << "Empty phone book!" << endl;
				break;
			}

			cin.ignore();

			cout << "Enter filename (.csv): ";
			cin.getline(filename, 100);

			Write(human, size, filename);

			cout << "Done" << endl;
			break;
		case 9:
			cin.ignore();

			cout << "Enter filename\n";
			cin.getline(filename, 100);

			Read(human, size, filename);

			cout << "Done" << endl;
			break;
		case 10:
			cin.ignore();

			cout << "Enter filename\n";
			cin.getline(filename, 100);

			ReadAdd(human, size, filename);

			cout << "Done" << endl;
			break;
		case 0:
			cout << "Bye!" << endl;

			job = 0;
			break;
		default:
			cout << "Wrong choise, try again!" << endl;

			break;
		}
	}
	for (int i = 0; i < size; i++) //Зачищаємо пам'ять
	{
		delete[] human[i].name;
		delete[] human[i].phone;
		delete[] human[i].email;
	}
}