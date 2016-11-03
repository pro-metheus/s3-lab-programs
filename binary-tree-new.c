#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node{
	int data;
	struct node* left;
	struct node* right;
}*ptr,*new_node,*root;


void prerec(struct node* root){
	if(root!=NULL){
		printf("%d",root->data);
		prerec(root->left);
		prerec(root->right);
	}
}



void inorder2(){
	int top=-1;
	ptr=root;
	int i=0;
	struct node* bt[100];
	top=-1;
	while(i<count){
		if(ptr->left!=NULL){
			top++;
			bt[top]=ptr;
			ptr=ptr->left;
		}
		else if(ptr->right!=NULL && ptr->left==NULL){
			ptr=ptr->right;
			printf("%d",ptr->data);
			i++;
		}
		
		else if(ptr->right==NULL && ptr->left==NULL){
			printf("%d",ptr->data);
			i++;
			ptr=bt[top];
			top--;
			printf("%d",ptr->data);
			i++;
			if(ptr->right!=NULL){
				ptr=ptr->right;
			}
		}
		
		
	}
}




void inorder(){
	int top=-1;
	ptr=root;	
	int i=0;
	struct node* bt[100];
	top=-1;
	while(i<count){
		if(ptr->left!=NULL){
			top++;
			bt[top]=ptr;
			ptr=ptr->left;
			printf("\n went lest");
		}
		
		
		
		else if((ptr->left==NULL)&&(ptr->right==NULL)){
			printf("this first\n");
			printf("%d",ptr->data);
			i++;
			ptr=bt[top];
			top--;
			printf("%d",ptr->data);
			i++;
			if(ptr->right!=NULL){
				ptr=ptr->right;
			}
		
		}
		
		else{
			printf("second wife yeh\n");
			
			ptr=ptr->right;
			printf("%d",ptr->data);
			i++;
		}
		
	}
}



void inrec(struct node* root){
	if(root!=NULL){
		inrec(root->left);
		printf("%d",root->data);
		inrec(root->right);
	}
}
void preorder3(){
	int top=-1;
	ptr=root;
	int i=0;
	struct node* bt[100];
	top=-1;
	
	while(i<count){
		printf("%d",ptr->data);
		i++;
		if(ptr->left!=NULL){
			top++;
			bt[top]=ptr;
			ptr=ptr->left;
		}
		else if(ptr->left==NULL && ptr->right!=NULL){
			ptr=ptr->right; //manipulate in case of error cause its not backtracked
		}
		else if(ptr->left==NULL && ptr->right==NULL){
			while(top!=-1){
				if(bt[top]->right!=NULL){
					ptr=bt[top]->right;
					top--;
					break;
				}
				else{
					top--;
				}
				
			}
		}
	}
	
	
}
void preorder2(){
	int top=-1;
	ptr=root;
	int i=0;
	struct node* bt[100];
	while(i<count){
		printf("%d",ptr->data);
		i++;
		if(ptr->left!=NULL){
			top++;
			bt[top]=ptr;
			ptr=ptr->left;
		}
		
	//	else if(ptr->left==NULL && ptr->right !=NULL){
	//		top++;
	//		bt[top]=ptr;
	//		ptr=ptr->right;
	///	} 
		
		else{
			if(ptr->left== NULL && ptr->right==NULL){
			
			while(top!=-1){
				if(bt[top]->right!=NULL){
					ptr=bt[top]->right;
					top--;
					break;
				}
				else{
					top--;
				}
			}}//
			else if(ptr->left==NULL && ptr->right!=NULL){
			
			
			while(ptr->left==NULL  && ptr->right!=NULL){
				top++;
				bt[top]=ptr->right;
			}
			
			
			}
			
			
			
		}
	}
}




void preorder(){


struct node* bt[100];
int top=-1;
ptr=root;
int i=0;
while(i<=count){
	
	printf("%d",ptr->data);
	i++;
	if(ptr->left!=NULL){
		top++;
		bt[top]=ptr;
		ptr=ptr->left;
	}
	else if(ptr->left==NULL && ptr->right!=NULL){
		ptr=ptr->right;
	}
	
	else{
		if(bt[top]->right!=NULL){
			ptr=bt[top]->right;
			top--;
		}
	}
	}
	
	
}




void maketree(){
	char ch;
	char op;
	int x=0;
	if(root==NULL){
		new_node=(struct node*)malloc(sizeof(struct node));
		printf("\n Enter root node :");
		scanf("%d",&new_node->data);
		new_node->left=NULL;
		new_node->right=NULL;
		root=new_node;
		ptr=root;
		count++;
	}  //if root is null enter root
	
	
	else{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->left=NULL;
		new_node->right=NULL;
		if(ptr->left==NULL && ptr->right==NULL){
			printf("\n LEFT AND RIGHT NODES AVAILABLE <l/r>");
			scanf(" %c",&ch);
			switch(ch){
				case 'l':printf("\n Enter to left node :");
						scanf("%d",&new_node->data);
						count++;
						ptr->left=new_node;
						break;
				case 'r':printf("\n Enter to the right node :");
						scanf(" %d",&new_node->data);
						ptr->right=new_node;
						count++;
						break;
				default:printf("\n problem detected...");
			}//ends here
		}
		
		
		
		
		else{
		
		//if(ptr->left==NULL || ptr->right==NULL){
				do{
				
			printf("\nl for left node, r for right node");
			scanf("%c",&ch);
			switch(ch){
				case 'l':if(ptr->left==NULL){
					printf("\n Enter to the left node :");
					count++;
					scanf("%d",&new_node->data);
					ptr->left=new_node;
					x=1;
				}//if
				
						else{
							printf("\n LEFT NODE ALREADY OCCUPIED...traverse to this node? <y/n>");
							scanf(" %c",&op);
							switch(op){
								case 'y':printf("moved to this left node :");
										ptr=ptr->left;
										break;
								case 'n':break;
							}
							}
							break; //case 1 ends here...
				case 'r':if(ptr->right==NULL){
					printf("\n Enter to th right node :");
					scanf("%d",&new_node->data);
					count++;
					ptr->right=new_node;
					x=1;
				}//if
						else{
							printf("\n RIGHT NODE ALREADY OCCUPIED...traverse to this node? <y/n>");
							scanf(" %c",&op);
							switch(op){
								case 'y':printf("moved to right node :");
										ptr=ptr->right;
										break;
								case 'n':break;
							}
						}
						break;
						}//main switch ends here....
			}while(x!=1);
		}
	}
	
}






void main()
{
	int n;
	do{
	
	printf("\n Enter 1 for insertion...");
	scanf("%d",&n);
	switch(n){
		case 1:maketree();
		printf("\nthe member length :%d",count);
				break;
		case 2:preorder3();
				break;
		case 3:inorder2();
				break;
	}
}while(n<=3);
	
}
