//
// Created by ���� on 2022/12/21.
//
#include "option.h"
#include "data_list.h"
#include "data_io.h"
int main() {
    catagory_init();//��ʼ������
    data_import();  //��������
    while (1){
        run(); //���н���
    }
}
