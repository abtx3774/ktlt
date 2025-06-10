#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void doc(int *n,char file[],int a[MAX][MAX]){
    FILE *f = fopen(file,"r");
    if(f==NULL ) printf("k tim thay file");
    fscanf(f,"%d",n);
    for(int i=0;i<*n;i++){
        for(int j=0;j<*n;j++){
            fscanf(f,"%d",&a[i][j]);
        }
    }
}
float tbc(int a[MAX][MAX], int n) {
    float sum = 0, trbc;
    int count=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j > n - 1){
                sum += a[i][j];
                count ++;
            }
                
        }
    }
    return sum/count;
}
int check(int n,int a[MAX][MAX]){
    for(int i=0;i<=2;i++){
        for(int j=0;j<i;j++){
            if (a[i][j]!=0){
                return 1;
                break;
            }
            else return 0;
        }
    }
}
int main()
{
    char s[MAX];
    int n;
    int a[MAX][MAX];
    printf("nhap ten file: ");
    scanf("%s",s);
    doc(&n,s,a);
    printf("tbc la: %.2f",tbc(a,n));
    if(check(n,a)==1) printf("\nkhong phai la tam giac tren");
    else printf("\nma tran tam giac tren");
}
