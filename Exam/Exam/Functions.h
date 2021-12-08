#pragma once
#include"User.h"

bool CorrectEmail(char t[100]); //Функція перевірки введеного емейлу
bool CorrectPhone(char t[100]); //Функція перевірки введеного телефону
void Add(user*& human, int& size); //Функція для добавляння користувача
void Delete(user*& human, int& size, int index);
void Show(user* human, int size, int group); //Функція для виводу на екран (index = group, див.структура)
int Search(user* human, int size);//Функція пошуку людини
void Editing(user*& human, int size, int choise, int index);
void Sort(user*& human, int size);
int FastAccess(user*& human, int size);
void Write(user* human, int size, char* filename);
void Read(user*& human, int& size, char* filename);
void ReadAdd(user*& human, int& size, char* filename);