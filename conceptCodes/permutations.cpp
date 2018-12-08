#include <bits/stdc++.h>

using namespace std;

//string.substr(int pos,int len)
//pos = starting poistion of substring
//len = length of substr required
//if(len > size of string) then a substr will run until the end of string
void permutationString(string s,string prefix,string suffix){
	if(prefix.size()==s.size()){
		cout<<prefix<<endl;
		return;
	}else{
		for(int i=0;i<suffix.size();i++){
		    
			permutationString(s,prefix+suffix[i],suffix.substr(0,i)+suffix.substr(i+1,suffix.size()));
		}
	}
}

void printArray(std::vector<int> arr){
	for (int i = 0; i < arr.size(); ++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void swap(std::vector<int> &arr,int i1,int i2){
	int temp=arr[i1];
	arr[i1]=arr[i2];
	arr[i2]=temp;
}

void permutationArray(vector<int> &arr,int start,int sizeFixed){
	if(sizeFixed==arr.size()){
		printArray(arr);
	}else{
		start++;
		sizeFixed++;
		for(int i=start;i<arr.size();i++){
			swap(arr,start,i);
			permutationArray(arr,start,sizeFixed);
			swap(arr,start,i);
		}
	}
}

namespace paras{
//returns same output as c++ next permutation
//returns the next greater number than this.. if no such no. exists it returns the smallest no
//of sequence possible
//Implemetation:
//the decreasing suffix is reverse and then returned
//eg. in 1 2 3 6 5 4 ... (6 5 4) is the suffix in decresing order


	void next_permutation(std::vector<int> &A){
		if(A.size()==1){
        	return;
    	}
    	int start=0;
    	for (int i = 0; i < A.size()-1; ++i)
    	{
        	if(A[i+1]<=A[i]){
                
        	}else{
            	start=i+1;
       		}
    	}
    	if(start==0){
        	reverse(A.begin(), A.end());
        	return;
    	}
    	for(int i=A.size()-1;i>=start;i--){
        	if(A[i]>A[start-1]){
            	swap(A,i,start-1);
            	reverse(A.begin()+start,A.end());
            	return;
        	}
    	}
    
	}
}


int main(){
	/*string s = "abc";
	permutationString(s,"",s);*/
	std::vector<int> arr={1,2,3};
	/*permutationArray(arr,-1,0);
	cout<<"using next_permutation:"<<endl;
	do{
		cout<<s<<endl;
	}while(next_permutation(s.begin(), s.end()));

	do{
		printArray(arr);
	}while(next_permutation(arr.begin(), arr.end()));*/
	paras::next_permutation(arr);
	printArray(arr);
	
	
}