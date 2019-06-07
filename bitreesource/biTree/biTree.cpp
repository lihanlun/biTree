// biTree.cpp : 定义控制台应用程序的入口点。
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
	cout << ch << "在第" << level << "层" << endl;
}

void operation3(nodeSructType ch, int level)
{
	cout << ch.middle << "在第" << level << "层" << endl;
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
	//queue<BTNode> queue;大bug隐藏在这个地方；注意queue这个容器装的是什么东西
	queue<biNodeStructTree > queue;
	
	queue.push(T);         //算法：根结点入队列

	while (!queue.empty()) { //若队列非空则循环执行下列的3个步骤

		T = queue.front();  //步骤1：对头元素出队，指针从新指向，front()方法是将返回队头元素
		printf("%d\n ",T->data.middle );//队头元素出队然后将队头元素的左右孩子入队
		queue.pop();//pop是出队

		if (T->lchild != NULL) {//步骤2：左子树不空，将左子树入队
			queue.push(T->lchild);//入队的就是一个地址元素
		}

		if (T->rchild != NULL) {//步骤3：右子树不空，将右子树入队
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

