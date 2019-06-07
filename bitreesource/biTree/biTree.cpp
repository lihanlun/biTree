// biTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include<stack>
#include<queue>
using namespace std;
typedef struct nodestruct
{
	int forward;
	int middle;
	int backward;
}nodeSructType,*nodeSructTypeP;
typedef struct BiNodeStructNode
{
	nodeSructType data;
	struct BiNodeStructNode *lchild, *rchild;

}BiNodeStruct, *biNodeStructTree;
typedef char ElemType;
typedef struct BiTnode
{
	ElemType data;
	struct BiTnode *lchild, *rchild;
	
}BiTnode,*biTree;

void operation1(ElemType ch)
{
	cout << ch << " ";
}
void operation2(ElemType ch, int level)
{
	cout << ch << "�ڵ�" << level << "��" << endl;
}

void operation3(nodeSructType ch, int level)
{
	cout << ch.middle << "�ڵ�" << level << "��" << endl;
}
void  CreateBiNodeStructTree(biNodeStructTree *T, nodeSructType *data)
{
	if (data == NULL)
		return;
	else if((data->forward-data->backward)<10)
	{
		delete data;
		*T = NULL;
		return;
	}
	else
	{
		*T = (biNodeStructTree)malloc(sizeof(BiNodeStruct));
		(*T)->data = *data;
		nodeSructType *ldata = (nodeSructTypeP)malloc(sizeof(nodeSructType));
		ldata->backward = data->backward;
		ldata->forward = data->middle;
		ldata->middle = (ldata->backward + ldata->forward) / 2;
		nodeSructType *rdata = (nodeSructTypeP)malloc(sizeof(nodeSructType));;
		rdata->backward = data->middle;
		rdata->forward = data->forward;
		rdata->middle = (rdata->backward + rdata->forward) / 2;
		CreateBiNodeStructTree(&(*T)->lchild,ldata);
		CreateBiNodeStructTree(&(*T)->rchild,rdata);
	}

}
void CreateBiTree(biTree *T)
{
	ElemType ch;
	cin >> ch;
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (biTree)malloc(sizeof(BiTnode));
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}
void PreOrderStructTreeTraverse(biNodeStructTree T, int level)
{
	if (T == NULL)
		return;
	operation3(T->data, level);
	PreOrderStructTreeTraverse(T->lchild, level + 1);
	PreOrderStructTreeTraverse(T->rchild, level + 1);

}
void LevelOrderStructTreeTraverse(biNodeStructTree T) {
	//queue<BTNode> queue;��bug����������ط���ע��queue�������װ����ʲô����
	queue<biNodeStructTree > queue;
	
	queue.push(T);         //�㷨������������

	while (!queue.empty()) { //�����зǿ���ѭ��ִ�����е�3������

		T = queue.front();  //����1����ͷԪ�س��ӣ�ָ�����ָ��front()�����ǽ����ض�ͷԪ��
		printf("%d\n ",T->data.middle );//��ͷԪ�س���Ȼ�󽫶�ͷԪ�ص����Һ������
		queue.pop();//pop�ǳ���

		if (T->lchild != NULL) {//����2�����������գ������������
			queue.push(T->lchild);//��ӵľ���һ����ַԪ��
		}

		if (T->rchild != NULL) {//����3�����������գ������������
			queue.push(T->rchild);
		}
	}
}
void PreOrderTraverse(biTree T, int level)
{
	if (T == NULL)
		return;
	operation2(T->data, level);
	PreOrderTraverse(T->lchild, level + 1);
	PreOrderTraverse(T->rchild, level + 1);
	
}

void PostOrderTravelse(biTree T, int level)
{
	if (T == NULL)
		return;
	PostOrderTravelse(T->lchild, level + 1);
	PostOrderTravelse(T->rchild, level + 1);
	operation2(T->data, level);
}
void InOrderTraverse(biTree T, int level)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild, level + 1);
	operation2(T->data, level);
	InOrderTraverse(T->rchild, level + 1);
	
}

int main()
{
	nodeSructType nodeStruct;
	nodeStruct.backward = 0;
	nodeStruct.forward = 1000;
	nodeStruct.middle = 500;
	biNodeStructTree TT = NULL;
	CreateBiNodeStructTree(&TT, &nodeStruct);
	int level = 1;
	//PreOrderStructTreeTraverse(TT, level);
	LevelOrderStructTreeTraverse(TT);
	/*
	int level = 1;
	biTree T = NULL;
	cout << "please input bitree using preOrder" << endl;
	CreateBiTree(&T);
	cout << "please input qianxu bianli" << endl;
	PreOrderTraverse(T, level);
	cout << "please input zhongxu bianli" << endl;
	InOrderTraverse(T, level);
	cout << "houxu bianli" << endl;
	PostOrderTravelse(T, level);
	cout << endl;
	cin >> level;
	cin.get();*/
    return 0;
}

