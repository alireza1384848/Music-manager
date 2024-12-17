#include "Set.h"
#include<exception>
#include"merge sort.h"
using namespace std;
SparseSet::SparseSet(int maxval, int capacity)
{
	MaxVal = maxval;
	this->capacity = capacity;
	this->dence = new Musician * [capacity] {nullptr};
	this->sparse = new int[maxval];
	for (int i = 0; i <= MaxVal; i++)sparse[i] = -1;
	currnum = 0;
}

SparseSet::~SparseSet()
{
	delete[] this->dence;
	//delete this->sparse;
}

void SparseSet::insert(string name)
{
	Musician* temp = new Musician(name);
	if (currnum >= capacity || temp->getId() > MaxVal) 
	{
		delete temp;
		throw overflow_error("Set Overflow");
	}
	dence[currnum] = temp;
	sparse[temp->getId()] = currnum;
	currnum++;
}

void SparseSet::erase(int id)
{
	if ( id >= capacity || currnum<=0)throw std::invalid_argument("Unknown Value");
	
	int delpos  = sparse[id];
	Musician* temp = dence[delpos];
//delete and sort
	for (size_t i =delpos ; i < currnum-1; i++)
	{
		sparse[dence[i+1]->getId()] = i;
		dence[i] = dence[i + 1];
	}
	delete temp;
	currnum--;
}
void SparseSet::search(int id)
{
	if (sparse[id] < currnum && dence[sparse[id]]->getId() == id)
	{
		dence[sparse[id]]->print();
		return;
	}
	cout << "User Not Found";
}

void SparseSet::findmusic(string name)
{
	for (size_t i = 0; i<currnum ; i++)
	{
		if(dence[i]->findMusic(name))
		{
			return;
		}
	}
	cout << "Music don't Exist!"<<endl;
}

void SparseSet::delmusic(int musicionid, int musicid)
{
	if (sparse[musicionid] != -1)
	{
		dence[sparse[musicionid]]->deleteMusic(musicid);
		return;
	}
	throw out_of_range("id not found");

}

Music* SparseSet::Addmusic(int musicionid, string name, string text, int year)
{
	if (sparse[musicionid] != -1)
	return dence[sparse[musicionid]]->AddMusic(name,text,year);
	throw out_of_range("id not found");

}

void SparseSet::findword(int musicionid, int musicid, string text)
{
	if (sparse[musicionid] != -1)
	{
		cout << dence[sparse[musicionid]]->findword(musicid, text) << endl;
		return;
	}

	throw out_of_range("id not found");

}

void SparseSet::countword(int musicionid, int musicid, string text)
{
	if (sparse[musicionid] != -1)
	{
		cout << dence[sparse[musicionid]]->countword(musicid, text) << endl;
		return;
	}
	throw out_of_range("id not found");
}

void SparseSet::clear()
{
	currnum = 0;
}

int SparseSet::lastid()
{
	return dence[currnum-1]->getId();
}

void SparseSet::print()
{
	for (size_t i = 0; i < currnum; i++)
	{
		; dence[i]->print(); cout<<endl;
	}

}
