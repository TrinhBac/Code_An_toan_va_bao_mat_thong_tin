#include <bits/stdc++.h>

using namespace std;

string chuoiGoc, chuoiMaHoa, banMa="", giaiMa="";
//chuoiGoc --> banMa | chuoiMaHoa --> giaiMa
int k;

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

int mod(int a, int b){
    if(a<0){
        if(a*1.0/b == a/b)
            return 0;
        else return (b - abs(a)%b);
    }else
        return a%b;
}

string encode(){
    for(int i=0;i<chuoiGoc.length();i++)
        banMa+=char(65 + mod(chuoiGoc[i]-65+k,26));
    return banMa;
}

string decode(){
    for(int i=0;i<chuoiMaHoa.length();i++)
        giaiMa+=char(65 + mod(chuoiMaHoa[i]-65-k,26));
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
    cout<<"Nhap khoa k: ";
    cin>>k;
    cout<<"--> Ma hoa "+chuoiGoc+" la: "+encode()<<endl;
    cout<<"--> Giai ma "+chuoiMaHoa+" la: "+decode()<<endl;
    ghiFile(giaiMa);

	return 0;
}
