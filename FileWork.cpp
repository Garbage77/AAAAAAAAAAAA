#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Input.h"

enum ChoiceMenu { Save = 1, Back};
enum WorkwithNonExistsFile { Create = 1, DontCreate };
enum WorkWithExistFile { EditAll = 1 };

using namespace std;

bool CheckFile(string path) {
	struct stat statbuf[100];
	if (!stat(path.c_str(), statbuf))
		return true;
	else
		return false;
}


void SaveInfoMenu(int& choice) {
	while (choice != Save and choice != Back) {
		cout << "������ ��������� ��������������� ������ � ����?" << endl;
		cout << "1 - ��������� ������ � ����" << endl << "2 - ��������� � ������� ����" << endl;
		choice = InputInt();
		if (choice != Save and choice != Back)
			cout << "������ �������� ���, ���������� ������� ���� �� �������������� ���������." << endl << endl;
	}
}

void SaveInfo(vector <double>& vec) {
	string path;
	ofstream fout;
	int choice = 0;
	int choice1 = 0, choice2 = 0;
	do {
		cout << "������� ���� � ����� � ������� ������ ��������: ";
		cin >> path;
		if (CheckFile(path)) {
			cout << "���� �� ��������� ���� ������" << endl;
			do {
				cout << "�������� �������: " << endl;
				cout << "1 - ������������ ����" << endl;
				cout << "2 - �������� ����� �����" << endl;
				choice1 = InputInt();
				switch (choice1) {
				case (EditAll):
					fout.open(path);
					if (!fout.is_open()) {
						cout << "�� ����� ������� ���� ��� ���������, ��������� ��������� �����, �������� �� �������� ������ ��� ������" << endl << "���������� �������� ����� �����" << endl;
						choice1 = Back;
					}
					break;
				case (Back):
					break;
				default:
					cout << "������ �������� ���, �������� �� ��������������: " << endl;
				}
			} while (choice1 != EditAll and choice1 != Back);
		}
		else {
			cout << "���� �� ������ ���� �� ������, �� ������ ������� ����, ���� ����������� ������ ������ ����" << endl;
			do {
				cout << "1 - ������� ����� ����" << endl << "2 - �������� ����� �����" << endl;
				choice2 = InputInt();
				switch (choice2) {
				case (Create):
					fout.open(path);
					if (CheckFile(path))
						cout << "���� ������." << endl;
					else
						cout << "���� �� �����-�� ������� �� ����� �������." << endl;
					break;
				case (DontCreate):
					break;
				default:
					cout << "������ �������� ���, �������� �� ��������������: " << endl;
					break;
				}
			} while (choice2 != Create and choice2 != DontCreate);
		}
	} while (choice1 != EditAll and choice2 != Create);
	choice1 = 0;
	choice2 = 0;
	if (CheckFile(path) and (fout.is_open())) {
		for (int i = 0; i < size(vec); i++) {
			fout << vec[i] << " ";
			if (i % 11 == 10)
				fout << endl;
		}
		cout << "������ ������� ��������� � �����." << endl;
	}
	fout.close();
}