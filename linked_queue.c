#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
	char valid;
	char dirty;
	char way;
    
	int tag;
	int address;
	
	struct QueueNode *pre;
	struct QueueNode *post;
	
	int block_data[2][4];
}Node_q;

typedef struct Queue{
	int count;
	Node_q* first;
	Node_q* last;
}Queue;


Node_q *create_node();
Queue *create_queue();
Node_q *dequeue(Queue *queue);
void enqueue(Queue *queue, Node_q* new_node);
Node_q *find_node(Queue* queue, int tag);
void reconstruct_queue(Queue *queue, int tag);

int main(){

    Node_q* sample1 = (Node_q*)malloc(sizeof(Node_q));
    Node_q* sample2 = (Node_q*)malloc(sizeof(Node_q));
    
    Queue* sample_queue = create_queue();
    Node_q* sample_find;   
    sample1->tag = 123;
    sample2->tag = 824;
    enqueue(sample_queue, sample1);
    enqueue(sample_queue, sample2);
    sample_find = find_node(sample_queue, 123);
    printf("check find func\n");

    reconstruct_queue(sample_queue, 123);
    printf("%d\n",sample_queue->count);
    printf("%d\n", sample_find->tag);
    printf("%d\n", (sample_queue->first)->tag);

    return 0;
}

Node_q *create_node(){
	Node_q* node = (Node_q*)malloc(sizeof(Node_q));

	return node;
}



Queue *create_queue(){

	Queue*	queue = (Queue*)malloc(sizeof(Queue));
	queue->first = NULL;
	queue->last = NULL;
	queue->count = 0;
	return queue;
}

Node_q *dequeue(Queue *queue){
	if(queue->count == 0){
		return NULL;
	}
	else{
		Node_q* evict = queue->last;
		(evict->pre)->post = NULL;
		queue->last = evict->pre;
		(queue->count)--;
		return evict;
	}
}

void enqueue(Queue *queue, Node_q* new_node){
	if(queue->count == 0){
		queue->first = new_node;
		queue->last = new_node;
		new_node->post = NULL;
		(queue->count)++;
	}	
	else{
		Node_q* prefirst = queue->first;
		new_node->post = prefirst;
		new_node->pre = prefirst->pre;
		prefirst->pre = new_node;
		queue->first = new_node;
		(queue->count)++;
	}
}


Node_q *find_node(Queue* queue, int tag){
	if((queue->count) == 0) return NULL;
	else{
		Node_q *temp = queue->first;
        while(temp != NULL){
			if((temp->tag) == tag)	return	temp;
			else{
                temp = temp->post;
            }
		}		
	}
    return NULL;
}


void reconstruct_queue(Queue *queue, int tag){

	if((queue->count) == 0 || (queue->count) == 1)	return;
	
    else{
		Node_q* temp = find_node(queue, tag);
		(temp->pre)->post = temp->post;
        if(temp == queue->last){
            dequeue(queue);
            enqueue(queue, temp);
        }
        else{
            (temp->post)->pre = temp->pre;
		    (queue->count)--;
		    enqueue(queue, temp);
        }
		return;
	}
}

