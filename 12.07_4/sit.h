/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-12-08 16:00
#
# Filename: sit.h
#
# Description: 
#
=============================================================================*/
#include<iostream>
#include<vector>
#include<array>
#define SitsNumberPerRows 5
#define RowsNumberPerChunk 20
#define TURE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
#define AVILIABLE   1;
#define INAVILIABLE   -1;
#define UNENGOUH 0;
typedef int Status;
//typedef struct Sit{
//    int flag = AVILIABLE;
//    int SitNumber = 0;
//}Sit,SitPoint;
//typedef struct Rows{
//    Sit Sits[SitsNumberPerRows+1];
//    int available_site = 5;
//    int RowsNumber = 0;
//} Rows,* RowsPoint;
//typedef struct Chunk{
//    Rows rows[RowsNumberPerChunk+1];
//    Status available_rows[RowsNumberPerChunk+1]={1};
//}Chunk;
//Status Init(Chunk &C){
//    for(int r = 1;r<=RowsNumberPerChunk;r++){
//        C.rows[r].RowsNumber = SitsNumberPerRows*(r-1);
//        for(int i = 1;i<=SitsNumberPerRows;i++){
//            C.rows[r].Sits[i].SitNumber = C.rows[r].RowsNumber+i;
//        }
//    }
//    return OK;
//}
//Status Arrange(int tickets,Chunk &C){
//    switch (tickets){
//        case 5:
//            int r = 1;
//            while(r<=20){
//                if(C.available_rows[r]==1){
//                    C.rows[r].available_site = 0;
//                    C.available_rows[r] = -1;
//                    for(int i= 1;i<=SitsNumberPerRows;i++)
//                        std::cout<<C.rows[r].Sits[i].SitNumber;
//                    std::cout<<std::endl;
//                    return OK;
//                }
//                else r++;
//            }
//            int r = 1; 
//            while(r<=20){
//            }
//    }
//}
typedef struct Sit{
    int flag = 0;
    int number = 0;
    int row_number = 0;
}Sit;
typedef struct Row{
    Sit sits[21][6];
    int row_ststus[21];
}Row;
Status Init(Row &R){
    for(int r = 1;r<=20;r++){
        R.row_ststus[r] = 5;
        for(int s = 1;s<=5;s++){
            R.sits[r][s].flag = 1;
            R.sits[r][s].number = (r-1)*5+s;
            R.sits[r][s].row_number = r;
        }
    }
    return OK;
}
int Arrange(Row &R,int tickets){
    for(int r = 1;r<=20;r++){
        if(R.row_ststus[r]>=tickets){
            for(int s=1;s<=tickets;s++)
                std::cout << R.sits[r][6-R.row_ststus[r]].number;
            R.row_ststus[r] -= tickets;
            std::cout << std::endl;
            return tickets;
        }
    }
    if(tickets == 1)
        return -1;
    else
        return(Arrange(R,tickets-1));
}
Status Deal(Row &R){
    int tickets = 0;
    std::cin >> tickets;
    int current_ticket = tickets;
    while (current_ticket == 0)
        current_ticket =current_ticket -  Arrange(R,current_ticket);
    return OK;
}

