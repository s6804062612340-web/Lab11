#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>
#define NO_SCORE 5
#define N 10

typedef struct {
    char name[16];
    char surname[20];
    int score[NO_SCORE];
    float total;
} Student;

void readStudentData(Student *);
void findTotalScore(Student *);
float findAverage(Student);
void findLessThanTen(Student);
void writefile(Student*std);
void readfile(Student*newstd);

void main() {
    Student std[N];
    Student newstd[N];
    float avg;
    if(access("C:\\lab11\\no2",0)!=0)
        system("mkdir c:\\lab11\\no2");

        //อ่านข้อมูลเก็บลงไฟล์ C:\\lab11\\no2\\std10.dat
        //มีข้อมูลคือ ชื่อนามสกุลและคะแนนสอบแต่ละครั้งของนักเรียน จำนวน 10 คน
        for(int i=0;i<N;i++){
            readStudentData(&std[i]);
        }
        writefile(std);
        //เปิดไฟล์
        readfile(newstd); 
        
        for(int j=0; j <N; j++){
            findTotalScore(&newstd[j]);
            avg = findAverage(newstd[j]);
            printf("\n\nAverage score is %.2f", avg);
            findLessThanTen(newstd[j]);
        }
}

void readStudentData(Student *pStd) {
    int i;
    printf("Enter student data\n");

    printf("\tName : ");
    scanf("%s", &pStd->name);

    printf("\tSurname : ");
    scanf("%s", &pStd->surname);

    for (i=0; i<NO_SCORE; i++) {
        printf("\tScore %d : ", i+1);
        scanf("%d", &pStd->score[i]);
    }
}

void findTotalScore(Student *pStd) {
    int i;
    printf("\n\nPrint student data");
    printf("\n\t%s %s got score ", pStd->name, pStd->surname);
    pStd->total = 0.0;
    
    for (i=0; i<NO_SCORE; i++) {
        printf("%6d", pStd->score[i]);
        pStd->total += pStd->score[i];
    }
    printf("\n\tTotal score is %.2f", pStd->total);
    }

float findAverage(Student s) {
    return(s.total/NO_SCORE);
}

void findLessThanTen(Student s) {
    int i,count=0;
    printf("\n\nScore less than 10");
    for (i=0; i<NO_SCORE; i++) {
        if (s.score[i] < 10) {
        printf("\n\tTest no.%d - %d", i+1, s.score[i]);
        count++;
    }
    }
    if (count==0) /* กรณีที่ไม่มีการสอบครั้งใดได้น้อยกว่า 10 */
    printf(" -> None");
}

void writefile(Student*std){
    FILE*fptr;
    fptr=fopen("C:\\lab11\\no2\\std10.dat","wb");

    if(fptr == NULL){
        printf("can;t open");
        return;
    }
    fwrite(std,sizeof(Student),N,fptr);

    fclose(fptr);
}

void readfile(Student*newstd){
    FILE*fptr;

    fptr=fopen("C:\\lab11\\no2\\std10.dat","rb");
    if(fptr == NULL){
        printf("can't open\n");
        return;
    }
    fread(newstd,sizeof(Student),N,fptr);
    fclose(fptr);
}
