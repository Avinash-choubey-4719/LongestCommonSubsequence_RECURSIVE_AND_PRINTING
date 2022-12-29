#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return a>b?a:b;
}

int lcs(string x, string y, int m, int n){
    if(m == 0 || n == 0){
        return 0;
    }

    if(x[m - 1] == y[n - 1]){
        return 1 + lcs(x, y, m - 1, n - 1);
    }

    if(x[m - 1] != y[n - 1]){
        return max(lcs(x, y, m - 1, n), lcs(x, y, m, n - 1));
    }
}

int main(){
    string x = "geeks";
    string y = "geks";
    int m = x.length();
    int n = y.length();

    int result = lcs(x, y, m, n);
    cout<<result<<endl;
    return 0;
}