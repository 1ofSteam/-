//
// Created by ���� on 2022/12/22.
//
#include <malloc.h>
#include "string.h"
#include "data_list.h"
#include "catagory_management.h"
#include "menu.h"
#include "stdio.h"
#define NON 0 //�����ڸ÷���
#define YES 1 //���ڸ÷���

struct catagory book_catagory[cat_length];

//���ͼ���ģ��
void add_book_operation() {
    int is_done=NON;
    while (!is_done){
        int catagory_number,book_number,book_storage;
        char book_name[100];

        scanf("%d %d %s %d",&catagory_number,&book_number,book_name,&book_storage);
        fflush(stdin);
        if(book_catagory[catagory_number].size>=1){
            //����
            int res=duplicate_checking(catagory_number,book_number,book_storage);
            if(res==YES){
                printf("����ظ��������ӿ�档\n");
                fflush(stdout);
                continue_question(&is_done);
                continue;
            }
        }
        add_book_to_library(catagory_number,book_number,book_name,book_storage);
        printf("��ӳɹ�!����%d���࣬�����%d��������%s����%d����\n",catagory_number,book_number,book_name,book_storage);
        continue_question(&is_done);
    }
}

//����ִ�����ͼ�����
void add_book_to_library(int catagory_number,int book_number,char *book_name,int book_storage) {

    if(book_catagory[catagory_number].is_exist==NON){
        book_catagory[catagory_number].is_exist=YES;
    }
    //����ָ��֮ǰ�����
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
    New_Book->total_storage=book_storage;
    New_Book->storage_now=book_storage;
    New_Book->borrow_number=0;
    //ͷָ��ָ���������
    book_catagory[catagory_number].head=New_Book;
    book_catagory[catagory_number].size+=1; //��������
}

//��ʼ����������
void catagory_init(){
    for (int i = 0; i < cat_length; ++i) {
        book_catagory[i].is_exist=NON;
        book_catagory[i].size=0;
        strcpy(book_catagory[i].catagory_name,"-1");
        book_catagory[i].head=NULL;
    }
}

//����
int duplicate_checking(int catagory_num, int book_num,int storage_num) {
    struct Book_Node *point=book_catagory[catagory_num].head;
    while(point!=NULL){
        if(point->book_number==book_num){
            point->total_storage+=storage_num;
            point->storage_now+=storage_num;
            return YES;
        }
        point=point->next;
    }
    return NON;
}

//�Ƿ�ѭ���ĺ��� �����ʺܸ�
void continue_question(int *is_done){
    printf("�Ƿ�������ϣ�1�˳� 0����\n");
    fflush(stdout);
    scanf("%d",is_done);
    fflush(stdin);
    if(*is_done==YES){
        printf("�˳���......\n");
        fflush(stdout);
    }
    else{
        printf("����\n");
        fflush(stdout);
    }
}

//ͼ�����
void delete_book_operation(){
    int catagory_num,book_num;
    int isDone=NON;
    while (!isDone){
        scanf("%d %d",&catagory_num,&book_num);
        struct Book_Node *point=book_catagory[catagory_num].head;
        int find=NON;
        while(point!=NULL){
            if(point->book_number==book_num){
                find=YES;
                break;
            }
            point=point->next;
        }

        if (find == NON){
            printf("���޴��飬����ʧ��\n");
            continue_question(&isDone);
            continue;
        }

        if(point->borrow_number!=0){
            printf("������Ϊ %d ���ܳ��⡣\n",point->borrow_number);
            fflush(stdout);
            continue_question(&isDone);
            continue;
        }
        //��������
        point->able=NON;
        book_catagory[catagory_num].size-=1;
        printf("����ɹ���\n");
        continue_question(&isDone);
    }
}