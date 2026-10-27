#include<bits/stdc++.h>
using namespace std; 
int main () {

    int choose ;
    cin >> choose ;
    int n ; cin >> n ; 
    int matrix [n][n];
    for ( int i = 0 ; i < n ; i ++ ) {

        for ( int j = 0 ; j < n ; j ++ ) {
            cin >> matrix[i][j];


        }
    }
    if (choose==1){

        for ( int i = 0 ; i < n ; i ++ ) {
            int count = 0 ; 
            for ( int j = 0 ; j < n ; j ++ ) {

                if ( matrix[i][j]) count ++ ; 
            }
            cout << count <<" " ; 

        }
        cout<< endl ;
    }
    if (!choose){

        
    }
}