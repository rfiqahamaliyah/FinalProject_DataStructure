#include "MLL1toN.h"
void createListCredit(listCredit &Credits){ // SLL [done] [clean]
// {I.S : -
//  F.S : Membuat daftar kredit}
    first(Credits) = NULL;
} // (14)

adrCredit createElementCredit(listCredit &Credits, dataCredit dataCred) { // SLL [done] [clean]
// {I.S : Masukkan berupa data kartu kredit
//  F.S : Membuat elemen data kartu kredit tersebut}
    adrCredit thisCredit = new elmCredit;
    data(thisCredit) = dataCred;
    nextCredit(thisCredit) = NULL;
    return thisCredit;
} // (14)

void insertLastCredit(listCredit &Credits, adrCredit credP){ // SLL [done] [clean]
// {I.S : Daftar kredit mungkin ada atau kosong
//  F.S : Menambahkan kartu kredit ke akhir daftar kredit}
    if(first(Credits) == NULL){
        first(Credits) = credP;
    } else {
        adrCredit thisCredit = first(Credits);
        while(nextCredit(thisCredit) != NULL){
            thisCredit = nextCredit(thisCredit);
        }
        nextCredit(thisCredit) = credP;
    }
} // (15)

void deleteFirstCredit(listCredit &Credits, adrCredit &credP){ // SLL [done] [done]
// {I.S Daftar kredit mungkin ada atau kosong
//  F.S Menghapus kartu kredit yang ada di awal daftar kredit}
    if(first(Credits) == NULL){
        cout<<"--- Tidak ada Kartu Kredit yang terdaftar!\n";
    }else if(nextCredit(first(Credits)) == NULL){
        credP = first(Credits);
        first(Credits) = NULL;
        nextCredit(credP) = NULL;
    }else{
        credP = first(Credits);
        first(Credits) = nextCredit(first(Credits));
        nextCredit(credP) = NULL;
    }
} // (13)

void deleteAfterCredit(listCredit &Credits, adrCredit &credP, dataCredit dataCred){ // SLL [done] [clean]
// {I.S : Daftar kredit mungkin ada atau kosong
//  F.S : Menghapus kartu kredit yang ada di antara awal dan akhir daftar kredit}
    if(first(Credits) == NULL) {
        cout<<"--- Tidak ada Kartu Kredit yang terdaftar!\n";
    }else{
        adrCredit precCredit = first(Credits);
        while((data(nextCredit(precCredit)).creditID != dataCred.creditID)){
            precCredit = nextCredit(precCredit);
        }
        credP = nextCredit(precCredit);
        nextCredit(precCredit) = nextCredit(credP);
        nextCredit(credP) = NULL;
    }
} // (13)

void deleteLastCredit(listCredit &Credits, adrCredit &credP){ // SLL [done] [clean]
// {I.S : Daftar kredit mungkin ada atau kosong
//  F.S : Menghapus kartu kredit yang ada di akhir daftar kredit}
    if(first(Credits) == NULL){
        cout<<"--- Tidak ada Kartu Kredit yang terdaftar!\n";
    }else if(nextCredit(first(Credits)) == NULL){
        credP = first(Credits);
        first(Credits) == NULL;
        nextCredit(credP) == NULL;
    }else{
        adrCredit thisCredit = first(Credits);
        while(nextCredit(nextCredit(thisCredit)) != NULL){
            thisCredit = nextCredit(thisCredit);
        }
        credP = nextCredit(thisCredit);
        nextCredit(thisCredit) = NULL;
        nextCredit(credP) = NULL; 
    }
} // (13)

void insertLastCustomer(listCustomer &Customers, adrCustomer custP){ // CSLL [done] [clean]
// {I.S : Pelanggan mungkin belum ada atau sudah ada
//  F.S : Menambahkan pelanggan kedalam daftar pelanggan}
    if(first(Customers) == NULL) {
        first(Customers) = custP;
        nextCustomer(custP) = first(Customers);
    }else{
        adrCustomer thisCustomer = first(Customers);
        while(nextCustomer(thisCustomer) != first(Customers)){
            thisCustomer = nextCustomer(thisCustomer);
        }
        nextCustomer(thisCustomer) = custP;
        nextCustomer(custP) = first(Customers);
    }
} // 1

void showCustomerData(listCustomer &Customers, dataCustomer dataCust){ // CSLL [done] [clean]
// {I.S : Daftar pelanggan mungkin belum ada atau sudah ada
//  F.S : Menampilkan data pelanggan X}
    adrCustomer thisCustomer = getCustomer(Customers, dataCust);
    if(thisCustomer != NULL){
        cout<<"--- Nama\t\t\t: "<<data(thisCustomer).name<<"\n";
        cout<<"--- NIK\t\t\t\t: "<<data(thisCustomer).NIK<<"\n";
        cout<<"--- Gender\t\t\t: "<<data(thisCustomer).gender<<"\n";
        cout<<"--- Umur\t\t\t: "<<data(thisCustomer).age<<"\n";
        cout<<"--- Total Kredit\t\t: "<<data(thisCustomer).totalCredits<<"\n\n";
    }else{
        cout<<"\n--- Customer tidak terdaftar!\n";      
    }
} // 2

adrCredit getCreditFromCustomer(listCredit Credits, listCustomer Customers, dataCustomer dataCust){ // [done] [clean]
// {I.S : -
//  F.S : Mengembalikan address kartu kredit dari sebuah pelanggan}
    adrCredit thisCredit = first(Credits);
    adrCustomer foundCustomer = getCustomer(Customers, dataCust);
    while(thisCredit != NULL){
        if(child(thisCredit) == foundCustomer){
            return thisCredit;
        }else{
            thisCredit = nextCredit(thisCredit);
        }
    }
    return NULL;
} // 8

