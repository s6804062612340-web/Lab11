#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>

void addRecord(char *addName, int addAge);

int main() {

    char name[64]; int age;
    printf("Enter name: "); scanf("%s", name);
    printf("Enter age: "); scanf("%d", &age);
    addRecord(name, age);

return 0;
}

void addRecord(char *addName, int addAge) {
    FILE*fptr;
    //สร้างโฟล์เดอร์หากไม่มี
    if(access("C:\\lab11\\no1",0) != 0){
        system("mkdir C:\\lab11\\no1"); // Call OS ให้ใช้คำสั้ง system สร้าง path ให้
        }

    fptr=fopen("C:\\lab11\\no1\\first.txt","a");
    if(fptr == NULL){
        printf("Can't Open");
        return;
        }; 
    fprintf(fptr,"Name: %s Age: %d\n",addName,addAge);

    fclose(fptr);
    getch();
}
