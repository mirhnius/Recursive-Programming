/*FIRST DRAFT*/

#include<iostream>
#include<string>

using namespace std;
int ConvertBase6ToBase10(string s){
	if(s.size() == 0)
		return 0;

    string character = s.substr(s.size()-1,1);
	char digit = character[0];
	return digit - '0' + 6 * (ConvertBase6ToBase10(s.substr(0,s.size()-1)));

}



int main(){
	string number;
	while(cin>>number)
		cout<< ConvertBase6ToBase10(number)<<endl;

}