#include <bits/stdc++.h>

#define pb push

using namespace std;

//can be used to implement min and max heap

struct Point{
	int x;
	int y;
	Point(int _x,int _y){
		x=_x;
		y=_y;
	}

	
};



//make a struct and overload this operator() function with this EXACT signature..
//NOTICE () after operator and then (args)
struct comp{
	bool operator() (Point a,Point b){
		return a.x>b.x;
	}
};

int main(int argc, char const *argv[])
{
	priority_queue<int> p;//by default give priority to largerst element
	p.pb(4);
	p.pb(1);
	p.pb(7);
	p.pb(11);
	while (!p.empty())
	{
		cout<<p.top()<<" ";
		p.pop();
	}
	cout<<endl;

	//remember this function greater for default types like int,long,etc.
	priority_queue< int , vector<int> , greater<int> > p2;//by default give priority to largerst element
	p2.pb(4);
	p2.pb(1);
	p2.pb(7);
	p2.pb(11);
	while (!p2.empty())
	{
		cout<<p2.top()<<" ";
		p2.pop();
	}
	cout<<endl;

	//Notice how struct comp is passed
	priority_queue<Point,vector<Point>,comp> p3;
	p3.pb(Point(1,2));
	p3.pb(Point(0,93));
	p3.pb(Point(9,11));
	while(!p3.empty()){
		cout<<p3.top().x<<" ";
		p3.pop();
	}

	

	return 0;
}