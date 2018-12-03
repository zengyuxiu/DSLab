/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-10-31 17:01
#
# Filename: Lk_sort.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include "LkList.h"
#include <iostream>
Status LkSort_insertion(LkList &L){
    if(LkListEmpty(L))
        return ERROR;
    for (Position p=L.head->next->next;p->next!=NULL;p=p->next){
        ElemType key = p->next->data;
        Position j = L.head;
        while (j != p){
            if (key < j->next->data){
                Position cur_p = p->next;
                p->next = p->next->next;
                cur_p->next = j->next;
                j->next = cur_p;
                break;
            }
            j = j->next;
        }
    }
    return OK;
}
