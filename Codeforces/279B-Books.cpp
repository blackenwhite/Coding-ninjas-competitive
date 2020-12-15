#include <bits/stdc++.h>
using namespace std;
#define ll long
const int N=100005;

ll a[N];

void solve(){
  ll n,t;
  cin>>n>>t;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  ll sum=0;
  int ans=INT_MIN;
  int j=-1;
  for(int i=0;i<n;i++){
    if(sum+a[i]<=t){
      sum+=a[i];
    }else{
      sum+=a[i];
      while(sum>t){
        j++;
        sum-=a[j];
      }

    }
    ans=max(ans,i-j);
  }
  cout<<ans<<endl;
}

int main(){
  solve();
}
