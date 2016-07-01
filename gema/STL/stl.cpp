#include <bits/stdc++.h>

using namespace std;

/* BIBLIOTECA STL
	vector #include <vector>
	map
	stack
	set
	queue
	priority_queue
*/

struct Point {
	int x, y;

	Point() { // caso não dê valores pra x e y
		x = 1;
		y = 2;
	}
	Point (int x, int y) {
		this->x = x;
		this->y = y;
	}

	int squaredDistanceTo (Point p) {
		return (x-b.x)*(x-b.x)*(y-b.y)*(y-b.y);
	}
	bool operator < (Point b) const {  //para conseguir comparar dois pontos com map
		if (x != b.x) return x < b.x;
		return y < b.y;
	}
};

int main (void) {


/*

========================================
Fila

queue<int> s;
s.push(1); //coloca o elemento na fila
s.push(2);
s.push(3);
cout << s.front << endl; 
s.pop(); 
s.empty(); esvazia a fila
cout << s.front() << endl;

========================================
Stack:

stack<int> s;
s.push(1); //coloca o elemento na pilha
s.push(2);
s.push(3);
cout << s.top << endl; retorn o ultimo elemento da pilha
s.pop(); tira o elemento do topo
s.empty(); esvazia a pilha
cout << s.top() << endl;

=========================================
Declarar e ordenar vector com C++ 11.0:

vector<int> = {11, 15, 16, 19};
sort (v.begin(), v.end());

for (auto x : v) {
	cout << x << " ";
}

==========================================
Map:

	int n;
	cin >> n;
	map <string, int> m; (<tipo da chave, localização da chave>)
	m["bla"] = 11;

-----------------------------------------
	(compilar com -std=c++0x)

	
	map <Point, string> m;
	m[Point(1,2)] = "oito";
	m[Point(3,4)] = "cinco";

	for(auto it : m) {
		cout << it.first.x << " " << it.first.y << " " << it.second << endl;
	}
	
==========================================
Vector:	

	vector <Point> v;
	Point a;
	a.x = 1;
	a.y = 2;
	v.push_nack (a); 
	cout << v[0].x <<  << v[0].y << endl;
	cout << v.size() << endl;

-----------------------------------------

	int n;
	cin >> n;
	vector <string> v;
	for (int i=0; i<n; i++) {
		string x;
		cin >> x;
		v.push_back(x);
	}
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << endl;
	}

=========================================

	Point p,q;
	cin >> p.x >> p.y;
	cin >> q.x >> q.y;
	cout << q.squareDistanceTo (p) << endl;
*/
}