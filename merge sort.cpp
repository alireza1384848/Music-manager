#include <iostream>
#include<array>
#include"merge sort.h"
using namespace std;


void Merge_Stick(int* const a, int p, int s, int f, int len) {
	int n1 = p + s - p;
	int n2 = s + f - s + 1;
	int* newarr = new int[f + 1];
	for (int i = 0; i <= len; i++) {
		newarr[i] = a[i];
	}

	int start = p;
	for (int i = start; i <= f; i++) {
		if (a[p] > a[s] && s < n2) {
			newarr[i] = a[s];
			s++;
		}
		else if (a[p] <= a[s] && p < n1) {
			newarr[i] = a[p];
			p++;
		}
		else if (a[p] > a[s] && p < n1) {
			newarr[i] = a[p];
			p++;
		}
		else if (a[p] <= a[s] && s < n2) {
			newarr[i] = a[s];
			s++;
		}

	}

	for (int i = start; i <= f; i++) {
		a[i] = newarr[i];
	}
	

}

void Mergesort(int* const a, int s, int f, int len) {
	
	if (s < f) {
		int q = (f + s) / 2;
		Mergesort(a, s, q, len);
		Mergesort(a, q + 1, f, len);
		Merge_Stick(a, s, q + 1, f, len);
	}
	else {
		return;
	}
}