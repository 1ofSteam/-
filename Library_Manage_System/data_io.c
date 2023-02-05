//
// Created by ���� on 2022/12/28.
//
#include <malloc.h>
#include <stdio.h>
#include "catagory_management.h"
#include "string.h"
#include "data_io.h"
#include "data_list.h"

void data_import() {
    //ָ���ļ�
    FILE *fp = fopen("./data/data_load.txt", "r+");
    if(!fp){
        perror("file open failed");
        return;
    }
    char buf[BUFSIZ]={0};
    fgets(buf,BUFSIZ,fp); //����ȥ��

    //�������
    while (strncmp(buf,"����� ��� ���� �鼮���� ����� ������\n", BUFSIZ)!=0){
        fgets(buf,BUFSIZ,fp);
        if(strncmp(buf,"����� ��� ���� �鼮���� ����� ������\n", BUFSIZ)!=0){
            catagory_import(buf);
        }
    }
    //����ͼ��
    while(!feof(fp)){
        fgets(buf, BUFSIZ, fp);
        book_import(buf);
    }
    printf("ͼ�鵼��ɹ���\n");
    fclose(fp);
}

void data_export() {
    FILE *fp = fopen("./data/data_save.txt", "w+");
    if(!fp){
        perror("file open failed");
        return;
    }
    fprintf(fp,"����� ������\n");
    catagory_export(fp);
    fprintf(fp,"����� ��� ���� �鼮���� ����� ������\n");
    book_export(fp);
    fclose(fp);
    printf("����ɹ���\n");
}

void catagory_import(char *buf){
    int catagory_number;
    char catagory_name[30];
    sscanf(buf,"%d %s",&catagory_number,catagory_name);
    book_catagory[catagory_number].is_exist=YES;
    strcpy(book_catagory[catagory_number].catagory_name,catagory_name);
}

void book_import(char *buf){
    int catagory_number,book_number,total_storage,storage_now,borrow_number;
    char book_name[100];
    //������Ԫ�ظ�ֵ
    sscanf(buf,"%d %d %s %d %d %d",&catagory_number,&book_number,book_name,&total_storage,&storage_now,&borrow_number);
    struct Book_Node *New_Book; //��̬����һ���ڴ�ռ��Ϊͼ��
    New_Book=(struct Book_Node*) malloc(sizeof(struct Book_Node));
    New_Book->next=book_catagory[catagory_number].head;
    //��ʼ��Ϊ�ɷ���
    New_Book->able=YES;
    //������
    strcpy(New_Book->bookname,book_name);
    //���
    New_Book->book_number=book_number;
    //������Ĵ���
    New_Book->total_storage=total_storage;
    New_Book->storage_now=storage_now;
    New_Book->borrow_number=borrow_number;
    //ͷָ��ָ���������
    book_catagory[catagory_number].head=New_Book;
    book_catagory[catagory_number].size+=1; //��������
}

void catagory_export(FILE *fp){
    for (int i = 1; i < 101; ++i) {
        if(book_catagory[i].is_exist==YES){
            fprintf(fp,"%d %s\n",i,book_catagory[i].catagory_name);
        }
    }
}

void book_export(FILE *fp){
    for (int i = 1; i < cat_length; ++i) {
        struct Book_Node *point;
        if(book_catagory[i].is_exist==YES){
            point=book_catagory[i].head;
            while (point!=NULL){
                if(point->able==YES){
                    fprintf(fp,"%d %d %s %d %d %d\n",i,point->book_number,point->bookname,
                            point->total_storage,point->storage_now,point->borrow_number);
                }
                point=point->next;
            }
        }
    }
    long pos = ftell(fp);
    // ���ļ�ָ�뵹�ص��ļ�ĩβ
    fseek(fp, -1, SEEK_END);
    // ����ԭ�еĻ��з�
    fputc(EOF, fp);
    // ���ļ�ָ�뵹�ص��ļ�ĩβ
    fseek(fp, pos, SEEK_SET);
}