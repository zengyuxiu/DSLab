#include "bitree.h"
#include <queue>
#include <iostream>
#include <stack>
#ifndef VISIT
#define VISIT
std::stack<BiTNode*> S;
std::queue<BiTNode*> Q;
Status visit(TElemType e){
    if(e != NaN){
        std::cout << e << std::endl;
        return OK;
    }
    else 
        return ERROR;
}
Status RecursionPreOrderTraverse(BiTree T,Status (*visit)(TElemType e)){
    if(T)
        if(visit(T->data))
            if(RecursionPreOrderTraverse(T->lchild,visit))
                if(RecursionPreOrderTraverse(T->rchild,visit))
                    return OK;
        return ERROR;
}
Status RecursionPostOrderTraverse(BiTree T,Status (*visit)(TElemType e)){
    if(T)
        if(RecursionPostOrderTraverse(T->lchild,visit))
            if(RecursionPostOrderTraverse(T->rchild,visit))
                if(visit(T->data))
                    return OK;
        return ERROR;
}
Status RecursionInOrderTraverse(BiTree T,Status (*visit)(TElemType e)){
    if(T)
        if(RecursionInOrderTraverse(T->lchild,visit))
            if(visit(T->data))
                if(RecursionInOrderTraverse(T->rchild,visit))
                    return OK;
        return ERROR;
}
Status InOrderTraverse(BiTree T,Status (*visit)(TElemType e)){
    S.push(T);
    while(S.empty()){
        BiTNode * p = NULL;
        while((p = S.top())&&p)
            S.push(p->lchild);
        S.pop();
        if(!S.empty()){
           p = S.top();
           S.pop();
           if(!visit(p->data))
               return ERROR;
           S.push(p->rchild);
        }
    }
    return OK;
}
Status PreOrderTraverse(BiTree T,Status (*visit)(TElemType e)){
    BiTNode * p = T;
    while(!S.empty()||p){
        while(p){
            if(!visit(p->data))
                return ERROR;
            S.push(p);
            p = p->lchild;
        }
        if(!S.empty()){
            p = S.top();
            S.pop();
            p = p->rchild;
        }
    }
    return OK;
}
Status PostOrderTraverse(BiTree T,Status (*visit)(TElemType e)){
    BiTNode * p = T;
    BiTNode * LastVisitedP= NULL;
    while(p){
        S.push(p);
        p = p->lchild;
    }
    while (!S.empty())
    {
        p = S.top();
        S.pop();
        if(p->lchild == NULL || p->lchild == LastVisitedP){
            visit(p->data);
            LastVisitedP = p;
        }
        else {
            S.push(p);
            p = p->rchild;
            while (p){
                S.push(p);
                p = p->lchild;
            }
        }
    }
    return OK;
}
Status LevelOrder(BiTree T,Status (*visit)(TElemType e)){
    BiTNode * p = T;
    Q.push(p);
    while(!Q.empty()){
        BiTNode * tmp = Q.front();
        visit(tmp->data);
        Q.pop();
        if(tmp->lchild)
            Q.push(tmp->lchild);
        if(tmp->rchild)
            Q.push(tmp->rchild);
    }
    return OK;
}
#endif
