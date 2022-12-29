#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return a>b?a:b;
}

string printLcs(string x, string y, int m, int n){
    int t[m + 1][n + 1];

    memset(t, 0, sizeof(t));

    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){

            if(x[i - 1] == y[j - 1]){
                t[i][j] = 1 + t[i - 1][j - 1];
            }

            else if(x[i - 1] != y[j - 1]){
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    int i = m, j = n;
    string res = "";
    while(i > 0 && j > 0){
        if(x[i - 1] == y[j - 1]){
            res.push_back(x[i - 1]);
            i--;
            j--;
        }

        else if(t[i - 1][j] > t[i][j - 1]){
            i--;
        }

        else{
            j--;
        }
    }

    return res;
}

int main(){

    string x = "geeks";
    string y = "geks";
    int m = x.length();
    int n = y.length();

    string result = printLcs(x, y, m, n);
    cout<<result<<endl;
    return 0;
}