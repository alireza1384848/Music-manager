#pragma once
#include <string>
#include"LInkedlist.h"
#include"Music.h"
using namespace std;
class Musician
{
private:
	static int lastid;
	int id;
	string name;
	Linkedlist<Music> *musics;
public:
	Musician(string name);
	Music* AddMusic(string name, string text, int year);
	void deleteMusic(int id);//throw excp if cant find
	bool findMusic(string name);
	int findword(int musicid,string word);
	int countword(int musicid,string word);
	int getId();
	void print();
};

