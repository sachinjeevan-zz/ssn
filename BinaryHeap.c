#include<stdio.h>
#include<stdlib.h>
struct BHeap
{
    int* A;
    int size;
    int i;
};
void insert_heap(struct BHeap* heap,int ele)
{
    heap->A[heap->i] = ele;
    int child = heap->i;
    while(child!=0)
    {
        int parent = (child-1)/2;
        if( heap->A[child] > heap->A[parent] )
        {
            int temp = heap->A[child];
            heap->A[child] = heap->A[parent];
            heap->A[parent] = temp;
        }
        else
        {
            break;
        }
        child = parent;
    }
    heap->i = heap->i + 1;

}
void print_heap(struct BHeap* heap)
{
    for(int i=0;i<heap->i;i++)
    {
        printf("%d ",heap->A[i]);
    }
}
int extract_max(struct BHeap* heap) // 7    6      // 6    5  //  5     4
{
    if(heap->i>0)
    {
        int temp = heap->A[0];
        heap->A[0] = heap->A[heap->i-1];  
        heap->A[heap->i-1] = temp;
        heap->i = heap->i - 1;
        int parent = 0;
        while(1)
        {
            int left = (parent*2+1) , right = (parent*2+2),max;
            if(left < heap->i && right < heap->i)
            {
                max = heap->A[left] > heap->A[right] ? left : right;
            } 
            else if(left < heap->i)
            {
                max = left;
            }
            else{
                return heap->A[heap->i];
            }

            if(heap->A[parent] < heap->A[max])
            {
                int temp = heap->A[parent];
                heap->A[parent] = heap->A[max];
                heap->A[max] = temp;
            }
            else
            {
                return heap->A[heap->i];
            }

            parent = max;
        }
    }
    else{
        return -1;
    }
}
struct BHeap* createHeap(int size)
{
    struct BHeap* heap = (struct BHeap*)malloc(sizeof(struct BHeap));
    heap->size = size;
    heap->A = (int*)malloc(sizeof(int)*size);
    heap->i = 0;
    return heap;
}
int main()
{
    int n;
    scanf("%d",&n);
    struct BHeap* heap = createHeap(n);
    for(int i=0;i<n;i++)
    {
        int ele ;
        scanf("%d",&ele);
        insert_heap(heap,ele);
    }
    print_heap(heap);
    printf("\n");
    for(int i=0;i<n;i++)
    {
        extract_max(heap);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",heap->A[i]);
    }
}