#include<bits/stdc++.h>
using namespace std;
int main () {


    int t , n ; cin >>t >>n;
    while ( t-- &&cin>>n ) {


        set<char> s;
        string x;
        while ( n-- && cin >> x ) {

            for ( char c : x )  s.insert(c);
            for ( char c : s ) cout << c << " " ;
            cout << "\n";
        }
    }
}