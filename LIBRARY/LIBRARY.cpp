#include <iostream>
#include <fstream>
using namespace std;

    string dataAnggota[100][3];
    char confirm;
	fstream fileAnggota;
    string Buku[1][5]={"Judul Buku\t","Penulis","\tTahun Terbit","\tKategori","No.Seri"};
    string dataBuku[100][5];
	fstream fileBuku;
    string Peminjaman[1][5]={"No. seri buku\t","Nomor anggota","\tTanggal Pinjam","\tTanggal Kembali","\tDenda"};

	fstream filePeminjaman;
	int transaksi,baristerakhir;
    string dataPeminjaman[100][5];


void subAnggota();
void subBuku();
void subPeminjaman();
void subDenda (string buku, string nim, string hari,string bulan, string tahun);
void subPinjem();
void subRajin();
void subTanggalTerbit();
int main()
{
    int sub;
    cout<<"_______________________"<<endl;
    cout<<" SISTEM PERPUSTAKAAN "<<endl;
    cout<<"_______________________"<<endl<<endl;
    cout<<"1. Pendaftaran Anggota Baru"<<endl;
    cout<<"2. Input data buku"<<endl;
    cout<<"3. Transaksi peminjaman/pengembalian buku"<<endl;
    cout<<"4. Buku yang paling sering dipinjam"<<endl;
    cout<<"5. Anggota yang paling rajin"<<endl;
    cout<<"6. Buku berdasarkan tahun"<<endl <<endl;

    cout<<"Pilih program yang akan dijalankan: ";cin>>sub;

    switch(sub)
    {
        case 1: subAnggota(); break;
        case 2: subBuku(); break;
        case 3: subPeminjaman(); break;
        case 4: subPinjem();break;
        case 5: subRajin();break;
        case 6: subTanggalTerbit();break;
        default: cout << "Input error. Silahkan restart program"<<endl; return 0;
    }
}

void subAnggota()
{

	fileAnggota.open("Anggota.txt", ios::in);
    baristerakhir=0;
    for(int i = 0 ; i < 100 ; i++){
        if(fileAnggota.eof()){
            break;
        }
        for(int j = 0 ; j <3 ; j++){

            fileAnggota >> dataAnggota[i][j];

        }
         baristerakhir++;
    }

    bool sudah = false;
    fileAnggota.close();
    cout<<endl<<"# Pendaftaran Anggota Baru Perpustakaan #"<<endl;
    fileAnggota.open("Anggota.txt", ios::app);
    for (int j = baristerakhir;j < 100;j++)
    {
        for (int i=0;i<3;i++)
        {
            if (i==0)
            {

                    cout <<"Nomor Anggota : ";
                    cin >> dataAnggota[j][i];
            }
            else if (i==1)
                {
                    cout<<"Nama: ";
                    cin>>dataAnggota[j][i]; //cuma 1 kata
                }
                else
                {
                    cout<<"Jenis keanggotaan: ";
                    cin>>dataAnggota[j][i];
                }

            fileAnggota<<dataAnggota[j][i]<<"\t";
        }

        sudah = true;
        fileAnggota<<endl;
        cout<<endl;
        cout<<"Tekan Y untuk kembali ke menu utama, N untuk kembali menambahkan anggota baru: ";cin>>confirm;
        while(confirm != 'Y' || confirm  != 'N'){
            if(confirm == 'Y' || confirm  == 'N'){
                break;
            }
            cout<<"Tekan Y untuk kembali ke menu utama, N untuk kembali menambahkan anggota baru: ";cin>>confirm;

        }
        switch (confirm)
        {
            case 'Y': main();fileAnggota.close(); break;
            case 'N': subAnggota(); break;
        }
    }
}


