#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


char TmpStr [1000];
FILE *fp;
int AddressCount;
char AddressList[2000][100];
int i;
int WalletCount;
char WalletList[2000][100];
int j;


int main()
{
    srand (time(NULL));

    fp = fopen("/home/ubuntu/monero_loadtest/src/addresses.txt", "r");
    AddressCount = 0;

    while (fgets( TmpStr,100,fp) > 0 ) {
        TmpStr[ strlen(TmpStr) -1] = '\0';
	strcpy( AddressList[AddressCount++], TmpStr);
        //printf("%d addresses loaded\n", AddressCount);
    }
    fclose(fp);

    fp = fopen("/home/ubuntu/monero_loadtest/src/wallets.txt", "r");
    WalletCount = 0;

    while (fgets( TmpStr,100,fp) > 0 ) {
        TmpStr[ strlen(TmpStr) -1] = '\0';
	strcpy( WalletList[WalletCount++], TmpStr);
        //printf("%d wallets loaded\n", WalletCount);
    }
    fclose(fp);

    //printf("%d addresses loaded\n", AddressCount);

    printf("%s\n", WalletList[ rand() % WalletCount]);	// wallet to open
    //printf("MainMining.bin\n");	// wallet to open
    printf("testing123\n");				// password to unlock wallet
    usleep(100000);
    printf("save\n");					// save wallet

    usleep(100000);
    for (i=0;i<10;i++) {
    	printf("transfer %s 0.%d\n", 
			AddressList[ rand() % AddressCount], rand() % 999);
        usleep(100000);
        printf("testing123\n");				// Authorize the transaction with the password
        usleep(100000);
        printf("y\n");					// Confirm 'y' to accept no payment id
        usleep(100000);
        printf("y\n");					// Confirm 'y' to proceed
        usleep(100000);
        printf("y\n");					// Extra confirm, if there is a transaction backlog
    }
    printf("save\n");					// save wallet
    printf("exit\n");					// exit wallet

}
