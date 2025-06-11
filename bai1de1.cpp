#include<stdio.h>
#include<math.h>
typedef struct {
   float x;
   float y; 
}chi;
void read(const char *file,int *n,chi x[100]){
    FILE *f=fopen(file,"r");
    if (f==NULL) printf("khong tim thay file");
    fscanf(f,"%d",n);
    for(int i=0;i<*n;i++){
        fscanf(f,"%f%f",&x[i].x,&x[i].y);
    }fclose(f);
    return;
}
void tk(int n,chi x[100]){
    int nt=0,nn=0;
    for (int i=0; i<n; i++){
        if (x[i].x * x[i].x + x[i].y* x[i].y < 25){
            nt++;
        }else nn++;
    }
    printf ("\nso diem nam trong hinh tron la: %d",nt);
    printf ("\nso diem nam ngoai hinh tron la: %d",nn);
}
void check(int n,chi a[100]){
    for (int i=0; i<n;i++){
        for (int j=i+1;j<n;j++){
            if (a[i].x == -a[j].x && a[i].y == -a[j].y){
                printf ("\ncap so doi la %.3f%.3f va %.3f%.3f",a[i].x,a[i].y,a[j].x,a[j].y);
            }
        }    
    }return;
}
int main ()
{
    int n;
    char a[30];
    chi s[100];
    printf("nhap ten file: ");
    scanf("%s",a);
    read(a,&n,s);
    tk(n,s);
    check(n,s);
    return 0;
}
