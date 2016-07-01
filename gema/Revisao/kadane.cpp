#include <iostream>
#include <climits>

using namespace std;

int a[101][101];

int kadane2D(int n) {
    int *columnSum = new int[n];
    int s=INT_MIN,S=INT_MIN,t;
    for(int row = 0; row<n; row++) {
        for(int i=0; i<n; i++) columnSum[i] = 0;
        for(int x = row; x<n; x++) {
            s = INT_MIN;
            t = 0;
            for(int i=0; i<n; i++) {
                columnSum[i]+=a[x][i];
                t+=columnSum[i];
                if(t>s)
                    s = t;
                if(t<0)
                    t = 0;
            }
            if(s>S)
                S = s;
        }
    }
    delete [] columnSum;
    return S;
}
int main( void )
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<kadane2D(n)<<endl;
    return 0;
}