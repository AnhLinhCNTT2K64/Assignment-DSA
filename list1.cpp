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
		
		Node(SV* sv){
			this->sv = sv;
			next = nullptr;
		}
};

class DS{
	private:
		Node* head;
	public:
		DS(){
			head = nullptr;
		}
		//Them sv vao cuoi ds
		void themsvcuoi(SV *sv){
			Node* newnode = new Node(sv);
			if(!head){
				head = newnode;
				return;
			}
			Node* current = head;
			while(current->next){
				current = current->next;
			}
			current->next = newnode;
		}
		//them sv vao dau ds
		void themsvdau(SV* sv){
			Node* newnode = new Node(sv);
			newnode->next = head;
			head = newnode;
		}
		//xoa sv
		void xoasv(string msv){
			Node* current = head;
			Node* prev = nullptr;
			while(current && current->sv->msv != msv){
				prev = current;
				current = current->next;
			}
			if(current){
				if(prev){
					prev->next = current->next;
				}
				else{
					head = current->next;
				}
				delete current->sv;
				delete current;
			}
		}
		
		//thay the
		void thaythe(int i, SV* svMoi){
			Node* current = head;
			int count=0;
			while(current){
				if(count == i){
					delete current->sv;
					current->sv = svMoi;
					return;
				}
			}
			count++;
			current = current->next;
		}
		
		//in ds
		void inDanhSach() {
	        Node* current = head;
	        while (current) {
	            current->sv->inTT();
	            current = current->next;
	        }
    	}
    	
};

int main(){
	DS ds;

    // them sv cuoi
    SV* sv1 = new SV("SV001", "Nguyen Van A", 1, 1, 2000, "Nam", "Ha Noi");
    SV* sv2 = new SV("SV002", "Tran Thi B", 2, 2, 2001, "Nu", "Hai Phong");
    ds.themsvcuoi(sv1);
    ds.themsvcuoi(sv2);
    
    //them sv dau
    SV* sv3 = new SV("SV003", "Le Van C", 3, 3, 1999, "Nam", "Da Nang");
    ds.themsvdau(sv3);
    cout << "Danh sach sinh vien:" << endl;
    ds.inDanhSach();

    // Xóa sinh viên
    ds.xoasv("SV002");
    cout << "\nSau khi xoa SV002:" << endl;
    ds.inDanhSach();

    // Thay the sinh viên thu i
    SV* svMoi = new SV("SV004", "Pham Van D", 4, 4, 2002, "Nam", "Nha Trang");
    ds.thaythe(1, svMoi);  // Thay the sinh viên thu 1
    cout << "\nSau khi thay the sinh viên thu 1:" << endl;
    ds.inDanhSach();
}
