#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    cin>>n;
    n++;
    for (int i = 1; i < n; i++){
        for (int j = 1; j <= n-i; j++){
            cout<<"* ";
        }
        
        for (int k = 1; k < i; k++){
            cout<<"  ";
        }

        for (int x = 1; x < i; x++)
        {
            cout<<"  ";
        }

        for (int y = 1; y <= n-i ; ++y)
        {
            cout<<"* ";
        }
        cout<<endl;
        
    }

    for (int i = n-1; i > 0; i--){
        for (int j = 1; j <= n-i; j++){
            cout<<"* ";
        }
        
        for (int k = 1; k < i; k++){
            cout<<"  ";
        }

        for (int x = 1; x < i; x++)
        {
            cout<<"  ";
        }

        for (int y = 1; y <= n-i ; ++y)
        {
            cout<<"* ";
        }
        cout<<endl;
        
    }
    return 0;
}
