/*PRINTING RECURSIVELY AND PART 2*/
#include<iostream>
#include<vector>

using namespace std;


vector<string> insert_at_bottom(string x,vector<string>vec) { 
  
    if(vec.size() == 0) 
    vec.push_back(x); 
  
    else{ 
        string a = vec.back(); 
        vec.pop_back(); 
        vec = insert_at_bottom(x,vec); 
        vec.push_back(a); 
    } 
    return vec;

} 
  
vector<string> reverse(vector<string>vec) 
{ 
    if(vec.size()>0) 
    { 
        string x = vec.back(); 
        vec.pop_back(); 
        vec = reverse(vec); 
        vec = insert_at_bottom(x,vec);
        return vec; 
    } 
    return vector<string>(0);
} 



int main(){
	vector<string> numbers,n;
    string x;
    while (cin >> x)
        numbers.push_back(x);
    
    n = reverse(numbers);
    for(int i = 0;i < n.size();i ++){
    	cout<<n[i];
        if(i + 1 == n.size())
            cout<<endl;
        else
            cout<<" ";
    }



}
