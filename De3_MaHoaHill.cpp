#include <bits/stdc++.h>

using namespace std;

string chuoiGoc, chuoiMaHoa, banMa="", giaiMa="";
//chuoiGoc --> banMa | chuoiMaHoa --> giaiMa
int mtK[2][2], mtBu[2][2], mtND[2][2];
int a,b,c,d;

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
    int tich;
    for(int i=0;i<chuoiGoc.length();i+=2){
        tich = (chuoiGoc[i]-65)*mtK[0][0] +(chuoiGoc[i+1]-65)*mtK[1][0];
        banMa+=char(65 + mod(tich,26));
        tich = (chuoiGoc[i]-65)*mtK[0][1] +(chuoiGoc[i+1]-65)*mtK[1][1];
        banMa+=char(65 + mod(tich,26));
    }
    return banMa;
}

int main()
{
    chuoiGoc = "HARD";
    a=12; mtK[0][0]=a;
    b=5; mtK[0][1]=b;
    c=3; mtK[1][0]=c;
    d=7; mtK[1][1]=d;
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
    cout<<"Nhap chuoi can so sanh: ";
    getline(cin,chuoiMaHoa);
    if(chuoiMaHoa == banMa)
        cout<<"Ban nhap dung"<<endl;
    else
        cout<<"Ban nhap sai"<<endl;
    printf("--> Ma tran K(giai ma) la:\n");
    cout<<mtND[0][0]<<"\t"<<mtND[0][1]<<endl;
    cout<<mtND[1][0]<<"\t"<<mtND[1][1]<<endl;

	return 0;
}
