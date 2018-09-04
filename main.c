#include <stdio.h>

typedef int KeyType;

//基数

int digit(int data[],int size){//计算出最大数的位数
    int tmp=0,rv=1;
    for(int i=0;i<size;i++)
        if(tmp<data[i])
            tmp=data[i];
    while (tmp>=10){
        tmp=(double)tmp/10.0;
        rv*=10;
    }
    return rv;
}
void radix(int data[],int size){
    int maxdi=digit(data,size);

    for(int i=1;i<=maxdi;i*=10){
        int tmp[10][100]={0};
        int count[10]={0};
        int n=0;

        for(int j=0;j<size;j++){
            n=data[j]%(i*10);//得出关键字
            n=n/i;

            count[n]++;
            tmp[n][count[n]-1]=data[j];
        }
        int m=0,l=0;

        for(int j=0;j<10;j++){
            l=count[j];
            for(int k=0;k<l;k++){
                data[m++]=tmp[j][k];
            }
        }
    }
}

/*
void radix(int data[],int size){
    int maxdi=digit(data,size),n,k=0;
    for(int i=0;i<maxdi;i*=10){
        int tmp[10][1000]={0};
        for(int j=0;j<size;j++){
            n=(data[j]/i)%10;
            tmp[n][j]=data[j];
        }
        for(int p=0;p<10;p++)
            for(int j=0;j<size;j++){
                if(tmp[p][j]!=0)
                    data[k++]=tmp[p][j];
            }
    }
}
*/
//堆  第一个不可以用
void HeapAdijust(int data[],int s,int e){
    int tmp=data[s];
    for(int i=2*s+1;i<=e;i*=2,i+=1){
        if(i<e&&data[i]<data[i+1])
            i++;
        if(tmp>data[i])break;
        data[s]=data[i];s=i;
    }
    data[s]=tmp;
}
void CreatHeap(int data[],int size){
    for(int i=size/2;i>=0;i--){
        HeapAdijust(data,i,size-1);
    }
}
void Heap(int data[],int size){
    CreatHeap(data,size);
    for(int i=size;i>0;i--){
        int x=data[0];
        data[0]=data[i-1];
        data[i-1]=x;
        HeapAdijust(data,0,i-2);
    }
}

//归并


int main()
{
    int data[]={9,22,7,14,289};
    Heap(data,5);
    for(int i=0;i<5;i++){
        printf("%d ",data[i]);
    }printf("\n");
}
