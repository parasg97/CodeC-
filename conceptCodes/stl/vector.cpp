#include <bits/stdc++.h>

using namespace std;

//use macros
#define pb push_back

/*
1. allocate memory of array in advance when declaring the vectror
	This will improve the performance by 75%!!
	Use: 
	vector <int> v;
	v.reserve(1000);

2. Clear and erase doest not free up memory the just remove elements.
	user v.shrink_to_fit(); after clear or erase

3. If you want to copy a vector from one v to another
	use newV = oldV;
	instead of runnig a loop and doing push_back or insert
	This is 55% faster

4. avoid v.at() : it is v. slow
use V[i] or a iterator

5. Use auto itr = v.begin() to get a iterator.
	It will save typing time.

6. Try avoid inserting element at the front of vector.
	Vector is a array , first it will shift all the ele to the right . O(n) complexity.
	Can use list instead. It takes O(1) time.
	list <int> l1;
	l1.push_front(3);

7.use emplace_back instead of push_back for faster performance

8.Types of iterators offered:
	a. begin()
	b. end()
	c. rbegin()-> this is used to iterate vector in reverse direction
	d. rend()
	e. cbegin()-> constant itreator... we can traverse the vector using this but we cannot modify the
				  element it is pointing to
	f. cend()
	g. crbegin()
	h. crend()
*/

void showOtherFunc(){
	std::vector<int> v;
	v.pb(5);
	v.pb(3);
	v.pb(1);
	v.pb(8);
	v.pb(9);

	for(auto itr=v.rbegin();itr!=v.rend();itr++){
		cout<<*itr<<" ";
	}

}

int main(int argc, char const *argv[])
{
	std::vector<int> v={1,5,7,8};
	cout<<"v:"<<" ";
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;

	//v.begin() points at first ele
	//v.end() points at next to last ele....it does not point at last ele
	cout<<"v.begin() and end:"<<" ";
	cout<<*(v.begin())<<" "<<*(v.end())<<endl;
	
	//insert 4 b/w  7 and 8
	//std::vector<int>::iterator it = v.begin();
	auto itr = v.begin();
	//inserts ele before itr
	v.insert(itr,4);
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;

	cout<<"now"<<endl;
	auto itr3 = v.begin();
	itr3++;
	auto itr4 = v.insert(itr3,11);//returns itr to added element
	cout<<*itr4<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;

	//inserting multiple elements
	v.insert(v.end(),v2.begin(),v2.end());

	

	//remove a single ele
	auto itr2 = v.begin();
	v.erase(itr2);
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;

	auto itr6 = v.begin();
	itr6++;
	itr6++;
	cout<<"blah"<<endl;
	cout<<*itr6<<endl;
	auto itr7= v.erase(itr6);//points to elemnt next to the deleted element
	cout<<*itr7<<endl;

	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;

	auto itr8 = v.begin();
	itr8++;
	itr8++;
	cout<<"blah2"<<endl;
	cout<<*itr8<<endl;
	 v.erase(itr8);
	cout<<*itr8<<endl;

	//remove range of ele
	auto start = v.begin();
	auto end = v.end();
	end--;
	end--;
	v.erase(start,end);
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	//how to remove a specific element
	//v.erase();

	//how to empty a vector
	v.clear();
	showOtherFunc();
}

