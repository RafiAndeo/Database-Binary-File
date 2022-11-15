#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct makanan{
    string idMenu;
    string namaMenu;
    string deskripsi;
    double harga;
    string klasifikasi;
};

struct pesanan{
    string idPesanan;
    string atasNama;
    string tanggal;
    string jam;
    double total;
};

struct detilPesanan{
    string idPesanan;
    string idMenu;
    int jumlah;
    double harga;
    double totalHarga;
};

makanan ambilData(int posisi, fstream &myFile){
    makanan bufferData;

    myFile.seekp((posisi - 1)*sizeof(makanan));
    myFile.read(reinterpret_cast<char*>(&bufferData),sizeof(makanan));

    return bufferData;
}

pesanan ambilData2(int posisi, fstream &myFile){
    pesanan bufferData;

    myFile.seekp((posisi - 1)*sizeof(pesanan));
    myFile.read(reinterpret_cast<char*>(&bufferData),sizeof(pesanan));

    return bufferData;
}

detilPesanan ambilData3(int posisi, fstream &myFile){
    detilPesanan bufferData;

    myFile.seekp((posisi - 1)*sizeof(detilPesanan));
    myFile.read(reinterpret_cast<char*>(&bufferData),sizeof(detilPesanan));

    return bufferData;
}

void menulisData(makanan &data, fstream &myFile){
    myFile.write(reinterpret_cast<char*>(&data),sizeof(makanan));
}

void menulisData2(pesanan &data, fstream &myFile){
    myFile.write(reinterpret_cast<char*>(&data),sizeof(pesanan));
}

void menulisData3(detilPesanan &data, fstream &myFile){
    myFile.write(reinterpret_cast<char*>(&data),sizeof(detilPesanan));
}

void menulisDataByPos(int posisi, makanan &bufferData, fstream &myFile){
    myFile.seekg((posisi-1)*sizeof(makanan));
    myFile.write(reinterpret_cast<char*>(&bufferData),sizeof(makanan));
}

void menulisDataByPos2(int posisi, pesanan &bufferData, fstream &myFile){
    myFile.seekg((posisi-1)*sizeof(pesanan));
    myFile.write(reinterpret_cast<char*>(&bufferData),sizeof(pesanan));
}

void menulisDataByPos3(int posisi, detilPesanan &bufferData, fstream &myFile){
    myFile.seekg((posisi-1)*sizeof(detilPesanan));
    myFile.write(reinterpret_cast<char*>(&bufferData),sizeof(detilPesanan));
}

