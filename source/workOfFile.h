#include <iostream>
#include <vector>

using namespace std;

void writtingResultToFile(const string& fileName, vector <int> &index) {

	ofstream outputFile(fileName);
	if (index.size() == 0)
	{
		outputFile << "����� �� ������ � ������";
	}
	else
	{
		outputFile << "����� ��� ������ � ������. �������, ������� � ������� ���������� ����������: ";
		for (int k = 0; k < index.size(); k++)
			outputFile << index[k] << " ";
	}
}