#include <bits/stdc++.h>

using namespace std;

//use macros
#define pb push_back


//List is a doubly linked list
//It does not allow random access to a element as in vector. To reach a element one should
//itreate from start
//Altough addtion and deletion are supported in O(1) time.
//Unique func apart from other than vector is merge

int main(int argc, char const *argv[])
{
	list<int> l1;
	l1.pb(1);
	l1.pb(5);
	l1.pb(9);
	l1.pb(10);
	list<int> l2;
	l2.pb(2);
	l2.pb(6);
	l2.pb(7);
	l2.pb(13);
	l1.merge(l2);
	for(auto itr=l1.begin();itr!=l1.end();itr++){
		cout<<*itr<<" ";
	}
	return 0;
}