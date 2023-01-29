#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	vector<string> str;
	str.push_back("abc");
	str.push_back("xyz");
	str.push_back("ohh");
	//while(next_permutation(begin(str),end(str)));
	do{
		cout << str[0] << ' ' << str[1] << ' ' << str[2] << endl;
	}while(next_permutation(str.begin(),str.end()));
	
	
	return 0;
}
