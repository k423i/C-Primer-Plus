#include <iostream>
#include <malloc.h>
typedef char TElemType;
using namespace std;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T)//��������������ַ�
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
void InOrderTraverse(BiTree &T)//�������
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout<<T->data;
        InOrderTraverse(T->rchild);
    }
}
void PreOrderTraverse(BiTree &T)//�������
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
    cout<<"���������";
    InOrderTraverse(s);
    cout<<"\n���������";
    PreOrderTraverse(s);
}
