#include<iostream>
#include<climits> 
using namespace std;
//swap function
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
//function which  return the parent node of the given index
int parent(int i)
{return (i-1)/2;}
//funciton which return left child node of current index
int left(int i)
{return (2*i)+1;}
//funciton which return right child node of current index
int right(int i)
{return (2*i)+2;}
//heap class
class heap{
    int *harr;
    int heap_size;
    int capacity;
public:
//constructor for initilizing the array adn its size
heap(int cap)
{
    capacity=cap;
    heap_size=0;
    harr=new int[cap];
}
//function to heapify the array
void heapify(int i)
{
    int l = left(i); 
   int r = right(i);
    int smallest = i; 
    if (l < heap_size && harr[l] < harr[i])
    smallest = l; 
     if (r < heap_size && harr[r] < harr[smallest]) 
    smallest = r; 
    if (smallest != i)
    {
       swap(&harr[i],&harr[smallest]);
    heapify(smallest); 
    }
    
}
//function to insert into heap
void insert(int k)
{
    if(capacity==heap_size)
    {
        cout<<"\noverflow\n";
        return ;
    }
    heap_size++;
    int i=heap_size-1;
    harr[i]=k;
    while(i!=0&&harr[i]<harr[parent(i)])
    {
        swap(&harr[i],&harr[parent(i)]);
        i = parent(i); 
    }
}
//function to extract root of min heap
int extractmin()
{
    if(heap_size<=0)
    {cout<<"no value"<<endl;
    return INT_MAX;}
    if(heap_size==1)
    {heap_size--;
    
    return harr[0];}
    int root=harr[0];
    harr[0]=harr[heap_size-1];
    heap_size--;
    heapify(0);
    return root;
}
//function to delete the node with given index
void delete_key(int k)
{
    harr[k]=INT_MIN;
    while(k!=0 && harr[k]<harr[parent(k)])
    {
        swap(&harr[k],&harr[parent(k)]);
        k = parent(k); 
    }
        extractmin();

}
};
//main function
int main()
{
    heap h(10);
    h.insert(4);
    h.insert(2);
    h.insert(3);
    h.insert(0);
    h.insert(-1);
   cout<<h.extractmin()<<endl;
   cout<<h.extractmin()<<endl;
   h.delete_key(0);
 cout<<h.extractmin();
 
    return 0;
}