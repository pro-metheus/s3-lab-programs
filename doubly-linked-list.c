//doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
	struct node* prev;
}*start=NULL,*cur=NULL,*pre=NULL,*new_node;
int main()
{   int op,oop;
do{
	printf("\nenter 1 for insertion ");
	printf("\nenter 2 for deletion ");
	printf("\nenterr 3 for searching");
	printf("\nenter 4 for displaying... \n");
	printf("Insert option code :");
	scanf("%d",&op);
	switch(op){
		case 1:printf("insertion...\n");
		//insertion from here
		printf("\nenter 1 for insertion at start");
	printf("\nenter 2 for insertion at ant position ");
	printf("\nenter 3 for insertion at end ");
		printf("insert option code...");
		scanf("%d",&oop);
		switch(oop){
			case 1:printf("insert at start \n");
			      if(start==NULL){
			      	new_node=(struct node*)malloc(sizeof(struct node));
			      	new_node->next=NULL;
			      	new_node->prev=NULL;
			      	scanf("%d",&new_node->data);
			      	start=new_node;
			      	cur=new_node;
				  }
				  else{
				  	new_node=(struct node*)malloc(sizeof(struct node));
				  	new_node->next=start;
				  	new_node->prev=NULL;
				  	scanf("%d",&new_node->data);
				  	start=new_node;
				  	cur=new_node;
				  }
				  break;
			case 2:printf("insertion at the middle...\n");
			      new_node=(struct node*)malloc(sizeof(struct node));
			       int count,pos;
			       count=1;
			       printf("enter the position :");
			       scanf("%d",&pos);
			       printf("enter value :");
			       scanf("%d",&new_node->data);
			       cur=start;
			       while(count<pos){
			       	pre=cur;
			       	cur=cur->next;
			       	count++;}
			       	   	new_node->next=cur;
			       	   	new_node->prev=cur->prev;
			       	   	pre->next=new_node;
			       	   	cur->prev=new_node;
						  
				   
				   break;
			case 3:printf("insert at ende \n");
			cur=start;
			while(cur->next!=NULL){
				cur=cur->next;
			}
			new_node=(struct node*)malloc(sizeof(struct node));
			scanf("%d",&new_node->data);
			cur->next=new_node;
			new_node->prev=cur;
			new_node->next=NULL;
			
			break;
		}
			break;
	
			
			
			
			
			
			
			
			
			
		
		
		
		
		
		
		
		//to here
		
		
		case 2:printf("deletion\n");
		if(start==NULL){
			printf("insert please...\n");
			break;
		}
		//deletion from here
		int oop;
		 printf("\nenter one for deletion at start");
	printf("\nenter 2 for deletion at any position ");
	printf("\nenter 3 for deletion at end ");
		printf("enter option code :");
		scanf("%d",&oop);
		switch(oop){
			     case 1:printf("deletion at start\n");
			     		if(start==NULL){
			           	
			           	printf("list empty...");;
			           	break;
					   }
			           cur=start;
			           if(cur->next==NULL){
			           	//free(cur);
			           	start=NULL;
			           	break;
					   }
			           pre=cur;
			           cur=cur->next;
			           start=cur;
			           free(pre);
			           start->prev=NULL;
			           
			           
					   break;
			     case 2:printf("deletion at middle\n");
			        
					    int count,pos;
			       count=1;
			       printf("enter the position :");
			       scanf("%d",&pos);
			       cur=start;
			       while(count<pos){
			       	pre=cur;
			       	cur=cur->next;
			       	count++;}
			       	pre->next=cur->next;
			       	(cur->next)->prev=pre;
			       	
					   break;
				//	   break;
			
			
			    case 3:printf("deletion at the end :\n");
			          cur=start;
			          while(cur->next!=NULL){
			          	pre=cur;
			          	cur=cur->next;
					  }
					  pre->next=NULL;
					  free(cur);
					  
					  break;
				//	  break;
}break;
		case 3:printf("searching...\n");
		int key;
		printf("insert key :");
		scanf("%d",&key);
		cur=start;
		int pos;
		pos=1;
		while(cur!=NULL){
			if(cur->data==key){
			printf("found at %d" ,pos);
			cur=cur->next;
			pos++;	
			}
			else{
				cur=cur->next;
				pos++;
			}
		}
		break;
		
		
		case 4:printf("printing elements...\n");
				if(start==NULL){
					printf("\nEmpty list...");
					break;
				}
		       cur=start;
		       while(cur!=NULL){
		       	printf("%d\t",cur->data);
		       	cur=cur->next;
			   }
			   break;
	}
	}while(op<=4);
	}

