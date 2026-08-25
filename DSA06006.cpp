#include<bits/stdc++.h>
using namespace std;

int main () {

    int test; cin >> test;
    while ( test -- ) {
        int n ; cin >> n ;

        int a[3]={0};
        for ( int i = 0 ; i < n; i ++  ){
            int temp ;  cin >> temp ;
            a[temp]++;
        
            
        }    
        for ( int i = 0 ; i < 3 ; i ++ ){
            for ( int j = 0 ; j < a[i]; j ++ ) {
                cout << i << " ";

            }
        }
        cout << endl;

    }
}