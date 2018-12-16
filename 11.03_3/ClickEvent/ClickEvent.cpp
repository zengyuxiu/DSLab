/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-12-07 13:43
#
# Filename: ClickEvent.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include<iostream>
#include "Window.h"
int main(void){
    int WindowNumber = 0;
    int ClickNumber = 0;
    int WindowPosition[2][2] = {{0,0},{0,0}};
    int PointPosition[2] = {0,0};
    LkList L;
    InitLkList(L);
    std::cin>>WindowNumber;
    std::cin>>ClickNumber;
    for(int r =1;r<= WindowNumber;r++){
        std::cin >> WindowPosition[0][0] >> WindowPosition[0][1]>>WindowPosition[1][0]>>WindowPosition[1][1];
        CreateWindows(L,WindowPosition,r);
    }
    for(int r =1;r<=ClickNumber;r++){
        std::cin >> PointPosition[0] >> PointPosition[1];
        FocusWindows(L,PointPosition);
    }
}
