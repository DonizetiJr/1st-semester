const int N = 1001;
int g[N];

int find (int x) {
    if (x == g[x]) return x;
    return g[x] = find ( g[x] );
}

void junta (int a, int b) {
    int aa = find (a);
    int bb = find (b);
    if (aa != b) g[aa] = bb;
}

int main (void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) g[i] = i;
    // ordena as arestas
    // vai juntando ate 0 e o n-1 estarem conectados
    // a resposta vai ser o peso da aresta qye conectou por ultimo
}