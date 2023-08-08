#include "MLL1toN.h"
void createlistCustomer(listCustomer &Customers){ // CSLL [done] [clean]
// {I.S : -
//  F.S : Membuat daftar customer}
    first(Customers) = NULL; 
} // (16)

adrCustomer createElementCustomer(listCustomer &Customers, dataCustomer dataCust){ // [done] [clean]
// {I.S : Masukkan berupa data customer
//  F.S : Membuat elemen data customer tersebut}
    adrCustomer thisCredit = new elmCustomer;
    data(thisCredit) = dataCust;
    nextCustomer(thisCredit) = NULL;
    return thisCredit;
} // (16)

void deleteFirstCustomer(listCustomer &Customers, adrCustomer &custP){ // CSLL [done] [clean]
// {I.S : List mungkin berisi satu elemen atau lebih
//  F.S : custP berisi elemen pertama yang dihapus dari list customer}
    adrCustomer thisCustomer;
    if(nextCustomer(first(Customers)) == first(Customers)){
        custP = first(Customers);
        nextCustomer(custP) = NULL;
        first(Customers) = NULL;
    }else{
        thisCustomer = first(Customers);
        while(nextCustomer(thisCustomer) != first(Customers)){
            thisCustomer = nextCustomer(thisCustomer);
        }
        custP = first(Customers);
        first(Customers) = nextCustomer(first(Customers));
        nextCustomer(thisCustomer) = first(Customers);
        nextCustomer(custP) = NULL;
    }
} // (17)

void deleteAfterCustomer(listCustomer &Customers, adrCustomer &custP, dataCustomer dataCust){ // CSLL [done] [clean]
// {I.S : List tidak kosong, cust adalah dataCustomer yang akan dihapus
//  F.S : custP menyimpan elemen yang dihapus}
    adrCustomer thisCustomer;
    if(nextCustomer(first(Customers)) != first(Customers)){
        thisCustomer = first(Customers);
        while(data(nextCustomer(thisCustomer)).name != dataCust.name && data(nextCustomer(thisCustomer)).NIK != dataCust.NIK){
            thisCustomer = nextCustomer(thisCustomer);
        }
        custP = nextCustomer(thisCustomer);
        nextCustomer(thisCustomer) = nextCustomer(custP);
        nextCustomer(custP) =  NULL;
    }
}// (17)

void deleteLastCustomer(listCustomer &Customers, adrCustomer &custP) { // CSLL [done] [clean]
// {I.S : List tidak kosong
//  F.S : custP adalah elemen terakhir yang dihapus dari list customer}
    adrCustomer thisCustomer;
    thisCustomer = first(Customers);
    while(nextCustomer(nextCustomer(thisCustomer)) != first(Customers)){
        thisCustomer = nextCustomer(thisCustomer);
    }   
    custP = nextCustomer(thisCustomer);
    nextCustomer(thisCustomer) = first(Customers);
    nextCustomer(custP) = NULL;
} // (17)

adrCustomer getCustomer(listCustomer Customers, dataCustomer dataCust){ // CSLL [done] [clean]
// {I.S : Terdefinisi customer X
//  F.S : Mengembalikan address dari elemen cust X jika ditemukan atau NULL jika tidak ditemukan}
    adrCustomer thisCustomer = first(Customers);
    if(thisCustomer == NULL){
        return NULL;
    }else{
        do{
            if(data(thisCustomer).NIK == dataCust.NIK && data(thisCustomer).name == dataCust.name){
                return thisCustomer;
            }else{
                thisCustomer = nextCustomer(thisCustomer);
            }
        }while(thisCustomer != first(Customers));
        return NULL;
    }
}
// (4)

adrCredit getCredit(listCredit Credits, dataCredit dataCred){ // SLL [done] [clean]
// {I.S : Terdefinisi data credit Y
//  F.S : Mengembalikan address dari elemen credit Y jika ditemukan atau NULL jika tidak ditemukan}
    adrCredit thisCredit = first(Credits);
    while(thisCredit != NULL){
        if(data(thisCredit).creditID == dataCred.creditID){
            return thisCredit;
        }else{
            thisCredit = nextCredit(thisCredit);
        }
    }
    return NULL;
}

void addCreditToCustomer(listCredit &Credits, listCustomer &Customers, dataCredit dataCred, dataCustomer dataCust){ // [done] [clean]
// {I.S : Terdefinisi nama customer X
//  F.S : Data credit baru ditambahkan ke dalam list credit sebagai elemen terakhir
//        kemudian hubungkan cust x dengan elemen credit baru}
    adrCredit thisCredit = createElementCredit(Credits, dataCred);
    insertLastCredit(Credits, thisCredit);
    connectCreditToCustomer(Credits, Customers, dataCred, dataCust);
} // (5)

