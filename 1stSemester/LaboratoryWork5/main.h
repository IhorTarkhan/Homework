#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main_Lab_1_5() {
	map<string, int> mapOfWords;

	string wordRead;
	int numberRead;

	ifstream file("text.txt");
	while (!file.eof()) {
		file >> wordRead;
		file >> numberRead;
		mapOfWords.insert(make_pair(wordRead, numberRead));
	}
	file.close();

	string line;
	ifstream file2("text2.txt");
	while (getline(file2, line)) {
		int valueOfLine = 0;
		while (line.find(" ") != string::npos) {
			string word = line.substr(0, line.find(" "));
			line = line.substr(line.find(" ") + 1);

			if (mapOfWords.find(word) != mapOfWords.end()) {
				valueOfLine += mapOfWords.find(word)->second;
			}
		}
		valueOfLine += mapOfWords.find(line)->second;
		cout << valueOfLine << endl;
	}
	file2.close();
    return 0;
}