void subBuku()
{


	fileBuku.open("Data Buku.txt" , ios::in);
    baristerakhir=0;
     for(int i = 0 ; i < 100 ; i++){
        if(fileBuku.eof()){
            break;
        }

        for(int j = 0 ; j < 5 ; j++){
            fileBuku >> dataBuku[i][j];
        }
         baristerakhir++;
    }

    fileBuku.close();
    fileBuku.open("Data Buku.txt" , ios::app);
    cout<<endl<<"# Pendataan buku #"<<endl;
    bool sudah = true;
    for (int j=baristerakhir;j<100;j++)
    {
        for (int i=0;i<5;i++)
        {
            if (i==0)
            {
                cout<<"Judul buku: ";
                cin>>dataBuku[j][i];
            }
            else if (i==1)
                {
                    cout<<"Penulis: ";
                    cin>>dataBuku[j][i]; //cuma 1 kata
                }
                else if (i==2)
                    {
                        cout<<"Tahun terbit: ";
                        cin>>dataBuku[j][i];
                    }
                    else if (i==3)
                        {
                            cout<<"Kategori: ";
                            cin>>dataBuku[j][i];
                        }
                        else if (i==4)
                            {
                                    cout<<"Nomor Seri: ";///first name
                                    cin>>dataBuku[j][i];


                                }


            fileBuku<<dataBuku[j][i] << "\t";
            sudah = true;
        }
        fileBuku<<endl;
        cout<<endl;

        cout<<"Tekan Y untuk kembali ke menu utama, N untuk kembali menambahkan buku: ";cin>>confirm;
        while(confirm != 'Y' || confirm  != 'N'){
            if(confirm == 'Y' || confirm  == 'N'){
                break;
            }
            cout<<"Tekan Y untuk kembali ke menu utama, N untuk kembali menambahkan buku: ";cin>>confirm;

        }
        switch (confirm)
        {
            case 'Y': main();fileBuku.close(); break;
            case 'N': subBuku(); break;
        }

    }

}





void subPeminjaman()
{

	fstream filePeminjaman;
	int transaksi,kolomterakhir=0;
	filePeminjaman.open("Peminjaman.txt",ios::in);
    baristerakhir=0;
     for(int i = 0 ; i < 100 ; i++){
        if(filePeminjaman.eof()){
            break;
        }
        for(int j = 0 ; j < 5 ; j++){
            filePeminjaman >> dataPeminjaman[i][j];
        }
         baristerakhir++;
    }
    filePeminjaman.close();

	cout<<endl<<"# Transaksi buku #"<<endl;

    cout<<"1. Peminjaman"<<endl;
    cout<<"2. Pengembalian"<<endl;
    cout<<"Pilih jenis transaksi yang ingin dijalankan: ";cin>>transaksi;
    string day,month,year;
    string buku,nim;
    	filePeminjaman.open("Peminjaman.txt",ios::app);
    switch(transaksi){
    case 1:
        for(int i = baristerakhir ; i < 100 ; i++){
            for(int j = 0; j < 5;j++ ){
                if(j == 0){
                    cout << "No Anggota : ";
                    cin >> dataPeminjaman[i][j];

                }
                else if(j == 1){
                    cout << "No Buku : \t";
                    cin >> dataPeminjaman[i][j];
                }
                else if(j == 2){
                    cout << "Hari : \t";
                    cin >> dataPeminjaman[i][j];
                }
                else if(j == 3){
                    cout << "Bulan: \t";
                    cin >> dataPeminjaman[i][j];
                }
                 else if(j == 4){
                    cout << "Tahun: \t";
                    cin >> dataPeminjaman[i][j];
                }
                filePeminjaman<< dataPeminjaman[i][j] << "\t";
            }

            filePeminjaman<<endl;
        cout<<"Tekan Y untuk kembali ke menu utama, N untuk kembali menambahkan buku: ";cin>>confirm;
        while(confirm != 'Y' || confirm  != 'N'){
            if(confirm == 'Y' || confirm  == 'N'){
                break;
            }
            cout<<"Tekan Y untuk kembali ke menu utama, N untuk kembali menambahkan buku: ";cin>>confirm;

        }
        switch (confirm)
        {
            case 'Y': fileBuku.close();main();; break;
            case 'N': subPeminjaman(); break;
        }
        }

        break;
    case 2:
        cout << "No. Buku: ";
        cin >> buku;
        cout << "No. NIM: ";
        cin >> nim;
        cout << "Pengembalian DD/MM/YY " << endl;
        cout <<"Hari : ";
        cin >> day;
        cout <<"Bulan : ";
        cin >> month;
        cout <<"Tahun : ";
        cin >> year;
        subDenda(buku,nim,day,month,year);
        break;
    }
    main();

}

