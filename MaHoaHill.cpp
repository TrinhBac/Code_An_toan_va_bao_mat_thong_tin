#include <bits/stdc++.h>

using namespace std;

string chuoiGoc, chuoiMaHoa, banMa="", giaiMa="";
//chuoiGoc --> banMa | chuoiMaHoa --> giaiMa
int mtK[2][2], mtBu[2][2], mtND[2][2];
int a,b,c,d;

string docFile(){
    fstream f;
	f.open("input.txt", ios::in);
	string data;
	string line;
	while (!f.eof())
	{
		getline(f, line);
		data += line;
	}
	f.close();
	cout <<"Du lieu trong file la:"<<endl;
    cout<<data<<endl;
    return data;
}

void ghiFile(string data){
    fstream f;
	f.open("output.txt", ios::out);
	f<<data<<endl;
	f.close();
    cout<<"Da ghi du lieu."<<endl;
}

string toUpperCase(string str){
    for(int i=0;i<=str.length();i++){
        if(str[i]>=97&&str[i]<=122)
            str[i]=str[i]-32;
    }
    return str;
}

//cach 1: tim modulo nghich dao (a^-1 mod m) don gian nhat
int modInverse(int a, int m)
{
    for (int x=-2*m;x<2*m;x++)
        if( ((a%m)*(x%m)) % m == 1)
            return x;
}

int mod(int a, int b){
    if(a<0){
        if(a*1.0/b == a/b)
            return 0;
        else return (26 - abs(a)%b);
    }else
        return a%b;
}

string encode(){
    int tich;
    for(int i=0;i<chuoiGoc.length();i+=2){
        tich = (chuoiGoc[i]-65)*mtK[0][0] +(chuoiGoc[i+1]-65)*mtK[1][0];
        banMa+=char(65 + mod(tich,26));
        tich = (chuoiGoc[i]-65)*mtK[0][1] +(chuoiGoc[i+1]-65)*mtK[1][1];
        banMa+=char(65 + mod(tich,26));
    }
    return banMa;
}

string decode(){
    int tich;
    for(int i=0;i<chuoiMaHoa.length();i+=2){
        tich = (chuoiMaHoa[i]-65)*mtND[0][0] +(chuoiMaHoa[i+1]-65)*mtND[1][0];
        giaiMa+=char(65 + mod(tich,26));
        tich = (chuoiMaHoa[i]-65)*mtND[0][1] +(chuoiMaHoa[i+1]-65)*mtND[1][1];
        giaiMa+=char(65 + mod(tich,26));
    }
    return giaiMa;
}

int main()
{
    cout<<"Nhap chuoi goc: ";
    getline(cin,chuoiGoc);
    chuoiGoc = toUpperCase(chuoiGoc);
    cout<<"Nhap ban ma: ";
    getline(cin,chuoiMaHoa);
    chuoiMaHoa = toUpperCase(chuoiMaHoa);
    cout<<"Nhap ma tran khoa:\n";
    cout<<"a    b"<<endl;
    cout<<"c    d"<<endl;
    cout<<"Nhap a: "; cin>>a; mtK[0][0]=a;
    cout<<"Nhap b: "; cin>>b; mtK[0][1]=b;
    cout<<"Nhap c: "; cin>>c; mtK[1][0]=c;
    cout<<"Nhap d: "; cin>>d; mtK[1][1]=d;
    int detK = mod(a*d-b*c, 26);
    int ndModDetK = modInverse(detK,26);
    mtBu[0][0] = mod(d,26);
    mtBu[0][1] = mod(-1*b,26);;
    mtBu[1][0] = mod(-1*c,26);
    mtBu[1][1] = mod(a,26);
    mtND[0][0] = mod(ndModDetK*mtBu[0][0],26);
    mtND[0][1] = mod(ndModDetK*mtBu[0][1],26);
    mtND[1][0] = mod(ndModDetK*mtBu[1][0],26);
    mtND[1][1] = mod(ndModDetK*mtBu[1][1],26);

    cout<<"--> Ma hoa "+chuoiGoc+" la: "+encode()<<endl;
    cout<<"--> Giai ma "+chuoiMaHoa+" la: "+decode()<<endl;
    ghiFile(giaiMa);

	return 0;
}
