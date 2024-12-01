#include "Set.h"
#include<exception>
using namespace std;
SparseSet::SparseSet(int maxval, int capacity)
{
	MaxVal = maxval;
	this->capacity = capacity;
	this->dence = new int[capacity] ;
	this->sparse = new int[maxval] ;
	currnum = 0;
}

SparseSet::~SparseSet()
{
	delete[] this->dence;
	delete[] this->sparse;
}

void SparseSet::insert(int val)
{
	if (this->search(val) == -1)return;
	if (currnum>=capacity || val>MaxVal)throw overflow_error("Set Overflow");
	dence[currnum] = val;
	sparse[val] = currnum;
	currnum++;
}

void SparseSet::erase(int val)
{
	//TODO : sort it
	if (search(val) == -1)throw std::invalid_argument("Unknown Value");
	int temp = dence[currnum];
	dence[sparse[val]] = temp;
	sparse[temp] = sparse[val];
	currnum --;
}

int SparseSet::search(int tar)
{
	if (tar > MaxVal)return -1;
	if (sparse[tar] < currnum || dence[sparse[tar]] == tar)
		return sparse[tar];
	return -1;
}

void SparseSet::clear()
{
	currnum = 0;
}
