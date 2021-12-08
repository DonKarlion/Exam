#pragma once
#include"User.h"

bool CorrectEmail(char t[100]); //Функція перевірки введеного емейлу
bool CorrectPhone(char t[100]); //Функція перевірки введеного телефону
void Add(user*& human, int& size); //Функція для добавляння користувача
void Delete(user*& human, int& size, int index);//Функція видалення по індексу
void Show(user* human, int size, int group); //Функція для виводу на екран (index = group, див.структура)
int Search(user* human, int size);//Функція пошуку людини
void Editing(user*& human, int size, int choise, int index);//Функція корегування 
void Sort(user*& human, int size);//Функція сортування
int FastAccess(user*& human, int size);//Функція швидкого доступу
void Write(user* human, int size, char* filename);//Функція запису у файл
void Read(user*& human, int& size, char* filename);//Функція зчитування з файлу
void ReadAdd(user*& human, int& size, char* filename);//Функція зчитування та додавання в кінець