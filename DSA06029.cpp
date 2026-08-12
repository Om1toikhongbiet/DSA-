#include<bits/stdc++.h>
using namespace std;
int main () {

int n ; cin >> n ;
int a[n];
for ( int i = 0 ; i < n ; i ++ ) {

    cin >> a[i];

}
vector<int> temp;
vector<string> Ins;




    for ( int i = 0 ; i < n; i ++){

        temp.push_back(a[i]);
        sort(temp.begin(),temp.end());
        string s ="";
        s+="Buoc "+ to_string(i) +": ";
        for (auto x : temp){

            s+=to_string(x)+" ";
        }
        Ins.push_back(s);        
        
    }
    for( int i = Ins.size()-1; i>=0 ; i--){

        cout<<Ins[i]<<" \n";
    }

}