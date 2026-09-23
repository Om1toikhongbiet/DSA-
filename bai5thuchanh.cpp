#include<bits/stdc++.h>
using namespace std;
bool cmp (const pair <int,int> &a , const pair <int, int> &b){
if ( a.second!=b.second){
    
    return a.second>b.second;
}
return a.first <b.first;
}
int main () {

    int test ; cin>> test;
    while ( test -- ) {


        int n ; cin >> n ;
        map <int,int> arr ; 
        for ( int i = 0 ; i < n ; i ++){

            int temp ; cin >> temp ; 
            arr[temp]++;
            
        }
        vector<pair<int , int > > freq_de (arr.begin() , arr.end() );
        sort( freq_de.begin() , freq_de.end() ,cmp);
        for (auto x : freq_de){
            for ( int i = 0 ; i < x.second; i ++ ) {

                cout<< x.first << " " ;
            }
        }
        cout<< endl;
        
        

    }
}