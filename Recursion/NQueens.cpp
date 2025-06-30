#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(int row,int col, vector<string>&temp, int n){
        //checek in north west and north east if there are any things went wrong
        //it wont be in same row
        //chekc if it is same colum
        for(int i=0; i < n; i++)if(temp[i][col] == 'Q')return false;

        //north west direction

        int tempRow = row;
        int tempCol = col;
        while(tempRow >= 0 && tempCol >= 0){
            if(temp[tempRow][tempCol] == 'Q')return false;
            tempRow--;
            tempCol--;
        }

        tempRow = row;
        tempCol = col;
        //north east directino

        while(tempRow >=0 && tempCol < n){
            if(temp[tempRow][tempCol] == 'Q')return false;
            tempRow--;
            tempCol++;
        }

        return true;
    }
    void solve(int row,vector<vector<string>>&res, vector<string>&temp, int n){
        if(row >= n){
            res.push_back(temp);
            return;
        }

        for(int col = 0; col < n; col++){
            if(isPossible(row,col,temp,n)){
                temp[row][col] = 'Q';
                solve(row+1,res,temp,n);
                temp[row][col]  = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        //just like waht we do with vector<vector<int>>
        vector<string>temp(n,string(n,'.'));
        solve(0,res,temp,n);
        return res;
    }
};