adrCustomer getCustomerFromCredit(listCredit Credits, listCustomer Customers, dataCredit dataCred) { // [done] [clean]
// {I.S : -
//  F.S : Mengembalikan address pelanggan dari daftar kredit}
    adrCredit foundCredit = getCredit(Credits, dataCred);
    if(foundCredit == NULL || child(foundCredit) == NULL){
        return NULL;
    }else{
        return child(foundCredit);
    }
} // (12)

void connectCreditToCustomer(listCredit &Credits, listCustomer &Customers, dataCredit dataCred, dataCustomer dataCust){ // [done] [clean]
// {I.S : Kredit belum memiliki child (terkoneksi) dengan pelanggan atau daftar kredit kosong
//  F.S : Melakukan konektivitas pelanggan dengan kartu kredit nya}
    adrCredit foundCredit = getCredit(Credits, dataCred);
    adrCustomer foundCustuomer = getCustomer(Customers, dataCust);
    if(foundCredit == NULL && foundCustuomer != NULL){
        cout<<"\n--- Data Kartu Kredit belum terdaftar!\n    Menambahkan Data Kartu Kredit baru : SUCCESS\n";
        adrCredit thisCredit = createElementCredit(Credits, dataCred);
        insertLastCredit(Credits, thisCredit);
        ++data(foundCustuomer).totalCredits;
        child(thisCredit) = foundCustuomer;
        cout<<"\n--- Berhasil menghubungkan Kartu Kredit dengan Customer!\n";
    }else if(child(foundCredit) != NULL && foundCustuomer != NULL){
        if(child(foundCredit) == foundCustuomer){
            cout<<"--- Kartu Kredit Customer sudah terdaftar\n";
        }else{
            --data(child(foundCredit)).totalCredits;
            child(foundCredit) = foundCustuomer;
            ++data(foundCustuomer).totalCredits;
            cout<<"\n--- Berhasil menghubungkan Kartu Kredit dengan Customer!\n";
        }
    }else if(child(foundCredit) == NULL){
        child(foundCredit) = foundCustuomer;
        ++data(foundCustuomer).totalCredits;
        cout<<"\n--- Berhasil menghubungkan Kartu Kredit dengan Customer!\n";
    }else{
        cout<<"--- Customer tidak terdaftar\n";
    }
} // (9)

void deleteAllCreditInCustomer(listCredit &Credits, listCustomer &Customers, dataCustomer dataCust){ // [done] [clean]
// {I.S : Terdaftar tiap kredit dari pelanggan atau tidak
//  F.S : Menghapus tiap kredit yang dimiliki oleh pelanggan}
    adrCredit credP;
    adrCredit foundCredit = getCreditFromCustomer(Credits, Customers, dataCust);
    adrCustomer foundCustomer = getCustomer(Customers, dataCust);
    if(foundCredit == NULL && foundCustomer != NULL){
        cout<<"\n--- Tidak Ada Kartu Kredit Yang Terdaftar!\n";
    }else if(foundCustomer == NULL){
        cout<<"\n--- Customer Tidak Terdaftar!\n";
    }else{
        while(foundCredit != NULL){
            disconnectCreditAndCustomer(Credits, Customers, data(foundCredit), dataCust);
            if(foundCredit == first(Credits)){
                deleteFirstCredit(Credits, credP);
            }else if(nextCredit(foundCredit) == NULL){
                deleteLastCredit(Credits, credP);
            }else{
                deleteAfterCredit(Credits, credP, data(foundCredit));
            }
            foundCredit = getCreditFromCustomer(Credits, Customers, dataCust);
        }
        cout<<"\n--- Berhasil Menghapus Kartu Kredit!\n";
    }
} // 6

void menu(int &command){ // [done] [clean]
// {I.S : -
//  F.S : Menampilkan menu yang akan di input oleh user}
    cout<<"\n";
    cout<<"\t\t\t\t\t\t********[[ MENU ]]********\n";
    cout<<"\t\t\t\t\t\t**************************\n\n";
    cout<<"[1] Menambahkan customer baru\n";
    cout<<"[2] Menampilkan data customer\n";
    cout<<"[3] Menghapus customer tertentu\n";
    cout<<"[4] Mencari customer X\n";
    cout<<"[5] Menambahkan kartu kredit dari customer X\n";
    cout<<"[6] Menghapus kartu kredit dari customer X\n";
    cout<<"[7] Menampilkan seluruh kartu kredit dari customer X\n";
    cout<<"[8] Mencari kartu kredit Y dari customer X\n";
    cout<<"[9] Membuat relasi antara customer X dan kartu kredit Y\n";
    cout<<"[10] Menghapus relasi antara customer X dan kartu kredit Y\n";
    cout<<"[11] Menampilkan data customer yang memiliki kredit terbanyak\n";
    cout<<"[12] Mencari nama customer dari kartu kredit Y\n";
    cout<<"[0] Exit\n\n";
    cout<<"Masukan Angka : ";
    command = validateIntInput(command);
}

int validateIntInput(int x){ // [done] [clean]
// {I.S : Masukkan input bisa bernilai integer atau non-integer
//  F.S : Memastikan bahwa input nilai selalu integer}
    while(true){
        cin>>x;
        if(!cin){
            cout<<"Entry tidak valid\nMasukkan entry lagi : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }else{
            break;
        }
    }
    return x;
}