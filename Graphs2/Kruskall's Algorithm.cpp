#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int weight;
    int first;
    int second;
    
    Edge(){
        weight=0;
        first=0;
        second=0;
    }
    
    Edge(int w,int f,int s){
        weight=w;
        first=f;
        second=s;        
    }
    bool operator <(const Edge &e1) const{
        return weight>=e1.weight;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    
    priority_queue<Edge> pq;
    
    vector <Edge> MST;
    
    for(int i=0;i<E;i++){
        int ei,ej,wi;
        cin>>ei>>ej>>wi;
        
        Edge E(wi,ei,ej);
        pq.push(E);
    }
    
    int count=0;
    int *parent=new int[V];
    
    for(int i=0;i<V;i++)
        parent[i]=i;
    
    while(count<V-1 && !pq.empty()){
        Edge e=pq.top();
        pq.pop();
        
        int x1=parent[e.first];
        
        while(x1!=parent[x1])
            x1=parent[x1];
        
        int x2=parent[e.second];
        while(x2!=parent[x2])
            x2=parent[x2];
        
        if(x1!=x2){
            count++;
            MST.push_back(e);
            
            parent[x1]=x2;
        }
    }
    
    for(int i=0;i<MST.size();i++){
        
        int a=(MST[i].first<=MST[i].second)?MST[i].first:MST[i].second;
        int b=(MST[i].first>MST[i].second)?MST[i].first:MST[i].second;
        
        cout<<a<<" "<<b<<" "<<MST[i].weight<<endl;;
    }

  return 0;
}
