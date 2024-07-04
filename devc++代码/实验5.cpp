#include <bits/stdc++.h>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
 typedef struct Event//定义事件结点
{
	int occurTime;//发生时刻
	int type;//事件类型：0表示顾客到达；1~N表示顾客从N号窗口离开
	struct Event *next;
}Event,*EventList;
typedef struct QElemType{//定义链式队列数据结构
	int arriveTime;//到达时间
	int duration;//持续时间
	struct QElemType *next;
}QElemType;
typedef struct LinkedQueue{
	QElemType *front;//头指针
	QElemType *rear;//尾指针
}LinkedQueue;
#define MAXSIZE 20//银行服务窗口最大数量
int gWindowsNum;//银行服务窗口数
int gCustomerNum;//客户总人数
int gTotalTime;//总服务时间
int gCloseTime;//银行关闭时间
EventList gEventList;//事件列表
Event gEvent;//事件
LinkedQueue gQueue[MAXSIZE];//队列数组
QElemType gCustomer;//队列结点

int InitList(EventList* pList)//初始化事件链表
{
	*pList=(Event*)malloc(sizeof(Event));
	if(*pList==NULL)
	{
		printf("分配内存失败\n");
		exit(-1);
	}
	(*pList)->next=NULL;
	return OK;
}
int OrderInsert(EventList pList,Event sEvent)//插入元素
{
	Event *pAfter,*pBefore;//临时变量，用于在链表中插入结点
	pAfter=pList;
	pBefore=pList->next;
	while(pAfter!=NULL && sEvent.occurTime>pAfter->occurTime)//比较事件发生的时间
	{
		pBefore=pAfter;
		pAfter=pAfter->next;
	}
	pBefore->next=(Event*)malloc(sizeof(Event));//创建一个新的结点，挂在Before和After两个结点中间
	pBefore->next->occurTime=sEvent.occurTime;//对新结点赋值
	pBefore->next->type=sEvent.type;
	pBefore->next->next=pAfter;
	return OK;
}
int EmptyList(EventList pList)//判断链表是否为空
{
	if(pList->next==NULL)
		return TRUE;
	else
		return FALSE;
}
int DelFirst(EventList pList,Event *pEvent)//删除首结点
{
	Event *pTmp;
	if(EmptyList(pList))
	{
		printf("链表为空");
		return ERROR;
	}
	else 
	{
		pTmp=pList->next;//删除链表首结点
		pList->next=pTmp->next;
		*pEvent=*pTmp;//保存数值
		free(pTmp);//释放内存
		return OK;
	}
}
int ListTraverse(EventList pList)//遍历链表
{
	Event *pTmp;
	pTmp=pList;
	while(pTmp->next!=NULL)
	{
		pTmp=pTmp->next;
		if(pTmp->type==0)
			printf("第%d分钟，下一名客户即将到来。\n",pTmp->occurTime);
		else
			printf("第%d分钟，%d号窗口的客户即将离开。\n",pTmp->occurTime,pTmp->type);
	}
	printf("\n");
	return OK;
}
int InitQueue(LinkedQueue *pQueue)//初始化队列
{
	pQueue->front=pQueue->rear=(QElemType*)malloc(sizeof(QElemType));//分配内存
	if(pQueue->front==NULL)
	{
		printf("分配内存失败\n");
		exit(-1);
	}
	pQueue->front->next=NULL;
	return OK;
}
int EmptyQueue(LinkedQueue *pQueue)//判断链表是否为空
{
	if(pQueue->front==pQueue->rear)
		return TRUE;
	else 
		return FALSE;
}
int DelQueue(LinkedQueue *pQueue,QElemType *pQElem)//首结点出队
{
	QElemType *pTmp;//临时结点指针
	if(EmptyQueue(pQueue))
	{
		printf("队列为空，不能继续出队列\n");
		return ERROR;
	}
	else 
	{//指向首结点后一个元素，并复制给pQElem
		pTmp=pQueue->front->next;
		*pQElem=*pTmp;
		pQueue->front->next=pTmp->next;//删除这个结点
		if(pQueue->rear==pTmp)
			pQueue->rear=pQueue->front;
		free(pTmp);
		return OK;
	}
}
int EnQueue(LinkedQueue *pQueue,QElemType sQElem)//结点入队
{
	QElemType *pTmp;//临时结点指针
	pTmp=(QElemType*)malloc(sizeof(QElemType));
	if(pTmp==NULL)
	{
		printf("内存分配失败\n");
		exit(-1);
	}
	else 
	{//尾结点指向新入队的元素
		*pTmp=sQElem;
		pTmp->next=NULL;
		pQueue->rear->next=pTmp;
		pQueue->rear=pTmp;
	}
	return OK;
}
int QueueLength(LinkedQueue *pQueue)//获取队列长度
{
	QElemType *pTmp;//临时结点指针
	int count=0;//遍历链表，统计结点数
	pTmp=pQueue->front->next;//队列第一个结点
	while(pTmp!=NULL)
	{
		count++;
		pTmp=pTmp->next;
	}
	return count;
}
int GetHead(LinkedQueue *pQueue,QElemType *pQElem)//获取队列首结点
{
	if(EmptyQueue(pQueue))
	{
		printf("队列为空");
		return ERROR;
	}
	*pQElem=*(pQueue->front->next);
	return OK;
}
int QueueTraverse(LinkedQueue *pQueue)//遍历队列
{
	QElemType *pTmp;//临时结点指针
	if(EmptyQueue(pQueue))
	{
		printf("队列为空\n");
		return ERROR;
	}
	pTmp=pQueue->front->next;//队列第一个结点
	while(pTmp!=NULL)
	{
		printf(">[到达时刻：第%d分钟，服务时长：%d分钟]\n",pTmp->arriveTime,pTmp->duration);
		pTmp=pTmp->next;
	}
	printf("\n");
	return OK;
}
void Initialize( )//初始化数据
{
	int i;
	gTotalTime=0;
	gCustomerNum=0;
	InitList(&gEventList);//初始化事件列表
	printf("请输入银行服务窗口个数(1~20):");//服务窗口个数
	scanf("%d",&gWindowsNum);
	while (gWindowsNum<1 || gWindowsNum>MAXSIZE)
	{
		printf("请输入1到%d之间的整数：",MAXSIZE);
		scanf("%d",&gWindowsNum);
	}
	printf("\n请输入服务关闭时间（超过这个时间就不在接纳新顾客）（单位：分钟）：");//服务关闭时间
	scanf("%d",&gCloseTime);
	while(gCloseTime<1)
	{
		printf("请输入大于零的整数:");
		scanf("%d",&gCloseTime);
	}
	for(i=0;i<gWindowsNum;i++)//为每个窗口建立一个空队列
	{
		InitQueue(&gQueue[i]);
	}
}
//int ShortestQueue( );
int ShortestQueue( )//获取最短队列的编号
{
	int i=0;
	int min=9999;//最短队列的长度
	int index=-1;//最短队列的编号
	int length=0;
	//遍历各个窗口，比较哪个窗口排队的人最少
	for(i=0;i<gWindowsNum;i++)
	{
		length=QueueLength(&gQueue[i]);
		if(min>length)
		{
			min=length;
			index=i;
		}
	}
	return index;
}

