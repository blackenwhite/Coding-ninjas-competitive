#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
int main(){
  int t;
  cin>>t;
  string s;
  while(t--){
    cin>>s;
    if(mp.find(s)==mp.end()){
      cout<<"OK"<<endl;
      mp[s]++;
    }else{
      cout<<s<<mp[s]<<endl;
      mp[s]++;
    }
  }
}
