#include<iostream>
using namespace std;

template <class T>
void myswap(T& a, T& b){
	T tmp = a;
	a = b;
	b = tmp;
}
template <typename Z>
void sapxep(Z* a, int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i]<a[j]){
				myswap(a[i], a[j]);
			}
		}
	}
}

int main(){
	int n; cin>>n;
	int a[100];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sapxep(a, n);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
}
