#include <bits/stdc++.h> 
#include <vector> 
using namespace std; 
   
int main() {
	long long n, memory = 0;
    cin >> n;
    vector<int> V(1, 1);
	for(int i = 2; i <= n; i++){
	    memory = 0;
	    for(auto it = V.begin(); it != V.end(); it++){
	        memory += *it * i;
	        *it = memory % 10;
	        memory /= 10;
	    }
	    while(memory){
	        V.push_back(memory % 10);
	        memory /= 10;
	    }
	}
	for(auto it = V.rbegin(); it != V.rend(); it++) cout << *it;
}

