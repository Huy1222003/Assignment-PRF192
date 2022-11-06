#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
struct sinhvien{
    char name[100];
};
FILE *pt;
FILE *po;
typedef struct sinhvien SV;
int del() {
    fclose(pt);
    fclose(po);
   int del = remove("studen.txt");
    pt=fopen("studen.txt","a+");
    po=fopen("studen.txt","r");
}
void menu(){
	printf ("==================================");
	printf ("\n");
	printf ("||		Menu		||");
	printf ("\n");
	printf ("==================================");
    printf("\n");
    printf("1-Print student list\n");
    printf("2-Scan new student \n");
    printf("3-Search a student by name\n");
    printf("4-Exit\n");
}
char* Ltrim(char s[]){
    int i=0;
    while(s[i]==' ') i++;
    if(i>0) strcpy(&s[0],&s[i]);
    return s;
}
char* rtrim (char s[]){
    int i=strlen(s)-1;
    while(s[i]==' ') i--;
    s[i+1]='\0';
    return s;
}
char* trim(char s[]){
    rtrim(Ltrim(s));
    char *ptr=strstr(s,"  ");
    while(ptr!=NULL){
        strcpy(ptr,ptr+1);
        ptr=strstr(s,"  ");
    }
    return s;
}
char* namestr(char s[]){
    trim(s);
    strlwr(s);
    int L=strlen(s);
    int i;
    for(i=0;i<L;i++){
        if(i==0||(i>0&&s[i-1]==' ')) s[i]=toupper(s[i]);
    }
    return s;
}
void printstudent(int *n,SV a[]){
    if(*n==0) printf("file student null");
    else{
        int i;
        for(i=0;i<*n;i++){
            printf("%s\n",a[i].name);
        }
    }
}
void addstudent(int *n,SV a[]){
    printf("Enter the number of the student: ");
    int x;scanf("\n%d",&x);
    getchar();
    while(x--){
    printf("\n Nhap sinh vien thu %d:", *n + 1);
    gets(a[*n+1].name);
    fflush(stdin);
    ++*n;
    fprintf(pt,"%s\n",namestr(a[*n].name));
    }
}
void searchstudent(int *n,SV a[]){
    int found = 0;
     int i;
     char s[30];
     printf("nhap ten sinh vien muon tim :");
     gets(s);
     fflush(stdin);
     namestr(s);

    for(i = 0; i < *n; i++) {
        if (strcmp(a[i].name,s)==0) {
            found = 1;
            printf("sinh vien co ten la %s xuat hien tai vi tri %d \n", s,i);
        }
    }
    if(found==0){
        printf("\nSinh vien co ten la %s khong ton tai.",s);
    }
}
int main(){
    int choice;
    while(choice!=5){
        menu();
        printf("Select your choice :");
    scanf("%d",&choice);getchar();
    pt=fopen("studen.txt","a+");
    po=fopen("studen.txt","r");
    SV a[1000];
    int i=0;
    while(fgets(a[i].name,30,po) != NULL){
        char cop[100];
        strcpy(cop,a[i].name);
        int c=strlen(cop);
        cop[c-1]='\0';
        strcpy(a[i].name,cop);
        fflush(stdin);
        ++i;
    }
    printf("co tong cong %d hoc sinh \n",i);
    switch (choice)
    {
    case 1:
    printstudent(&i,a);
    fclose(pt);
    fclose(po);
    break;
    case 2:
    addstudent(&i,a);
    fclose(pt);
    fclose(po);
    break;
    case 3:
    searchstudent(&i,a);
    fclose(pt);
    fclose(po);
    break;
    case 4:
    printf("Exit program!\n");
    break;
    default:
        break;
    }

    }
    getchar();
}
