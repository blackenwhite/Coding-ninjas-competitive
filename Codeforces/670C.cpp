#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n , m;
    cin >> n;
    ll language[n];

    map<ll , ll> scientist;

    for(ll i = 0 ; i < n ; i++) {
        cin >> language[i];
        scientist[language[i]]++;
    }

    cin >> m;
    ll audio[m + 9] , subtitle[m + 9];

    for(ll i = 0 ; i < m ; i++)
        cin >> audio[i];
    for(ll i = 0 ; i < m ;i++)
        cin >> subtitle[i];

    vector<pair<ll , ll> >ans;

    for(ll i = 0 ; i < m ; i++)
        ans.push_back(make_pair(scientist[audio[i]] , scientist[subtitle[i]]));
    ll pos = 1 , j = 0;
    for(ll i = 1 ; i < m ; i++) {
        if(ans[i].first > ans[j].first){
                j = i;
                pos = j + 1;
        }
        else if(ans[i].first == ans[j].first && ans[i].second > ans[j].second){
            j = i;
            pos = j + 1;
        }
    }

    cout << pos;
    return 0;
}