void CustomerArrived()//处理客户到达事件
{
	QElemType sQElem;
	Event sEvent;
	int index;//排队人数最少的窗口编号
	int arrivetime;//客户到达时间
	int duration;//业务办理时间
	printf("当前时刻：第%d分钟\n", gEvent.occurTime);//顾客到达的时间，在上一位顾客之后1~5分钟
	arrivetime = gEvent.occurTime+ rand() % 5 + 1;
	duration = rand() % 21 + 10;//办理业务时间为10~30分钟
	if (arrivetime < gCloseTime)//服务尚未关闭
	{
		gCustomerNum++;//新顾客到达事件
		sEvent.occurTime = arrivetime;
		sEvent.type = 0;
		OrderInsert(gEventList, sEvent);//顾客进入人数最少的窗口排队
		sQElem.arriveTime = gEvent.occurTime;//入队时刻
		sQElem.duration = duration;//办理业务时间
		index = ShortestQueue();
		EnQueue(&gQueue[index], sQElem);//入列
        //如果恰好排在了队首，预定离开事件
		if (QueueLength(&gQueue[index]) == 1)
		{
			//记录顾客从第index+1号号窗口离开（因为索引从0开始）
			sEvent.occurTime =gEvent.occurTime + duration;
			sEvent.type = index + 1;
			OrderInsert(gEventList, sEvent);
		}
	}
	else//银行排队服务关闭，不再接受新客户
		printf("\n排队服务以关闭，不再接受新客户！\n");
}
void CustomerLeaved( )//处理顾客离开事件
{
	Event sEvent;
	int index=gEvent.type-1;//队列编号为窗口编号-1
	DelQueue(&gQueue[index],&gCustomer);//删除队首结点
	printf("\n顾客离开时间：第%d分钟。",gEvent.occurTime);
	gTotalTime+=gCustomer.duration;//记录服务时间
	//如果队列不为空，则预定下一位顾客从第index+1号窗口离开
	if(!EmptyQueue(&gQueue[index]))
	{
		GetHead(&gQueue[index],&gCustomer);//获得下一位顾客
		//记录离开事件
		sEvent.occurTime=gEvent.occurTime+gCustomer.duration;
		sEvent.type=index+1;
		OrderInsert(gEventList,sEvent);
	}
}
void PrintQueue( )//显示当前窗口队列
{
	int i;
	printf("\n窗口排队状态：\n");
	for(i=0;i<gWindowsNum;i++)
	{
		printf("%d号窗口：\n",i+1);
		QueueTraverse(&gQueue[i]);
	}
	printf("\n");
}
void PrintEventList( )//显示当前时间表
{
	printf("\n事件表状态：\n");
	ListTraverse(gEventList);
}
void BankSimulation( )//银行排队模拟
{
	//随机数发生器，用于模拟随机客户排队事件
	//根据当前系统时间初始化随机种子
	srand( (unsigned)time(NULL));
	//准备开业
	Initialize( );
	//第一个顾客到来
	gEvent.occurTime=0;
	gEvent.type=0;
	OrderInsert(gEventList,gEvent);
	//处理排队列表
	while(!EmptyList(gEventList))
	{
		DelFirst(gEventList,&gEvent);
		//处理顾客事件
		if(gEvent.type==0)
			CustomerArrived( );
		else
			CustomerLeaved( );
		//显示当前事件列表，以及排队情况
		PrintEventList( );
		PrintQueue( );
		//暂停一会，便于观察输出内容
		system("PAUSE");
		printf("\n");
	}
	//平均服务时间
	printf("\n");
	printf("客户平均服务时间：%f分钟\n",(float)gTotalTime/gCustomerNum);
	system("PAUSE");
}

int main( )//主函数入口
{
	BankSimulation( );
	return 0;
}
