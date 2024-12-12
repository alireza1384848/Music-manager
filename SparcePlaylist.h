#pragma once
#include"Music.h"
#include<string>
using namespace std;
class SparcePlaylist
{
public:

	SparcePlaylist(string Name, int maxval=100,int capacity=100);
	~SparcePlaylist();
	void insert(Music* newmu);
	void erase(int id);
	void search(int id);
	void findmusic(string name);
	void delmusic(int musicionid, int musicid);
	int getid();
	void Print();
	int Size();
	void Quicksortinyear(int low, int high);
	void cpyset();
	int partitions(Music ** &arr,int low , int high);
	void printsort();
private:
	Music ** dence;
	Music ** Sortedset;
	int* sparse;
	int MaxVal;
	int capacity;
	int currnum;
	string name;
	int id;
	static int lastid;
};

