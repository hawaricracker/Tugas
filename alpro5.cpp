#include <bits/stdc++.h>
using namespace std;

void pat1(int n){
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
}

void pat2(int n){
	for (int i = 4; i >= 0; --i)
	{
		for (int j = i; j >= 0; --j)
		{
			cout<<i<<" ";
		}
		cout<<endl;
	}
}
int n;
int main(int argc, char const *argv[])
{
	cin>>n;
	pat1(n);
	pat2(n);
	return 0;
}