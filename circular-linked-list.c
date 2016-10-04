#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
}*start=0,*cur,*new_node,*prev;
int main()
{
	int op,oop,count=0;
	do{
	
	printf("\n1 for insertion :\n");
	printf("2 for deletion  :\n");
	printf("3 for displaying:\n");
	scanf("%d",&op);
	switch(op){
		case 1:printf("insertion");
			printf("1 for insertion at beginning \n");
			printf("2 for insertion at the end   \n");
			scanf("%d",&oop);
			switch(oop){
			
				case 1:printf("insertion at start : \n");
				count++;
				new_node=(struct node *)malloc(sizeof(struct node));
				printf("enter the value :");
				scanf("%d",&new_node->data);
				new_node->next=NULL;
				if(start==NULL){
					start=new_node;
					cur=new_node;
					cur->next=start;
				}
				else{
					cur=start;
					while(cur->next!=start){
						cur=cur->next;
					}
					new_node->next=start;
					cur->next=new_node;
					start=new_node;
				}
			break;
			case 2:printf("insertion at the end..\n");
			count++;
			new_node=(struct node*)malloc(sizeof(struct node));
			printf("enter the element :");
			scanf("%d",&new_node->data);
			new_node->next=start;
			cur=start;
			while(cur->next!=start){
				cur=cur->next;
			}
			new_node->next=start;
			cur->next=new_node;
			break;
	}break;
	case 2:printf("deletion ...\n");
	printf("1 for deletion at start\n");
	printf("2 for deletion at the end\n");
	scanf("%d",&oop);
	switch(oop){
		case 1:printf("start deleted\n");
		//count--;
		if(count==1){
		free(start);
		//free(cur);
		count--;}
		else{
		while(cur->next!=start){
			prev=cur;
			cur=cur->next;
		}
		cur->next=start->next;
		start=cur->next;
		count--;}
		//prev->next=cur;
		//free(start);
		//start=cur;
		break;
		case 2:printf("deletion at the end\n");
		//count--;
		cur=start;
		while(cur->next!=start){
			prev=cur;
			cur=cur->next;
		}
		prev->next=start;
		count--;
		break;
	}break;
	case 3: if(count==0)
		{printf("empty...");
		}
		else{
		
		cur =start;
		printf("%d",cur->data);
//		cur=cur->next;
		while(cur->next!=start){
			cur=cur->next;
			printf("%d\t",cur->data);
		//	cur=cur->next;
		}}
		break;
	
}//while(op<=3);
}while(op<=4);
}
