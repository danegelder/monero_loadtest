#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string.h>
#include<sys/types.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <sys/time.h>       /* time */

using namespace std;

std::ifstream walletsfile("/home/ubuntu/monero_loadtest/src/wallets.txt");
std::ifstream addressfile("/home/ubuntu/monero_loadtest/src/addresses.txt");

string  Wallet [2000];
string  Address [2000];
string ThisWallet;
string ThisAddress;
int  NumWallets = 0;
int  NumAddresses = 0;



int main () {

    int i,j;
    struct timeval time; 


    gettimeofday(&time,NULL);


    srand (time.tv_usec);


    while ( walletsfile >> ThisWallet) {
        Wallet[NumWallets++] = ThisWallet;
    }

    while ( addressfile >> ThisAddress) {
        Address[NumAddresses++] = ThisAddress;
    }




    //cout << Wallet[ rand() % NumWallets ]  <<  "\n" ;		// wallet to open
    cout << "MainMining.bin\n" ;		// wallet to open

    cout << "testing123\n";			// password

    cerr << "Waiting for wallet to be ready\n" ;  		// stderr logging 

    cout << "save\n";				// save the wallet once blockchain has been read

    cerr << "Transferring\n" ;  		// stderr logging 

    for (i=0;i<10;i++) {

        

        cout << "transfer "  ;

        for (j=0;j<10;j++) {

            cout << Address[ rand() % NumAddresses ]  << " " << rand() % 3 << "." << rand() % 1000 << " "  ;

        }

        cout << " e2780d2166a5e845ae1b528d04adeeb7fb6425ab12586ca7b7e8ee15bcf744c2\n";	// issue transfer command

        cout << "testing123\n";			// password

        cout << "y\n";				// Confirm no transaction payment id

        cout << "y\n";				// Confirm  to proceed

        cout << "y\n";				// Confirm if there is a backlog in processing

    }

    cerr << "Completed...\n" ;  		// stderr logging 


}

