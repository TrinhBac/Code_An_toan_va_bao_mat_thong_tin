#include <bits/stdc++.h>

using namespace std;

string chuoiGoc, chuoiMaHoa, banMa="", giaiMa="";
//chuoiGoc --> banMa | chuoiMaHoa --> giaiMa
int a,b,k;

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

//cach 2: theo eclip mo rong tim (a^-1 mod m)
int eclipModInverse(int a, int b)
{
	int b0=b,t,q;
	int x0=0,x1=1;
	if(b==1) return 1;
	while(a>1){
		q=a/b;
		t=b, b=a%b, a=t;
		t=x0, x0=x1-q*x0, x1=t;
	}
	if(x1<0)
        x1+= b0;
	return x1;
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
    for(int i=0;i<chuoiGoc.length();i++)
        banMa+=char(65 + mod(a*(chuoiGoc[i]-65)+ b,26));
    return banMa;
}

string decode(){
    int k=eclipModInverse(a,26);
    for(int i=0;i<chuoiMaHoa.length();i++)
        giaiMa+=char(65 + mod(k*(chuoiMaHoa[i]-65-b),26));
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
    cout<<"Nhap a: ";
    cin>>a;
    cout<<"Nhap b: ";
    cin>>b;
    cout<<"--> Ma hoa "+chuoiGoc+" la: "+encode()<<endl;
    cout<<"--> Giai ma "+chuoiMaHoa+" la: "+decode()<<endl;
    ghiFile(giaiMa);

	return 0;
}
