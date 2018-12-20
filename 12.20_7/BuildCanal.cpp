/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-12-20 17:39
#
# Filename: BuildCanal.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include"MiniSpanTree_PRIM.cpp"
int main(){
    MGraph G;
    CreateUDN(G);
    MiniSpanTree_PRIM(G,1);
}
