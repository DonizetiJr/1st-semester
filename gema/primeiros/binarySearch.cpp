#include <bits/stdc++.h>

using namespace std;


vector <int> v = {1, 14, 22, 26, 30, 44, 56};

bool contains(int x) {
	int lo = 0;
	int hi = v.size()-1;

	if(v[hi] < x) return false;
	
	while(lo != hi) {
		int mi = (hi + lo)/2;
		if(v[mi] >= x) hi = mi; 
		else lo = mi + 1; 
	}
	return v[lo] == x;
}

int main(void) {
	while(1) {
		int k;
		count << contains(k) << endl;
	}
}