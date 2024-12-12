#pragma once
#include<string>
#include"SuffixArray.h"
using namespace std;
class Music
{
private:
	static int lastid;
	int Id;
	int	Pub_year;
	string name;
	string Text;
	SuffixArray suffarr;// must be lower alphabet and without any more charater no number

public:
	Music(string name, string text, int year);
	int id();
	int year();
	string getName();
	int findword(string word);
	int countword(string word);
	void print();
};

