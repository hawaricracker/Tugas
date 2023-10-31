#include <bits/stdc++.h>
using namespace std;
int main()
{
    //bagian deklarasi variabel
    char a;
    int b,sum = 0,cnt = 0;
    float res;
    //mengambil input (x,y,z)
    cin>>a;
    //menggunakan switch untuk membedakan kasus (x,y,z)
    switch (a)
    {
    //bagian jika input x
    case 'x':
        //mengambil input
        cin>>b;
        //menggunakan while supaya dapat mengambil input terus-menerus hingga inputnya -999
        while (b != -999)
        {
            //mengecek apakah bilangan ganjil atau bukan
            if (b % 2 != 0)
            {
                //menambahkan input ke variabel sum
                sum += b;
                //menambahkan jumlah hitungan input
                cnt++;
            }
            cin>>b;
        }
        //menghitung hasil
        res = float(sum)/cnt;
        //menampilkan hasil
        cout<<res<<endl;
        break;

    //bagian jika input y
    case 'y':
        //mengambil input
        cin>>b;
        //menggunakan while supaya dapat mengambil input terus-menerus hingga inputnya -999
        while (b != -999)
        {
            //mengecek apakah bilangan genap atau bukan
            if (b % 2 == 0)
            {
                //menambahkan input ke variabel sum
                sum += b;
                //menambahkan jumlah hitungan input
                cnt++;
            }
            cin>>b;
        }
         //menghitung hasil
        res = float(sum)/cnt;
        //menampilkan hasil
        cout<<res<<endl;
        break;
    
    //bagian jika input z
    default:
        //mengambil input
        cin>>b;
        //menggunakan while supaya dapat mengambil input terus-menerus hingga inputnya -999
        while (b != -999)
        {
            //menambahkan input ke variabel sum
            sum += b;
            //menambahkan jumlah hitungan input
            cnt++;
            cin>>b;
        }
         //menghitung hasil
        res = float(sum)/cnt;
        //menampilkan hasil
        cout<<res<<endl;
        break;
    }
    return 0;
}
