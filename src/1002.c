/**
 * 超时......
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dial{
	char phone[10];
	int num;
	struct dial * next;
}dial;



void deal(char * phone,char * usable);

int main1002(void){
	int count;
	dial * head = (dial *)malloc(sizeof(struct dial));
	//初始化头结点
	head->next = NULL;
	head->num = -1;
	strcpy(head->phone,"\0");
	//输入电话数量
	scanf("%d",&count);
	char phone[800];//接受键盘的电话
	char usable[10];//转换后的电话

	while(--count>=0){
		scanf("%s",phone);
		deal(phone,usable);

		//进行从大到小插入
		dial * find = head;int flag = 0;//判断到表尾是否插入数据
		while(find->next !=NULL){
			if(strcmp(find->next->phone,usable) < 0){
				find = find->next;
				continue;
			}
			//相等则num+1
			else if(strcmp(find->next->phone,usable)==0){
				flag = 1;
				find->next->num++;
				break;
			}
			else{
				//出现小的情况时则需要建立节点
				flag = 1;
				dial * tmp = (dial *)malloc(sizeof(dial));
				strcpy(tmp->phone,usable);
				tmp->num = 1;
				tmp->next = find->next;
				find->next = tmp;
				break;
			}
			find = find->next;
		}
		//处理首节点为0情况
		if(flag == 0){
			find->next = (dial *)malloc(sizeof(dial));
			strcpy(find->next->phone,usable);
			find->next->num = 1;
			find->next->next = NULL;
		}

	}
	int flag_duplicate = 0;
	dial * cur = head->next;
	//free(head);
	while(cur!=NULL){
		if(cur->num>1){
			printf("%s %d\n",cur->phone,cur->num);
			flag_duplicate = 1;
		}

		dial * tmp = cur;
		cur = cur->next;
	//	free(tmp);
	}
	if(flag_duplicate == 0){
		printf("No duplicates.\n");
	}
	return 0;
}
//处理接受的电话号
void deal(char * src,char * des){
    int i,j;
    for(i = 0,j = 0;src[i]!='\0'&&j<=8;i++){
        if(src[i]=='-') continue;
        if(src[i]=='Q') continue;
        if(src[i]=='Z') continue;

        if(j==3) des[j++] = '-';

        switch(src[i]){
        case '1':des[j++] = '1';break;
        case '0':des[j++] = '0';break;
        case 'A':
        case 'B':
        case 'C':
        case '2': des[j++] = '2';break;

        case 'D':
        case 'E':
        case 'F':
        case '3':des[j++] = '3';break;


        case 'G':
        case 'H':
        case 'I':
        case '4':des[j++] = '4';break;


        case 'J':
        case 'K':
        case 'L':
        case '5': des[j++] = '5';break;


        case 'M':
        case 'N':
        case 'O':
        case '6':des[j++] = '6';break;

        case 'P':
        case 'R':
        case 'S':
        case '7':des[j++] = '7';break;


        case 'T':
        case 'U':
        case 'V':
        case '8':des[j++] = '8';break;

        case 'W':
        case 'X':
        case 'Y':
        case '9':des[j++] = '9';break;

        }
    }
    des[j] = '\0';
}






