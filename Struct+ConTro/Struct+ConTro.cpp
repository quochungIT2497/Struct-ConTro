#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct QuyPhi
{
    QuyPhi(string ht, string qq, int t, float cc, float v1, float v2, float v3)//rút gọn khai báo struct
    {
        Ho_Ten = ht;
        QueQuan = qq;
        tuoi = t;
        chieu_cao = cc;
        vong_1 = v1;
        vong_2 = v2;
        vong_3 = v3;
        sungai = false;
        Chinhcung = false;
    };
    QuyPhi(const QuyPhi& copy)//Tạo thông báo khi có tạo bản sao dữ liệu thuộc 1 địa chỉ bộ nhớ
    {
        Ho_Ten = copy.Ho_Ten;
        QueQuan = copy.QueQuan;
        tuoi = copy.tuoi;
        chieu_cao = copy.chieu_cao;
        vong_1 = copy.vong_1;
        vong_2 = copy.vong_2;
        vong_3 = copy.vong_3;
        sungai = copy.sungai;
        cout << "Tao copy cua " << copy.Ho_Ten << endl;
        Ho_Ten = Ho_Ten + "(copied)";
    }
    virtual int So_lan_tham()//đặt tạo giá trị ảo để xuất các struct hdt kế thừa
    {
        return 14;
    }
    string Ho_Ten;
    string QueQuan;
    int tuoi;
    float chieu_cao;
    float vong_1;
    float vong_2;
    float vong_3;
    bool sungai;// kiểu dữ liệu true false
    bool Chinhcung;
};

struct DongCung : public QuyPhi //HĐT kế thừa QuyPhi
{
    DongCung(string ht, string qq, int t, float cc, float v1, float v2, float v3) : QuyPhi(ht, qq, t, cc, v1, v2, v3)
    {}
    int So_lan_tham()
    {
        return 10;
    }
};

struct TayCung : public QuyPhi //HĐT kế thừa QuyPhi
{
    TayCung(string ht, string qq, int t, float cc, float v1, float v2, float v3) : QuyPhi(ht, qq, t, cc, v1, v2, v3)
    {}
    int So_lan_tham()
    {
        return 3;
    }
};

struct NamCung : public QuyPhi //HĐT kế thừa QuyPhi
{
    NamCung(string ht, string qq, int t, float cc, float v1, float v2, float v3) : QuyPhi(ht, qq, t, cc, v1, v2, v3)
    {}
    int So_lan_tham()
    {
        return 2;
    }
};

struct HoangThat : public QuyPhi
{
    HoangThat(string ht, string qq, int t, float cc, float v1, float v2, float v3) : QuyPhi(ht, qq, t, cc, v1, v2, v3)
    {}
    int So_lan_tham()
    {
        return 30;
    }
};

void sung_ai(QuyPhi* yeuthich)//Đặt con trỏ trỏ vào chính xác vị trí vùng dữ liệu để không bị tạo bản copy và cho ra kq sửa đổi chính xác với trường được trỏ vào
{
    cout << " So lan hoang thuong ghe tham Quy Phi " << (*yeuthich).Ho_Ten << " la " << yeuthich ->So_lan_tham() << endl;//Dùng syntax hướng đối tượng để chỉ vào số lần thăm
    //cout <<(*yeuthich).Ho_Ten <<" Co duoc hoang thuong sung ai? " << endl;
    if (yeuthich->So_lan_tham() >= 10)//Syntax HDT trỏ về số lần thăm
    {
        (*yeuthich).sungai = true;
    }
}

void Chinh_cung(QuyPhi* Chinhcung)
{
    if (Chinhcung->So_lan_tham() >= 30)
    {
        (*Chinhcung).Chinhcung = true;
    }
}

int main()
{
    QuyPhi* phitan[5] = //tạo con trỏ mảng với 4 phần tử mới - nếu không dùng HĐT thì loại bỏ new
    {
      new QuyPhi("Nga","Ha Noi",20,1.75,95,60,100),
      new DongCung("Ngoc","Bac Ninh",18,1.7,90,58,92),
      new NamCung("Huynh","Nha Trang",25,1.72,88,55,102),
      new TayCung("Truc","TP HCM",30,1.69,110,65,105),
      new HoangThat("Uyen","Da Nang",18,1.6,95,65,100)
    };
    /*QuyPhi Nga("Ha Noi",20,1.75,95,60,100);
    QuyPhi Ngoc("Bac Ninh",18,1.7, 90,58,92);
    QuyPhi *aiphi = nullptr;
    aiphi = &Nga;
    //Nga.tuoi = 25;
    cout<<(*aiphi).tuoi<<endl;
    aiphi = &Ngoc;
    cout<<"------------"<<endl;
    cout<<(*aiphi).QueQuan<<endl;
    QuyPhi *aiphi;*/
    /* for (aiphi = &phitan[0]; aiphi < phitan + 4; aiphi++)
     {
         cout << (*aiphi).Ho_Ten << endl;
         cout << (*aiphi).tuoi << endl;
         cout << (*aiphi).QueQuan << endl;
         cout << (*aiphi).chieu_cao << endl;
         cout << (*aiphi).vong_1 << endl;
         cout << (*aiphi).vong_2 << endl;
         cout << (*aiphi).vong_3 << endl;
         cout << "------" << endl;
     }
     cout<<phitan[3].Ho_Ten<<" co phai la nguoi duoc hoang thuong uu ai? "<<(phitan[3].sungai ? " Dung vay "
     : " Khong phai ")<<endl;
     sung_ai(&phitan[3]);
     cout << phitan[3].Ho_Ten << " co phai la nguoi duoc hoang thuong uu ai? " << (phitan[3].sungai ? " Dung vay "
         : " Khong phai ") << endl;*/
    QuyPhi* aiphi;//tạo con trỏ mới
    for (int i = 0; i < 4; i++)
    {
        cout << (*phitan[i]).Ho_Ten << endl;//vì ở trên dùng con trỏ mảng mới -> dùng trỏ mảng mới cho phần in
        cout << (*phitan[i]).tuoi << endl;
        cout << (*phitan[i]).QueQuan << endl;
        cout << (*phitan[i]).chieu_cao << endl;
        cout << (*phitan[i]).vong_1 << endl;
        cout << (*phitan[i]).vong_2 << endl;
        cout << (*phitan[i]).vong_3 << endl;
        cout << "------" << endl;
    }
    /*cout << (*phitan[2]).Ho_Ten << " co phai la nguoi duoc hoang thuong uu ai? " << ((*phitan[2]).sungai ? " Dung vay "
        : " Khong phai ") << endl;
    cout << "-------------------------" << endl;*/
    for (int i = 0; i < 5; i++)
    {
        aiphi = phitan[i];
        sung_ai(aiphi);
        cout << (*aiphi).Ho_Ten << " co phai la nguoi duoc hoang thuong uu ai? " <<endl<< ((*aiphi).sungai ? " Dung vay "
            : " Khong phai ") << endl;
        Chinh_cung(aiphi);
        cout << " Quy phi " << (*aiphi).Ho_Ten << " la Hoang Hau tuong lai ?" << endl;
        cout << ((*aiphi).Chinhcung ? " Chinh Xac " : " Chua chinh xac") << endl;
    }
    //cout << phitan[0].QueQuan<<endl;
    return 0;
}
