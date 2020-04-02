/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/
/*
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Input Format :
Line 1 : Two integers N and M, the number of rows and columns of the board
Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.
Output Format :
Return 1 if there is a cycle else return 0
Constraints :
2 ≤ N, M ≤ 50
Sample Input :
3 4
AAAA
ABCA
AAAA
Sample Output :
1
*/


#include <bits/stdc++.h>
#define MAXN 51

using namespace std;

#define li long int
li yes,N,M;
li check[50][50];

void dfs(char board[][MAXN],li i,li j,li i0,li j0){
    check[i][j]=1;
    if(!(i==i0 && j+1==j0) && j+1<M){
        if(board[i][j]==board[i][j+1]){
            if(check[i][j+1]){
                yes=1;
                return;
            }
            dfs(board,i,j+1,i,j);
        }
        if(yes) return;
    }
    if(yes) return;
    if(!(i+1==i0 && j==j0)&& i+1<N){
        if(board[i+1][j]==board[i][j]){
            if(check[i+1][j]){
                yes=1;
                return;
            }
            dfs(board,i+1,j,i,j);
        }
        if(yes) return;
    }
    if(yes) return;
    if(!(i==i0 && j-1==j0)&& j-1>=0){
        if(board[i][j-1]==board[i][j]){
            if(check[i][j-1]){
                yes=1;
                return;
            }
            dfs(board,i,j-1,i,j);
        }
        if(yes) return;
    }
    if(yes) return;
    if(!(i-1==i0 && j==j0)&& i-1>=0){
        if(board[i-1][j]==board[i][j]){
            if(check[i-1][j]){
                yes=1;
                return;
            }
            dfs(board,i-1,j,i,j);
        }
        if(yes) return;
    }
    if (yes) return;
    check[i][j]=2;
    
}

int solve(char board[][MAXN],int n, int m)
{
	// Write your code here.
    N=n;
    M=m;
    memset(check,0,sizeof(check));
    yes=0;
    for (li i=0;i<n;i++){
        for (li j=0;j<m;j++){
            if(check[i][j]==0) dfs(board,i,j,-1,-1);
            if(yes) break;
        }
        if(yes) break;
    }
    return yes;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}
