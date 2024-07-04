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
 typedef struct Event//�����¼����
{
	int occurTime;//����ʱ��
	int type;//�¼����ͣ�0��ʾ�˿͵��1~N��ʾ�˿ʹ�N�Ŵ����뿪
	struct Event *next;
}Event,*EventList;
typedef struct QElemType{//������ʽ�������ݽṹ
	int arriveTime;//����ʱ��
	int duration;//����ʱ��
	struct QElemType *next;
}QElemType;
typedef struct LinkedQueue{
	QElemType *front;//ͷָ��
	QElemType *rear;//βָ��
}LinkedQueue;
#define MAXSIZE 20//���з��񴰿��������
int gWindowsNum;//���з��񴰿���
int gCustomerNum;//�ͻ�������
int gTotalTime;//�ܷ���ʱ��
int gCloseTime;//���йر�ʱ��
EventList gEventList;//�¼��б�
Event gEvent;//�¼�
LinkedQueue gQueue[MAXSIZE];//��������
QElemType gCustomer;//���н��

int InitList(EventList* pList)//��ʼ���¼�����
{
	*pList=(Event*)malloc(sizeof(Event));
	if(*pList==NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	(*pList)->next=NULL;
	return OK;
}
int OrderInsert(EventList pList,Event sEvent)//����Ԫ��
{
	Event *pAfter,*pBefore;//��ʱ�����������������в�����
	pAfter=pList;
	pBefore=pList->next;
	while(pAfter!=NULL && sEvent.occurTime>pAfter->occurTime)//�Ƚ��¼�������ʱ��
	{
		pBefore=pAfter;
		pAfter=pAfter->next;
	}
	pBefore->next=(Event*)malloc(sizeof(Event));//����һ���µĽ�㣬����Before��After��������м�
	pBefore->next->occurTime=sEvent.occurTime;//���½�㸳ֵ
	pBefore->next->type=sEvent.type;
	pBefore->next->next=pAfter;
	return OK;
}
int EmptyList(EventList pList)//�ж������Ƿ�Ϊ��
{
	if(pList->next==NULL)
		return TRUE;
	else
		return FALSE;
}
int DelFirst(EventList pList,Event *pEvent)//ɾ���׽��
{
	Event *pTmp;
	if(EmptyList(pList))
	{
		printf("����Ϊ��");
		return ERROR;
	}
	else 
	{
		pTmp=pList->next;//ɾ�������׽��
		pList->next=pTmp->next;
		*pEvent=*pTmp;//������ֵ
		free(pTmp);//�ͷ��ڴ�
		return OK;
	}
}
int ListTraverse(EventList pList)//��������
{
	Event *pTmp;
	pTmp=pList;
	while(pTmp->next!=NULL)
	{
		pTmp=pTmp->next;
		if(pTmp->type==0)
			printf("��%d���ӣ���һ���ͻ�����������\n",pTmp->occurTime);
		else
			printf("��%d���ӣ�%d�Ŵ��ڵĿͻ������뿪��\n",pTmp->occurTime,pTmp->type);
	}
	printf("\n");
	return OK;
}
int InitQueue(LinkedQueue *pQueue)//��ʼ������
{
	pQueue->front=pQueue->rear=(QElemType*)malloc(sizeof(QElemType));//�����ڴ�
	if(pQueue->front==NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	pQueue->front->next=NULL;
	return OK;
}
int EmptyQueue(LinkedQueue *pQueue)//�ж������Ƿ�Ϊ��
{
	if(pQueue->front==pQueue->rear)
		return TRUE;
	else 
		return FALSE;
}
int DelQueue(LinkedQueue *pQueue,QElemType *pQElem)//�׽�����
{
	QElemType *pTmp;//��ʱ���ָ��
	if(EmptyQueue(pQueue))
	{
		printf("����Ϊ�գ����ܼ���������\n");
		return ERROR;
	}
	else 
	{//ָ���׽���һ��Ԫ�أ������Ƹ�pQElem
		pTmp=pQueue->front->next;
		*pQElem=*pTmp;
		pQueue->front->next=pTmp->next;//ɾ��������
		if(pQueue->rear==pTmp)
			pQueue->rear=pQueue->front;
		free(pTmp);
		return OK;
	}
}
int EnQueue(LinkedQueue *pQueue,QElemType sQElem)//������
{
	QElemType *pTmp;//��ʱ���ָ��
	pTmp=(QElemType*)malloc(sizeof(QElemType));
	if(pTmp==NULL)
	{
		printf("�ڴ����ʧ��\n");
		exit(-1);
	}
	else 
	{//β���ָ������ӵ�Ԫ��
		*pTmp=sQElem;
		pTmp->next=NULL;
		pQueue->rear->next=pTmp;
		pQueue->rear=pTmp;
	}
	return OK;
}
int QueueLength(LinkedQueue *pQueue)//��ȡ���г���
{
	QElemType *pTmp;//��ʱ���ָ��
	int count=0;//��������ͳ�ƽ����
	pTmp=pQueue->front->next;//���е�һ�����
	while(pTmp!=NULL)
	{
		count++;
		pTmp=pTmp->next;
	}
	return count;
}
int GetHead(LinkedQueue *pQueue,QElemType *pQElem)//��ȡ�����׽��
{
	if(EmptyQueue(pQueue))
	{
		printf("����Ϊ��");
		return ERROR;
	}
	*pQElem=*(pQueue->front->next);
	return OK;
}
int QueueTraverse(LinkedQueue *pQueue)//��������
{
	QElemType *pTmp;//��ʱ���ָ��
	if(EmptyQueue(pQueue))
	{
		printf("����Ϊ��\n");
		return ERROR;
	}
	pTmp=pQueue->front->next;//���е�һ�����
	while(pTmp!=NULL)
	{
		printf(">[����ʱ�̣���%d���ӣ�����ʱ����%d����]\n",pTmp->arriveTime,pTmp->duration);
		pTmp=pTmp->next;
	}
	printf("\n");
	return OK;
}
void Initialize( )//��ʼ������
{
	int i;
	gTotalTime=0;
	gCustomerNum=0;
	InitList(&gEventList);//��ʼ���¼��б�
	printf("���������з��񴰿ڸ���(1~20):");//���񴰿ڸ���
	scanf("%d",&gWindowsNum);
	while (gWindowsNum<1 || gWindowsNum>MAXSIZE)
	{
		printf("������1��%d֮���������",MAXSIZE);
		scanf("%d",&gWindowsNum);
	}
	printf("\n���������ر�ʱ�䣨�������ʱ��Ͳ��ڽ����¹˿ͣ�����λ�����ӣ���");//����ر�ʱ��
	scanf("%d",&gCloseTime);
	while(gCloseTime<1)
	{
		printf("����������������:");
		scanf("%d",&gCloseTime);
	}
	for(i=0;i<gWindowsNum;i++)//Ϊÿ�����ڽ���һ���ն���
	{
		InitQueue(&gQueue[i]);
	}
}
//int ShortestQueue( );
int ShortestQueue( )//��ȡ��̶��еı��
{
	int i=0;
	int min=9999;//��̶��еĳ���
	int index=-1;//��̶��еı��
	int length=0;
	//�����������ڣ��Ƚ��ĸ������Ŷӵ�������
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

void CustomerArrived()//����ͻ������¼�
{
	QElemType sQElem;
	Event sEvent;
	int index;//�Ŷ��������ٵĴ��ڱ��
	int arrivetime;//�ͻ�����ʱ��
	int duration;//ҵ�����ʱ��
	printf("��ǰʱ�̣���%d����\n", gEvent.occurTime);//�˿͵����ʱ�䣬����һλ�˿�֮��1~5����
	arrivetime = gEvent.occurTime+ rand() % 5 + 1;
	duration = rand() % 21 + 10;//����ҵ��ʱ��Ϊ10~30����
	if (arrivetime < gCloseTime)//������δ�ر�
	{
		gCustomerNum++;//�¹˿͵����¼�
		sEvent.occurTime = arrivetime;
		sEvent.type = 0;
		OrderInsert(gEventList, sEvent);//�˿ͽ����������ٵĴ����Ŷ�
		sQElem.arriveTime = gEvent.occurTime;//���ʱ��
		sQElem.duration = duration;//����ҵ��ʱ��
		index = ShortestQueue();
		EnQueue(&gQueue[index], sQElem);//����
        //���ǡ�������˶��ף�Ԥ���뿪�¼�
		if (QueueLength(&gQueue[index]) == 1)
		{
			//��¼�˿ʹӵ�index+1�źŴ����뿪����Ϊ������0��ʼ��
			sEvent.occurTime =gEvent.occurTime + duration;
			sEvent.type = index + 1;
			OrderInsert(gEventList, sEvent);
		}
	}
	else//�����Ŷӷ���رգ����ٽ����¿ͻ�
		printf("\n�Ŷӷ����Թرգ����ٽ����¿ͻ���\n");
}
void CustomerLeaved( )//����˿��뿪�¼�
{
	Event sEvent;
	int index=gEvent.type-1;//���б��Ϊ���ڱ��-1
	DelQueue(&gQueue[index],&gCustomer);//ɾ�����׽��
	printf("\n�˿��뿪ʱ�䣺��%d���ӡ�",gEvent.occurTime);
	gTotalTime+=gCustomer.duration;//��¼����ʱ��
	//������в�Ϊ�գ���Ԥ����һλ�˿ʹӵ�index+1�Ŵ����뿪
	if(!EmptyQueue(&gQueue[index]))
	{
		GetHead(&gQueue[index],&gCustomer);//�����һλ�˿�
		//��¼�뿪�¼�
		sEvent.occurTime=gEvent.occurTime+gCustomer.duration;
		sEvent.type=index+1;
		OrderInsert(gEventList,sEvent);
	}
}
void PrintQueue( )//��ʾ��ǰ���ڶ���
{
	int i;
	printf("\n�����Ŷ�״̬��\n");
	for(i=0;i<gWindowsNum;i++)
	{
		printf("%d�Ŵ��ڣ�\n",i+1);
		QueueTraverse(&gQueue[i]);
	}
	printf("\n");
}
void PrintEventList( )//��ʾ��ǰʱ���
{
	printf("\n�¼���״̬��\n");
	ListTraverse(gEventList);
}
void BankSimulation( )//�����Ŷ�ģ��
{
	//�����������������ģ������ͻ��Ŷ��¼�
	//���ݵ�ǰϵͳʱ���ʼ���������
	srand( (unsigned)time(NULL));
	//׼����ҵ
	Initialize( );
	//��һ���˿͵���
	gEvent.occurTime=0;
	gEvent.type=0;
	OrderInsert(gEventList,gEvent);
	//�����Ŷ��б�
	while(!EmptyList(gEventList))
	{
		DelFirst(gEventList,&gEvent);
		//����˿��¼�
		if(gEvent.type==0)
			CustomerArrived( );
		else
			CustomerLeaved( );
		//��ʾ��ǰ�¼��б��Լ��Ŷ����
		PrintEventList( );
		PrintQueue( );
		//��ͣһ�ᣬ���ڹ۲��������
		system("PAUSE");
		printf("\n");
	}
	//ƽ������ʱ��
	printf("\n");
	printf("�ͻ�ƽ������ʱ�䣺%f����\n",(float)gTotalTime/gCustomerNum);
	system("PAUSE");
}

int main( )//���������
{
	BankSimulation( );
	return 0;
}
