#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
}*start=NULL,*cur=NULL,*new_node,*prev;



int main()
{
//	new_node=(struct node*)malloc(sizeof(node));
	int op;
	do{
	
	printf("\nenter the option code ");
	printf("\nenter 1 for insertion ");
	printf("\nenter 2 for deletion ");
	printf("\n3 for displaying... \n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:printf("insertion...\n");
		int oop;
		printf("\nenter the sub option code...");
		printf("\nenter 1 for insertion at start");
	printf("\nenter 2 for insertion at the end ");
	printf("\nenter 3 for insertion at any position ");
		scanf("%d",&oop);
		//switch 2 begins from here...
		
		switch(oop){
			

			case 1:printf("\ninsertion at start ");
				
		       	new_node=(struct node*)malloc(sizeof(struct node));
			    printf("\nenter the value...\n");
			    scanf("%d",&new_node->data);
			    new_node->next=NULL;
			    if(start==NULL){
				   start=new_node;
				   cur=new_node;
			    }  
			    else{
				   new_node->next=start;
				   start=new_node;
				   cur=new_node;
			    }  
		    break;
			case 2:printf("\ninsertion at the end...");
			    new_node=(struct node*)malloc(sizeof(struct node));
			    cur=start;
			    scanf("%d",&new_node->data);
			    new_node->next=NULL;
			    while(cur->next!=NULL){
				    cur=cur->next;
			   }   
		       //	cur=cur->next;
			   cur->next=new_node;
			   break;
	        case 3:printf("\ninsertion at position");
		    	new_node=(struct node*)malloc(sizeof(struct node));
			    int pos;
			    int count=1;
			    printf("\nenter the position :");
			    scanf("%d",&pos);
			    scanf("%d",&new_node->data);
			    cur=start;
			    while(count<pos){
				   prev=cur;
				   cur=cur->next;
				   count+=1;
			   }
			    new_node->next=cur;
			    prev->next=new_node;
			    break;
		      } break; //oop
		      
	
	    case 2:printf("\ndeleting menu");
	    printf("\nenter one for deletion at start");
	printf("\nenter 2 for deletion at the end ");
	printf("\nenter 3 for deletion at any position ");
	    printf("\nenter option code :");
	    scanf("%d",&oop);
	    switch(oop){
	    	case 1:printf("\ndeletion at start...");
	    	cur=start;
	    	if(start->next==NULL){
	    		start=NULL;
	    		break;
			}
	    	start=cur->next;
	    	free(cur);
	    	break;
	    	case 2:printf("\ndeletion at the end");
	    	cur=start;
	    	while(cur->next!=NULL){
	    		cur=cur->next;
			}
			prev=cur;
			cur=cur->next;
			prev->next=NULL;
			free(cur);
			case 3:printf("\ndeletion at any position");
			int pos;
			    int count=1;
			    printf("\nenter the position :");
			    scanf("%d",&pos);
			    //scanf("%d",&new_node->data);
			    cur=start;
			    while(count<pos){
				   prev=cur;
				   cur=cur->next;
				   count+=1;
			   }
			    //new_node->nex>t=cur;
			    prev->next=cur->next;
			    free(cur);
			    break;
		}
		
	    
		case 3:cur=start;
		printf("\n");
		if(start==NULL){
			printf("\nempty list...");
		}
		while(cur!=NULL){
			printf("%d\t",cur->data);
			cur=cur->next;
		}
		break;   
	} 
	}while(op<4);
	//return 0;
}
