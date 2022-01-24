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

// Prime Sieve ERATOSTHENES
// Now Here we are going to write a code about a find a prime numbers from a to b 
// By in efficient way O(n log log n)
// In this problem 1 < a,b < 1e9 and between a to b len(a,b) < 1e5;


/*
so in this we can not just create array of 1e9 and find prime...
Here we know that from a to b there are many numbers that are already a multiples number of prime numbers that are < a ...

So here we first find the prime numbers to 1e5 ...
and then find the 1st number that are multiple of prime p.

so how can we find that...?

y = (x/p) * p <= x

if(y < x) y += p which is a multiple of prime p and travers from a to b and mark it false...exactly same as we do in sieve algo...

*/

#define MAX 1000005
vi prime;

void gen_prime()
{
	bitset<MAX> b;
	b.set();

	for(int i = 2;i*i < MAX;i++)
	{
		if(b[i])
			for(int j = i;j*i<MAX;j++)
				b[j*i] = false;
	}
	prime.pb(2);
	for(int i = 3;i < MAX;i+=2)
		if(b[i])
			prime.pb(i);
}

int main(int argc, char const *argv[]) {
	// your code goes here
	clock_t begin = clock();
	first_run();
	gen_prime();

	ll a,b;
	cin >> a >> b;
	vector<bool> s(b-a,1);
	vector<ll> ans_prime;
	for(int i = 0; prime[i]*prime[i] <= b;i++)
	{
		int j = a/prime[i];
		j = j * prime[i];
		if(j < a) j += prime[i];

		for(;j<= b;j += prime[i])
			if(j != prime[i])
				s[j-a] = 0;//create a offset...
	}
	for(int i = 0;i < s.size();i++)
		if(s[i])
			ans_prime.pb(i+a);


	for(ll i : ans_prime)
		cout<<i<<" ";



	#ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
	return 0;
}