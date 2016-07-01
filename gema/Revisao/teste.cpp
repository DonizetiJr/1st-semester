#include <bits/stdc++.h>

using namespace std;


int M[2000][2000];

int knapsack(int value[], int weight[], int s, int n)
{      
  for(int i = 1; i <= s; i++){
    for(int j = 0; j <n; j++){
      if(j > 0){
        M[j][i] = M[j-1][i];
        if (weight[j] <= i)
          M[j][i] = max(M[j][i], M[j-1][i-weight[j]]+value[j]);
      }
      else{
        M[j][i] = 0;
        if(weight[j] <= i)
          M[j][i] = max(M[j][i], value[j]);
      }
    }

  }        
  return M[n-1][s];
}  

int main()
{
    int s, n;
    cin >> s >> n;
    
    int* value = new int[n+1];
    int* weight = new int[n+1];
    for ( int i = 0; i < n; i++) {
        cin>>weight[i]>>value[i];
    }

    cout<<knapsack(value,weight,s,n)<<endl;
    return 0;
} 