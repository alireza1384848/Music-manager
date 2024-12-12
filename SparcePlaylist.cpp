#include "SparcePlaylist.h"
#include <stdexcept>
#include <iostream>
int SparcePlaylist::lastid = 0;
SparcePlaylist::SparcePlaylist(string Name, int maxval, int capacity)
{
	name = Name;
	id = ++lastid;
	MaxVal = maxval;
	this->capacity = capacity;
	this->dence = new Music * [capacity] {nullptr};
	this->sparse = new int[maxval] {-1};
	currnum = 0;

}


SparcePlaylist::~SparcePlaylist()
{
	delete[] this->dence;
	delete[] this->sparse;
}

void SparcePlaylist::insert(Music* newmu)
{
	if (currnum >= capacity || newmu->id() > MaxVal)
	{
		throw overflow_error("Set Overflow");
	}
	dence[currnum] = new Music(*newmu);
	sparse[newmu->id()] = currnum;
	currnum++;
}

void SparcePlaylist::erase(int id)
{
	if (id >= capacity || currnum <= 0 || sparse[id]==-1)throw std::invalid_argument("Unknown Value");

	int delpos = sparse[id];
	Music* temp = dence[delpos];
	//delete and sort
	for (size_t i = delpos; i < currnum - 1; i++)
	{
		sparse[dence[i + 1]->id()] = i;
		dence[i] = dence[i + 1];
	}
	try
	{
	delete temp;
	}
	catch (const std::exception&)
	{

	}
	
	currnum--;
}

void SparcePlaylist::search(int id)
{
	if (id< MaxVal&& sparse[id]!=-1 &&sparse[id] < currnum && dence[sparse[id]]->id() == id)
	{
		dence[sparse[id]]->print();
		return;
	}
	cout << "Music Not Found!";
}


void SparcePlaylist::findmusic(string name)
{
}

void SparcePlaylist::delmusic(int musicionid, int musicid)
{
}

int SparcePlaylist::getid()
{
	return id;
}

void SparcePlaylist::Print()
{
	cout << "************************playlist " << name << " info************************" << endl;
	cout << "ID : " << id << endl;
	cout << "Name : " << name << endl;
	cout << "*********************Musics*********************"<<endl;
	for(int i=0; i<currnum;i++)
	{
		dence[i]->print();
	}
	cout << endl;

}

int SparcePlaylist::Size()
{
	return currnum ;
}

void SparcePlaylist::Quicksortinyear(int low , int high)
{
	
	//(*Sortedset)[4]->year();
	
	if (low < high) {
		int pi = partitions(Sortedset, low, high);

		Quicksortinyear(pi + 1, high);
		Quicksortinyear(low, pi - 1);
	}
}
void SparcePlaylist::cpyset()
{
	Sortedset = new Music*[capacity];
		for (int i = 0; i < Size(); i++)
			Sortedset[i] = new Music(*(dence[i]));
}
void swap(Music**& arr, int tar, int des)
{
	Music* temp = (arr)[tar];
	(arr)[tar] = (arr)[des];
	(arr)[des] = temp;
}
int SparcePlaylist::partitions(Music**& arr, int low, int high)
{
	int pivot = (arr)[high]->year();

	int i = low - 1;
	for (int j = low; j <high ; j++)
	{
		int jyear = (arr)[j]->year();
		if (jyear < pivot)
		{
			i++;
			swap(arr, i, j);
		}

	}

	swap(arr, i + 1, high);
	return i + 1;

}

void SparcePlaylist::printsort()
{
	for(int i=0;i<this->Size();i++)
	{
		(Sortedset)[i]->print();
		cout << endl;
	}

}


