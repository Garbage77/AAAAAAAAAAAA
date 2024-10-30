#include "Input.h"
#include "sort.h"
#include <iostream>
#include <vector>
#include "FileWork.h"

using namespace std;

enum MENU { Input = 1, InputFile, Quit };

//����� ���������� � �������������
void MainInfo(void) {
	cout << "������������" << endl;
	cout << "��������� �������� ���������� � ��������, ������ 433" << endl;
}

//����� ����
void ChoiceInfo(void) {
	cout << "1 - ������ ������ �������" << endl << "2 - ������ ������ �� �����" << endl;
	cout << "3 - ����� �� ���������" << endl;
}

//����� ������ ���� �������������
int InputChoiceMenu(void) {
	int choice = 0;
	cout << "�������� ������ �������� :" << endl;
	ChoiceInfo();
	choice = InputInt();
	return choice;
}

//����
void Menu() {
	int choice = 0;
	MainInfo();
	do {
		choice = InputChoiceMenu();
		switch (choice) {
		case (Input):
			InputArrayByUser();
			break;
		case(InputFile):
			InputArrayByFile();
			break;
		case(Quit):
			break;
		default:
			cout << "������ �������� ���, ���������� �������� �� ��������������" << endl;
		}
	} while (choice != Quit);
	cout << "�������, ��� ����������� ���� ���������" << endl;
}



