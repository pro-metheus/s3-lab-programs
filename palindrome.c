//palindrome via linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
	struct node* prev;
}*start,*end,*new_node,*cur;
int main()
{
	int count,terms,palindrome;
	count=0;
	printf("enter the number of terms :");
	scanf("%d",&terms);
	while(count<terms){
		new_node=(struct node*)malloc(sizeof(node));
		scanf("%d",&new_node->data);
		if(start==NULL){
			new_node->next=NULL;
			new_node->prev=NULL;
			start=new_node;
			cur=new_node;
			count++;
			
		}
		else{
			cur->next=new_node;
			new_node->prev=cur;
			new_node->next=NULL;
			cur=new_node;
			count++;
		}
	}
	cur=start;
	while(cur!=NULL){
		printf("%d",cur->data);
		cur=cur->next;
	}
	cur=start;
	while(cur->next!=NULL){
		cur=cur->next;
	}
	end=cur;
	cur=start;
	while(cur->next!=NULL && end->prev!=NULL){
		if(cur->data==end->data){
			cur=cur->next;
			end=end->prev;
			palindrome=1;
			//printf("in loop");
		}
		else{
			printf("\nnot palindrome");
			palindrome=0;
			break;
		}
	} 
	
	
	
	if(palindrome==1){
		printf("palindrome");
	}
}
