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

// Better Version of Prime Sieve ERATOSTHENES
// Now Here we are going to write a code about a find a prime numbers from 1 to n 
// By in efficient way O(n)


/*

how we can do that??

create a vector of size n and in that we can store a value of its index value like v[2] = 2,v[3] = 3...

Lets first know abouts function pi(x) = y, where y is a lowest prime factor of number x,except 1.

corner point about this is a pi(1) = Inf.

ex:- pi(6) = 2, pi(5) = 5,...

Properties:- 

1)pi(x) = x, iff x is prime number.

2)pi(x+p) = p where p is prime numbers which are less than x


first define a vector s and store index value in it...
start from index = 2 (Because it is a first prime number)
so s[2] = 2;from property(1).and push it to a prime vector prime{2}

now traverse to multiples of 2 and store its value.

s[2*2] = s[4] = 2.

and so on.

by doing this we traverse through all element by one time so its TC = O(n)...


by this algo we use s vector to finds factors of any number in O(log2(n))...
HOW??-> pi(30) = 2 => pi(30/2) = pi(15) = 3 => pi(15/3) = pi(5) = 5...

so TC = n/2 + n/3 + ... + n/p,where p is max prime number < n 



ex:- 1 to 20 find a prime numbers


s : 	  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
values  : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

prime = {}


iteration 1 for n = 2

s : 	  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
values  : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

prime = {2}

s[2*2] = s[4] = 2;

s : 	  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
values  : 1 2 3 2 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
prime = {2}

iteration 2 for n = 3

s : 	  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
values  : 1 2 3 2 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
prime = {2,3}

s[3*2] = s[6] = 2
s[3*3] = s[9] = 3

s : 	  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
values  : 1 2 3 2 5 2 7 8 3 10 11 12 13 14 15 16 17 18 19 20
prime = {2,3}

iteration 3 for n = 4

s : 	  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
values  : 1 2 3 2 5 2 7 8 3 10 11 12 13 14 15 16 17 18 19 20
prime = {2,3}(not push in vector because s[4] != 4)

s[4*2] = s[8] = 2
s[4*3] = s[12] = 3

s : 	  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
values  : 1 2 3 2 5 2 7 2 3 10 11  3 13 14 15 16 17 18 19 20
prime = {2,3}

iteration 4 for n = 5

s : 	  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
values  : 1 2 3 2 5 2 7 2 3 10 11  3 13 14 15 16 17 18 19 20
prime = {2,3,5}

s[5*2] = s[12] = 2
s[5*3] = s[15] = 3
s[5*5] = s[25] = 5

s : 	  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
values  : 1 2 3 2 5 2 7 8 3  2 11 12 13 14  3 16 17 18 19 20
prime = {2,3,5}
*/

#define MAX 1000005
vi prime;

void gen_prime()
{
	vi s(MAX);
	for(int i = 0;i < MAX;i++)
		s[i] = i;

	for(int i = 2;i < MAX;i++)
	{
		if(s[i] == i)
			prime.pb(i);
		for(int j = 0;prime[j]*i < MAX and prime[j] <= i and j < prime.size();j++)
			s[i*prime[j]] = prime[j];
	}

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