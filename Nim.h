#pragma once
#include <vector>
using namespace std;
class Nim
{
public:
	Nim();
	~Nim();
	void printmenu();
	void twoplayers();
	void ai();
	void files();
private:
	void showmas(char*, int, char*, int, char*, int);
	void showai(vector<char>, vector<char>, int, int);
	void showai(vector<char>, vector<char>, vector<char>, int, int, int);
	void showai(vector<char>, vector<char>, vector<char>, vector<char>, int, int, int, int);
	void fromfile();
	void removefile();
};

