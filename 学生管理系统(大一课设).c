#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
enum Option
{
	exit1,//0
	add,//1
	del,//2
	modify,//3
	search,//4
	print,//5
};
enum Con
{
	ERRO,
	NAME,
	UNIT,
	PHONE,
	TELE,
	ADDR,
};
typedef struct peo{
	char name[100];
	char unit[100];
	char phone[100];
	char tele[100];
	char address[100];
}peo;
typedef struct Contact{
	peo* data;
	int num;
	int capacity;
}Contact;


void InitContact(Contact* ss);
void DestroyContact(Contact* ss);
void AddContact(Contact* ss);
void PrintContact(const Contact* ss);
void DelContact(Contact* ss);
void SearchContact(const Contact* ss);
void SaveContact(const Contact* ss);
void ModifyContact(Contact* ss);
void SortContact(Contact* ss);
#define _CRT_SECURE_NO_WARNINGS 1
void CheckCapacity(Contact* ss)
{
	if(ss->num == ss->capacity)
	{
		peo* tmp = (peo*)realloc(ss->data,(ss->capacity + 2) * sizeof(peo));
		if(tmp !=NULL)
		{
			ss->data = tmp;
		}
		else
		{
			perror("CheckCapacity::realloc");
			return;
		}
		ss->capacity += 2;
		printf("增加容量成功!");
	}
}
void LoadContact(Contact* ss)
{
	FILE* pf = fopen("contact.dat","rb");
	if(pf == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	peo tmp={ 0 };
	while(fread(&tmp,sizeof(peo),1,pf))
	{
		CheckCapacity(ss);
		ss->data[ss->num]=tmp;
		ss->num++;
	}
	fclose(pf);
	pf == NULL;
}
void InitCon(Contact* ss)
{
	assert(ss);
	ss->num =0;
	ss->capacity = 3;
	ss->data = (peo*)malloc(ss->capacity * sizeof(peo));
	if(ss->data == NULL)
	{
		perror("InitContact::malloc");
		return;
	}
	memset(ss->data,0,ss->capacity * sizeof(peo));
	LoadContact(ss);
}
void AddContact(Contact* ss)
{
	assert(ss);
	CheckCapacity(ss);
	printf("请输入姓名:\n");
	scanf("%s",ss->data[ss->num].name);
	printf("请输入单位:\n");
	scanf("%s",ss->data[ss->num].unit);
	printf("请输入电话:\n");
	scanf("%s",ss->data[ss->num].phone);
	printf("请输入固定电话:\n");
	scanf("%s",ss->data[ss->num].tele);
	printf("请输入地址:\n");
	scanf("%s",ss->data[ss->num].address);
	ss->num++;
	printf("此用户已添加成功!\n");
}
void PrintContact(const Contact* ss)
{
	assert(ss);
	int i = 0;
	printf("%-20s %-30s %-12s %-12s %-30s\n","姓名","单位","电话","固定电话","地址");
	for(i=0;i<ss->num;i++)
	{
		printf("%-20s %-30s %-12s %-12s %-30s\n",ss->data[i].name,ss->data[i].unit,ss->data[i].phone,ss->data[i].tele,ss->data[i].address);
	}
}
int FindByName(const Contact* ss,char name[])
{
	assert(ss);
	int n = 0;
	for(n=0;n<ss->num;n++)
	{
		if(0 == strcmp(ss->data[n].name,name))
		{
			return n;
		}
	}
	return -1;
}
void DelContact(Contact* ss)
{
	assert(ss);
	if(ss->num == 0)
	{
		printf("该通讯录已空，无法进行删除操作！\n");
		return;
	}
	char name[100] = { 0 };
	printf("请输入需删除的联系人的姓名:\n");
	scanf("%s",&name);
	int pen = FindByName(ss, name);
	if(pen == -1)
	{
		printf("该联系人不存在！\n");
		return;
	}
	int m = 0;
	for(m=pen;m < ss->num-1;m++)
	{
		ss->data[m]=ss->data[m+1];
	}
	ss->num--;
	printf("删除成功!\n");
}
void SearchContact(const Contact* ss)
{
	char name[100] = { 0 };
	printf("请输入要查找的用户姓名:\n");
	scanf("%s",&name);
	int pen = FindByName(ss,name);
	if(pen == -1)
	{
		printf("该用户不存在!\n");
		return;
	}
	printf("%-20s %-30s %-12s %-12s %-30s\n","姓名","单位","电话","固定电话","地址");
	printf("%-20s %-30s %-12s %-12s %-30s\n",ss->data[pen].name,ss->data[pen].unit,ss->data[pen].phone,ss->data[pen].tele,ss->data[pen].address);
}
void SaveContact(const Contact* ss)
{
	FILE* pf = fopen("contact.dat","wb");
	if(pf == NULL)
	{
		perror("SaveContact::fopen");
		return;
	}
	int n =0;
	for(n=0;n<ss->num;n++)
	{
		fwrite(ss->data + n,sizeof(peo),1,pf);
	}
	fclose(pf);
	pf =NULL;
}
void ModifyContact(Contact* ss)
{
	assert(ss);
	char name[100];
	printf("请输入需修改的用户的姓名:\n");
	scanf("%s",&name);
	int pen = FindByName(ss, name);
	if(pen == -1)
	{
		printf("该联系人不存在！\n");
	}
	else
	{
		int Num = 0;
		do{
			printf("请输入该用户需修改的信息:\n");
			printf("退出(0) 姓名(1) 单位(2) 固定电话(3) 电话(4) 地址(5)");
			scanf("%d",&Num);
			switch(Num)
			{
				case 0:
					printf("已保存修改，退出界面>\n");
					break;
				case NAME:
					printf("请输入修改后的用户姓名:\n");
					scanf("%s",ss->data[pen].name);
					break;
				case UNIT:
					printf("请输入修改后的用户单位:\n");
					scanf("%s",ss->data[pen].unit);
					break;
				case PHONE:
					printf("请输入修改后的用户电话:\n");
					scanf("%s",ss->data[pen].phone);
					break;
				case TELE:
					printf("请输入修改后的用户固定电话:\n");
					scanf("%s",ss->data[pen].tele);
					break;
				case ADDR:
					printf("请输入修改后的用户地址:\n");
					scanf("%s",ss->data[pen].address);
					break;
					
				dafault:printf("未识别到该操作！\n");
			}
		}while(Num);
	}
	
}
void menu()
{
	printf("======================================\n");
	printf("========1.增加联系人>=================\n");
	printf("========2.删除联系人>=================\n");
	printf("========3.修改联系人>=================\n");
	printf("========4.查找联系人>=================\n");
	printf("========5.显示全部联系人>=============\n");
	printf("========0.退出>=======================\n");
	printf("======================================\n");
}
void test(){
	Contact con;
	InitCon(&con);
	int input = 0;
	do
	{
		menu();
		scanf("%d",&input);
		switch(input)
		{
			case add:
				AddContact(&con);
				break;
			case del:
				DelContact(&con);
				break;
			case modify:
				ModifyContact(&con);
				break;
			case search:
				SearchContact(&con);
				break;
			case print:
				PrintContact(&con);
				break;
			case exit1:
				SaveContact(&con);				
				printf("退出程序，欢迎再次使用!\n");
				break;	
			default:
				printf("没有找到该数字对应的操作！\n");
				break;
		}
	}while(input);
}
int main() {
	test();
	return 0;
}