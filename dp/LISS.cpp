//longest increasing sub seq
//https://www.youtube.com/watch?v=CE2b_-XfVDk

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
using namespace std;

int giveAns(std::vector<int> v){
	//this array represents the laregest lenght of subseq if this element is included in the sub seq
	std::vector<int> res(v.size(),1);//intializing with value 1

	for(int i=1;i<v.size();i++){
		for (int j = 0; j < i; ++j)
		{
			if(v[j]<=v[i]){
				res[i]=res[j]+1;
			}
		}
	}
	int ans=-1;
	for(int i=0;i<res.size();i++){
		ans=max(ans,res[i]);
	}
	return ans;

}

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.pb(temp);
	}
	cout<<giveAns(v);
	return 0;
}