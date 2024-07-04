#include <iostream>
#include <malloc.h>
typedef char TElemType;
using namespace std;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T)//按先序遍历输入字符
{
    char x;
    cin>>x;
    if(x=='#') T=NULL;
    else
    {
        T=new BiTNode;
        T->data=x;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
void InOrderTraverse(BiTree &T)//中序遍历
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout<<T->data;
        InOrderTraverse(T->rchild);
    }
}
void PreOrderTraverse(BiTree &T)//先序遍历
{
    if(T)
    {
        cout<<T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

int main()
{
    BiTree s;
    CreateBiTree(s);//AB#CD##E##F#GH###
    cout<<"中序遍历：";
    InOrderTraverse(s);
    cout<<"\n先序遍历：";
    PreOrderTraverse(s);
}
