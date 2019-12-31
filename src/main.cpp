#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
#include <utility>

using ull = unsigned long long;
using namespace std;

const string ERRORPARAMETER = "error: parameter\npass the file input";
const string ERROROPENING = "error: opening";
const wchar_t SEPARATOR = ',';

void InserLinesTokens(vector<wstring>& tokens, map<wstring, ull>& dict) {
	for (wstring& token : tokens) {
		map<wstring, ull>::iterator it = dict.find(token);
		if (it != dict.end())(it->second)++;
		else dict.insert(pair<wstring, ull>(move(token), 1));
	}
}

void Tokenize(wstring&& line, vector<wstring>& tokens) {
	tokens.clear();
	wstring::iterator prev;
	wstring::iterator pos = find_if(line.begin(), line.end(), isalpha);

	while (pos != line.end()) {
		prev = find_if_not(pos, line.end(), isalpha);
		wstring token(pos, prev);
		transform(token.begin(), token.end(), token.begin(), ::tolower);
		pos = find_if(prev, line.end(), isalpha);
		tokens.push_back(move(token));
	}
}

void CountWords(wifstream& file, map<wstring, ull>& dict) {
	vector<wstring> tokens(1000);
	wstring line;
	while (getline(file, line)) {
		Tokenize(move(line), tokens);
		InserLinesTokens(tokens, dict);
	}
	tokens.clear();
}

wifstream ReadFile(int ac, char* av[]) {
	if (ac != 2) {
		cout << ERRORPARAMETER << endl;
		exit(8);
	}

	wifstream file;
	file.open(av[1]);

	if (file.is_open() == false) {
		cout << ERROROPENING << endl;
		exit(1);
	}

	return std::move(file);
}

void ShowDictionary(const map<wstring, ull>& dict) {
	for (pair<wstring, ull>&& w : dict) {
		wcout << w.second << SEPARATOR << w.first << endl;
	}
}

int main(int ac, char* av[]) {
	wifstream file = ReadFile(ac, av);
	map<wstring, ull> dict;
	CountWords(file, dict);
	file.close();
	ShowDictionary(dict);
	dict.clear();
	   
	return 0;
}
