//Chuẩn bị đề tài cuối kỳ : Các nhóm tự lên ý tưởng để xuất một bài toán thực tế
//sử dụng lập trình hướng đối tượng với bắt buộc sử dụng kế thừa hoặc đa hình
//bằng ngôn ngữ C++.

//Thang điểm :
// 
    // < 3.0d > - Báo cáo word(giới thiệu nhóm, điểm đánh giá theo tỉ 100 %
    //-mỗi thành viên cách nhau 5 %, giới thiệu đề tài, quy luật
    //- cách thức thiết kế lớp, giải thích code, minh họa thực thi)
    //< 2.0d > - Thiết kế lớp cơ bản phải có đủ tiêu chí getter / setter,các hàm khởi tạo, hàm quá tải nhập xuất.
    //< 3.0d > - Kế thừa(tính 1d), đa hình(tính 2d) giải quyết bài toán
    
    //< 2.0d > - Xây dựng ứng dụng(Console tính 1d, có màu sắc tính 2d)
    //Đại diện thành viên nộp file word(trong file word có link demo và
    //	link mã nguồn thực thi hoàn chỉnh).

    //5. Vườn Thú
    //Lớp cơ sở : DongVat(Tên, Tuổi, Cân Nặng).
    //Lớp kế thừa : Meo(Giống loài), Cho(Giống loài), Chim(Loài chim).
    //Đa hình : Phương thức Keu() để mô tả tiếng kêu đặc trưng của từng loài.
    //Phương thức TinhTienThucAn() được tính dựa trên thuộc tính riêng mỗi loại 
     //làm thay đổi công thức tính.

#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <vector>
#include <fstream>

using namespace std;


// Lớp cơ sở DongVat
class DongVat {

protected:
    string ten;
    int tuoi;
    float canNang;

public:
    // Constructors
    DongVat(string _ten = " ", int _tuoi = 0, float _canNang = 0) 
    {
        _ten = ten;
        _tuoi = tuoi;
        _canNang = canNang;
    }
	// Copy Constructor
    DongVat(const DongVat& other)
    {
        ten = other.ten;
        tuoi = other.tuoi;
        canNang = other.canNang;
    }

    // Destructor
    ~DongVat() {}

    // Getter
    string getTen() { return ten; }
    int getTuoi() { return tuoi; }
    float getCanNang() { return canNang; }
    // Setter
    void setTen(string _ten) { ten = _ten; }
    void setTuoi(int _tuoi) { tuoi = _tuoi; }
    void setCanNang(float _canNang) { canNang = _canNang; }

    // đa hình
    virtual void keu() 
    {
        cout << "Dong vat keu" << endl;
    }

    // Quá tải
    friend istream& operator>>(istream& is, DongVat& dv)
    {
        cout << "Nhap ten: ";
        getline(is, dv.ten);
        cout << "Nhap tuoi: ";
        is >> dv.tuoi;
        cout << "Nhap can nang: ";
        is >> dv.canNang;
        is.ignore(); 
        return is;
    }

    friend ostream& operator<<(ostream& os, DongVat dv) 
    {
        os << "Ten: " << dv.ten << ", Tuoi: " << dv.tuoi << ", Can Nang (Kg): " << dv.canNang;
		return os;
    }
    
	// Phương thức tính tiền thức ăn
    virtual float tinhTienThucAn()
    {
        return 0; 
	}
};

// Lớp kế thừa Meo Từ lớp cơ sở DongVat
class Meo : public DongVat 
{
    private:
		string giongLoai;
    public:
		// Constructor
        Meo(string _ten = " ", int _tuoi = 0, float _canNang = 0,string _giongloai="")
        {
            _ten = ten;
            _tuoi = tuoi;
            _canNang = canNang;
			_giongloai = giongLoai;
        }
		// copy constructor
        Meo(const Meo& other)
        {
            ten = other.ten;
            tuoi = other.tuoi;
            canNang = other.canNang;
            giongLoai = other.giongLoai;
        }
		// destructor
        ~Meo() {}
		// getters/setters cho giongLoai
        string getGiongLoai() { return giongLoai; }
        void setGiongLoai(string _giongLoai) { giongLoai = _giongLoai; }
        // Tieng keu
        void keu() override 
        {
            cout << "Meo Meo" << endl;
		}
        // tinhTienThucAn()
        float tinhTienThucAn() override {
            return canNang * 20000; // 20k/kg cân nặng
        }

        // toán tử nhập 
        friend istream& operator>>(istream& is, Meo& m) 
        {
            is >> static_cast<DongVat&>(m); 
            cout << "Nhap giong loai: ";
            getline(is, m.giongLoai); 
            return is;
        }

