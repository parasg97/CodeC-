
int giveModulo(long long l,long long r){
    int m=1000000007;
    return (((l%m)*(r%m))%m);
}


int Solution::maxSpecialProduct(vector<int> &A) {
    
    int msp=0;
    int sp=0;
    int size=A.size();
    stack<long long> s;//save index
    s.push(0);
    long long leftA[size];
    long long rightA[size];
    for (int i = 0; i < size; ++i)
    {
    	leftA[i]=0;
    	rightA[i]=0;
    }
	for(int i=1;i<(A.size()-1);i++){
		if(A[s.top()]>A[i]){
			leftA[i]=s.top();
		}
		else{
			while(!s.empty()){
				if(A[s.top()]>A[i]){
					leftA[i]=s.top();
					break;
				}
				s.pop();
			}
		}
		s.push(i);
	}
	while(!s.empty()){
		s.pop();
	}
	s.push(A[size-1]);
	for(int i=(size-2);i>=0;i--){
		if(A[s.top()]>A[i]){
			rightA[i]=s.top();
		}
		else{
			while(!s.empty()){
				if(A[s.top()]>A[i]){
					rightA[i]=s.top();
					break;
				}
				s.pop();
			}
		}
		s.push(i);
	}
	for (int i = 0; i < size; ++i)
	{
		sp=giveModulo(leftA[i],rightA[i]);
		if(sp>msp)
			msp=sp;
	}
    return msp;
}

/*if(mtn>A[i]){
			sp=giveMSP(A,i);
			if(sp>msp){
				msp=sp;
			}
		}else if(A[i]>mtn){
			mtn=A[i];
		}*/
