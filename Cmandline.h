#pragma once
#include"Set.h"
#include"Musician.h"
#include"SuffixArray.h"
#include"SparcePlaylist.h"
#include"Queue.h"
using namespace std;
class Cmandline
{
	SparseSet * Musicians;
	Linkedlist<Music *> Musics;
	Linkedlist <SparcePlaylist *> AllPlaylist;
	Queue<SparcePlaylist*> playQueue;

public:
	Cmandline();
	string* getcommand();
	void proccescommand();
	Music* findMusic(int id);
	int findMusicind(int id);
	void findprintPL(int id);
	int findplayid(int id);

};

