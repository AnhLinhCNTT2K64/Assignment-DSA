#include <bits/stdc++.h>
using namespace std;

class MH {
    private:
        string ma;
        string ten;
        int sotc;
    public:
        MH(): ma(""), ten(""), sotc(0) {}
        MH(string ma, string ten, int sotc): ma(ma), ten(ten), sotc(sotc) {}
        
        void nhap() {
            cout << "Nhap ma mon: ";
            getline(cin, ma);
            cout << "Nhap ten mon: ";
            getline(cin, ten);
            cout << "Nhap so tin chi: ";
            cin >> sotc;
            cin.ignore();
        }

        void xuat() const {
            cout << "Ma mon: " << ma << " - Ten mon: " << ten << " - So tin chi: " << sotc << endl;
        }

        int getSoTinChi() const {
            return sotc;
        }

        string getTen() const {
            return ten;
        }
};

class DKHP {
    private:
        int msv;
        string ten;
        vector<MH> monHocs;
    public:
        DKHP(): msv(0), ten("") {}
        DKHP(int msv, string ten): msv(msv), ten(ten) {}
        
        void input() {
            cout << "Nhap ma sinh vien: ";
            cin >> msv;
            cin.ignore();
            cout << "Nhap ten sinh vien: ";
            getline(cin, ten);
        }

        void output() const {
            cout << "Ma sinh vien: " << msv << " - Ten sinh vien: " << ten << endl;
        }

        void themMonHoc(const MH &mh) {
            monHocs.push_back(mh);
        }

        int thongke(string name) const {
            int d = 0;
            for (const auto &mh : monHocs) {
                if (mh.getTen() == name) {
                    d++;
                }
            }
            return d;
        }

        int tinhTongTinChi() const {
            int tongTinChi = 0;
            for (const auto &mh : monHocs) {
                tongTinChi += mh.getSoTinChi();
            }
            return tongTinChi;
        }
};

int main() {
    int m, n;
    cout << "Nhap so mon hoc m: ";
    cin >> m;
    cout << "Nhap so sinh vien n: ";
    cin >> n;
    cin.ignore();

    vector<MH> danhSachMonHoc;
    cout << "Nhap danh sach mon hoc: " << endl;
    for (int i = 0; i < m; i++) {
        MH mh;
        mh.nhap();
        danhSachMonHoc.push_back(mh);
    }

    vector<DKHP> danhSachSV;
    cout << "Nhap danh sach sinh vien: " << endl;
    for (int i = 0; i < n; i++) {
        DKHP sv;
        sv.input();
        for (int j = 0; j < m; j++) {
            sv.themMonHoc(danhSachMonHoc[j]);
        }
        danhSachSV.push_back(sv);
    }

    string name;
    cout << "\nNhap ten mon hoc can thong ke: ";
    getline(cin, name);

    int soSinhVien = 0;
    for (const auto &sv : danhSachSV) {
        soSinhVien += sv.thongke(name);
    }

    cout << "\nSo sinh vien dang ki mon " << name << " la: " << soSinhVien << endl;

    cout << "\nThong tin sinh vien va tong tin chi da dang ky:\n";
    for (const auto &sv : danhSachSV) {
        sv.output();
        cout << "Tong so tin chi da dang ky: " << sv.tinhTongTinChi() << endl;
    }

    return 0;
}

