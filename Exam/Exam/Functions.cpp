#include<iostream>
#include"Functions.h"
#pragma warning(disable:4996)

using namespace std;

bool CorrectPhone(char t[100])
{
	if (strlen(t) == 0) //перевірка на пустоту
		return false;
	for (int i = 0; i < strlen(t); i++)//Йдемо по масиву введеної строки
	{
		if (!isdigit(t[i]))//Якщо елемент масиву не число
		{
			if (t[i] == '+' || t[i] == '(' || t[i] == ')' || t[i] == ' ')//То провіряємо чи належить воно до нашої групи
				continue;//Якщо так - продовжуємо
			else
				return false;//Якщо ні - повертаємо Фолсе, що номер не вірний
		}
	}
	return true;//Якщо пройшли всі елементи, то відправляємо тру - номер вірний
}

bool CorrectEmail(char t[100])
{
	if (strlen(t) == 0) //перевірка на пустоту
		return false;
	int counter = 0;//Лічильник символів
	for (int i = 0; i < strlen(t); i++)
	{
		if (t[i] == '@' && counter > 2)//Йдемо по масиву до першої @, якщо елементів більше 3х, то
		{
			counter = 0;//Обнуляємо лічильник
			for (int j = i + 1; j < strlen(t); j++)//Перекидуємо індекс, щоб не йти по масиву з початку
			{
				if (t[j] == '@')//Якщо знайшли другу @ відправляємо фолс
					return false;
				else if (t[j] == '.' && counter > 0)//Коли знайшли . і елементів більше 1, то
				{
					counter = 0;//Обнулили лічилик 2
					for (int i = j + 1; i < strlen(t); i++)//Передали індекс
					{
						counter++;//Рахуємо символи
					}
					if (counter < 2)//Якщо їх менше 2
						return false;//Відправляємо фолс
					else
						return true;//Інакше - Тру
				}
				else if (t[j] == '.' && counter == 0)//Коли знайшли . і елементів менше 1-го
					return false;//Повертаємо фолс
				counter++;//Дадаємо лічильник 2
			}
		}
		else if (t[i] == '@' && counter < 3)//Якщо елементів менше 3х, то повертаємо фолс - емейл не є вірний
			return false;
		counter++;//Додаємо лічильник 1
	}
	return false;//Якщо не знайшли @ відправляємо фолс
}

void Add(user*& human, int& size)
{
	bool correct = false; //Булка, щоб не викликати функції перевірки кілька разів
	char t[100];//Тимчасовий буфер
	int group;

	user* temp = new user[size + 1]; //Створили тимчасовий масив
	for (int i = 0; i < size; i++)
	{
		temp[i] = human[i]; //переписали в нього попередні
	}
	delete[] human;//видалили старий
	human = temp;//перезаписали

	do
	{
		cout << "Enter new user name\n";//Запросили ім'я
		cin.getline(t, 100);//записали в буфер
	} while (strlen(t) == 0);//перевірка на пустоту

	human[size].name = new char[strlen(t) + 1];//виділили пам'ять
	strcpy(human[size].name, t);//скопіювали


	do
	{
		cout << "Enter new user phone (+(XXX) XXX XX XX)\n";//Запросили телефон
		cin.getline(t, 100);//Записали в буфер
		correct = CorrectPhone(t);//Перевірили на правильність
		if (correct)//Якщо номер правильний, то
		{
			human[size].phone = new char[strlen(t) + 1];//Виділили пам'ять
			strcpy(human[size].phone, t);//Записали
		}
	} while (!correct);//Якщо не номер неправильний - запрошуємо знову

	do
	{
		cout << "Enter new user email (example@x.xx)\n";
		cin.getline(t, 100);
		correct = CorrectEmail(t);
		if (correct)
		{
			human[size].email = new char[strlen(t) + 1]; // АНАЛОГІЧНО ЯК З НОМЕРОМ
			strcpy(human[size].email, t);
		}
	} while (!correct);

	do
	{
		cout << "Enter group:\n0-no any group\n1-family\n2-work\n3-favorites\n";//Запитали в користувача до якої групи віднести людину
		cin >> group;
		if (group > -1 && group < 4)
		{
			human[size].group = group;
			correct = true;
		}
		else
		{
			cout << "Wrong choise, try again!" << endl;
			correct = false;
		}
	} while (!correct);
	size++;//збільшили розмір на один
}

