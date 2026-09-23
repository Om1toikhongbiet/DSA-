#include<bits/stdc++.h>
using namespace std;
int main () {

    int n ; 
    if ( !(cin>>n)) return 0 ;
    vector < int > a (n);
    vector<int> odd, even;
    for ( int i = 0 ; i < n ; i ++ ) {

        cin >> a[i] ; 
        if ( a[i] %2== 0 ){

            even.push_back(a[i]);
            
        }else{

            odd.push_back(a[i]);
        }
    }
    sort ( even.begin () , even.end() );
    sort ( odd.begin() , odd.end() , greater<int>());
    int inx_even = 0 ; 
    int inx_odd=0 ; 
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( a[i]%2== 0 ) {

            cout << even[inx_even++] << " " ;
        }else{

            cout<<odd[inx_odd++] << " " ;
        }


    }
    cout << endl;
}