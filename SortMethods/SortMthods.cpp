#include<stdio.h>

void show(int a[], int size){
    for(int i = 0; i < size; i++){
        printf(" %d",a[i]);
    }
    printf("\n");
}

// 冒泡排序
void BubbleSort(int a[], int size){
    int len = size;
    int count = 0;
    for(int i = 0; i < len-1; i++){
        for(int j = 0; j < len-1-i; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
            count++;
        }
    }
    printf("%d\n",count);
    show(a,len);
}

// 冒泡排序(优化算法)
void BubbleSort2(int a[], int size){
    int len = size;
    int flag = 0;
    int count = 0;
    for(int i = 0; i < len-1; i++){
        flag = 0;
        for(int j = 0; j < len-1-i; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
            count++;
        }
        if(flag == 0) break;
    }
    printf("%d\n",count);
    show(a,len);
}


// 选择排序
void SelectionSort(int a[], int size){
    int minIndex;
    for(int i = 0; i<size-1; i++){
        minIndex = i;
        // 寻找最小元素的位置,并存储到minIndex中
        for(int j = i; j<size-1; j++){
            if(a[j] < a[minIndex]){
                minIndex = j;
            }
        }
        // 元素初始位置交换位置
        int temp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = temp; 
    }
    show(a,15);
}

// 插入排序
void InsertionSort(int a[], int len){

    // 用cursor指示排好的序列的末尾，方便移动插入数据
    int cursor;
    // 用来临时储存要插入的元素
    int temp;
    for(int i = 1; i<len; i++){

        cursor = i-1;
        temp = a[i];

        // 当cusor指示的数据要比要插入的数据小时，将当前元素的位置后移，也将cursor前移去比较
        while(cursor >=0 && a[cursor] > temp){
            a[cursor+1] = a[cursor];
            cursor--;
        }

        //while循环以后，刚好当前cursor指示的元素比要插入的元素小，将待插入的元素插入位置
        a[cursor+1] = temp;
    }
    show(a,15);
}

void insert(int a[], int start, int h, int len){
    int temp;
    int cursor;
    for(int i = start+h; i<len; i+=h){
        cursor = i-h;
        temp = a[i];
        while(cursor >= 0 && temp < a[cursor]){
            a[cursor+h] = a[cursor];
            cursor -= h;
        }
        a[cursor+h] = temp;
    }
}

// 希尔排序
void ShellSort(int a[], int len){
    if(len < 2) return;
    // 确定每次插排时，每组相邻元素的间隔h
    for(int h = len/2; h > 0; h/=2){
        // 依次对每组进行插排
        for(int i = 0; i < h; i++){
            insert(a,i,h,len);
        }
    }
    show(a,len);
}

int partition(int a[], int left, int right){

    // 确定中轴基准
    int pivot = a[left];
    int i = left+1;
    int j = right;

    while(1){
        // 从左向右找到第一个比基准大的
        while( i<=j && a[i] <= pivot) i++;
        // 从右向左找到第一个比基准小的
        while( j>=i && a[j] >= pivot) j--;

        // 若位置i，j重叠，则终止循环
        if(i >= j) break;

        // i,j位置的值交换
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    // 容易知道在j迭代的结尾，j一定是到了i的位置，此时i位置的元素值一定要比pivot小，可以与基准交换位置
    a[left] = a[j];
    a[j] = pivot;

    return j;
}

// 快速排序
void QuickSort(int a[], int left, int right){
    if(left <= right){
        int midth = partition(a,left,right);
        // 当只有一个元素时，这里的midth与left，right值是一样的，这也是为什么前面要套一个if，防止数组越界
        QuickSort(a,left,midth-1);
        QuickSort(a,midth+1,right);
    }
    else return;
}

void merge(int a[], int left, int midth, int right){
    int b[right-left+1];
    int cursor = 0;
    int i = left;
    int j = midth+1;
    while(i <= midth && j <= right){
        if(a[i] < a[j]){
            b[cursor] = a[i];
            i++;
        }
        else{
            b[cursor] = a[j];
            j++;
        }
        cursor++;
    }
    while(i<=midth){
        b[cursor] = a[i];
        i++; cursor++;
    }
    while(j<=right){
        b[cursor] = a[j];
        j++; cursor++;
    }

    for(int x = left, m = 0; x<=right; m++,x++){
        a[x] = b[m];
    }
}

// 归并排序
void MergeSort(int a[], int left,int right){
    if(left < right){
        int midth = (right+left)/2;
        // 这里将数组分成两个部分，不是乱分的，必须要把midth放到前一个，而midth+1放到下一个
        // 由于这里的递归出口是left == right
        // 而如果不是midth+1，我们永远也得不到midth == right
        MergeSort(a,left,midth);
        MergeSort(a,midth+1,right);
        merge(a,left,midth,right);
    }
    else return;
}

void swap(int a[],int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void heapify(int a[],int len, int n){
    if(n >= len) return ;
    int c1 = 2*n + 1;
    int c2 = 2*n + 2;
    int max = n;
    if(c1 < len && a[c1] > a[max]){
        max = c1;
    }
    if(c2 < len && a[c2] > a[max]){
        max = c2;
    }
    if(max != n){
        swap(a,n,max);
        heapify(a,len,max);
    }
}

void build_heap(int a[], int len){
    for(int i = (len-1)/2; i>=0; i--){
        heapify(a,len,i);
    }
}

// 堆排序
void HeapSort(int a[], int len){
    build_heap(a,len);
    for(int i = len-1; i>=0; i--){
        swap(a,0,i);
        build_heap(a,i);
        show(a,i);
    }
}

// 计数排序
void CountingSort(int a[], int len){
    int max = 0;
    for(int i = 0; i<len; i++){
        if(a[i] > max) max = a[i];
    }
    int b[max+1];
    for(int i = 0; i<max+1; i++){
        b[i] = 0;
    }
    for(int j = 0; j<len; j++){
        b[a[j]]++;
    }
    int k = 0;
    for(int i = 0; i<=max; i++){
        for(int j = b[i]; j>0; j--){
            a[k++] = i;
        }
    }
    show(a,len);
}

int main(){
    int a[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    //BubbleSort(a,15);
    //BubbleSort2(a,15);
    //SelectionSort(a,15);
    //InsertionSort(a,15);
    //ShellSort(a,15);
    //QuickSort(a,0,14);
    //MergeSort(a,0,14);
    //HeapSort(a,15);
    //show(a,15);
    CountingSort(a,15);
    return 0;
}