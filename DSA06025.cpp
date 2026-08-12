/*Hãy thực hiện thuật toán sắp xếp chèn trên dãy N số nguyên. Ghi ra các bước thực hiện thuật 
toán. 
Dữ liệu vào: Dòng 1 ghi số N (không quá 100). Dòng 2 ghi N số nguyên dương (không quá 100). 
Kết quả: Ghi ra màn hình từng bước thực hiện thuật toán. Mỗi bước trên một dòng, các số 
trong dãy cách nhau đúng một khoảng trống. 
Ví dụ: 
Input 
4 
5 7 3 2 
Output 
Buoc 0: 5 
Buoc 1: 5 7 
Buoc 2: 3 5 7 
Buoc 3: 2 3 5 7*/
#include<bits/stdc++.h>
using namespace std;
int main () {

int n ; cin >> n ;
int a[n];
for ( int i = 0 ; i < n ; i ++ ) {

    cin >> a[i];

}
vector<int> temp;



    for ( int i = 0 ; i < n; i ++){

        temp.push_back(a[i]);
        sort(temp.begin(),temp.end());
        string s ="";
        s+="Buoc "+ to_string(i) +": ";
        for (auto x : temp){

            s+=to_string(x)+" ";
        }
        s.pop_back();
        cout<<s<<"\n";
    }

}