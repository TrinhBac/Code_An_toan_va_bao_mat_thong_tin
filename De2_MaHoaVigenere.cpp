#include <bits/stdc++.h>

using namespace std;

string chuoiGoc, chuoiMaHoa, banMa="", giaiMa="", khoa;
//chuoiGoc --> banMa | chuoiMaHoa --> giaiMa

int mod(int a, int b){
    if(a<0){
        if(a*1.0/b == a/b)
            return 0;
        else return (b - abs(a)%b);
    }else
        return a%b;
}

string encode(){
    int c=0, k=khoa.length();
    for(int i=0;i<chuoiGoc.length();i++){
        banMa+=char(65 + mod(chuoiGoc[i]+khoa[c%k]-65*2,26));
        c++;
    }
    return banMa;
}

string timKhoa(){
    string khoa = "";
    string banRo = "PSYCHE";
    string banMa = "RANJLV";
    for(int i=0;i<banMa.length();i++){
        if(banMa[i]<banRo[i])
            khoa+=char(banMa[i]-banRo[i] + 65 + 26);
        else    khoa+=char(banMa[i]-banRo[i] + 65);
    }
    return khoa;
}

int main()
{
    chuoiGoc = "THISCRYPTOSY";
    khoa = "WIZARD";
    cout<<"--> Ma hoa "+chuoiGoc+" la: "+encode()<<endl;
    cout<<"Nhap chuoi can kiem tra: ";
    getline(cin, chuoiMaHoa);
    if(chuoiMaHoa == banMa)
        cout<<"Ban nhap dung"<<endl;
    else cout<<"Ban nhap sai"<<endl;
    cout<<"Khoa la: "<<timKhoa()<<endl;

	return 0;
}
