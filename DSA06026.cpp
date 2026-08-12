#include<bits/stdc++.h>
using namespace std; 
int main () {

    int n ; cin >> n;
    vector<int> v;

    for ( int i = 0 ; i < n ; i ++){
        int temp ; cin>>temp;
        v.push_back(temp);
        
    }
    bool stop = false;
    int step = 1 ;
    while (stop==false ){
        stop =true;
     

            for ( int j =0 ; j < n -1; j++){

                if ( v[j]>v[j+1]){ swap(v[j+1],v[j]);stop=false;}
               
            }
            if (stop) break;
            string s ="";
            s+="Buoc "+ to_string(step)+":";
            cout<< s;
            step++;

        
            for (auto x : v){
        
                cout<<" "<<x;
            }
            cout<<"\n";
    }


}