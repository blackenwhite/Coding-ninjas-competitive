#include <bits/stdc++.h>
using namespace std;  //                       Nabajyoti Majumdar

void buildZ(int* Z, string str){
  int l=0;int r=0;
  int n=str.length();
  for (int i=1;i<n;i++){
    if(i>r){
      l=i;
      r=i;
      while(r<n && str[r-l]==str[r]){
        r++
      }
      Z[i]=r-l;
      r--;
    }else{
      int k=i-l;
      if(Z[k]<=r-i){
        Z[i]=Z[k];
      }else{
        l=i;
        while (r<n && str[r-l]==str[r]){
          r++;
        }
        Z[i]=r-l;
        r--;
      }
    }
  }
}

void searchstring(string text,string pattern){
  string str=pattern+"$"+text;
  int n=str.length();
  int* Z=new int[n]();
  buildZ(Z,str);
  for (int i=0;i<n;i++){
    cout<<i-pattern.length()-1<<endl;
  }
}

int main(){
  string text="abcdsafbcdfasbcda";
  string pattern="bcd";
  searchstring(text,pattern);
  return 0;
}


