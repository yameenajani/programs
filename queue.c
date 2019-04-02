// Program to implement queue using two stacks

#include <stdio.h> 
#include <stdlib.h> 

struct sNode { 
	int data; 
	struct sNode* next; 
}; 

void push(struct sNode** top_ref, int new_data); 

int pop(struct sNode** top_ref); 

struct queue { 
	struct sNode* stack1; 
	struct sNode* stack2; 
}; 

void enQueue(struct queue* q, int x) 
{ 
	push(&q->stack1, x); 
} 

int deQueue(struct queue* q) 
{ 
	int x; 

	if (q->stack2 == NULL) { 
		while (q->stack1 != NULL) { 
			x = pop(&q->stack1); 
			push(&q->stack2, x); 
		} 
	} 

	x = pop(&q->stack2); 
	return x; 
} 

void push(struct sNode** top_ref, int new_data) 
{ 
	struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode)); 
	if (new_node == NULL) { 
		printf("Stack overflow \n"); 
		getchar(); 
		exit(0); 
	} 

	new_node->data = new_data; 

	new_node->next = (*top_ref); 

	(*top_ref) = new_node; 
} 

int pop(struct sNode** top_ref) 
{ 
	int res; 
	struct sNode* top; 

	top = *top_ref; 
	res = top->data; 
	*top_ref = top->next; 
	free(top); 
	return res; 
} 

int main() 
{ 
	struct queue* q = (struct queue*)malloc(sizeof(struct queue)); 
	q->stack1 = NULL; 
	q->stack2 = NULL; 
    int n, t, x;
	scanf("%d", &n);
    for(int i=0;i<n;i++)
        {
      scanf("%d",&t);  
    switch(t)
        {
        case 1:
            scanf("%d",&t);
            enQueue(q, t);
            break;
        case 2:
            deQueue(q);
            break;
        case 3:
            x = deQueue(q);
            enQueue(q, x);
            printf("%d\n", x);
        break;
    }
    }
	return 0; 
} 

