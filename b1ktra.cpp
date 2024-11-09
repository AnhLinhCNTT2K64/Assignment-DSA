#include<bits/stdc++.h>
using namespace std;

class Ds_nguyen{
	private:
		int n;
		int *a;
	public:
		Ds_nguyen(): n(0), a(nullptr){}
		Ds_nguyen(int n):n(n){
			a = new int[n];
		}
		friend istream& operator>>(istream& is, Ds_nguyen& a){
			cout<<"\nNhap day so: ";
			for(int i=0; i<a.n; i++){
				is >> a.a[i];
			}
			return is;
		}
		friend ostream& operator<<(ostream& os, Ds_nguyen& a){
			for(int i=0; i<a.n; i++){
				os << a.a[i]<<" ";
			}
			return os;
		}
		float tbc(){
			float t=0;
			int d=0;
			for(int i=0; i<n; i++){
				if(a[i]>0){
					t+=a[i];
					d++;
				}
			}
			if(d>0){
				return t/(d*1.0);
			}
			else{
				return 0;
			}
		}
		int dem(){
			int dem=0;
			for(int i=0; i<n; i++){
				int s = sqrt(a[i]);
				if(s*s == a[i]){
					dem++;
				}
			}
			return dem;
		}
};

int main(){
	int n; 
	cout<<"\nNhap n: ";
	cin>>n;
	Ds_nguyen ds(n);
	cin>>ds;
	cout<<ds;
	cout<<"\nTrung binh cong cac phan tu duong la: "<<ds.tbc()<<endl; 
	cout<<"\nCo "<<ds.dem()<<" so chinh phuong trong day"<<endl;
}
