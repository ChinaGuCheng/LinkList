
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

typedef struct Maker{
	char name[64];
	int age;
}Maker;

//打印函数
void print(void *data)
{
	Maker *tmp = (Maker *)data;
	printf("name:%s  age:%d\n", tmp->name, tmp->age);
}

//比较函数
int Conpare(void *data1, void *data2)
{
	Maker *d1 = (Maker *)data1;
	Maker *d2 = (Maker *)data2;
	if (strcmp(d1->name, d2->name) == 0 && d1->age == d2->age)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int main(void)
{
	Maker m1 = { "aaa", 10 };
	Maker m2 = { "bbb", 20 };
	Maker m3 = { "ccc", 30 };
	Maker m4 = { "ddd", 40 };
	Maker m5 = { "eee", 50 };

	Maker m6 = { "fff", 60 };
	Maker m7 = { "ggg", 70 };
	//初始化
	void *list = InitLinkList();
	if (list == NULL)
	{
		return -1;
	}

	//头插
	//InsertHeadLinkList(list, &m1);
	//InsertHeadLinkList(list, &m2);
	//InsertHeadLinkList(list, &m3);
	//InsertHeadLinkList(list, &m4);
	//InsertHeadLinkList(list, &m5);

	//尾插
	InsertTailLinkList(list, &m1);
	InsertTailLinkList(list, &m2);
	InsertTailLinkList(list, &m3);
	InsertTailLinkList(list, &m4);
	InsertTailLinkList(list, &m5);
	//打印
	PrintList(list, print);
	//删除
	printf("\n-----删除位置2的节点后-----\n");
	RemoveLinkList(list, 2);
	PrintList(list, print);
	//头插尾插
	printf("\n-----头插60尾插70后-----\n");
	InsertHeadLinkList(list, &m6);
	InsertTailLinkList(list, &m7);
	PrintList(list, print);
	//头删尾删
	printf("\n-----头删尾删后-----\n");
	RemoveHead(list);
	RemoveTail(list);
	PrintList(list, print);
	//指定值前面插入
	printf("\n-----指定值20前面插入60后-----\n");
	ValueLeftInsert(list, &m2, &m6, Conpare);
	PrintList(list, print);
	//指定值后面插入
	printf("\n-----指定值40后面插入70后-----\n");
	ValueRightInsert(list, &m4, &m7, Conpare);
	PrintList(list, print);
	//指定值删除
	printf("\n-----删除值为40的节点后-----\n");
	ValueDel(list, &m4, Conpare);
	PrintList(list, print);
	//获取指定位置的值
	printf("\n-----位置为3的节点的值为-----\n");
	print(GetPosValue(list, 3));
	//获取头尾元素得值
	printf("-----头元素的值为-----\n");
	print(GetHeadValue(list));
	printf("-----尾元素的值为-----\n");
	print(GetTailValue(list));


	printf("\n-----销毁后-----\n");
	//FreeList(list);		//使用这个释放后list不会置空 所有不能再打印
	FreeList2(&list);		//使用这个释放后list会置空
	PrintList(list, print);


	printf("\n");
	system("pause");
	return 0;
}
