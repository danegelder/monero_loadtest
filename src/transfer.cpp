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

    printf("%s\n", WalletList[ rand() % WalletCount]);
    printf("testing123\n");
    usleep(100000);
    printf("save\n");
    usleep(100000);
    for (i=0;i<100;i++) {
    	printf("transfer %s 0.00%d dd04bdf008f7601e024c323349c0a00aff1bf01bd0f2e38073142976bfb84762\n", AddressList[ rand() % AddressCount], rand() % 99999);
        usleep(100000);
        printf("testing123\n");
        usleep(100000);
        printf("y\n");
        usleep(100000);
        printf("y\n");
    }

 /* Do something more if you want */
}