void subDenda (string buku,string nim,string hari,string bulan,string tahun)
{
    filePeminjaman.open("Peminjaman.txt",ios::in);
    baristerakhir=0;
     for(int i = 0 ; i < 100 ; i++){
        if(filePeminjaman.eof()){
            break;
        }
        for(int j = 0 ; j < 5 ; j++){
            filePeminjaman >> dataPeminjaman[i][j];
        }
         baristerakhir++;
    }

    filePeminjaman.close();
    string jenisAnggota, mahasiswa, dosen;
    fstream check;
    int day =0 ,month = 0, year = 0;
    int day1 =0 ,month1 = 0, year1 = 0;
    ///konversi hari
    if(hari[0] > 48){
        day = (hari[0] -48) * 10;
    }
    day = day + (hari[1]-48);
        ///konversi bulan
    if(bulan[0] > 48){
        month = (bulan[0] -48) * 10;
    }
    month = month + (bulan[1]-48);


    ///konversi tahun
    if(tahun[0] > 48){
        year = (tahun[0] -48) * 1000;
    }
    if(tahun[1] > 48){
        year = year+(tahun[1] -48) * 100;
    }
    if(tahun[2] > 48){
        year = year+(tahun[2] -48) * 10;
    }
    year = year + (tahun[3]-48);
    int selisihTahun,selisihBulan,selisihHari;

    int denda = 0;

    if(nim[0] == '1'){
        jenisAnggota = "Mahasiswa";
    }
    else if(nim[0] == '2'){
        jenisAnggota = "Dosen";
    }
    for(int i = 0 ; i < baristerakhir;i++){
        if(dataPeminjaman[i][1] == buku &&  dataPeminjaman[i][0] == nim){
                    if(dataPeminjaman[i][2][0] > 48){
                        day1 = (dataPeminjaman[i][2][0] -48) * 10;
                    }
                    day1 = day1 + (dataPeminjaman[i][2][1]-48);
                        ///konversi bulan
                    if(dataPeminjaman[i][3][0] > 48){
                        month1 = (dataPeminjaman[i][3][0] -48) * 10;
                    }
                    month1 = month1 + (dataPeminjaman[i][3][1]-48);

                    ///konversi tahun
                    if(dataPeminjaman[i][4][0] > 48){
                        year1 = (dataPeminjaman[i][4][0]-48) * 1000;
                    }
                    if(dataPeminjaman[i][4][1]> 48){
                        year1 = year1+ (dataPeminjaman[i][4][1]-48) * 100;
                    }
                    if(dataPeminjaman[i][4][2] > 48){
                        year1 = year1+(dataPeminjaman[i][4][2] -48) * 10;
                    }
                    year1 = year1 + (dataPeminjaman[i][4][3]-48);
                selisihTahun = (year1-year) *12;
                selisihBulan = ((selisihTahun + month1) - month) * 30;
                selisihHari =  ((selisihBulan + day1) - day) *-1;
                if(jenisAnggota == "Mahasiswa") {
                    if(selisihHari > 14){
                        denda = (selisihHari-14) * 1000;

                    }
                }
                else{
                    if((selisihHari/30) > 6){
                        denda = (selisihHari -180) * 1000;
                    }
                }


        }
    }
     cout << "Denda : " << denda << endl;
     filePeminjaman.close();
}

