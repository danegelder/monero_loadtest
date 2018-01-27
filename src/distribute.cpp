#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

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





    while ( walletsfile >> ThisWallet) {
        Wallet[NumWallets++] = ThisWallet;
    }

    while ( addressfile >> ThisAddress) {
        Address[NumAddresses++] = ThisAddress;
    }


    cout << "Debug: Loaded " << NumWallets << " wallets and " << NumAddresses << " addresses.\n";

    cout << "MainMining.bin\n" ;		// wallet to open

    cout << "testing123\n";			// password

    cout << "save\n";				// save the wallet once blockchain has been read

    cout << "transfer 45gF1fmpESRE9M57ovLSQtgKDyf5coCBT1VjyMwrSdDcEpiD7ofGw2rdGN8Vj1bWjK9AtCiJv3Yi9MQYtvNiPKVz9RPkC9p 2.0\n";	// issue transfer command

    cout << "testing123\n";			// password

    cout << "y\n";				// Confirm no transaction payment id

    cout << "y\n";				// Confirm  to proceed

    cout << "y\n";				// Confirm if there is a backlog in processing
}

