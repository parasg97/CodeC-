#include <bits/stdc++.h>

using namespace std;




  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    ListNode* res=NULL;
    ListNode* resH=NULL;
    multimap<int,LisNode*> m;
    int size=0;
    for (int i = 0; i < A.size(); ++i)
    {
    	m.insert(pair<int,ListNode*>(A[i]->val,A[i]));
    	size+=A[i]
    }
    
    while(true){
    	auto itr=m.begin();
    	auto itr2=itr->next;
    	if(res==NULL){
    		resH=itr;
    		res=resH;
    		res->next=NULL;
    	}else{
    		res->next=itr;
    		res=res->next;
    		res->next=NULL;
    	}
    	m.erase(itr);
    	if(itr2!=NULL){
    		m.insert(pair<int,ListNode*>(itr2->val,itr2));
    	}
    	if(m.empty()){
    		return;
    	}

    }
    return resH;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}