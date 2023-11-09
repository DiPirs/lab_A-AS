#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>
#include <random>

#include "workOfFile.h"

using namespace std;

vector <int> index;
int* pi;

string generateWord(const int& alphabetSize, const string& alphabet, const int& sizeWord) {

	srand(time(nullptr));
	random_device random;
	mt19937 gen(random());

	uniform_int_distribution <int> dis(0, alphabetSize - 1);

	string word;

	for (int i = 0; i < sizeWord; i++)
	{
		int randomIndex = dis(gen);
		word += alphabet[randomIndex];
	}

	return word;
}

string genRepeatWord(const string& word, const int& k) {

	string result;

	for (int i = 0; i < k; i++)
	{
		result += word;
	}

	return result;
}

void naiveStringAlgoritm(const string &text, const string &paragraph) {

	int n = text.length();
	int m = paragraph.length();

	auto startTime = chrono::high_resolution_clock::now();

	for (int i = 0; i <= n - m; i++)
	{
		if (text.substr(i, m) == paragraph)
			index.push_back(i);
	}

	auto endTime = chrono::high_resolution_clock::now();

	chrono::duration <double> totalTime = endTime - startTime;


	ofstream outputFileInTime("outTimeFirstAlgoritm.txt");

	outputFileInTime << "Время работы 'Наивного' алгоритма: " << totalTime.count() << " секунд.";

	writtingResultToFile("outResultFirstAlgoritm.txt", index);
}

void prefixFunction(const string& p) {

	int m = p.length();

	pi = new int[m];
	pi[0] = 0;

	int j = 0, i = 1;

	while (i < m)
	{
		if (p[j] == p[i])
		{
			pi[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			if (j == 0)
			{
				pi[i] = 0;
				i++;
			}
			else
			{
				j = pi[j - 1];
			}
		}
	}
}

void kmpAlgoritm(const string& text, const string& paragraph) {
	
	index.clear();
	
	int n = text.length();
	int m = paragraph.length();

	auto startTime = chrono::high_resolution_clock::now();

	prefixFunction(paragraph);

	int i = 0;
	int j = 0;

	while (i < n)
	{
		if (text[i] == paragraph[j])
		{
			i++;
			j++;
			if (j == m)
				index.push_back(i - m);
		}
		else
		{
			if (j > 0)
				j = pi[j - 1];
			else
				i++;
		}
	}

	auto endTime = chrono::high_resolution_clock::now();

	chrono::duration <double> totalTime = endTime - startTime;

	ofstream outputFileInTime("outTimeSecondAlgoritm.txt");

	outputFileInTime << "Время работы алгоритма 'Кнута-Морриса-Пратта': " << totalTime.count() << " секунд.";

	writtingResultToFile("outResultSecondAlgoritm.txt", index);
}

void experiment4_1() {
	ofstream outTimeExperement4_1;
	outTimeExperement4_1.open("timeForExperiment4_1.txt", std::fstream::app);

	string text_old = "ab", paragraph_old = "ab";

	string text_new, paragraph_new;

	for (int k = 1; k <= 1001; k += 10)
	{	
		int persent = k / 10;
		if (persent % 10 == 0)
		{
			cout << "Готово на " << persent << "%..." << endl;
		}

		text_new = genRepeatWord(text_old, 1000 * k);
		paragraph_new = genRepeatWord(paragraph_old, k);

		auto startExperement = chrono::high_resolution_clock::now();

		kmpAlgoritm(text_new, paragraph_new);

		auto endExperement = chrono::high_resolution_clock::now();

		chrono::duration <double> totalTimeExperement = endExperement - startExperement;
		outTimeExperement4_1 << k << " " << totalTimeExperement.count() << endl;
	}
}

void experiment4_2() {

	ofstream outTimeNaiveAlgoritm;
	ofstream outTimeKMPAlgoritm;

	outTimeNaiveAlgoritm.open("timeNaiveForExperiment4_2.txt", std::fstream::app);
	outTimeKMPAlgoritm.open("timeKMPForExperiment4_2.txt", std::fstream::app);

	int alphabetSizeText = 2;			
	int wordLenghtText = 1000001;		

	string alphabetText = "ab";			
	string paragraph, paragraph_init = "a";

	string text = generateWord(alphabetSizeText, alphabetText, wordLenghtText);

	for (int m = 1; m <= 1000001; m += 10000)
	{
		int persent = (m - 1) / 10000;
		if (persent % 10 == 0)
		{
			cout << "Готово на " << persent << "%..." << endl;
		}

		paragraph = genRepeatWord(paragraph_init, m);

		// =========================================================
		auto startTimeNaive = chrono::high_resolution_clock::now();

		naiveStringAlgoritm(text, paragraph);

		auto endTimeNaive = chrono::high_resolution_clock::now();

		chrono::duration <double> totalTimeNaive = endTimeNaive - startTimeNaive;
		outTimeNaiveAlgoritm << m << " " << totalTimeNaive.count() << endl;
		// =========================================================
		auto startTimeKMP = chrono::high_resolution_clock::now();

		kmpAlgoritm(text, paragraph);

		auto endTimeKMP = chrono::high_resolution_clock::now();

		chrono::duration <double> totalTimeKMP = endTimeKMP - startTimeKMP;
		outTimeKMPAlgoritm << m << " " << totalTimeKMP.count() << endl;
		// =========================================================
	}
}

void experiment4_3() {
	ofstream outTimeNaiveAlgoritm;
	ofstream outTimeKMPAlgoritm;

	outTimeNaiveAlgoritm.open("timeNaiveForExperiment4_3.txt", std::fstream::app);
	outTimeKMPAlgoritm.open("timeKMPForExperiment4_3.txt", std::fstream::app);

	string text;
	string paragraph = "aaaaa";

	for (int h = 1; h <= 1000001; h += 10000)
	{
		int persent = (h - 1) / 10000;
		if (persent % 10 == 0)
		{
			cout << "Готово на " << persent << "%..." << endl;
		}

		text = genRepeatWord(paragraph + "b", h);

		// =====================================================
		auto startTimeNaive = chrono::high_resolution_clock::now();

		naiveStringAlgoritm(text, paragraph);

		auto endTimeNaive = chrono::high_resolution_clock::now();

		chrono::duration <double> totaltimeNaive = endTimeNaive - startTimeNaive;
		outTimeNaiveAlgoritm << h << " " << totaltimeNaive.count() << endl;
		// ======================================================
		auto startTimeKMP = chrono::high_resolution_clock::now();

		kmpAlgoritm(text, paragraph);

		auto endTimeKMP = chrono::high_resolution_clock::now();

		chrono::duration <double> totalTimeKMP = endTimeKMP - startTimeKMP;
		outTimeKMPAlgoritm << h << " " << totalTimeKMP.count() << endl;
		// ======================================================
	}



}