        // toán tử xuất 
        friend ostream& operator<<(ostream& os, Meo m) {
            os << static_cast<const DongVat&>(m) 
                << " | Giong loai: " << m.giongLoai; 
            return os;
        }
};


// Lớp kế thừa Cho Từ lớp cơ sở DongVat
class Cho : public DongVat 
{
    private:
	    string giongLoai;
    public:

		// Constructor
        Cho(string _ten = " ", int _tuoi = 0, float _canNang = 0, string _giongloai = "")
        {
            _ten = ten;
            _tuoi = tuoi;
            _canNang = canNang;
            _giongloai = giongLoai;
        }
		// Destructor
		~Cho() {}
       
		// Copy Constructor 
        Cho(const Cho& other)
        {
            ten = other.ten;
            tuoi = other.tuoi;
            canNang = other.canNang;
            giongLoai = other.giongLoai;
        }
		// Getter/Setter
        string getGiongLoai() { return giongLoai; }
        void setGiongLoai(string _giongLoai) { giongLoai = _giongLoai; }

        // Tieng keu
        void keu() override 
        {
            cout << " Gau Gau " << endl;
		}

        // tinhTienThucAn()
        float tinhTienThucAn() override {
            return canNang * 15000; // 15k/kg cân nặng
        }

        //toán tử nhập
        friend istream& operator>>(istream& is, Cho& m) {
            is >> static_cast<DongVat&>(m); 
            cout << "Nhap giong loai: ";
            getline(is, m.giongLoai); 
            return is;
        }

        // toán tử xuất 
        friend ostream& operator<<(ostream& os, Cho m) 
        {
            os << static_cast<const DongVat&>(m)<< " | Giong loai: " << m.giongLoai;
            return os;
        }
};


// Lớp kế thừa Chim Từ lớp cơ sở DongVat
class Chim : public DongVat 
{
    private:
	    string loaiChim;
    public:

        // Constructor
        Chim(string _ten = "", int _tuoi = 0, float _canNang = 0.0, string _loaiChim = "") 
        {
            ten = _ten;
            tuoi = _tuoi;
            canNang = _canNang;
            loaiChim = _loaiChim;
        }
        // Destructor
		~Chim() {}
        
        // Copy Constructor 
        Chim(const Chim& other) 
        {
            ten = other.ten;
            tuoi = other.tuoi;
            canNang = other.canNang;
            loaiChim = other.loaiChim;
        }
        // Getter/Setter
        string getLoaiChim() { return loaiChim; }
        void setLoaiChim(string _loaiChim) { loaiChim = _loaiChim; }
		
        // Tieng keu
        void keu() override
        {
            cout << " Chip Chip " << endl;
        }

        // tinhTienThucAn()
        float tinhTienThucAn() override 
        {
            return canNang * 85000; // 8500/kg cân nặng
        }


        // toán tử nhập
        friend istream& operator>>(istream& is, Chim& m) 
        {
            is >> static_cast<DongVat&>(m); 
            cout << "Nhap giong loai: ";
            getline(is, m.loaiChim); 
            return is;
        }

        // toán tử xuất
        friend ostream& operator<<(ostream& os, Chim m) 
        {
            os << static_cast<const DongVat&>(m) 
                << " | Loai Chim: " << m.loaiChim; 
            return os;
        }

};


void SetColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Hàm hiển thị menu
void Menu() {
    SetColor(13); // Màu xanh dương nhạt
    cout << "\n\n";
    cout << setw(40) << " ______________________________ " << endl;
    cout << setw(40) << "|------------------------------|" << endl;
    cout << setw(40) << "|    QUAN LY VUON THU          |" << endl;
    cout << setw(40) << "|______________________________|" << endl;
    

    SetColor(13); // Màu vàng
    cout << setw(40) << "| 1. Them dong vat moi         |" << endl;
    cout << setw(40) << "| 2. Xem danh sach dong vat    |" << endl;
    cout << setw(40) << "| 3. Nghe tieng keu            |" << endl;
    cout << setw(40) << "| 4. Tinh tien thuc an         |" << endl;
    cout << setw(40) << "| 5. Thoat                     |" << endl;

    SetColor(13); // Màu xanh dương nhạt
    cout << setw(40) << "|______________________________|" << endl;

    SetColor(10); 
    cout << setw(30) << "Lua chon cua ban: ";
    SetColor(7); // Trở lại màu trắng
}

