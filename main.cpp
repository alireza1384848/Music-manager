#include<string>
#include"Set.h"
#include"Musician.h"
#include"Queue.h"
#include"SuffixArray.h"
using namespace std;
int main()
{
	SuffixArray a("ki migere jato    man man man manjatojatojatojato");
	a.print();
	cout << a.occurance(" man ");

}