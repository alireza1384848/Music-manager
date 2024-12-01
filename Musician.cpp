#include "Musician.h"
int Musician::lastid = 0;
Musician::Musician(string name)
{
	id = ++lastid;
	this->name = name;
}

void Musician::AddMusic(string name, string text, int year)
{
	Music* ms = new Music(name,text, year);
	musics.push_back(*ms);
}

void Musician::deleteMusic(int id)
{
	for (size_t i = 0; i < musics.size(); i++)
	{
		if(musics[i].id()==id)
		{
			musics.erase(i);
			return;
		}
	}
	throw invalid_argument("Can't find index");
}

void Musician::print()
{
	cout << "Id:" << id << "  Name:" << name <<"  Number of Songs:"<<musics.size();
	//musics[1].print();

}

