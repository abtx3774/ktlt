#include<stdio.h>
#include<string.h>
#define LEO 100
typedef struct{
    char ten[LEO];
    char tg[LEO];
    int nam;
}hi;
void read(const char *file ,int *n,hi a[LEO]){
    FILE *f= fopen(file,"rt");
    if (f==NULL) printf ("khong tim thay file ");
    fscanf(f,"%d\n",n);
    for(int i=0;i<*n;i++){
        fgets(a[i].ten,LEO,f);
        fgets(a[i].tg,LEO,f);
        fscanf(f,"%d\n",&a[i].nam);
        a[i].ten[strcspn(a[i].ten,"\n")]='\0';
        a[i].tg[strcspn(a[i].tg,"\n")]='\0';
    }fclose(f);
}
void seach(int n,hi a[LEO]){
    char s[LEO];
    printf("\nnhap ten sach can tim: ");
    fgets(s,LEO,stdin);
    s[strcspn(s,"\n")]=0;
    for (int i=0;i<n;i++){
        if (strstr(a[i].ten,s)!=NULL){
            printf("\n%s\t %s\t %d",a[i].ten,a[i].tg,a[i].nam);
        }
    }
    return;
}
void sx(int n,hi a[LEO]){
    for(int i=0;i<n-1;i++){
       for (int j=0;j<n-i-1;j++){
            if(a[j].nam>a[j+1].nam){
               hi t =a[j];
               a[j]=a[j+1];
               a[j+1]=t;
           }
       }
    }
}
void in(int n, hi a[LEO]){
    FILE *f = fopen("outtrinh.txt","wt");
    if(f == NULL) printf("khong tim file de in ");
    fprintf(f,"%d\n",n);
    for (int i=0;i<n;i++){
        if(a[i].nam<2000){
            fprintf(f,"%s\n%s\n%d\n", a[i].ten, a[i].tg, a[i].nam);
        }
    } 
    fclose(f);
    printf("\nda in thanh cong");
} 
int main()
{
    int n;
    char s[30];
    hi a[LEO];
    printf("nhap ten file:");
    scanf("%s",s);
    getchar();
    read(s,&n,a);
    seach(n,a);
    sx(n,a);
    in(n,a);
}

