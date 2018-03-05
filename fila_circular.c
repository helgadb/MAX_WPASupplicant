#include<stdio.h>
#include<stdlib.h>

struct circqueue {
   int front,rear;
   int capacity;
   int *arraySignal;
   int *arrayNoise;
   int *arrayQual;
};

struct circqueue *q(int size) {
   struct circqueue *q=malloc(sizeof(struct circqueue));
   if(!q)return NULL;
   q->capacity=size;
   q->rear=-1;
   q->front=-1;
   q->arraySignal=malloc(q->capacity*sizeof(int));
   if(!q->arraySignal)return NULL;
   q->arrayNoise=malloc(q->capacity*sizeof(int));
   if(!q->arrayNoise)return NULL;
   q->arrayQual=malloc(q->capacity*sizeof(int));
   if(!q->arrayQual)return NULL;
   int i;
   for (i=0; i < q->capacity ;i++) {
       q->arraySignal[i]=999;
       q->arrayNoise[i]=999;
       q->arrayQual[i]=-1;
   }
   return q;
}

int queuesize(struct circqueue *q) {
   int c=0;
   int i;
   for (i=0; i < q->capacity ;i++) {
	if ( q->arraySignal[i] != 999 ) c=c+1;
   }
   return c;
}

void enqueue(struct circqueue *q,int x, int y, int z) {
	q->rear=(q->rear+1)%q->capacity;
	q->arraySignal[q->rear]=x;
        q->arrayNoise[q->rear]=y;
        q->arrayQual[q->rear]=z;
	int s=queuesize(q);
	if ( s >= q->capacity ) q->front = (q->rear+1)%(q->capacity);
	else q->front = 0;
}

int getcirqlastidx(struct circqueue *q) {
   int data=0;
   if ( q->rear != -1 ) {
	return q->rear;
   }
   else {
	return -1;
   }
}

int main()
{
    struct circqueue *win = q( 4 );
    int l;
    int g;
	enqueue(win, -1, -1, -1);
	enqueue(win, -2, -2, -2);
	enqueue(win, -3, -3, -3);
	enqueue(win, -4, -4, -4);
	enqueue(win, -5, -5, -5);
	enqueue(win, -6, -6, -6);
	l=getcirqlastidx(win);
	g=win->arraySignal[l];
    free( win->arraySignal );
    free( win->arrayNoise );
    free( win->arrayQual );
    free( win );
}
