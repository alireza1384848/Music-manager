#include<iostream>
class SparseSet
{
public:
	SparseSet(int maxval,int capacity);
	~SparseSet();
	void insert(int val);
	void erase(int val);
	int search(int tar);
	void clear();
	void sort();
	void print();
private:
	int* dence;
	int* sparse;
	int MaxVal;
	int capacity;
	int currnum;
};
