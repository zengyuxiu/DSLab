/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-12-18 19:48
#
# Filename: RemovingGames.cpp
#
# Description: 
#
=============================================================================*/
#include<iostream>
#include <array>
int main(void){
    int m,n;
    int flag[10];
    std::cin >> n >> m;
    int Area[n+1][m+1];
    std::array<int,10> row_cross;
    for(int r = 1;r<=n;r++){
        row_cross.fill(0);
        for(int i = 1;i<=m;i++){
            std::cin >> Area[r][i];
            row_cross.at(Area[r][i])++;
        }
        for(int i = 1;i<=9;i++)
            if(row_cross[i] >= 3)
                flag[i] = 1;
    }
    for(int r= 1;r<=m;r++){
        row_cross.fill(0);
        for(int i = 1;i<=n;i++)
            row_cross.at(Area[i][r])++;
        for(int i = 1;i<=9;i++)
            if(row_cross[i] >= 3)
                flag[i] = 1;
    }
    for(int r= 1;r<=n;r++)
        for(int i = 1;i<=m;i++)
            if(flag[Area[r][i]] == 1)
                Area[r][i] = 0;
    for(int r= 1;r<=m;r++)
        for(int i = 1;i<=n;i++)
            if(flag[Area[i][r]] == 1)
                Area[r][i] = 0;
    for(int r= 1;r<=n;r++){
        for(int i = 1;i<=m;i++)
            std::cout << Area[r][i] << ' ';
        std::cout << std::endl;
    }
}
