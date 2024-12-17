#include<iostream>
#include"Musician.h"
class SparseSet
{
public:
	SparseSet(int maxval, int capacity);
	~SparseSet();
	void insert(string name);
	void erase(int id);
	void search(int id);
	void findmusic(string name);
	void delmusic(int musicionid, int musicid);
	Music* Addmusic(int musicionid, string name, string text, int year);
	void findword(int musicionid, int musicid, string text);
	void countword(int musicionid, int musicid, string text);
	void clear();//TODO : not impelemnted
	int lastid();
	void print();
private:
	Musician ** dence;
	int* sparse;
	int MaxVal;
	int capacity;
	int currnum;
};