// Hàm hiển thị danh sách động vật đẹp mắt
void HienThiDanhSach( vector<DongVat*>& danhSach) {
    SetColor(13); // Màu hồng
    cout << "\n" << setw(60) << "DANH SACH DONG VAT TRONG VUON THU\n";
    cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;

    // Tiêu đề cột
    SetColor(13);
    cout << setw(5) << "STT" << setw(20) << "Ten"
        << setw(10) << "Tuoi" << setw(15) << "Can nang(KG)"
        << setw(20) << "Loai/Giong" << setw(15) << "Tien thuc an" << endl;
    cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;

    // Dữ liệu
    SetColor(7); // Màu trắng
    for (int i = 0; i < danhSach.size(); ++i) {
        cout << setw(5) << i + 1;

        // Hiển thị thông tin chung
        cout << setw(20) << danhSach[i]->getTen()
            << setw(10) << danhSach[i]->getTuoi()
            << setw(15) << danhSach[i]->getCanNang();

        // Hiển thị thông tin riêng
        if (auto meo = dynamic_cast<Meo*>(danhSach[i])) {
            cout << setw(20) << meo->getGiongLoai();
        }
        else if (auto cho = dynamic_cast<Cho*>(danhSach[i])) {
            cout << setw(20) << cho->getGiongLoai();
        }
        else if (auto chim = dynamic_cast<Chim*>(danhSach[i])) {
            cout << setw(20) << chim->getLoaiChim();
        }

        // Hiển thị tiền thức ăn
        SetColor(10); // Màu xanh lá
        cout << setw(15) << danhSach[i]->tinhTienThucAn() << " VND";
        SetColor(7); // Trở lại màu trắng

        cout << endl;
    }
    cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;
}

// Hàm xử lý lựa chọn menu
void XuLyLuaChon(int choice, vector<DongVat*>& danhSach) {
    switch (choice) {
    case 1: { // Thêm động vật mới
        SetColor(11);
        cout << "\nChon loai dong vat (1-Meo, 2-Cho, 3-Chim): ";
        int type;
        cin >> type;
        cin.ignore();

        DongVat* dv = nullptr;
        switch (type) {
        case 1:
            dv = new Meo();
            cin >> *dynamic_cast<Meo*>(dv);
            break;
        case 2:
            dv = new Cho();
            cin >> *dynamic_cast<Cho*>(dv);
            break;
        case 3:
            dv = new Chim();
            cin >> *dynamic_cast<Chim*>(dv);
            break;
        }

        if (dv) {
            danhSach.push_back(dv);
            SetColor(10);
            cout << "\nThem thanh cong!\n";
        }
        break;
    }

    case 2: { // Xem danh sách
        if (danhSach.empty()) {
            SetColor(12);
            cout << "\nDanh sach trong!\n";
        }
        else {
            HienThiDanhSach(danhSach);
        }
        break;
    }

    case 3: { // Nghe tiếng kêu
        if (danhSach.empty()) {
            SetColor(12);
            cout << "\nDanh sach trong!\n";
        }
        else {
            SetColor(14);
            cout << "\n=== TIENG KEU DONG VAT ===\n";
            for (auto dv : danhSach) {
                SetColor(11);
                cout << setw(15) << dv->getTen() << ": ";
                SetColor(13);
                dv->keu();
            }
        }
        break;
    }

    case 4: { // Tính tiền thức ăn
        if (danhSach.empty()) {
            SetColor(12);
            cout << "\nDanh sach trong!\n";
        }
        else {
            float tongTien = 0;
            for (auto dv : danhSach) {
                tongTien += dv->tinhTienThucAn();
            }
            SetColor(14);
            cout << "\nTong tien thuc an cho toan vuon thu: ";
            SetColor(10);
            cout << tongTien << " VND/ngay\n";
        }
        break;
    }

    case 5: // Thoát
        SetColor(14);
        cout << "\nCam on da su dung chuong trinh!\n";
        break;

    default:
        SetColor(12);
        cout << "\nLua chon khong hop le!\n";
    }

    if (choice != 5) {
        SetColor(7);
        cout << "\nNhan phim bat ky de tiep tuc...";
        cin.get();
    }
}


int main() {

    vector<DongVat*> danhSach;
    int choice;

    danhSach.push_back(new Chim("Rio", 1, 0.3, "Vet"));
    danhSach.push_back(new Chim("John", 1, 3, "Dai Bang"));

    do {
        system("cls");
        Menu();

        // Nhập lựa chọn với kiểm tra lỗi
        while (!(cin >> choice) || choice < 1 || choice > 5) {
            SetColor(12);
            cout << "Lua chon khong hop le! Nhap lai (1-5): ";
            SetColor(7);
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore();

        XuLyLuaChon(choice, danhSach);

    } while (choice != 5);

    // Giải phóng bộ nhớ
    for (auto& dv : danhSach) {
        delete dv;
    }
    danhSach.clear();
   
    return 0;
}