#pragma once
#include<string>
using namespace std;
struct suffix{
	int index;
	int rank[2];
};
class SuffixArray
{
private:
	suffix* suffixes;
	string mystr;
	int Size;

public:
	SuffixArray(string arr);
	void Radixsort(suffix* suffixes,int size);
	void countsort(suffix* suffixes, int size, int rank);
	int find(string target);
	int occurance(string target);
	int lowerbond(string target);
	int higherbond(string target);
	void print();


};

