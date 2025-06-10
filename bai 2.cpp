#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
#define LEN 30

typedef struct{
    char ht[LEN];
    char q[LEN];
    char d;
}sv;
void doc(int *n,sv a[]){
    FILE *f = fopen("sv.txt","rt");
    if(f== NULL) printf("k tim thay file");
    fscanf(f,"%d\n",n);
    for(int i=0;i<*n;i++){
        fgets(a[i].ht,LEN,f);
        fgets(a[i].q,LEN,f);
        fscanf(f,"%c\n",&a[i].d);
        a[i].ht[strcspn(a[i].ht,"\n")] = 0;
        a[i].q[strcspn(a[i].q,"\n")] = 0;
    } fclose(f);
}
void tk(int n,sv a[]){
    int ca=0,cb=0,cc=0;
    for (int i=0;i<n;i++){
        switch (a[i].d){
            case 'A': ca++; break;
            case 'B': cb++; break;
            case 'C': cc++; break;
        }
    }
    printf("\nso ng dat diem A la: %d",ca);
    printf("\nso ng dat diem B la: %d",cb);
    printf("\nso ng dat diem C la: %d",cc); 
}
void seach(int n, sv a[]){
    char tim[LEN];
    printf("\nnhap ten can tim: ");
    fgets(tim,LEN,stdin);
    tim[strcspn(tim, "\n")] = 0;
    int e=0;
    for (int i=0; i < n; i++){
        if ((strstr (a[i].ht,tim))==0) {
            printf("ho ten: %s\t que quan: %s\t  hoc luc: %c",a[i].ht,a[i].q,a[i].d);
            
        }
        return;
    }
}
int main ()
{
    int n;
    sv a[MAX];
    doc(&n,a);
    tk(n,a);
    seach(n,a);
    return 0;
}
