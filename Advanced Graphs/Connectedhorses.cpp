/*

				Nabajyoti Majumdar
				

*/
/*
You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar 
N*M size board with similar arrangement of black and white 
cells.
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo 
10^9+7
Input:
First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.
Output:
For each test case, output the number of photographs taken by photographer.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
SAMPLE INPUT
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1                             Inspired from PRADEEP YADAV
4 4
SAMPLE OUTPUT
4
2
*/

#include<bits/stdc++.h>
using namespace std;
#define p int(1e9+7)
int mat[1001][1001],n,m;
#define ll long long int

void input();
void func();
ll fac(ll);
ll bfs(int,int);

int main()
{
	int t;
    cin>>t;
    while(t--) input();
	return 0;
}

void input(){
    int q;
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) 
            mat[i][j]=0;
    
    int x,y;
    while(q--){
        cin>>x>>y;
        mat[x][y]=1;
        
    }
    func();
    
}

void func(){
    long long ans=1,t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
           if(mat[i][j]==1){
               t=bfs(i,j);
               ans=(ans*fac(t))%p;
           } 
        }
    cout<<ans<<endl;
}


ll fac(ll t)
{
	ll ans=1;
	for(ll i=1;i<=t;i++)ans=(ans*i)%p;
	return ans;
}

ll bfs(int i,int j)
{
	ll t=1;
	mat[i][j]=2;
	// the eight conditions
	if(i-2>=1 && j+1<=m && mat[i-2][j+1]==1)t+=bfs(i-2,j+1);
	if(i-1>=1 && j+2<=m && mat[i-1][j+2]==1)t+=bfs(i-1,j+2);
	if(i+1<=n && j+2<=m && mat[i+1][j+2]==1)t+=bfs(i+1,j+2);
	if(i+2<=n && j+1<=m && mat[i+2][j+1]==1)t+=bfs(i+2,j+1);
	
	if(i-2>=1 && j-1>=1 && mat[i-2][j-1]==1)t+=bfs(i-2,j-1);
	if(i-1>=1 && j-2>=1 && mat[i-1][j-2]==1)t+=bfs(i-1,j-2);
	if(i+1<=n && j-2>=1 && mat[i+1][j-2]==1)t+=bfs(i+1,j-2);
	if(i+2<=n && j-1>=1 && mat[i+2][j-1]==1)t+=bfs(i+2,j-1);
	return t;
}

