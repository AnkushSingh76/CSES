/*#include<bits/stdc++.h>
using namespace std;
bool check(int row,int col,vector<vector<int>>&temp){
    for(int i=0;i<8;i++){
        if(temp[i][col]==1){
            return 0;
        }
        if(temp[row][i]==1){
            return 0;
        }
    }
    int i=row;
    int j=col;
    while(i>=0&&i<8&&j>=0&&j<8){
        if(temp[i][j]==1){
            return 0;
        }
        i++;
        j++;
    }
    i=row;
    j=col;
    while(i>=0&&i<8&&j>=0&&j<8){
        if(temp[i][j]==1){
            return 0;
        }
        i--;
        j--;
    }
    i=row;
    j=col;
    while(i>=0&&i<8&&j>=0&&j<8){
        if(temp[i][j]==1){
            return 0;
        }
        i++;
        j--;
    }
    i=row;
    j=col;
    while(i>=0&&i<8&&j>=0&&j<8){
        if(temp[i][j]==1){
            return 0;
        }
        i--;
        j++;
    }
    return 1;
}
void solve(int col,int &cnt,vector<vector<char>>grid,vector<vector<int>>&visited){
    if(col==8){
        cnt++;
        return;
    }
    for(int row=0;row<8;row++){
        if(grid[row][col]=='.'&&check(row,col,visited)){
            visited[row][col]=1;
            solve(col+1,cnt,grid,visited);
            visited[row][col]=0;
        }
    }
}
int main(){
    vector<vector<char>>grid(8,vector<char>(8));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>visited(8,vector<int>(8,0));
    int cnt=0;
    solve(0,cnt,grid,visited);
    cout<<cnt;
}*/
#include <bits/stdc++.h>
using namespace std;

const int N = 8;
char board[N][N];  // 8x8 chessboard
bool column[N], diag1[2 * N], diag2[2 * N];  // To track occupied columns and diagonals
int count_solutions = 0;  // To count the number of valid configurations

// Backtracking function to place queens row by row
void place_queens(int row) {
    if (row == N) {  // If all 8 queens are placed
        count_solutions++;  // Valid configuration found
        return;
    }

    for (int col = 0; col < N; col++) {
        if (board[row][col] == '*' || column[col] || diag1[row - col + N - 1] || diag2[row + col]) {
            // Skip if the square is blocked or attacked by another queen
            continue;
        }

        // Mark the column and diagonals as occupied
        column[col] = diag1[row - col + N - 1] = diag2[row + col] = true;

        // Recur to place queens in the next row
        place_queens(row + 1);

        // Backtrack: Unmark the column and diagonals
        column[col] = diag1[row - col + N - 1] = diag2[row + col] = false;
    }
}

int main() {
    // Input: 8x8 board where '*' represents a blocked cell
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // Start placing queens from the first row
    place_queens(0);

    // Output the number of valid configurations
    cout << count_solutions << endl;

    return 0;
}
