#include <stdio.h>

//基数 radix(data,6)
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
        //打印
        for(int i=0;i<size;i++){
            printf("%d ",data[i]);
        }printf("\n\n");
        sleep(1);
    }
}

//堆 Heap(data,6);
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
    printf("调整堆：\n");
    for(int i=size;i>0;i--){
        int x=data[0];
        data[0]=data[i-1];
        data[i-1]=x;
        HeapAdijust(data,0,i-2);
        //打印
        for(int i=0;i<size;i++){
            printf("%d ",data[i]);
        }printf("\n\n");
        sleep(1);
    }
}

//归并 Merge(data,5)
void Merge(int dataR[],int dataS[],int low,int mid,int high){
    int i=low,j=mid+1,k=low;
    while (i<=mid&&j<=high) {
        if(dataR[i]<dataR[j])
            dataS[k++]=dataR[i++];
        else
            dataS[k++]=dataR[j++];
    }
    while (i<=mid) dataS[k++]=dataR[i++];
    while (j<=high) dataS[k++]=dataR[j++];
}
void Msort(int dataR[],int dataS[],int low,int high){
    if(low==high)dataS[low]=dataR[low];
    else{
        int mid=(low+high)/2;
        int S[10]={0};//MAX =20;
        Msort(dataR,S,low,mid);
        Msort(dataR,S,mid+1,high);
        Merge(S,dataS,low,mid,high);
    }
}
void MergeSort(int data[],int size){
    Msort(data,data,0,size);
}

//快速 QuickSort(data,6)
int partition(int data[],int low,int high){
    int tmp=data[low],key=data[low];
    while (low<high) {
        while (low<high&&data[high]>=key) --high;
        data[low]=data[high];
        while (low<high&&data[low]<=key) ++low;
        data[high]=data[low];
    }data[low]=tmp;
    return low;
}
void QSort(int data[],int low,int high){
    if(low<high){
        int a=partition(data,low,high);
        QSort(data,low,a-1);
        QSort(data,a+1,high);
    }
}
void QuickSort(int data[],int size){
    QSort(data,0,size);
}

int main()
{
    int data[]={8,5,9,2,7,6,4};
    QuickSort(data,7);
    for(int i=0;i<7;i++){
        printf("%d ",data[i]);
    }printf("\n\n");
}
