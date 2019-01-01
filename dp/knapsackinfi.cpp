//https://www.hackerrank.com/challenges/unbounded-knapsack/problem

#include <bits/stdc++.h>

using namespace std;


// Complete the unboundedKnapsack function below.
int unboundedKnapsack(int k, vector<int> arr) {
    vector<int>dp(k+1,0);
    for(int i=0;i<(k+1);i++){
        for(int j=0;j<arr.size();j++){
            if(arr[j]<=i){
                dp[i]=max(dp[i],dp[i-arr[j]]+arr[j]);
            }
        }
    }
    return dp[k];

}

int main()
{

    int t,n,k;
    scanf("%d",&t);
    while(t){
        scanf("%d%d",&n,&k);
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        printf("%d\n", unboundedKnapsack(k,arr));
        t--;
    }
    
    return 0;
}

