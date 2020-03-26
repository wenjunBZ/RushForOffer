# 算法Algorithm 复习

## 排序类

### 快速排序--快排

#### 左右指针法

```C++
int PartSort(int* array,int left,int right)
{
    int& key = array[right];
    while(left < right)
    {
        while(left < right && array[left] <= key)
        {
            ++left;
        }
        while(left < right && array[right] >= key)
        {
            --right;
        }
        swap(array[left],array[right]);
    }
    swap(array[left],key);
    return left;
}

void QuickSort(int* array,int left,int right)
{
    assert(array);
    if(left >= right)
        return;

    //当序列较短时，采用直接插入
    int index = PartSort3(array,left,right);
    QuickSort(array,left,index-1);
    QuickSort(array,index+1,right);
}

```





## 二叉树类

[二叉树的前中后和层序遍历详细图解（递归和非递归写法）](https://blog.csdn.net/Monster_ii/article/details/82115772?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)

