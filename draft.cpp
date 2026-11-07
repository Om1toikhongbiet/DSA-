#include<bits/stdc++.h>
using namespace std;
bool col[9];
bool cross1[16];
bool cross2[16];
int A[9][9];
int max_score=0 ; 
void Try(int row) {
    for ( int c = 1; c<=8; c++){
        int current_score=0 ;
        if ( col[c]==false&&cross1==false&&cross2==false){

            current_score+=A[row][c];
            col[c]=true;
            cross1[row-c+8] = true;
            cross2[row+c-1] =true;
            if (row==8){

                max_score=max(max_score, current_score);

            }else{

                Try(row+1);
            }
        }
    }
    
}