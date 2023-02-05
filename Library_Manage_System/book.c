//
// Created by ���� on 2022/12/24.
//
#include "stdlib.h"
#include "data_list.h"
#include "stdio.h"
#include "book.h"
#include "string.h"

//�鼮��ѯ
void book_search(){
    printf("��������Ҫ��ѯ�ķ����+����š�������\n���磺1 2����1 ����\n");
    fflush(stdout);
    int is_done=NON;
    while (!is_done){
        int cat_num;
        char search_word[20];
        scanf("%d %s",&cat_num,search_word);
        fflush(stdin);
        if((int)search_word[0]>='0'&&(int)search_word[0]<='9'){
            int book_num= atoi(search_word);
            struct Book_Node *point=book_catagory[cat_num].head;
            while (point!=NULL){
                if(point->book_number==book_num){
                    break;
                }
                point=point->next;
            }
            if(point==NULL){
                printf("δ��ѯ���Ȿ�顣\n");
                continue_question(&is_done);
                continue;
            }
            printf("�ҵ��ˡ�\n����ţ�%d ��ţ�%d ������%s\n�鼮������%d �������%d ������%d\n",
                   cat_num,book_num,point->bookname,point->total_storage,point->storage_now,point->borrow_number);
            continue_question(&is_done);
            continue;
        }

        struct Book_Node *point=book_catagory[cat_num].head;
        while (point!=NULL){
            if(strcmp(point->bookname,search_word)==0){
                break;
            }
            point=point->next;
        }
        if(point==NULL){
            printf("δ��ѯ���Ȿ�顣\n");
            continue_question(&is_done);
            continue;
        }
        printf("�ҵ��ˡ�\n����ţ�%d ��ţ�%d ������%s\n�鼮������%d �������%d ������%d\n",
               cat_num,point->book_number,point->bookname,point->total_storage,point->storage_now,point->borrow_number);
        continue_question(&is_done);
    }
}

//�鼮����
void book_borrow(){
    printf("��������Ҫ���ĵ��顣 �����+���\n���磺1 2\n");
    fflush(stdout);
    int is_done=NON;
    while (!is_done){
        int cat_num,book_num;
        scanf("%d %d",&cat_num,&book_num);
        fflush(stdin);
        if(cat_num>100||book_catagory[cat_num].head==NON){
            printf("�����ʵķ��಻���ڣ�");
            continue_question(&is_done);
            continue;
        }
        struct Book_Node *point=book_catagory[cat_num].head;
        while (point!=NULL){
            if(point->book_number==book_num){
                break;
            }
            point=point->next;
        }
        if(point==NULL){
            printf("δ��ѯ���Ȿ�顣\n");

        }
        if(point->storage_now==0){
            printf("��治�㣬�޷����ġ�\n");
            continue_question(&is_done);
            continue;
        }
        point->borrow_number++;point->storage_now--;
        printf("���ĳɹ���������Ϊ%d�����Ϊ%d\n",point->borrow_number,point->storage_now);
        continue_question(&is_done);
    }
}

//�鼮�黹
void book_return(){
    printf("��������Ҫ�黹���顣 �����+���\n���磺1 2\n");
    fflush(stdout);
    int is_done=NON;
    while (!is_done){
        int cat_num,book_num;
        scanf("%d %d",&cat_num,&book_num);
        fflush(stdin);
        if(cat_num>100||book_catagory[cat_num].head==NON){
            printf("�����ʵķ��಻���ڣ�");
            continue_question(&is_done);
            continue;
        }
        struct Book_Node *point=book_catagory[cat_num].head;
        while (point!=NULL){
            if(point->book_number==book_num){
                break;
            }
            point=point->next;
        }
        if(point==NULL){
            printf("δ��ѯ���Ȿ�顣\n");

        }
        if(point->borrow_number==0){
            printf("�޽����û������ܷ�����\n");
            continue_question(&is_done);
            continue;
        }
        point->borrow_number--;point->storage_now++;
        printf("�����ɹ���������Ϊ%d�����Ϊ%d\n",point->borrow_number,point->storage_now);
        continue_question(&is_done);
    }
}