void showCustomerCredit(listCredit &Credits, listCustomer &Customers, dataCustomer dataCust){ // [done] [clean]
// {I.S : Terdefinisi nama customer X
//  F.S : Seluruh kartu kredit dari cust x akan ditampilkan}
    int counter = 0;
    adrCustomer thisCustomer;
    adrCredit thisCredit;
    thisCustomer = getCustomer(Customers, dataCust);    
    if(thisCustomer==NULL){
        cout<<"--- Customer tidak ditemukan\n";
    }else{
        thisCredit = first(Credits);
        while(thisCredit != NULL){
            if(child(thisCredit) == thisCustomer){
                counter++;
                cout<<"--- Nama Kredit\t\t\t: "<<data(thisCredit).creditName<<"\n";
                cout<<"--- Nomor Rekening\t\t: "<<data(thisCredit).creditID<<"\n";
            }
            thisCredit = nextCredit(thisCredit);
        }
        if(counter == 0){
            cout<<"--- Customer tidak memiliki kartu kredit\n";
        }
    }
} // (7)

void deleteCustomer(listCredit &Credits, listCustomer &Customers, dataCustomer dataCust) { // [done] [clean]
// {I.S : Terdefinisi data customer
// {F.S : Menghapus seluruh credit card milik customer X dari list credit 
//        kemudian menghapus customer X dari list customer}
    adrCustomer thisCustomer = getCustomer(Customers, dataCust);
    adrCustomer deletedCreditP;
    if(thisCustomer == NULL){     
        cout<<"--- Tidak bisa menghapus Data Customer! Nama Customer tidak ditemukan\n";
    }else{
        deleteAllCreditInCustomer(Credits, Customers, dataCust);
        if(thisCustomer == first(Customers)){
            deleteFirstCustomer(Customers, deletedCreditP);
        }else if(nextCustomer(thisCustomer) == first(Customers)){
            deleteLastCustomer(Customers, deletedCreditP);
        }else{
            deleteAfterCustomer(Customers, deletedCreditP, data(thisCustomer));
        }
        cout<<"--- Berhasil menghapus data customer\n";
    }
} // (3)

void disconnectCreditAndCustomer(listCredit &Credits, listCustomer &Customers, dataCredit dataCred, dataCustomer dataCust){ // [done] [clean]
// {I.S : Terdefinisi data credit Y dan data cust X
//  F.S : Memutuskan relasi antara credit Y dan cust X}
    adrCustomer findCustomer = getCustomer(Customers, dataCust);
    adrCredit findCredit = getCredit(Credits, dataCred);
    if(findCredit == NULL){
        cout<<"\n--- Kartu Kredit tidak terdaftar!\n";
    }else{
        --data(child(findCredit)).totalCredits;
        child(findCredit) = NULL;
    }
} // (10)

void showHighestCustomerCredits(listCredit &Credits, listCustomer &Customers){ // [done] [clean]
// {I.S : Terdefinisi list cust dan list credit, mungkin kosong
//  F.S : Menampilkan data customer dengan jumlah kredit terbanyak beserta kartu kredit yang dimilikinya}
    if(first(Customers) == NULL){
            cout<<"--- Daftar Customer kosong/tidak ada Kartu Kredit yang terdaftar!\n";
    }else{
        adrCustomer highestCustomer;
        adrCustomer thisCustomer = first(Customers);
        int highestCredits = 0;
        do{
            if(data(thisCustomer).totalCredits > highestCredits){
                highestCredits = data(thisCustomer).totalCredits;
                highestCustomer = thisCustomer;
            }
            thisCustomer = nextCustomer(thisCustomer);
        }while(thisCustomer != first(Customers));

        if(highestCredits == 0){
            cout<<"--- Tidak ada Kartu Kredit yang terdaftar dengan customer!\n";
        }else{
            cout<<"--- Total Kredit Tertinggi : "<<highestCredits<<endl;
            cout<<"\n--- Data Customer : "<<endl;
            showCustomerData(Customers, data(highestCustomer));
            showCustomerCredit(Credits, Customers, data(highestCustomer));
        // {Menampilkan pelanggan yang total kredit sama banyak dengan highestCustomer jika ada}
            thisCustomer = first(Customers);
            do{
                if(thisCustomer != highestCustomer && data(thisCustomer).totalCredits == highestCredits){
                    cout<<"\n==================================================================\n\n";
                    cout<<"--- Data Customer : "<<endl;
                    showCustomerData(Customers, data(thisCustomer));
                    showCustomerCredit(Credits, Customers, data(thisCustomer));
                }
                thisCustomer = nextCustomer(thisCustomer);
            }while(thisCustomer != first(Customers));
        }
    }    
} // (11)

bool getNIK(listCustomer Customers, dataCustomer dataCust){ // CSLL [done] [clean]
// {I.S : Terdefinisi NIK
//  F.S : Mengembalikan true jika nik ditemukan}
    adrCustomer thisCustomer = first(Customers);
    if(thisCustomer == NULL){
        return NULL;
    }else{
        do{
            if(data(thisCustomer).NIK == dataCust.NIK){
                return true;
            }else{
                thisCustomer = nextCustomer(thisCustomer);
            }
        }while(thisCustomer != first(Customers));
        return NULL;
    }
}
// (4)