void subPinjem(){
    filePeminjaman.open("Peminjaman.txt",ios::in);
    baristerakhir=0;
     for(int i = 0 ; i < 100 ; i++){
        if(filePeminjaman.eof()){
            break;
        }
        for(int j = 0 ; j < 5 ; j++){
            filePeminjaman >> dataPeminjaman[i][j];
        }
         baristerakhir++;
    }

    int maks = 0;
    int temp = 0;
    int indeksMaks;
    for(int i =0 ;i < baristerakhir; i++){
            temp = 0;
            for(int j = 0 ; j < baristerakhir ;j++ ){
                if(dataPeminjaman[i][1] == dataPeminjaman[j][1]){
                    temp++;
                }

            }
        if(temp > maks){
            maks = temp;
            indeksMaks = i;
        }
    }

    fileBuku.open("Data Buku.txt" , ios::in);
    baristerakhir=0;
     for(int i = 0 ; i < 100 ; i++){
        if(fileBuku.eof()){
            break;
        }

        for(int j = 0 ; j < 5 ; j++){
            fileBuku >> dataBuku[i][j];
        }
         baristerakhir++;
    }
    for(int p = 0 ; p < baristerakhir ; p++ ){
        if(dataPeminjaman[indeksMaks][1] == dataBuku[p][4]){
            cout << dataBuku[p][0];
            break;
        }
    }
    fileBuku.close();
    filePeminjaman.close();
    main();
}


void subRajin(){

   filePeminjaman.open("Peminjaman.txt",ios::in);
    baristerakhir=0;
     for(int i = 0 ; i < 100 ; i++){
        if(filePeminjaman.eof()){
            break;
        }
        for(int j = 0 ; j < 5 ; j++){
            filePeminjaman >> dataPeminjaman[i][j];
        }
         baristerakhir++;
    }

    int maks = 0;
    int temp = 0;
    int indeksMaks;
    for(int i =0 ;i < baristerakhir; i++){
            temp = 0;
            for(int j = 0 ; j < baristerakhir ;j++ ){
                if(dataPeminjaman[i][0] == dataPeminjaman[j][0]){
                    temp++;
                }

            }
        if(temp > maks){
            maks = temp;
            indeksMaks = i;
        }

    }

    fileAnggota.open("Anggota.txt", ios::in);
    baristerakhir=0;
    for(int i = 0 ; i < 100 ; i++){
        if(fileAnggota.eof()){
            break;
        }
        for(int j = 0 ; j <3 ; j++){

            fileAnggota >> dataAnggota[i][j];

        }
         baristerakhir++;
    }
    for(int p = 0 ; p < baristerakhir ; p++ ){
        if(dataPeminjaman[indeksMaks][0] == dataAnggota[p][0]){
            cout << dataAnggota[p][1];
            break;
        }
    }
    fileAnggota.close();
    filePeminjaman.close();

    main();
}

void subTanggalTerbit(){

    fileBuku.open("Data Buku.txt" , ios::in);
    baristerakhir=0;
     for(int i = 0 ; i < 100 ; i++){
        if(fileBuku.eof()){
            break;
        }

        for(int j = 0 ; j < 5 ; j++){
            fileBuku >> dataBuku[i][j];
        }
         baristerakhir++;
    }

    for(int i = 0 ; i<baristerakhir ; i++){
        for(int j = 0 ; j<baristerakhir + i +1;j++ ){
            if(dataBuku[i][2] < dataBuku[j][2]){
                swap(dataBuku[i],dataBuku[j]);
            }

        }
    }
    for(int p = 0 ; p < baristerakhir; p++){

        cout << dataBuku[p][2]<<" - "<<dataBuku[p][1]<<" - "<< dataBuku[p][0]<<endl;
    }

    main();

}



