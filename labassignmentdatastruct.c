#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

int count1 = 0;
int count2 = 0;
float previous_cpa = 0;
float list[MAX];
int i = 0;

struct stack
{
	int top;
	float list[MAX];
	float previous_cpa;
};

//Creating stack
void create(struct stack *t)
{
	t->top=-1;
	t->previous_cpa = 0;
}

//Check if stack is full
float full(struct stack *t)
{
	if(t->top==MAX - 1)
	   return(1);
	else
	   return(0);     
}

//Add element into stack
void push(struct stack *t, struct stack *t1, float data)
{
	
	if (full(t)==1)
	  printf("\nStack if Full\n");
	
	else{
		t->top++;
		t->list[t->top] = data;
	}  
	count1++;
	
	if(data>t->previous_cpa)
	{
	    t->previous_cpa = data;
	}
	else{
	t1->top++;
	t1->list[t1->top] = t->previous_cpa;
	count2++;
	}
}

//To print stack
void printStack(struct stack *t)
{
	
	printf("Stack: \n");
	int i;
	for (i = 0; i<t->top+0; i++){
		printf("Stack %d: %.2f\n", i, t->list[i]);
	}
	
	printf("\n");
}

void printmax(struct stack *t1)
{
	printf("\nHighest CPA is %.2f", t1->list[t1->top]);
}

//Driver code
int main()
{
	struct stack *t;
	struct stack *t1;
	t = (struct stack*)malloc(sizeof(struct stack));
	t1 = (struct stack*)malloc(sizeof(struct stack));
	create(t);
	create(t1);
	
	push(t,t1,2.76);
	push(t,t1,1.03);
	push(t,t1,3.27);
	push(t,t1,2.81);
	push(t,t1,1.10);
	
	printStack(t);
	printStack(t1);
	printmax(t1);
	
	return 0;
}




