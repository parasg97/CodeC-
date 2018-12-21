#include <bits/stdc++.h>

using namespace std;

int giveAscii(char c){
	return ((int)c);
}

int charToInt(char c){
    return ((int)c-'0');
    //return ((int)c-'a');//to get alphabets in range 0-25
}


string toBinary(int n){
    string result="";
    int rem;
    while(n>1){
        rem=n%2;
        result+=to_string(rem);
        n/=2;
    }
    result+=to_string(n);
    reverse(result.begin(), result.end());
    return result;
}

int toDeca(string bin){
    int power=0;
    int result=0;
    for(int i=bin.size()-1;i>=0;i--){
        result+=(charToInt(bin[i])*pow(2,power));
        power++;
    }
    return result;
}




int main(int argc, char const *argv[])
{
	cout<<toDeca("100")<<endl;
	return 0;
}