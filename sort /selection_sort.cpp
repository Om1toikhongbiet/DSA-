#include<bits/stdc++.h>
using namespace std;
int main () {

    int n ,k;
    int a[n];
    cin>>n>>k;
    int a = n ;
    for ( int i = 1, i < n ; i ++ ) {

        if ( a[i]<a[i+1]){

            a = i +1;
        }
        if ( a !=n){
            swap ; 
        }

    }
}