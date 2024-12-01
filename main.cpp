
#include"Set.h"
#include"Queue.h"
#include"SuffixArray.h"
int main()
{
	SparseSet a(10, 3);
	SuffixArray my("bananasalammanazibronkarpreyrfrefere");
	my.print();
	cout << my.find("bro");
}