int main(){
    fstream myFile;
    fstream myFile2;
    fstream myFile3;
    myFile.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
    myFile2.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
    myFile3.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);

    makanan makanan1, makanan2, makanan3, makanan4, makanan5, makanan6, makanan7, makanan8, makanan9, makanan10, makanan11, makanan12, makanan13, makanan14, makanan15, makanan16, makanan17, makanan18, makanan19, makanan20, makanan21, makanan22, makanan23, makanan24, makanan25, output;
    pesanan pesanan1, pesanan2, pesanan3, pesanan4, pesanan5, pesanan6, pesanan7, pesanan8, pesanan9, pesanan10, pesanan11, pesanan12, pesanan13, pesanan14, pesanan15, pesanan16, pesanan17, pesanan18, pesanan19, pesanan20, pesanan21, pesanan22, pesanan23, pesanan24, pesanan25, output2;
    detilPesanan dp1, dp2, dp3, dp4, dp5, dp6, dp7, dp8, dp9, dp10, dp11, dp12, dp13, dp14, dp15, dp16, dp17, dp18, dp19, dp20, dp21, dp22, dp23, dp24, dp25, output3;

    makanan1.idMenu = "bks1";
    makanan1.namaMenu = "bakso";
    makanan1.deskripsi = "makanan berkuah berdaging";
    makanan1.harga = 10000;
    makanan1.klasifikasi = "makanan utama";

    makanan2.idMenu = "nsgr2";
    makanan2.namaMenu = "nasi goreng";
    makanan2.deskripsi = "makanan bernasi";
    makanan2.harga = 15000;
    makanan2.klasifikasi = "makanan utama";

    makanan3.idMenu = "btgr3";
    makanan3.namaMenu = "batagor";
    makanan3.deskripsi = "makanan berminyak bersaos";
    makanan3.harga = 2000;
    makanan3.klasifikasi = "makanan pembuka";

    makanan4.idMenu = "lmbs4";
    makanan4.namaMenu = "lumpia basah";
    makanan4.deskripsi = "makanan berminyak bersaos";
    makanan4.harga = 7000;
    makanan4.klasifikasi = "makanan utama";

    makanan5.idMenu = "mgr5";
    makanan5.namaMenu = "mie goreng";
    makanan5.deskripsi = "makanan berminyak bersaos";
    makanan5.harga = 6000;
    makanan5.klasifikasi = "makanan utama";

    makanan6.idMenu = "mkh6";
    makanan6.namaMenu = "mie kuah";
    makanan6.deskripsi = "makanan berkuah berbumbu";
    makanan6.harga = 6000;
    makanan6.klasifikasi = "makanan utama";

    makanan7.idMenu = "sta7";
    makanan7.namaMenu = "sate ayam";
    makanan7.deskripsi = "makanan berbumbu bersaos";
    makanan7.harga = 3000;
    makanan7.klasifikasi = "makanan pembuka";

    makanan8.idMenu = "stk8";
    makanan8.namaMenu = "sate kambing";
    makanan8.deskripsi = "makanan berbumbu bersaos";
    makanan8.harga = 5000;
    makanan8.klasifikasi = "makanan pembuka";

    makanan9.idMenu = "dnt9";
    makanan9.namaMenu = "donat";
    makanan9.deskripsi = "makanan bergula";
    makanan9.harga = 8000;
    makanan9.klasifikasi = "makanan penutup";

    makanan10.idMenu = "aygr10";
    makanan10.namaMenu = "ayam goreng";
    makanan10.deskripsi = "makanan berminyak";
    makanan10.harga = 5000;
    makanan10.klasifikasi = "makanan pembuka";

    makanan11.idMenu = "aybk11";
    makanan11.namaMenu = "ayam bakar";
    makanan11.deskripsi = "makanan bersaos";
    makanan11.harga = 4000;
    makanan11.klasifikasi = "makanan pembuka";

    makanan12.idMenu = "aygl12";
    makanan12.namaMenu = "ayam gulai";
    makanan12.deskripsi = "makanan berbumbu";
    makanan12.harga = 6000;
    makanan12.klasifikasi = "makanan pembuka";

    makanan13.idMenu = "ayci13";
    makanan13.namaMenu = "ayam cabe ijo";
    makanan13.deskripsi = "makanan berbumbu";
    makanan13.harga = 4000;
    makanan13.klasifikasi = "makanan pembuka";

    makanan14.idMenu = "aycm14";
    makanan14.namaMenu = "ayam cabe merah";
    makanan14.deskripsi = "makanan berminyak berbumbu";
    makanan14.harga = 4000;
    makanan14.klasifikasi = "makanan pembuka";

    makanan15.idMenu = "aysw15";
    makanan15.namaMenu = "ayam suwir";
    makanan15.deskripsi = "makanan berminyak";
    makanan15.harga = 2000;
    makanan15.klasifikasi = "makanan pembuka";

    makanan16.idMenu = "aypp16";
    makanan16.namaMenu = "ayam pop";
    makanan16.deskripsi = "makanan berminyak bersaos";
    makanan16.harga = 5000;
    makanan16.klasifikasi = "makanan pembuka";

    makanan17.idMenu = "aysm17";
    makanan17.namaMenu = "ayam semur";
    makanan17.deskripsi = "makanan berbumbu";
    makanan17.harga = 6000;
    makanan17.klasifikasi = "makanan pembuka";

    makanan18.idMenu = "lsgn18";
    makanan18.namaMenu = "lasagna";
    makanan18.deskripsi = "makanan bersaos berbumbu";
    makanan18.harga = 25000;
    makanan18.klasifikasi = "makanan utama";

    makanan19.idMenu = "spgt19";
    makanan19.namaMenu = "spaghetti";
    makanan19.deskripsi = "makanan berminyak bersaos";
    makanan19.harga = 20000;
    makanan19.klasifikasi = "makanan utama";

    makanan20.idMenu = "pzz20";
    makanan20.namaMenu = "pizza";
    makanan20.deskripsi = "makanan berminyak bersaos berbumbu";
    makanan20.harga = 30000;
    makanan20.klasifikasi = "makanan utama";

    makanan21.idMenu = "nskn21";
    makanan21.namaMenu = "nasi kuning";
    makanan21.deskripsi = "makanan bernasi berbumbu";
    makanan21.harga = 10000;
    makanan21.klasifikasi = "makanan utama";

    makanan22.idMenu = "nsuk22";
    makanan22.namaMenu = "nasi uduk";
    makanan22.deskripsi = "makanan bernasi berbumbu";
    makanan22.harga = 10000;
    makanan22.klasifikasi = "makanan utama";

    makanan23.idMenu = "pdng23";
    makanan23.namaMenu = "puding";
    makanan23.deskripsi = "makanan bergula";
    makanan23.harga = 12000;
    makanan23.klasifikasi = "makanan penutup";

    makanan24.idMenu = "krng24";
    makanan24.namaMenu = "kue kering ";
    makanan24.deskripsi = "makanan bergula";
    makanan24.harga = 8000;
    makanan24.klasifikasi = "makanan penutup";

    makanan25.idMenu = "ktar25";
    makanan25.namaMenu = "kue tart";
    makanan25.deskripsi = "makanan bergula";
    makanan25.harga = 50000;
    makanan25.klasifikasi = "makanan penutup";

    pesanan1.idPesanan = "usr1";
    pesanan1.atasNama = "Rafi Andeo";
    pesanan1.tanggal = "26/10/2022";
    pesanan1.jam = "11:00";
    pesanan1.total = 100000;

    pesanan2.idPesanan = "usr2";
    pesanan2.atasNama = "Damar Muhammad";
    pesanan2.tanggal = "01/10/2022";
    pesanan2.jam = "10:00";
    pesanan2.total = 20000;

    pesanan3.idPesanan = "usr3";
    pesanan3.atasNama = "Raihan Syahran";
    pesanan3.tanggal = "03/10/2022";
    pesanan3.jam = "09:00";
    pesanan3.total = 50000;

    pesanan4.idPesanan = "usr4";
    pesanan4.atasNama = "Athar Dota";
    pesanan4.tanggal = "05/10/2022";
    pesanan4.jam = "06:00";
    pesanan4.total = 30000;

    pesanan5.idPesanan = "usr5";
    pesanan5.atasNama = "Aryandhika Ibnu";
    pesanan5.tanggal = "05/11/2022";
    pesanan5.jam = "14:00";
    pesanan5.total = 90000;

    pesanan6.idPesanan = "usr6";
    pesanan6.atasNama = "Aji Andhika";
    pesanan6.tanggal = "05/05/2022";
    pesanan6.jam = "20:00";
    pesanan6.total = 200000;

    pesanan7.idPesanan = "usr7";
    pesanan7.atasNama = "Ryan Syahran";
    pesanan7.tanggal = "08/08/2022";
    pesanan7.jam = "21:00";
    pesanan7.total = 250000;

    pesanan8.idPesanan = "usr8";
    pesanan8.atasNama = "Muhammad Ichsan";
    pesanan8.tanggal = "09/08/2022";
    pesanan8.jam = "01:00";
    pesanan8.total = 30000;

    pesanan9.idPesanan = "usr9";
    pesanan9.atasNama = "Gazel Rahmad";
    pesanan9.tanggal = "22/10/2022";
    pesanan9.jam = "03:00";
    pesanan9.total = 90000;

    pesanan10.idPesanan = "usr10";
    pesanan10.atasNama = "Najwa Priscilia";
    pesanan10.tanggal = "01/01/2021";
    pesanan10.jam = "05:00";
    pesanan10.total = 120000;

    pesanan11.idPesanan = "usr11";
    pesanan11.atasNama = "Rayhan Rafael";
    pesanan11.tanggal = "02/09/2020";
    pesanan11.jam = "20:00";
    pesanan11.total = 150000;

    pesanan12.idPesanan = "usr12";
    pesanan12.atasNama = "Reza Adhani";
    pesanan12.tanggal = "03/12/2020";
    pesanan12.jam = "22:00";
    pesanan12.total = 200000;

    pesanan13.idPesanan = "usr13";
    pesanan13.atasNama = "Dwikky Harris";
    pesanan13.tanggal = "02/02/2019";
    pesanan13.jam = "01:00";
    pesanan13.total = 300000;

    pesanan14.idPesanan = "usr14";
    pesanan14.atasNama = "Ghifari Zakaria";
    pesanan14.tanggal = "02/03/2017";
    pesanan14.jam = "05:00";
    pesanan14.total = 50000;

    pesanan15.idPesanan = "usr15";
    pesanan15.atasNama = "Imtiyaz Rifki";
    pesanan15.tanggal = "02/05/2015";
    pesanan15.jam = "06:00";
    pesanan15.total = 750000;

    pesanan16.idPesanan = "usr16";
    pesanan16.atasNama = "Hibby Abdul";
    pesanan16.tanggal = "10/06/2022";
    pesanan16.jam = "07:00";
    pesanan16.total = 25000;

    pesanan17.idPesanan = "usr17";
    pesanan17.atasNama = "Deyuna Rusmiland";
    pesanan17.tanggal = "11/09/2020";
    pesanan17.jam = "09:00";
    pesanan17.total = 15000;

    pesanan18.idPesanan = "usr18";
    pesanan18.atasNama = "Dian Tiara";
    pesanan18.tanggal = "02/11/2005";
    pesanan18.jam = "08:00";
    pesanan18.total = 50000;

    pesanan19.idPesanan = "usr19";
    pesanan19.atasNama = "Ridho Isda";
    pesanan19.tanggal = "01/11/2015";
    pesanan19.jam = "10:00";
    pesanan19.total = 300000;

    pesanan20.idPesanan = "usr20";
    pesanan20.atasNama = "Martondi Lubis";
    pesanan20.tanggal = "25/09/2019";
    pesanan20.jam = "11:00";
    pesanan20.total = 250000;

    pesanan21.idPesanan = "usr21";
    pesanan21.atasNama = "Riyadh Azhar";
    pesanan21.tanggal = "17/08/2008";
    pesanan21.jam = "14:00";
    pesanan21.total = 750000;

    pesanan22.idPesanan = "usr22";
    pesanan22.atasNama = "Elang Herama";
    pesanan22.tanggal = "25/10/2016";
    pesanan22.jam = "15:00";
    pesanan22.total = 100000;

    pesanan23.idPesanan = "usr23";
    pesanan23.atasNama = "Viriyo Marta";
    pesanan23.tanggal = "29/12/2014";
    pesanan23.jam = "11:00";
    pesanan23.total = 20000;

    pesanan24.idPesanan = "usr24";
    pesanan24.atasNama = "Krisna Yudha";
    pesanan24.tanggal = "02/02/2012";
    pesanan24.jam = "15:00";
    pesanan24.total = 75000;

    pesanan25.idPesanan = "usr25";
    pesanan25.atasNama = "Farrel Haiqal";
    pesanan25.tanggal = "29/10/2016";
    pesanan25.jam = "06:00";
    pesanan25.total = 90000;

    dp1.idPesanan = "usr1";
    dp1.idMenu = "ktar25";
    dp1.jumlah = 2;
    dp1.harga = 50000;
    dp1.totalHarga = 100000;

    dp2.idPesanan = "usr2";
    dp2.idMenu = "spgt19";
    dp2.jumlah = 1;
    dp2.harga = 20000;
    dp2.totalHarga = 20000;

    dp3.idPesanan = "usr3";
    dp3.idMenu = "ktar25";
    dp3.jumlah = 1;
    dp3.harga = 50000;
    dp3.totalHarga = 50000;

    dp4.idPesanan = "usr4";
    dp4.idMenu = "pzz20";
    dp4.jumlah = 1;
    dp4.harga = 30000;
    dp4.totalHarga = 30000;

    dp5.idPesanan = "usr5";
    dp5.idMenu = "pzz20";
    dp5.jumlah = 3;
    dp5.harga = 30000;
    dp5.totalHarga = 90000;

    dp6.idPesanan = "usr6";
    dp6.idMenu = "ktar25";
    dp6.jumlah = 4;
    dp6.harga = 50000;
    dp6.totalHarga = 200000;

    dp7.idPesanan = "usr7";
    dp7.idMenu = "ktar25";
    dp7.jumlah = 5;
    dp7.harga = 50000;
    dp7.totalHarga = 250000;

    dp8.idPesanan = "usr8";
    dp8.idMenu = "nskn21";
    dp8.jumlah = 3;
    dp8.harga = 10000;
    dp8.totalHarga = 30000;

    dp9.idPesanan = "usr9";
    dp9.idMenu = "nskn21";
    dp9.jumlah = 6;
    dp9.harga = 10000;
    dp9.totalHarga = 60000;

    dp10.idPesanan = "usr10";
    dp10.idMenu = "pdng23";
    dp10.jumlah = 10;
    dp10.harga = 12000;
    dp10.totalHarga = 120000;

    dp11.idPesanan = "usr11";
    dp11.idMenu = "ktar25";
    dp11.jumlah = 3;
    dp11.harga = 50000;
    dp11.totalHarga = 150000;

    dp12.idPesanan = "usr12";
    dp12.idMenu = "ktar25";
    dp12.jumlah = 4;
    dp12.harga = 50000;
    dp12.totalHarga = 200000;

    dp13.idPesanan = "usr13";
    dp13.idMenu = "ktar25";
    dp13.jumlah = 6;
    dp13.harga = 50000;
    dp13.totalHarga = 300000;

    dp14.idPesanan = "usr14";
    dp14.idMenu = "ktar25";
    dp14.jumlah = 1;
    dp14.harga = 50000;
    dp14.totalHarga = 50000;

    dp15.idPesanan = "usr15";
    dp15.idMenu = "ktar25";
    dp15.jumlah = 15;
    dp15.harga = 50000;
    dp15.totalHarga = 750000;

    dp16.idPesanan = "usr16";
    dp16.idMenu = "aygr10";
    dp16.jumlah = 5;
    dp16.harga = 5000;
    dp16.totalHarga = 25000;

    dp17.idPesanan = "usr17";
    dp17.idMenu = "aygr10";
    dp17.jumlah = 3;
    dp17.harga = 5000;
    dp17.totalHarga = 15000;

    dp18.idPesanan = "usr18";
    dp18.idMenu = "aygr10";
    dp18.jumlah = 10;
    dp18.harga = 5000;
    dp18.totalHarga = 50000;

    dp19.idPesanan = "usr19";
    dp19.idMenu = "ktar25";
    dp19.jumlah = 6;
    dp19.harga = 50000;
    dp19.totalHarga = 300000;

    dp20.idPesanan = "usr20";
    dp20.idMenu = "ktar25";
    dp20.jumlah = 5;
    dp20.harga = 50000;
    dp20.totalHarga = 250000;

    dp21.idPesanan = "usr21";
    dp21.idMenu = "ktar25";
    dp21.jumlah = 15;
    dp21.harga = 50000;
    dp21.totalHarga = 750000;

    dp22.idPesanan = "usr22";
    dp22.idMenu = "bks1";
    dp22.jumlah = 10;
    dp22.harga = 10000;
    dp22.totalHarga = 100000;

    dp23.idPesanan = "usr23";
    dp23.idMenu = "bks1";
    dp23.jumlah = 2;
    dp23.harga = 10000;
    dp23.totalHarga = 20000;

    dp24.idPesanan = "usr24";
    dp24.idMenu = "lsgn18";
    dp24.jumlah = 3;
    dp24.harga = 25000;
    dp24.totalHarga = 75000;

    dp25.idPesanan = "usr24";
    dp25.idMenu = "lsgn18";
    dp25.jumlah = 4;
    dp25.harga = 25000;
    dp25.totalHarga = 90000;

    menulisData(makanan1, myFile);
    menulisData(makanan2, myFile);
    menulisData(makanan3, myFile);
    menulisData(makanan4, myFile);
    menulisData(makanan5, myFile);
    menulisData(makanan6, myFile);
    menulisData(makanan7, myFile);
    menulisData(makanan8, myFile);
    menulisData(makanan9, myFile);
    menulisData(makanan10, myFile);
    menulisData(makanan11, myFile);
    menulisData(makanan12, myFile);
    menulisData(makanan13, myFile);
    menulisData(makanan14, myFile);
    menulisData(makanan15, myFile);
    menulisData(makanan16, myFile);
    menulisData(makanan17, myFile);
    menulisData(makanan18, myFile);
    menulisData(makanan19, myFile);
    menulisData(makanan20, myFile);
    menulisData(makanan21, myFile);
    menulisData(makanan22, myFile);
    menulisData(makanan23, myFile);
    menulisData(makanan24, myFile);
    menulisData(makanan25, myFile);

    menulisData2(pesanan1, myFile2);
    menulisData2(pesanan2, myFile2);
    menulisData2(pesanan3, myFile2);
    menulisData2(pesanan4, myFile2);
    menulisData2(pesanan5, myFile2);
    menulisData2(pesanan6, myFile2);
    menulisData2(pesanan7, myFile2);
    menulisData2(pesanan8, myFile2);
    menulisData2(pesanan9, myFile2);
    menulisData2(pesanan10, myFile2);
    menulisData2(pesanan11, myFile2);
    menulisData2(pesanan12, myFile2);
    menulisData2(pesanan13, myFile2);
    menulisData2(pesanan14, myFile2);
    menulisData2(pesanan15, myFile2);
    menulisData2(pesanan16, myFile2);
    menulisData2(pesanan17, myFile2);
    menulisData2(pesanan18, myFile2);
    menulisData2(pesanan19, myFile2);
    menulisData2(pesanan20, myFile2);
    menulisData2(pesanan21, myFile2);
    menulisData2(pesanan22, myFile2);
    menulisData2(pesanan23, myFile2);
    menulisData2(pesanan24, myFile2);
    menulisData2(pesanan25, myFile2);

    menulisData3(dp1, myFile3);
    menulisData3(dp2, myFile3);
    menulisData3(dp3, myFile3);
    menulisData3(dp4, myFile3);
    menulisData3(dp5, myFile3);
    menulisData3(dp6, myFile3);
    menulisData3(dp7, myFile3);
    menulisData3(dp8, myFile3);
    menulisData3(dp9, myFile3);
    menulisData3(dp10, myFile3);
    menulisData3(dp11, myFile3);
    menulisData3(dp12, myFile3);
    menulisData3(dp13, myFile3);
    menulisData3(dp14, myFile3);
    menulisData3(dp15, myFile3);
    menulisData3(dp16, myFile3);
    menulisData3(dp17, myFile3);
    menulisData3(dp18, myFile3);
    menulisData3(dp19, myFile3);
    menulisData3(dp20, myFile3);
    menulisData3(dp21, myFile3);
    menulisData3(dp22, myFile3);
    menulisData3(dp23, myFile3);
    menulisData3(dp24, myFile3);
    menulisData3(dp25, myFile3);

    output = ambilData(1, myFile);
    output2 = ambilData2(14, myFile2);
    output3 = ambilData3(14, myFile3);

    cout << output.idMenu << endl;
    cout << output.namaMenu << endl;
    cout << output.deskripsi << endl;
    cout << output.harga << endl;
    cout << output.klasifikasi << endl;

    cout << endl;

    cout << output2.idPesanan << endl;
    cout << output2.atasNama << endl;
    cout << output2.tanggal << endl;
    cout << output2.jam << endl;
    cout << output2.total << endl;

    cout << endl;

    cout << output3.idPesanan << endl;
    cout << output3.idMenu << endl;
    cout << output3.jumlah << endl;
    cout << output3.harga << endl;
    cout << output3.totalHarga << endl;

    myFile.close();
    cin.get();
    return 0;
}
