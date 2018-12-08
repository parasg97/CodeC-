#include <bits/stdc++.h>

using namespace std;

struct Record{
	int id=6;//members can be initialized
	string name;
	int returnID(){ //function can be used
		return id;
	}
	Record(string name){//parameterized constructor 
		this->name=name;
	}
	Record(){//non para const
		this->name="Gupta";

	}

	//Note: If you have declared parameterized constructor
	//default const is deleted and you have to make a non para const also to use it.
	//  A* a = new A(); (non para consr)  


private: // access modifier can be used
	int blah=96;
};

struct box
{
	int len;
	int wid;
	box(int x){
		len=x;
		wid=x;
	}

};

bool biger(box b1,box b2){
	return (b1.len<b2.len) ;
}

int main(int argc, char const *argv[])
{
	Record record=Record("paras");//using constructor
	cout<<record.name<<endl;
	Record* record1 = new Record("Suman");//using dynamic memory
	cout<<record1->name<<endl;
	Record* record2 = new Record();
	record2->name="Kamal";
	cout<<record2->name<<endl;
	//cout<<record2->blah<<endl; private cannot be accessed
	Record record3;
	record3.name="surabhi";
	cout<<record3.name<<endl;
	
	vector<box> v;
	for (int i = 0; i < 10; ++i)
	{
		box b(i);
		v.push_back(b);

	}
	sort(v.begin(),v.end(),biger);
	for (int i = 0; i < 10; ++i)
	{
		cout<<v[i].len<<" ";
	}
}