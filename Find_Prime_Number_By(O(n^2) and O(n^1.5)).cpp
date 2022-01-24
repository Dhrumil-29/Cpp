//Name:- Dhrumil Mevada
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define newline cout<<endl;
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define eb emplace_back
#define mod 1e9 + 7
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
#define deci(x,y) fixed<<setprecision(y)<<x
#define fio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << endl;
    err(++it, args...);
}




void first_run()
{
	fio;
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

//we want to write a brute force method to find a prime numbers from 1 to n

int main(int argc, char const *argv[]) {
	// your code goes here
	clock_t begin = clock();
	first_run();
	
	vi prime;
	int n;
	cin>>n;
	// T.C. = O(n^2) for 50000 it will take 296ms time
	bool flag = true;
	for(int i = 2;i <= n;i++)
	{
		flag = 1;
		for(int j = 2;j < i;j++)
		{
			if(i%j == 0)
			{
				flag = false;
				break;
			}
		}
		if(flag)
			prime.pb(i);
	}

	for(int i : prime)
		cout<<i<<" ";
	newline;


	//let's further optimize this algorithm
	// T.C. = O(n*sqrt(n)) for 50000 it will take 29ms time
	// bool flag = true;
	// for(int i = 2;i <= n;i++)
	// {
	// 	flag = 1;
	// 	for(int j = 2;j <= sqrt(i);j++)
	// 	{
	// 		if(i%j == 0)
	// 		{
	// 			flag = false;
	// 			break;
	// 		}
	// 	}
	// 	if(flag)
	// 		prime.pb(i);
	// }

	// for(int i : prime)
	// 	cout<<i<<" ";
	// newline;	

	#ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
	return 0;
}