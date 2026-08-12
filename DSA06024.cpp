/*Hãy thực hiện thuật toán sắp xếp chọn trên dãy N số nguyên. Ghi ra các bước thực hiện thuật 
toán. 
Dữ liệu vào: Dòng 1 ghi số N (không quá 100). Dòng 2 ghi N số nguyên dương (không quá 100). 
Kết quả: Ghi ra màn hình từng bước thực hiện thuật toán. Mỗi bước trên một dòng, các số 
trong dãy cách nhau đúng một khoảng trống. 
Ví dụ: 
Input 
4 
5 7 3 2 
Output: 
Buoc 1: 2 7 3 5 
Buoc 2: 2 3 7 5 
Buoc 3: 2 3 5 7 
*/
#include<bits/stdc++.h>
using namespace std;
int main () {

    int n ; cin >> n;
    int  a[n];
    for ( int i = 0 ; i < n ; i ++ ) {

        cin >> a[i];

    }
    int rlc = 0 ; 
    while ( rlc <= n-2) {

    

    int lc = rlc ;
    for ( int i = lc ; i < n-1 ; i ++ ) {

        int j = i+1;
        if ( a[j]<a[lc]) lc = j ; 

    }//find the min of last arr;

    if (lc !=rlc){

        int temp = a[lc];
        a[lc]=a[rlc];
        a[rlc]= temp ;

    }//Swap if have dif locate
    cout<<"Buoc "<<rlc+1<<": ";
    rlc++;
    
    for( auto x : a ){

        cout<<x<<" ";
    }
    cout<<endl;

}
}
