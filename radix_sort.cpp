#include<bits/stdc++.h>
using namespace std;
void counting_by_digit ( vector <int>& arr, int exp , int n ){


    int cnt [10] = { 0 } ;
    int sum  = 0 ; 
    for ( int i = 0 ; i < n ;  i ++ ) {

        int currdig = (arr[i]/exp)%10 ;
        cnt[currdig]++;
    }
    for ( int i = 0 ; i < 10 ; i ++ ) {
        int temp = cnt[i];
        cnt[i] = sum ; 
        sum += temp ; 

    }
    vector < int > c(n);
    for( int i = 0 ; i < n ; i ++ ) {
        int currdig = (arr[i]/exp)%10;
        c[cnt[currdig]]= arr[i];
        cnt[currdig]++;

    }
    for ( int i = 0 ; i < n ; i ++ ) arr[i] = c[i];
}
void cloop ( vector <int>& arr , int n ) {


    int maxx = *max_element( arr.begin() , arr.end() );
    for ( int exp = 1 ; maxx/exp >0 ; exp*=10){

        counting_by_digit(arr, n ,exp);
    }
}
int main () {

    vector < int > arr; 
    int n ; cin >> n ; 
    for ( int i = 0 ; i < n ; i ++){

        int temp; cin >> temp ; 
        arr.push_back(temp ) ; 
    }
    cloop(arr, n );
    for ( auto x  : arr) {

        cout << x << " " ;
        
    }
}