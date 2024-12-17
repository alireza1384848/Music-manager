#include "Musician.h"
int Musician::lastid = 0;
Musician::Musician(string name)
{
	id = ++lastid;
	this->name = name;
	musics = new Linkedlist<Music>();
}


Music* Musician::AddMusic(string name, string text, int year)
{
	Music* ms = new Music(name,text, year);
	musics->push_back(*ms);
	return ms;
}

void Musician::deleteMusic(int id)
{
	for (size_t i = 0; i < musics->size(); i++)
	{
		if((*musics)[i].id()==id)
		{
			musics->erase(i);
			return;
		}
	}
	throw invalid_argument("Can't find index");
}

bool Musician::findMusic(string name)
{
	bool canfind = false;
	for (size_t i = 0; i < musics->size(); i++)
	{
		if ((*musics)[i].getName() == name)
		{
			(*musics)[i].print();
			canfind= true;
		}
	}
	return canfind;

}

int Musician::findword(int musicid, string word)
{
	for (size_t i = 0; i < musics->size(); i++)
	{
		if((*musics)[i].id()==musicid)
		{
			return (*musics)[i].findword(word);
		}
	}
}

int Musician::countword(int musicid, string word)
{
	for (size_t i = 0; i < musics->size(); i++)
	{
		if ((*musics)[i].id() == musicid)
		{
			return (*musics)[i].countword(word);
		}
	}
}

int Musician::getId()
{
	return id;
}

void Musician::print()
{
	cout << "Id:" << id << "  Name:" << name <<"  Number of Songs:"<<musics->size();
	//musics[1].print();

}

