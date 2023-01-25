//
// Created by ���� on 2022/12/27.
//
#include <stdlib.h>
#include "stdio.h"
#include "catagory_management.h"
#include "data_list.h"
#include "string.h"

//�������
void catagory_search(){
    printf("������Ҫ��ѯ�ķ��ࡣ\n");
    fflush(stdout);
    fflush(stdin);
    char word[5];
    int is_done=NON;
    while (!is_done){
        scanf("%s",&word);
        fflush(stdin);
        if(strcmp(word,"#")==0){
            //ȫ�г� ���ڷ�����ҵ�һ��С����
            full_display();
            continue_question(&is_done);
            continue;
        }
        if(strcmp(word,"*")== 0){
            for (int i = 0; i < cat_length; ++i) {
                if(book_catagory[i].is_exist==YES){
                    printf("�����Ϊ��%d ",i);
                    printf("��%d���� ",book_catagory[i].size);
                    if(strcmp(book_catagory[i].catagory_name,"-1")!= 0){
                        printf("������Ϊ��%s",book_catagory[i].catagory_name);
                    }
                    printf("��\n");
                    fflush(stdout);
                }
            }
        }
        else{
            int cat_num= atoi(word);
            if(book_catagory[cat_num].is_exist==YES){
                fflush(stdout);
                printf("������� �����Ϊ��%d ��%d����",cat_num,book_catagory[cat_num].size);
                if(strcmp(book_catagory[cat_num].catagory_name,"-1")!= 0){
                    printf("������Ϊ��%s",book_catagory[cat_num].catagory_name);
                }
                printf("��\n");
                struct Book_Node *point=book_catagory[cat_num].head;
                while (point!=NULL){
                    if(point->able==YES){
                        printf("���Ϊ%d������Ϊ��%s��������Ϊ%d�����п��Ϊ%d��������Ϊ%d\n",
                               point->book_number,point->bookname,point->total_storage,point->storage_now,point->borrow_number);
                    }
                    point=point->next;
                }
                fflush(stdout);
            }
            else{
                fflush(stdout);
                printf("���಻���ڣ�\n");
            }
        }
        continue_question(&is_done);
    }
}

//��ӷ���
void catagory_add(){
    printf("������Ҫ���ӵķ��ࡣ\n");
    fflush(stdout);
    int cat_num;
    int is_done=NON;
    while (!is_done){
        scanf("%d",&cat_num);
        fflush(stdin);
        if(book_catagory[cat_num].is_exist==YES) {
            printf("���� %d �Ѵ��ڡ�\n",cat_num);
            fflush(stdout);
            continue_question(&is_done);
            fflush(stdout);
            continue;
        }
        //ת��״̬
        book_catagory[cat_num].is_exist=YES;
        printf("���� %d ��ӳɹ���\n",cat_num);
        fflush(stdout);
        continue_question(&is_done);
        fflush(stdout);
    }

}

//ɾ������
void catagory_del() {
    printf("������Ҫɾ���ķ��ࡣ\n");
    fflush(stdout);
    int cat_num;
    int is_done=NON;
    while (!is_done){
        scanf("%d",&cat_num);
        fflush(stdin);
        if(book_catagory[cat_num].is_exist==NON){
            printf("���಻���ڡ�\n");
            continue_question(&is_done);
            continue;
        }

        if(book_catagory[cat_num].size!=0){
            printf("�� %d ��ͼ�飬����ɾ����\n",book_catagory[cat_num].size);
            continue_question(&is_done);
            continue;
        }
        book_catagory[cat_num].is_exist=NON;
        printf("ɾ������ɹ���\n");
        continue_question(&is_done);
    }
}

//�޸ķ���
void catagory_modify(){
    printf("������Ҫ�޸ĵķ��ࡣ\n");
    fflush(stdout);
    int cat_num;
    int is_done=NON;
    while (!is_done){
        scanf("%d",&cat_num);
        fflush(stdin);
        printf("��Ҫ�޸ĵ�%d���࣬",cat_num);
        if(strcmp(book_catagory[cat_num].catagory_name,"-1")!= 0){
            printf("������Ϊ��%s",book_catagory[cat_num].catagory_name);
        } else{
            printf("������δ����");
        }
        printf("��\n");
        printf("������������ơ�\n");
        fflush(stdout);
        char cat_name[30];
        scanf("%s",cat_name);
        fflush(stdin);
        strcpy(book_catagory[cat_num].catagory_name,cat_name);
        printf("�������ɹ�������%d����Ϊ%s��\n",cat_num,book_catagory[cat_num].catagory_name);
        continue_question(&is_done);
    }
}

//ȫչʾ ���շ����鼮 �����鼮 չʾͼ������з�����鼮
// ֱ�۵ĸ��ܺ������ݣ�ˬ��
void full_display(){
    struct Book_Node *point;
    for (int i = 0; i < cat_length; ++i) {
        if(book_catagory[i].is_exist==YES){
            printf("����%d ����Ϊ%s ����%d���鼮\n",i,book_catagory[i].catagory_name,book_catagory[i].size);
            point=book_catagory[i].head;
            while (point!=NULL){
                if(point->able==YES){
                    printf("���Ϊ%d������Ϊ��%s��������Ϊ%d�����п��Ϊ%d��������Ϊ%d\n",
                           point->book_number,point->bookname,point->total_storage,point->storage_now,point->borrow_number);
                }
                point=point->next;
            }
            printf("\n");
        }
    }
}