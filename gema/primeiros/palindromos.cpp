#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < n/2; i++){
		ans += s[i] != s[s.size() - 1 - i];
	}
	cout << ans << endl;
	return 0;
}

/*
OPÇÃO EM SOLUÇÃO LINEAR (menor tempo por realizar apenas uma vez
								a cada string):

bool palindromo(string s) {
	for(int i =0; i < s,size()/2; ++1) {
		if(s[i] != s[s.size()]-1-i) return false;
	}
	return true;
}


*/