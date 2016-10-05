//maze problem
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
	int i,j,x,y;
	int maze[9][9];
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			maze[i][j]=0;
		}
	}
	maze[0][0]=1; //entrance set
	maze[8][8]=1; //exit set
	//maze created;
	int maxx,maxy;
	//eclrscr()
	maxx=9;
	maxy=9;
	int op;
	do{
	
	printf("/nenter the option code :");
	scanf("%d",&op);
	switch(op){
		case 1:printf("/nenter the row and column :");
		scanf("%d%d",&x,&y);
		printf("enter the value :");
		maze[x-1][y-1]=0;
		scanf("%d",&maze[x-1][y-1]);
		break;
		case 2:printf("\n\n");
		break;
	}
}while(op<2);
//mapping done till here...

for(i=0;i<9;i++){
	for(j=0;j<9;j++){
		printf("%d\t",maze[i][j]);
	}
	printf("\n");
}


//map printed


int controls;
int curx,cury;
curx=0;
cury=0;
int won=0;
int oop=0;

do{

printf("\n\nEnter the control :");
scanf("%d",&controls);
//int curx,cury;
if(curx==maxx-1&&cury==maxy-1){
	printf("you won....");
	won=1;
	//break;
}
else {

if(controls==12345){
	printf("GAME FINISHED....NEW RECORD!!!");
	exit(0);
}

else if(controls==1){
	if(curx==0){
		printf("\nmovement not possible");
	}
	else{
		if(maze[curx-1][cury]==1){
			printf("movement done!!");
			maze[curx-1][cury]=8;
			maze[curx][cury]=1;
			curx=curx-1;
			printf("\n\n");
			for(i=0;i<9;i++){
	for(j=0;j<9;j++){
		printf("%d\t",maze[i][j]);
	}
	printf("\n");
}
		}
		else{
			printf("\nmovement not possible");
		}
	}
}//control up set




else if(controls==2){
	if(cury==maxy){
		printf("\nnot possible");
	}
	else{
		if(maze[curx][cury+1]==1){
			printf("movement done...");
			maze[curx][cury+1]=8;
			maze[curx][cury]=1;
			cury=cury+1;
			printf("\n\n");
			for(i=0;i<9;i++){
	for(j=0;j<9;j++){
		printf("%d\t",maze[i][j]);
	}
	printf("\n");
}
		}
		else{
			printf("\nmovement not possible");
		}
		
		
	}
	
	
}//control right set





else if(controls==3){
	if(curx==maxx){
		printf("\nmovement not possible");
	}
	else{
		if(maze[curx+1][cury]==1){
			printf("movement done ");
			maze[curx+1][cury]=8;
			maze[curx][cury]=1;
			curx=curx+1;
			printf("\n\n");
			for(i=0;i<9;i++){
	for(j=0;j<9;j++){
		printf("%d\t",maze[i][j]);
	}
	printf("\n");
}
		}
		else{
			printf("\nmovement not possible");
		}
	}
}//control down set



else if(controls==4){
	if(cury==0){
		printf("\nmovement not possible");
	}
	else{
		if(maze[curx][cury-1]==1){
			printf("movement done");
			maze[curx][cury-1]=8;
			maze[curx][cury]=1;
			cury=cury-1;
			printf("\n\n");
			for(i=0;i<9;i++){      
	for(j=0;j<9;j++){
		printf("%d\t",maze[i][j]);
	}
	printf("\n");
}
		}
		else{
			printf("\nmovement not possible");
		}
	}
}//control right set

else if(controls==0){
	oop=1;
	break;
}



}


}while(won!=1||oop!=1);































	
}
