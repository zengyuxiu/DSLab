#include "bitree.h"
BiTNode * Search(BiTree T,TElemType e){
    BiTNode * p = NULL;
    if(T){
        if(T->data == e)
            return T;
        else {
            p = Search(T->lchild,e);
            if (p)
                return p;
            else return (Search(T->rchild,e));
        }
    }
    return NULL;
}
Status DeleteChildTree(BiTree T,TElemType e){
    BiTNode * p = NULL;
    p = Search(T,e);
    while(p){
        DestroyBiTree(p);
        Search(T,e);
    }
   return OK; 
}
