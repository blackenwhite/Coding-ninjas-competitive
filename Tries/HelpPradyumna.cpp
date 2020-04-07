/*  Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
*/

#include <bits/stdc++.h>
using namespace std;
char ans[200005];
class trieNode{
    public:
    bool isLeaf;
    trieNode** children;
    trieNode(){
        isLeaf = false;
        children = new trieNode*[26];
        for(int i = 0 ;i <26; i++){
            children[i] = NULL;
        }
    }
};
void insert(string s, trieNode* root){
    if(s.empty()){
        root->isLeaf = true;
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
    insert(s.substr(1), child);
}
 
int getId(char c) {
	if(c >= 'a') return c - 'a';
	return c - 'A';
}
 
trieNode* getNode(string s, trieNode* root) {
	trieNode* curr = root;
	for(int i = 0; i < s.size(); i++) {
		int temp = getId(s[i]);
		if(!curr->children[temp]) {
            return 0;
        }
		curr = curr->children[temp];
	}
	return curr;
}
void dfs(string s, trieNode* node, int k) {
	if(!node){
        return;
    }
	if(node->isLeaf){
		ans[k] = 0;
		cout << s << ans << '\n';
	}
	for(int i = 0; i < 26; ++i){
		if(node->children[i]) {
			ans[k] = i + 'a';
			dfs(s, node->children[i], k + 1);
		}
	}
}
int main()
{
    int n;
    cin>>n;
    trieNode* root = new trieNode();
    while(n--){
        string s;
        cin >> s;
        insert(s, root);
    }
    int q;
    cin >> q;
    while(q--){
        string t;
        cin >> t;
        trieNode* temp = new trieNode();
        temp = getNode(t, root);
        if(!temp){
            cout<<"No suggestions"<<endl;
            insert(t, root);
        }
        else{
            dfs(t, temp, 0);
        }
    }
    return 0;
}
