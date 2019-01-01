#include <bits/stdc++.h>

#define pb push_back

using namespace std;

vector<int> m;//mass
vector<int> v;//value

int giveAns(int w,std::vector<int> m,std::vector<int> v){
    int res[m.size()+1][w+1];
    for (int i = 0; i <=w; ++i)
    {
    	res[0][i]=0;
    }
    for (int i = 0; i <=m.size(); ++i)
    {
    	res[i][0]=0;
    }
    for (int i = 1; i <=w; ++i)
    {
    	for (int j = 1; j <=m.size(); ++j)
    	{
    		if(m[i-1]<=w){
    			res[i][j]=max(v[i-1]+res[i-1][w-m[i-1 ]],res[i-1][j]);
    		}else{
    			res[i][j]=res[i-1][j];
    		}
    	}
    }
    return res[m.size()][w];
}


int main() {
    int n,w,t;
    scanf("%d",&t);
    while(t){
        scanf("%d%d",&w,&n);
        vector<int> m(n);//mass
        vector<int> v(n);//value
        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            m[i]=a;
            v[i]=b;
        }
        printf("%d",giveAns(w,m,v));
        t--;
    }
}
