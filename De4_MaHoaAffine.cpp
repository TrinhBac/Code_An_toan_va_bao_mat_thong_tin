#include <bits/stdc++.h>

using namespace std;

string chuoiGoc, chuoiMaHoa, banMa="", giaiMa="";
//chuoiGoc --> banMa | chuoiMaHoa --> giaiMa
int a,b,k;

int modInverse(int a, int m)
{
    for(int i=1;i<m;i++)
        if((a*i)%m == 1)
            return i;
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
        banMa+=char(65 + mod(a*(chuoiGoc[i]-65)+ b,26));
    return banMa;
}

int main()
{
    chuoiGoc = "TAURUS";
    a=17, b=5;
    cout<<"--> Ma hoa "+chuoiGoc+" la: "+encode()<<endl;
    cout<<"Nhap chuoi can so sanh: ";
    getline(cin, chuoiMaHoa);
    if(chuoiMaHoa == banMa)
        cout<<"Ban nhap dung"<<endl;
    else
        cout<<"Ban nhap sai"<<endl;
    printf("K(giai ma) = (%d, %d)",modInverse(17,26),5);

	return 0;
}
