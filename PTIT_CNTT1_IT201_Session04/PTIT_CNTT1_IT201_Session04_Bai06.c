#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char *name;
    int age;
};

void informationStuden(struct Student *s) {
    char tempName[100];
    printf("Nhap ID: ");
    scanf("%d",&s->id);
    getchar();
    printf("Nhap ten: ");
    fgets(tempName,100,stdin);
    tempName[strcspn(tempName,"\n")] = 0;

    s->name = (char *)malloc((strlen(tempName)+1) * sizeof(char));
    strcpy(s->name,tempName);
    printf("Nhap age: ");
    scanf("%d",&s->age);
}

int searchStudentById(struct Student arr[],int n, int id) {
    for (int i = 0; i < n; i++) {
        if (arr[i].id == id) {
            return i;
        }
    }
    return -1;
}

void showStudent(struct Student s) {
    printf("ID: %d\n: ", s.id);
    printf("Ten:%s\n: ", s.name);
    printf("Tuoi: %d\n ",s.age);
}

int main() {
    int size = 5 ;
    struct Student arr[size];
    int searchId;

    for (int i = 0; i < size; i++) {
        printf("Nhap sinh vien thu %d : ",i + 1);
        informationStuden(&arr[i]);
    }

    printf("Moi ban nhap id sinh vien can tim");
    scanf("%d",&searchId);

    int result = searchStudentById(arr,size,searchId);
    if (result == -1) {
        printf("Sinh vien k ton tai");
    }else {
        showStudent(arr[result]);
    }
    for (int i = 0; i < size; i++) {
        free(arr[i].name);
    }
    return 0;
}