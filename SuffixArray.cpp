#include "SuffixArray.h"
#include <iostream>

int StrnCmp(string first, string sec, int max)
{
	for (size_t i = 0; i < max; i++)
	{
		if (first[i] > sec[i])
		{
			return 1;
		}
		else if (first[i] < sec[i])
		{
			return -1;
		}
	}
	return 0;
}

SuffixArray::SuffixArray(string arr)
{
	mystr = arr;
	int arrsize = arr.size();
	Size = arrsize;
	suffixes = new suffix[arrsize];
	//made suffixes
	for (int i = 0; i < arrsize; i++)
	{
		//index from 0 rank from 1
		suffixes[i].index = i;
		if (mystr[i] == ' ')
			suffixes[i].rank[0] = 0;
		else
		{
			suffixes[i].rank[0] = arr[i] - 'a' + 1;
		}
		if (i + 1 < arrsize && mystr[i+1]!=' ')
			suffixes[i].rank[1] = arr[i + 1] - 'a' + 1;
		else
			suffixes[i].rank[1] = 0;
	}
	this->Radixsort(suffixes, arrsize);

	int* index = new int[arrsize];


	for (size_t k = 4; k < arrsize * 2; k *= 2)
	{
		int rank = 1;
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		index[suffixes[0].index] = 0;
		for (int i = 1; i < arrsize; i++)
		{
			if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i - 1].rank[1])
			{
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = rank;
			}
			else
			{
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = ++rank;
			}
			index[suffixes[i].index] = i;
		}
		for (int i = 0; i < arrsize; i++)
		{
			int nextind = suffixes[i].index + k / 2;
			suffixes[i].rank[1] = (nextind < arrsize) ? suffixes[index[nextind]].rank[0] : 0;
		}
		this->Radixsort(suffixes, arrsize);
	}
}

void SuffixArray::Radixsort(suffix* suffixes, int size)
{
	this->countsort(this->suffixes, size, 1);
	this->countsort(this->suffixes, size, 0);
}

void SuffixArray::countsort(suffix* suffixes, int size, int rank)
{
	suffix* out = new suffix[size];
	int* count;
	int cousize = 0;
	if (size > 27) {
		count = new int[size+2] {0};
		 cousize = size+2;
	}
	else
	{
		count = new int[27] {0};
		cousize = 27;
	}
	for (int i = 0; i < size; i++)
	{
		count[suffixes[i].rank[rank]]++;
	}
	for (int i = 1; i < cousize; i++)
	{
		count[i] += count[i - 1];
	}
	for (int j = size - 1; j >= 0; j--)
	{
		out[count[suffixes[j].rank[rank]] - 1] = suffixes[j];
		count[suffixes[j].rank[rank]]--;
	}
	delete[](suffixes);
	this->suffixes = out;
}

int SuffixArray::find(string target)
{
	int tar_size = target.size();
	int right = Size - 1;
	int left = 0;
	int countites = 0;
	while (right >= left)
	{
		int mid = left + ((right - left) / 2);
		int res = StrnCmp(target, mystr.substr(suffixes[mid].index), tar_size);

		if (res == 0)
		{
			return suffixes[mid].index;
		}
		else if (res < 0)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return -1;
}

int SuffixArray::occurance(string target)
{
	return higherbond(target) - lowerbond(target);
}

int SuffixArray::higherbond(string target)
{
	int mainres = 0;
	int res = 0;
	int left = 0;
	int Right = Size-1;
	while (Right>=left)
	{
		int mid = left + ((Right - left) / 2);
		res = StrnCmp(target, mystr.substr(suffixes[mid].index),target.size());
		if(res<0)
		{
			Right = mid - 1;
		}
		else
		{
			mainres = mid;
			left = mid + 1;
		}
	}
	return mainres;
}

int SuffixArray::lowerbond(string target)
{
	int mainres = 0;
	int res = 0;
	int left = 0;
	int Right = Size - 1;
	while (Right >= left)
	{
		int mid = left + ((Right - left) / 2);
		res = StrnCmp(target, mystr.substr(suffixes[mid].index), target.size());
		if (res <= 0)
		{
			Right = mid - 1;
		}
		else
		{
			mainres = mid;
			left = mid + 1;
		}
	}
	return mainres;

}

void SuffixArray::print()
{
	for (size_t i = 0; i < Size; i++)
	{
		std::cout << i + 1 << "." << mystr.substr(suffixes[i].index) << endl;

	}


}
