struct Trie{
    int noc;//number of children
    char val;
    unordered_map<char,Trie*> children;
    Trie(char c){
        val=c;
        noc=0;
    }
};

Trie* root;

void makeTrie(Trie* root,string s,int i){
    if(i>=s.size()){
        return;
    }
    root->noc++;
    Trie* temp;
    if((root->children).find(s[i])==(root->children).end()){
        temp=new Trie(s[i]);
        (root->children)[s[i]]=temp;
        
    }else{
        temp=(root->children)[s[i]];
    }
    makeTrie(temp,s,++i);
    
}

string giveAns(Trie* root,string s,int i){
    if(i>s.size()){
        string temp;
        return temp;
    }
    Trie* temp;
    if(root->val=='1'){
        temp=(root->children)[s[i]];
        return giveAns(temp,s,++i);
    }else{
        string temp2;
        temp2=temp2+root->val;
        if(root->noc==1){
            return temp2;
        }else{
            temp=(root->children)[s[i]];
            temp2=temp2+giveAns(temp,s,++i);
            return temp2;
        }
    }
    
}



vector<string> Solution::prefix(vector<string> &A) {
    root=NULL;
    root=new Trie('1');
    vector<string> ans;
    ans.reserve(A.size());
    for(int i=0;i<A.size();i++){
        makeTrie(root,A[i],0);
    }
    for(int i=0;i<A.size();i++)
    {
        string temp=giveAns(root,A[i],0);
        //cout<<temp<<endl;
        ans.push_back(temp);
    }
   
    return ans;
    
}