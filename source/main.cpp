#include <iostream>
#include <conio.h>

#include "Algoritms.h"

using namespace std;


int main(){
	setlocale(0, "Rus");

	int answer;
	bool flag = true;

	string text;
	string paragraph;
	
	while (flag)
	{
		system("cls");

		cout << "1. ������ ���� ����� � �������\n2. ��������� ����� �� ������� �����\n3. ����� ���� (B1B2...Bs)^k"
			 << "\n4. ������������\n5. �����\n" << endl;
		cout << "����: ";
		cin >> answer;

		switch (answer)
		{
		case 1:
		{
			system("cls");
			cout << "������� �����: ";
			cin >> text;
			cout << "������� �������: ";
			cin >> paragraph;

			naiveStringAlgoritm(text, paragraph);
			kmpAlgoritm(text, paragraph);

			cout << "\n������! ���������� ������� ����� ����� � ������ 'outTime', � ������� ����� ����� � ������ 'outResult'" << endl;
			cout << "\n������� �� ����� ������, ����� ��������� �����..." << endl;

			char ch = _getch();
			break;
		}
		case 2:
		{
			system("cls");

			int alphabetSizeText = 0;
			int alphabetSizeParagraph = 0;

			int sizeWordText = 0;
			int sizeWordParagraph = 0;

			string alphabetText;
			string alphabetParagraph;

			cout << "[PROGRAM] ���� ����� 'Text' [PROGRAM]" << endl;
			cout << "������� ���������� ���� � ��������: ";
			cin >> alphabetSizeText;

			cout << "������� ����� ��������: ";
			cin >> alphabetText;

			cout << "������� ����� �����: ";
			cin >> sizeWordText;

			cout << endl << "[PROGRAM] ���� ����� 'Paragraph' [PROGRAM]" << endl << "������� ���������� ���� � ��������: ";
			cin >> alphabetSizeParagraph;

			cout << "������� ����� ��������: ";
			cin >> alphabetParagraph;

			cout << "������� ����� �����: ";
			cin >> sizeWordParagraph;

			if (sizeWordText < sizeWordParagraph)
			{
				cout << "\n������! ������ ������, � ������� ����� ������������ �����, �� ����� ���� ������ ����� �������." << endl;
				cout << "��������� � ���� � ��������� ���� � ������� �������... ������� ����� ������..." << endl;
				char ch = _getch();
				break;
			}

			cout << endl << endl;

			text = generateWord(alphabetSizeText, alphabetText, sizeWordText);

			cout <<"������������� ����� 'Text': " << text << endl;

			paragraph = generateWord(alphabetSizeParagraph, alphabetParagraph, sizeWordParagraph);
			cout << "������������� ����� 'Paragraph': " << paragraph << endl;

			cout << endl << "[PROGRAM] ������ '��������' ��������� [PROGRAM]";
			naiveStringAlgoritm(text, paragraph);
			cout << "\n������!" << endl << endl << "[PROGRAM] ������ '���' ��������� [PROGRAM]" << "\n������!" << endl;
			kmpAlgoritm(text, paragraph);

			cout << "\n���������� ������� ����� ����� � ������ 'outTime', � ������� ����� ����� � ������ 'outResult'" << endl;
			cout << "\n������� �� ����� ������, ����� ��������� �����..." << endl;

			char ch = _getch();
			break;
		}
		case 3:
		{
			system("cls");

			int k = 0;

			string newText;
			string newParagraph;

			cout << "[PROGRAM] ���� ����� 'Text' [PROGRAM]" << endl;
			cout << "������� ����� 'Text', ������� ����� ������������ � ���� (B1B2...Bs)^k: ";
			cin >> newText;
			cout << "������� ����� k: ";
			cin >> k;

			text = genRepeatWord(newText, k);

			cout << endl << "[PROGRAM] ���� ����� 'Paragraph' [PROGRAM]" << endl;
			cout << "������� ����� 'Paragraph', ������� ����� ������������ � ���� (B1B2...Bs)^k: ";
			cin >> newParagraph;
			cout << "������� ����� k: ";
			cin >> k;

			paragraph = genRepeatWord(newParagraph, k);

			if (text.length() < paragraph.length())
			{
				cout << "\n������! ������ ������, � ������� ����� ������������ �����, �� ����� ���� ������ ����� �������." << endl;
				cout << "��������� � ���� � ��������� ���� � ������� �������... ������� ����� ������..." << endl;
				char ch = _getch();
				break;
			}

			cout << endl << endl;

			cout << "������ ��������� ����� 'Text': " << text << endl;
			cout << "������ ��������� ����� 'Paragraph': " << paragraph << endl;

			cout << endl << "[PROGRAM] ������ '��������' ��������� [PROGRAM]";
			naiveStringAlgoritm(text, paragraph);
			cout << "\n������!" << endl << endl << "[PROGRAM] ������ '���' ��������� [PROGRAM]" << "\n������!" << endl;
			kmpAlgoritm(text, paragraph);

			cout << "\n���������� ������� ����� ����� � ������ 'outTime', � ������� ����� ����� � ������ 'outResult'" << endl;
			cout << "\n������� �� ����� ������, ����� ��������� �����..." << endl;

			char ch = _getch();
			break;
		}
		case 4:
		{
			char ch;
			system("cls");

			cout << "1. ����������� 4.1\n2. ����������� 4.2\n3. ����������� 4.3\n4. �����" << endl;
			cout << "����: ";
			cin >> answer;

			switch (answer)
			{
			case 1:
				system("cls");

				cout << "[PROGRAM] ������ ������������ 4.1 [PROGRAM]" << endl;
				cout << "����������, ��������� ���������� ������������! �� ���������� �������!" << endl << endl;

				experiment4_1();

				cout << "\n������. � ������������ ������������ ����� ����������� � ����� 'timeForExperiment4_1.txt'";
				cout << "\n������� �� ����� ������, ����� ��������� �����..." << endl;

				ch = _getch();
				break;
			case 2:
				system("cls");

				cout << "[PROGRAM] ������ ������������ 4.2 [PROGRAM]" << endl;
				cout << "����������, ��������� ���������� ������������! �� ���������� �������!" << endl << endl;

				experiment4_2();

				cout << "\n������. � ������������ ������������ ����� ����������� � ������: 'timeNaiveForExperiment4_2.txt'"
					 << "� 'timeKMPForExperiment4_2.txt'";
				cout << "\n������� �� ����� ������, ����� ��������� �����..." << endl;

				ch = _getch();
				break;
			case 3:
				system("cls");

				cout << "[PROGRAM] ������ ������������ 4.3 [PROGRAM]" << endl;
				cout << "����������, ��������� ���������� ������������! �� ���������� �������!" << endl << endl;

				experiment4_3();

				cout << "\n������. � ������������ ������������ ����� ����������� � ����� 'timeNaiveForExperiment4_3.txt'"
					 << "� 'timeKMPForExperiment4_3.txt'";
				cout << "\n������� �� ����� ������, ����� ��������� �����..." << endl;

				ch = _getch();
				break;
			case 4:
				break;
			default:
				break;
			}

			break;
		}
		case 5:
		{
			flag = false;
			cout << "\n�� ����� �������!" << endl;
			break;
		}
		default:
			break;
		}
	}
	return 0;
}