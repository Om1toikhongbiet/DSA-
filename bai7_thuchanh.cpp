#include <bits/stdc++.h>
using namespace std;
int main()
{

    int test;
    cin >> test;
    while (test--)
    {

        int n;
        cin >> n;
        int arr[3]={0};
        for (int i = 0; i < n; i++)
        {

            int temp;
            cin >> temp;
            arr[temp]++;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < arr[i]; j++)
            {

                cout << i<< " ";
            }
        }
        cout << endl;
    }
}