void Delete(user*& human, int& size, int index)
{
	user* temp = new user[size - 1]; //Створили тимчасовий масив
	for (int i = 0; i < size; i++)
	{
		if (i < index)
			temp[i] = human[i];
		else if (i > index)//переписали в нього попередні
			temp[i - 1] = human[i];
	}
	delete[] human;//видалили старий
	human = temp;
	size--;
}

void Show(user* human, int size, int group)
{
	if (group == 0) //Виводимо красиву засточку
	{
		cout << "---------ALL USERS---------\n";
		cout << "#\tName\t\tPhone\t\t\tEmail\t\t\tGroup\n";

	}
	else if (group == 1)
	{
		cout << "---------FAMILY---------\n";
		cout << "Name\t\tPhone\t\t\tEmail\n";

	}
	else if (group == 2)
	{
		cout << "---------WORK---------\n";
		cout << "Name\t\tPhone\t\t\tEmail\n";
	}
	else
	{
		cout << "---------FAVORITES---------\n";
		cout << "Name\t\tPhone\t\t\tEmail\t\tGroup\n";
	}
	for (int i = 0; i < size; i++)
	{
		if (group == 0)//Якщо індекс == 0, то
		{
			cout << i << "\t" << human[i].name << "\t" << human[i].phone << "\t" << human[i].email << "\t";//Виводимо інформацію про кожну людину
			if (human[i].group == 1)//групу виводимо для кожної людини окремо, щоб було зрозуміло і наглядно
				cout << "Family" << "\n";
			else if (human[i].group == 2)
				cout << "Work" << "\n";
			else if (human[i].group == 3)
				cout << "Favorites" << "\n";
			else
				cout << "No any group" << "\n";
		}
		else if (human[i].group == group)//Якщо ми виводимо якусь певну групу людей, то звіряємо її групу з вказаним індексом
		{
			cout << human[i].name << "\t" << human[i].phone << "\t" << human[i].email << endl;
		}
	}
}

int Search(user* human, int size)
{
	char t[100];
	bool found = false;

	cin.ignore();
	do
	{
		cout << "Enter user name or phone number\n";//Запросили ім'я
		cin.getline(t, 100);//записали в буфер
	} while (strlen(t) == 0);//перевірили на пустоту
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(t, human[i].name) || !strcmp(t, human[i].phone))
		{
			cout << "User " << human[i].name << " founded at index: " << i << endl;
			return i;
		}
	}
	if (!found)
	{
		cout << "User not found" << endl;
		return -1;
	}
}

void Editing(user*& human, int size, int choise, int index)
{
	int group;
	bool correct;
	char t[100];//Тимчасовий буфер

	if (choise == 1)
	{
		cin.ignore();
		do
		{
			cout << "Enter new user name\n";//Запросили ім'я
			cin.getline(t, 100);//записали в буфер
		} while (strlen(t) == 0);//перевірка на пустоту

		delete human[index].name;
		human[index].name = new char[strlen(t) + 1];//виділили пам'ять
		strcpy(human[index].name, t);//скопіювали	
	}

	else if (choise == 2)
	{
		do
		{
			cout << "Enter new user phone (+(XXX) XXX XX XX)\n";//Запросили телефон
			cin.getline(t, 100);//Записали в буфер
			correct = CorrectPhone(t);//Перевірили на правильність
			if (correct)//Якщо номер правильний, то
			{
				delete human[index].phone;
				human[index].phone = new char[strlen(t) + 1];//Виділили пам'ять
				strcpy(human[index].phone, t);//Записали
			}
		} while (!correct);//Якщо не номер неправильний - запрошуємо знову
	}

	else if (choise == 3)
	{
		do
		{
			cout << "Enter new user email (example@x.xx)\n";
			cin.getline(t, 100);
			correct = CorrectEmail(t);
			if (correct)
			{
				delete human[index].email;
				human[index].email = new char[strlen(t) + 1]; // АНАЛОГІЧНО ЯК З НОМЕРОМ
				strcpy(human[index].email, t);
			}
		} while (!correct);
	}

	else
	{
		do
		{
			cout << "Enter group:\n0-no any group\n1-family\n2-work\n3-favorites\n";//Запитали в користувача до якої групи віднести людину
			cin >> group;
			if (group > -1 && group < 4)
			{
				human[index].group = group;
				correct = true;
			}
			else
			{
				cout << "Wrong choise, try again!" << endl;
				correct = false;
			}
		} while (!correct);
	}
}

