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
// Now Here we are going to write a code about a find a prime numbers from 1 to n 
// By in efficient way O(n log log n)


/*

how we can do that??

create a vector of size n and in that we can store a value like true and false

true means it is a prime number and false means not a prime number

now we know that prime number start with n = 2, and multiples of 2 are not gonna
be a prime numbers so we can travers to a multiples of number 2 and we can mark to a false , so it means that that numbers are not a prime numbers.

ex:- 1 to 20 find a prime numbers

vector

numbers : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
values  : 1 1 1 1 1 1 1 1 1  1  1  1  1  1  1  1  1  1  1  1

iteration 1 for n = 2

numbers : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
values  : 1 1 1 0 1 0 1 0 1  0  1  0  1  0  1  0  1  0  1  0

iteration 2 for n = 3

numbers : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
values  : 1 1 1 0 1 0 1 0 0  0  1  0  1  0  0  0  1  0  1  0

iteration 3 for n = 4
(in this iteration we are not gonna do any thing because n = 4 is not a prime numbers)

iteration 4 for n = 5

numbers : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
values  : 1 1 1 0 1 0 1 0 0  0  1  0  1  0  0  0  1  0  1  0
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

	for(int i : prime)
		cout<<i<<" ";



	#ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
	return 0;
}