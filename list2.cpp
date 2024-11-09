#include<bits/stdc++.h>
using namespace std;

class SV{
	public:
		string msv;
		string ht;
		int ngay;
		int thang;
		int nam;
		string gt;
		string que;
		
		SV(string msv, string ht, int ngay,int thang,int nam,string gt,string que){
			this->msv = msv;
			this->ht = ht;
			this->ngay = ngay;
			this->thang = thang;
			this->nam = nam;
			this->gt = gt;
			this->que = que;
		}
		void inTT(){
			cout<<msv<<" "<<ht<<" "<<ngay<<" "<<thang<<" "<<nam<<" "<<gt<<" "<<que<<endl;
		}
};

class Node{
	public:
		SV* sv;
		Node* next;
		Node* prev;
		
		Node(SV* sv){
			this->sv = sv;
			next = nullptr;
			prev = nullptr;
		}
};

class Dblist{
	private:
		Node* head;
		Node* trail;
	public:
		Dblist(){
			head = nullptr;
			trail = nullptr;
		}
		
		void themsvcuoi(Sv* sv){
			Node* newnode =  new Node(sv);
			if(!head){
				head = newnode;
				trail = newnode;
			}
			else{
				trail->next = newnode;
				newnode->prev = trail;
				trail = newnode;
			}
		}
		
		void themsvdau(SV* sv){
			Node* newnode = new Node(sv);
			if(!head){
				head = newnode;
				trail = newnode;
			}
			else{
				newnode->next = head;
				head->prev = newnode;
				head = newnode;
			}
		}
		
		void xoasv(int i){
			if(head==nullptr) return;
			Node* current = head;
			for(int count = 0; count < i && curent != nullptr; count++){
				current = current->next;
			}
			if(current == nullptr) return;
			if(current->prev){
				current->prev->next = current->next;
			}
			
		}
};
