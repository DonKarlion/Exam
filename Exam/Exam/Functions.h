#pragma once
#include"User.h"

bool CorrectEmail(char t[100]); //������� �������� ��������� ������
bool CorrectPhone(char t[100]); //������� �������� ��������� ��������
void Add(user*& human, int& size); //������� ��� ���������� �����������
void Delete(user*& human, int& size, int index);
void Show(user* human, int size, int group); //������� ��� ������ �� ����� (index = group, ���.���������)
int Search(user* human, int size);//������� ������ ������
void Editing(user*& human, int size, int choise, int index);
void Sort(user*& human, int size);
int FastAccess(user*& human, int size);
void Write(user* human, int size, char* filename);
void Read(user*& human, int& size, char* filename);
void ReadAdd(user*& human, int& size, char* filename);