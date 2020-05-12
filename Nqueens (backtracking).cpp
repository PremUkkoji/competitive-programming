#include<bits/stdc++.h>
using namespace std;

#define N 4

bool isSafe(int board[N][N], int row, int col){
        
    int i, j;
    
    /* Check this row on left side */
    for(i = 0; i < col; i++)
        if(board[row][i])
            return false;
    
    /* Check upper diagonal on left side */
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return false;
    
    /* Check lower diagonal on left side */
    for(i = row, j = col; j >= 0 && i < N; i++, j--)
        if(board[i][j])
            return false;
    
    return true;
}

bool Nqueens(int board[N][N], int col){
    if (col >= N)
          return true;

    for(int r = 0; r < N; r++){
        if(isSafe(board, r, col)){
            board[r][col] = 1;

            if(Nqueens(board, col + 1))
                return true;

            board[r][col] = 0;
        }
    }
    return false;
}

void printBoard(int board[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
//    int board[N][N] = {
//        { 0, 0, 0, 0, 0, 0, 0, 0 },
//        { 0, 0, 0, 0, 0, 0, 0, 0 },
//        { 0, 0, 0, 0, 0, 0, 0, 0 },
//        { 0, 0, 0, 0, 0, 0, 0, 0 },
//        { 0, 0, 0, 0, 0, 0, 0, 0 },
//        { 0, 0, 0, 0, 0, 0, 0, 0 },
//        { 0, 0, 0, 0, 0, 0, 0, 0 },
//        { 0, 0, 0, 0, 0, 0, 0, 0 }
//    };
    
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
    
    if(Nqueens(board, 0))
        printBoard(board);
    else
        cout<<"Solution doesn't exists";
    
    return 0;
}
