#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5
int counter1=0;
int counter2=0;
int previous_cpa=0;
int i=0;
float student_cpa[MAX];

struct stack 
{
	int top; 
	float student_cpa[MAX];
	float previous_cpa;
};
void create(struct stack *student);
float full(struct stack *student);
void push(struct stack *student, struct stack *s1, float cpa);
void printStack(struct stack *student);
void printStack(struct stack *s1);
void printMax(struct stack *s1);


void create(struct stack *student)
{
	student->top=-1;
	student->previous_cpa=0;
}

float full(struct stack *student)
{
	if(student->top==MAX-1)
	return(1);
	else
	return(0);
}

void push(struct stack *student, struct stack *s1, float cpa)
{
	if(full(student)==1)
		printf("\nStack is Full\n");
	else
	{
		student->top++;
		student->student_cpa[student->top]=cpa;
	}
		counter1++;
	
	if(cpa>student->previous_cpa)
	{
		student->previous_cpa=cpa;
	}
	else{
		s1->top++;
		s1->student_cpa[s1->top]=student->previous_cpa;
		counter2++;
	}
}

void printStack(struct stack *student)
{
	int i;
	printf("Stack: \n");
	for(int i=0;i<student->top+0;i++)
	{
		printf("Stack %d: %.2f\n",i,student->student_cpa[i]);
	}
	printf("\n");
}

void printmax(struct stack *s1)
{
	printf("\nHighest CPA is %.2f", s1->student_cpa[s1->top]);
}

int main () {
	struct stack *student;
	struct stack *s1;
	
	student=(struct stack*)malloc(sizeof(struct stack));
	s1=(struct stack*)malloc(sizeof(struct stack));
	create(student);
	create(s1);
	
	push(student, s1, 2.76);
	push(student, s1, 1.03);
	push(student, s1, 3.27);
	push(student, s1, 2.81);
	push(student, s1, 1.10);
	
	printStack(student);
	printStack(s1);
	printmax(s1);
	
	return 0;
}