void Sort(user*& human, int size)
{
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (tolower(human[j].name[index]) > tolower(human[j + 1].name[index]))
			{
				if (index != 0)
					index = 0;
				swap(human[j], human[j + 1]);
			}
			else if (tolower(human[j].name[index]) == tolower(human[j + 1].name[index]))
			{
				j--;
				index++;
			}
		}
	}
}

int FastAccess(user*& human, int size)
{
	int choise;

	Show(human, size, 3);
	cout << "Do you want to search user index in main list?\n1 - Yes\n2 - No\nYour choise: ";
	cin >> choise;
	switch (choise)
	{
	case 1:
		return Search(human, size);
		break;
	case 2:
		return -1;
		break;
	default:
		cout << "Wrong choise!";
		break;
	}
	return -1;
}

void Write(user* human, int size, char* filename)
{
	char buf[2];
	FILE* f = fopen(filename, "w");
	if (!f)
		cout << "File not open\n";
	else
	{
		for (int i = 0; i < size; i++)
		{
			fputs(human[i].name, f);
			fputc(';', f);
			fputs(human[i].phone, f);
			fputc(';', f);
			fputs(human[i].email, f);
			fputc(';', f);
			itoa(human[i].group, buf, 10);
			fputs(buf, f);
			fputc('\n', f);
		}
		fclose(f);
	}
}

void Read(user*& human, int& size, char* filename)
{
	char buf[100];
	FILE* f = fopen(filename, "r");
	if (!f)
		cout << "Wrong file\n";
	else
	{
		while (fgets(buf, 100, f))
			size++;
		rewind(f);
		human = new user[size];
		for (int i = 0; i < size; i++)
		{
			fgets(buf, 100, f);
			char* token = strtok(buf, ";");
			human[i].name = new char[strlen(token) + 1];
			strcpy(human[i].name, token);
			token = strtok(NULL, ";");
			human[i].phone = new char[strlen(token) + 1];
			strcpy(human[i].phone, token);
			token = strtok(NULL, ";");
			human[i].email = new char[strlen(token) + 1];
			strcpy(human[i].email, token);
			token = strtok(NULL, ";");
			human[i].group = atoi(token);
		}
		fclose(f);
	}
}

void ReadAdd(user*& human, int& size, char* filename)
{
	int counter = 0;
	char buf[100];
	FILE* f = fopen(filename, "r");
	if (!f)
		cout << "Wrong file\n";
	else
	{
		while (fgets(buf, 100, f))
			counter++;
		rewind(f);

		user* temp = new user[size + counter]; 
		for (int i = 0; i < size; i++)
		{
			temp[i] = human[i]; 
		}
		delete[] human;

		for (int i = counter; i < size + counter; i++)
		{
			fgets(buf, 100, f);
			char* token = strtok(buf, ";");
			temp[i].name = new char[strlen(token) + 1];
			strcpy(temp[i].name, token);
			token = strtok(NULL, ";");
			temp[i].phone = new char[strlen(token) + 1];
			strcpy(temp[i].phone, token);
			token = strtok(NULL, ";");
			temp[i].email = new char[strlen(token) + 1];
			strcpy(temp[i].email, token);
			token = strtok(NULL, ";");
			temp[i].group = atoi(token);
		}
		fclose(f);
		human = temp;
		size += counter;
	}
}
