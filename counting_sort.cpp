#include<bits/stdc++.h>
using namespace std;
int main () {

vector <int> arr ;
int n ; cin >> n;
for ( int i = 0 ; i < n ; i ++ ) {
    int temp ; cin >> temp ;
    arr.push_back(temp);
}
int maxx = *max_element( arr.begin() , arr.end());
int count [maxx+1]={0};
for ( auto x : arr){

    count[x]++;
}
int sum = 0 ;
for ( int i = 0 ; i <=maxx; i ++ ) {

    int temp = count[i];
    count[i]= sum ; 
    sum+=temp ; 
}
vector<int> c(arr.size());
for ( int i = 0 ; i < arr.size() ; i ++ ) {

    c[count[arr[i]]]=arr[i];
    count[arr[i]]++;
}
for ( auto x : c){
    cout << x <<" " ;
}
}