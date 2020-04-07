#include <bits/stdc++.h>
using namespace std;
class trieNode{
    public:
    trieNode** children;
    int max_weight; // the corressponding max weight for each prefix.
    trieNode(){
        children = new trieNode*[26];
        for(int i = 0 ;i < 26; i++){
            children[i] = NULL;
        }
        max_weight = 0;
    }
};
 
void insert(string s, int weight, trieNode* root){
    if(s.empty()){
        return;
    }
    int index = s[0] - 'a';
    trieNode* child;
    if(root->children[index]){
        child = root->children[index];
    }
    else{
        child = new trieNode();
        root->children[index] = child;
    }
    if(root->max_weight < weight){
        root->max_weight = weight;
    }
    insert(s.substr(1), weight, child);
}
int searchBest(string s, trieNode* root){
    trieNode* current = root;
    int bestWeight = -1;
    for(int i = 0 ;i < s.size(); i++){
        int index = s[i] - 'a';
        trieNode* child = current->children[index];
        if(child){
            current = child;
            bestWeight = child->max_weight;
        }
        else{
            return -1;
        }
    }
    return bestWeight;
}
int main()
{
    int n, q;
    cin >>n >> q;
    trieNode* root = new trieNode();
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int w;
        cin >> w;
        insert(s, w,root);
    }
    while(q--){
        string t;
        cin >> t;
        int answer = searchBest(t, root);
        cout<<answer<<endl;
    }
    return 0;
}
