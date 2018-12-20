/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-12-20 16:18
#
# Filename: rolling_ball.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include<iostream>
#include<vector>
#define TURE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;
typedef struct Ball{
    int postion = 0;
    int speed = 1;
    static int Length ;
    Status Move(std::vector<Ball*> &Balls);
}Ball;
Status Ball::Move(std::vector<Ball*> &Balls){
    if(this->postion == 0 || this ->postion == Length) 
        this ->speed = - this->speed;
    for(auto OtherBall:Balls)
        if(OtherBall!=this)
            if(OtherBall->postion == this->postion){
                OtherBall->speed = -OtherBall->speed;
                this->speed = -this->speed;
            }
    this->postion += this->speed;
    return OK;
}
int main(void){
    int n = 0,L = 0,t = 0;
    std::vector<Ball*> Balls;
    std::cin >> n >> L >> t;
    Ball::Length = L;
    for(int i = 1;i<=n;i++){
        int position = 0;
        std::cin >>position ;
        Ball * a_new_ball = (Ball *)malloc(sizeof(Ball));
        a_new_ball ->postion =position ;
        Balls.push_back(a_new_ball);
    }
    for(int i = 1;i<=t;++i){
        for(auto a_ball:Balls)
            a_ball->Move(Balls);
    }
    for(auto const a_ball : Balls)
        std::cout << a_ball->postion << ' ';
    std::cout << std::endl;
    return OK;
}
