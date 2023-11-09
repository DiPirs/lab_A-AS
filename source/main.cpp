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

		cout << "1. Ручной ввод слова и образца\n2. Генерация слова из заданой длины\n3. Слова вида (B1B2...Bs)^k"
			 << "\n4. Эксперементы\n5. Выход\n" << endl;
		cout << "Ввод: ";
		cin >> answer;

		switch (answer)
		{
		case 1:
		{
			system("cls");
			cout << "Введите текст: ";
			cin >> text;
			cout << "Введите образец: ";
			cin >> paragraph;

			naiveStringAlgoritm(text, paragraph);
			kmpAlgoritm(text, paragraph);

			cout << "\nГотово! Результаты времени можно найти в файлах 'outTime', а индексы можно найти в файлах 'outResult'" << endl;
			cout << "\nНажмите на любую кнопку, чтобы вернуться назад..." << endl;

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

			cout << "[PROGRAM] Ввод слова 'Text' [PROGRAM]" << endl;
			cout << "Введите количество букв в алфавите: ";
			cin >> alphabetSizeText;

			cout << "Введите буквы алфавита: ";
			cin >> alphabetText;

			cout << "Введите длину слова: ";
			cin >> sizeWordText;

			cout << endl << "[PROGRAM] Ввод слова 'Paragraph' [PROGRAM]" << endl << "Введите количество букв в алфавите: ";
			cin >> alphabetSizeParagraph;

			cout << "Введите буквы алфавита: ";
			cin >> alphabetParagraph;

			cout << "Введите длину слова: ";
			cin >> sizeWordParagraph;

			if (sizeWordText < sizeWordParagraph)
			{
				cout << "\nОшибка! Длинна текста, в котором будет производится поиск, не может быть меньше длины образца." << endl;
				cout << "Вернитесь в меню и повторите ввод с верными данными... Нажмите любую кнопку..." << endl;
				char ch = _getch();
				break;
			}

			cout << endl << endl;

			text = generateWord(alphabetSizeText, alphabetText, sizeWordText);

			cout <<"Сгенерировано слово 'Text': " << text << endl;

			paragraph = generateWord(alphabetSizeParagraph, alphabetParagraph, sizeWordParagraph);
			cout << "Сгенерировано слово 'Paragraph': " << paragraph << endl;

			cout << endl << "[PROGRAM] Запуск 'Наивного' алгоритма [PROGRAM]";
			naiveStringAlgoritm(text, paragraph);
			cout << "\nГотово!" << endl << endl << "[PROGRAM] Запуск 'КМП' алгоритма [PROGRAM]" << "\nГотово!" << endl;
			kmpAlgoritm(text, paragraph);

			cout << "\nРезультаты времени можно найти в файлах 'outTime', а индексы можно найти в файлах 'outResult'" << endl;
			cout << "\nНажмите на любую кнопку, чтобы вернуться назад..." << endl;

			char ch = _getch();
			break;
		}
		case 3:
		{
			system("cls");

			int k = 0;

			string newText;
			string newParagraph;

			cout << "[PROGRAM] Ввод слова 'Text' [PROGRAM]" << endl;
			cout << "Введите слово 'Text', которое будет представлено в виде (B1B2...Bs)^k: ";
			cin >> newText;
			cout << "Введите число k: ";
			cin >> k;

			text = genRepeatWord(newText, k);

			cout << endl << "[PROGRAM] Ввод слова 'Paragraph' [PROGRAM]" << endl;
			cout << "Введите слово 'Paragraph', которое будет представлено в виде (B1B2...Bs)^k: ";
			cin >> newParagraph;
			cout << "Введите число k: ";
			cin >> k;

			paragraph = genRepeatWord(newParagraph, k);

			if (text.length() < paragraph.length())
			{
				cout << "\nОшибка! Длинна текста, в котором будет производится поиск, не может быть меньше длины образца." << endl;
				cout << "Вернитесь в меню и повторите ввод с верными данными... Нажмите любую кнопку..." << endl;
				char ch = _getch();
				break;
			}

			cout << endl << endl;

			cout << "Задано следующее слово 'Text': " << text << endl;
			cout << "Задано следующее слово 'Paragraph': " << paragraph << endl;

			cout << endl << "[PROGRAM] Запуск 'Наивного' алгоритма [PROGRAM]";
			naiveStringAlgoritm(text, paragraph);
			cout << "\nГотово!" << endl << endl << "[PROGRAM] Запуск 'КМП' алгоритма [PROGRAM]" << "\nГотово!" << endl;
			kmpAlgoritm(text, paragraph);

			cout << "\nРезультаты времени можно найти в файлах 'outTime', а индексы можно найти в файлах 'outResult'" << endl;
			cout << "\nНажмите на любую кнопку, чтобы вернуться назад..." << endl;

			char ch = _getch();
			break;
		}
		case 4:
		{
			char ch;
			system("cls");

			cout << "1. Эксперемент 4.1\n2. Эксперемент 4.2\n3. Эксперемент 4.3\n4. Назад" << endl;
			cout << "Ввод: ";
			cin >> answer;

			switch (answer)
			{
			case 1:
				system("cls");

				cout << "[PROGRAM] Запуск эксперемента 4.1 [PROGRAM]" << endl;
				cout << "Пожалуйста, дождитесь завершения эксперемента! Не закрывайте консоль!" << endl << endl;

				experiment4_1();

				cout << "\nГотово. С результатами эксперемента можно ознакомится в файле 'timeForExperiment4_1.txt'";
				cout << "\nНажмите на любую кнопку, чтобы вернуться назад..." << endl;

				ch = _getch();
				break;
			case 2:
				system("cls");

				cout << "[PROGRAM] Запуск эксперемента 4.2 [PROGRAM]" << endl;
				cout << "Пожалуйста, дождитесь завершения эксперемента! Не закрывайте консоль!" << endl << endl;

				experiment4_2();

				cout << "\nГотово. С результатами эксперемента можно ознакомится в файлах: 'timeNaiveForExperiment4_2.txt'"
					 << "и 'timeKMPForExperiment4_2.txt'";
				cout << "\nНажмите на любую кнопку, чтобы вернуться назад..." << endl;

				ch = _getch();
				break;
			case 3:
				system("cls");

				cout << "[PROGRAM] Запуск эксперемента 4.3 [PROGRAM]" << endl;
				cout << "Пожалуйста, дождитесь завершения эксперемента! Не закрывайте консоль!" << endl << endl;

				experiment4_3();

				cout << "\nГотово. С результатами эксперемента можно ознакомится в файле 'timeNaiveForExperiment4_3.txt'"
					 << "и 'timeKMPForExperiment4_3.txt'";
				cout << "\nНажмите на любую кнопку, чтобы вернуться назад..." << endl;

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
			cout << "\nДо новых встречь!" << endl;
			break;
		}
		default:
			break;
		}
	}
	return 0;
}