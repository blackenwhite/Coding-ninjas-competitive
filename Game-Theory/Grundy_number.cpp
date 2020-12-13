#include<bits/stdc++.h>
using namespace std;

int Mex(unordered_set<int>Set){
    int M=0;
    while(Set.find(M)!=Set.end()){
        M++;
    }
    return M;
}

int calcGrundy(int n){
    if(n==0){
        return 0;
    }
    
    unordered_set<int>Set;
    Set.insert(calcGrundy(n/2));
    Set.insert(calcGrundy(n/3));
    Set.insert(calcGrundy(n/6));
    return Mex(Set);
    
}

int main() {

	int n;
    cin>>n;
    printf("%d",calcGrundy(n));
    return 0;
}
