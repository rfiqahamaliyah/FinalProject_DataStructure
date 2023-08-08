#ifndef MLL1TON_H
#define MLL1TON_H
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#define nextCustomer(P) P->nextCustomer
#define nextCredit(P) P->nextCredit
#define data(P) P->data
#define child(P) P->child
#define first(L) ((L).first)

// Credit and Customer infotype
struct dataCredit {
    string creditName, creditID; 
};
struct dataCustomer {
    string name, gender;
    int age, NIK;
    int totalCredits = 0;
};
// Credit and Customer pointers
typedef struct elmCredit *adrCredit;
typedef struct elmCustomer *adrCustomer;
// Credit and Customer type
struct elmCredit {
    dataCredit data;
    adrCredit nextCredit;
    adrCustomer child;
};
struct elmCustomer {
    dataCustomer data;
    adrCustomer nextCustomer;
};
// Lists (L1 - SLL)
struct listCredit {
    adrCredit first;
};
// List (L2 - CLL)
struct listCustomer {
    adrCustomer first;
};

// create lists and elements
// credit
void createListCredit(listCredit &Credits);
adrCredit createElementCredit(listCredit &Credits, dataCredit data);
// customer
void createlistCustomer(listCustomer &Customers);
adrCustomer createElementCustomer(listCustomer &Customers, dataCustomer dataCust);


// insert data to lists
// menambakan kredit dan customer baru
void insertLastCredit(listCredit &Credits, adrCredit credP);
void insertLastCustomer(listCustomer &Customers, adrCustomer custP); // (1)


// show customer X data [name, age, gender, creditName]
// menampilkan data customer X
void showCustomerData(listCustomer &Customers, dataCustomer dataCust); // (2)


// delete customer
// menghapus customer tertentu
void deleteCustomer(listCredit &Credits, listCustomer &Customers, dataCustomer dataCust); // (3)


// find customer
// mencari customer X
adrCustomer getCustomer(listCustomer Customers, dataCustomer dataCust); // (4)


// add new credit to customer X
// menambahkan kartu kredit dari customer X
void addCreditToCustomer(listCredit &Credits, listCustomer &Customers, dataCredit dataCred, dataCustomer dataCust); // (5)


// delete credit from customer X
// menghapus kartu kredit dari customer X
void deleteAllCreditInCustomer(listCredit &Credits, listCustomer &Customers, dataCustomer dataCust); // (6)


// show all credits from customer x
// menampilkan seluruh karut kredit dari customer X
void showCustomerCredit(listCredit &Credits, listCustomer &Customers, dataCustomer dataCust); // (7)


// find credit from customer
// mencari kartu kredit Y dari customer X
adrCredit getCreditFromCustomer(listCredit Credits, listCustomer Customers, dataCustomer dataCust); // (8)


// connect credit to customer
// membuat relasi antara customer X dan kartu kredit Y
void connectCreditToCustomer(listCredit &Credits, listCustomer &Customers, dataCredit dataCred, dataCustomer dataCust); // (9)


// delete connection betweeen credit and customer
// menghapus relasi antara customer X dan kartu kredit Y
void disconnectCreditAndCustomer(listCredit &Credits, listCustomer &Customers, dataCredit dataCred, dataCustomer dataCust); // (10)


// highest credit cards owner
// menampilkan customer yang memiliki jumlah kartu kredit yang paling banyak dan menampilkan kartu kredit tersebut
void showHighestCustomerCredits(listCredit &Credits, listCustomer &Customers); // (11)


// find customer name from the credit cards identity
// Mencari nama customer dari kartu kredit Y 
adrCustomer getCustomerFromCredit(listCredit Credits, listCustomer Customers, dataCredit dataCred); // (12)


// find credit
adrCredit getCredit(listCredit Credits, dataCredit dataCred);

// find NIK
bool getNIK(listCustomer Customers, dataCustomer dataCust);

// extra function and procedure
// credit delete [single linked list]
void deleteFirstCredit(listCredit &Credits, adrCredit &credP);
void deleteAfterCredit(listCredit &Credits, adrCredit &credP, dataCredit dataCred);
void deleteLastCredit(listCredit &Credits, adrCredit &credP);
// customer delete [single circular linked list]
void deleteFirstCustomer(listCustomer &Customers, adrCustomer &custP);
void deleteAfterCustomer(listCustomer &Customers, adrCustomer &custP, dataCustomer dataCust);
void deleteLastCustomer(listCustomer &Customers, adrCustomer &custP);
// menu
void menu(int &command);
// validate integer input
int validateIntInput(int x);
#endif // MLL1TON_H