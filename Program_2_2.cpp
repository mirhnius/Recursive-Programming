#include<iostream>
#include<vector>
using namespace std;

vector<int>sorted_insert(vector<int>vec,int element){
	if(vec.size() == 0 || element > vec.back())
	    vec.push_back(element);
	else{
	    int temp = vec.back();
	    vec.pop_back();
	    vec = sorted_insert(vec,element);
	    vec.push_back(temp);

	}
	return vec;
}

vector<int>sort_vector(vector<int>vec){
    if(vec.size() != 0){
       int temp = vec.back();
       vec.pop_back();
       vec = sort_vector(vec);
       vec = sorted_insert(vec,temp);
    }
    return vec;
}
int main(){
	vector<int> numbers,n;
    int x;
    while (cin >> x)
        numbers.push_back(x);
    
    n = sort_vector(numbers);
    for(int i = 0;i < n.size();i ++){
    	cout<<n[i];
        if(i + 1 == n.size())
            cout<<endl;
        else
            cout<<" ";
    }



}


