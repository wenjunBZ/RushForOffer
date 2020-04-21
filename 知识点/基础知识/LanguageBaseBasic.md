# Language Base

语言基础问题

---

#### const 和define 区别：

**C++中不但可以用define定义常量还可以用const定义常量，它们的区别如下：**

* 用#define MAX 255定义的常量是没有类型的，所给出的是一个立即数，编译器只是把所定义的常量值与所定义的常量的名字联系起来，define所定义的宏变量在预处理的时候进行替换，在程序中使用到该常量的地方都要进行拷贝替换；

* 用const float MAX = 255; 定义的常量有类型名字，存放在内存的静态区域中，在程序运行过程中const变量只有一个拷贝，而#define 所定义的宏变量却有多个拷贝，所以宏定义在程序运行过程中所消耗的内存要比const变量的大得多；

* 用define定义的常量是不可以用指针变量去指向的，用const定义的常量是可以用指针去指向该常量的地址的；

* 用define可以定义一些简单的函数，const是不可以定义函数的.

具体来说，有以下几方面的区别：

1.编译器处理方式
define – 在预处理阶段进行替换
const – 在编译时确定其值

2.类型检查
define – 无类型，不进行类型安全检查，可能会产生意想不到的错误
const – 有数据类型，编译时会进行类型检查

3.内存空间
define – 不分配内存，给出的是立即数，有多少次使用就进行多少次替换，在内存中会有多个拷贝，消耗内存大
const – 在静态存储区中分配空间，在程序运行过程中内存中只有一个拷贝

4.其他
在编译时， 编译器通常不为const常量分配存储空间，而是将它们保存在符号表中，这使得它成为一个编译期间的常量，没有了存储与读内存的操作，使得它的效率也很高。
宏替换只作替换，不做计算，不做表达式求解。

宏定义的作用范围仅限于当前文件。
默认状态下，const对象只在文件内有效，当多个文件中出现了同名的const变量时，等同于在不同文件中分别定义了独立的变量。
如果想在多个文件之间共享const对象，必须在变量定义之前添加extern关键字（在声明和定义时都要加）。

```txt
规则
在C++ 程序中只使用const常量而不使用宏常量，即const常量完全取代宏常量。
```

---

#### new 和 malloc 区别

参考：
[动态内存分配、malloc与new的区别-CSDN博客](https://blog.csdn.net/qq_40840459/article/details/81268252?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)

解释还行：能应付基础面试，但是没有涉及基础根本

[经典面试题之new和malloc的区别](https://blog.csdn.net/nie19940803/article/details/76358673?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)

---

#### C/C++程序内存的分配

参考博客可以在`视图`菜单中关闭
[C/C++程序内存的分配](https://blog.csdn.net/cherrydreamsover/article/details/81627855)

有内存分配的理解，可以更深刻理解内存分配问题

[C/C++动态内存管理malloc/new、free/delete的异同](https://blog.csdn.net/cherrydreamsover/article/details/81022039)

[浅谈“C语言动态内存管理：malloc/calloc/realloc/free”](https://blog.csdn.net/cherrydreamsover/article/details/81019360)

关于C++中自由存储区的解释，参考

[C++ 自由存储区是否等价于堆？](https://www.cnblogs.com/QG-whz/p/5060894.html)



---

#### C++ static

[c++中static的用法详解--CSDN](https://blog.csdn.net/majianfei1023/article/details/45290467?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)

#### memcpy 和memmove 区别，以及strcpy



**memcpy和menmove区别主要在于内存重叠的处理问题**

* memcpy :不判断是否重叠问题，从头开始复制

* memmove: 会判断是否有内存重叠问题。若内存重叠，则从后往前复制，避免内存重叠

[memmove 和 memcpy的区别以及处理内存重叠问题](https://blog.csdn.net/li_ning_/article/details/51418400)



**strcpy和mencpy**

* strcpy主要是字符串的拷贝
* mencpy是内存的拷贝，可以是字符串，也可以是结构体，针对的是内存

参考



[strcpy、strncpy与memcpy的区别与使用方法--CSDN](https://blog.csdn.net/taric_ma/article/details/7383713?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)



---

#### vector和数组的区别

[c++ 的vector、array和数组的比较--CSDN](https://blog.csdn.net/haust_wang/article/details/49848169?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)

[STL vector的内部实现原理及基本用法--CSDN](https://blog.csdn.net/u012658346/article/details/50725933?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)

---

#### C++堆和栈的区别

主要区别有以下几点

* 管理方式
* 系统响应
* 空间大小
* 碎片问题
* 生长方向
* 分配方式
* 分配效率

具体参考：

[C++：堆和栈的区别--博客](https://www.cnblogs.com/yiluyisha/p/9049051.html)



---

#### C++中深拷贝浅拷贝问题

简单的说：浅拷贝就是使用同一块内存，拷贝后实际上还是指向同一块内存；

深拷贝之后，每个对象都有自己的内存，而不是指向相同一块内存

[C++面试题之浅拷贝和深拷贝的区别](https://blog.csdn.net/caoshangpa/article/details/79226270)



---

#### [为什么析构函数必须是虚函数？为什么C++默认的析构函数不是虚函数](https://www.cnblogs.com/yuanch2019/p/11625460.html) 



**将可能会被继承的父类的析构函数设置为虚函数，可以保证当我们new一个子类，然后使用基类指针指向该子类对象，释放基类指针时可以释放掉子类的空间，防止内存泄漏。**

C++默认的析构函数不是虚函数是因为虚函数需要额外的虚函数表和虚表指针，占用额外的内存。而对于不会被继承的类来说，其析构函数如果是虚函数，就会浪费内存。因此C++默认的析构函数不是虚函数，而是只有当需要当作父类时，设置为虚函数。



**请你说一说你理解的虚函数和多态**
多态的实现主要分为静态多态和动态多态，***静态多态主要是重载，在编译的时候就已经确定；动态多态是用虚函数机制实现的，在运行期间动态绑定。***举个例子：一个父类类型的指针指向一个子类对象时候，使用父类的指针去调用子类中重写了的父类中的虚函数的时候，会调用子类重写过后的函数，在父类中声明为加了virtual关键字的函数，在子类中重写时候不需要加virtual也是虚函数。
虚函数的实现：在有虚函数的类中，类的最开始部分是一个虚函数表的指针，这个指针指向一个虚函数表，表中放了虚函数的地址，实际的虚函数在代码段(.text)中。当子类继承了父类的时候也会继承其虚函数表，当子类重写父类中虚函数时候，会将其继承到的虚函数表中的地址替换为重新写的函数地址。使用了虚函数，会增加访问内存开销，降低效率。



构造函数不能声明为虚函数（**虚函数只有和对象结合才能呈现多态，构造函数时对象正在生成**）。



---

#### 支配规则、赋值兼容、虚函数的区别

**支配规则**： 通过自身对象、指针、引用访问（***自身的***）虚函数、普通函数

**赋值兼容规则**：通过基类指针、对象、引用访问（***派生类中基类部分的***）的普通函数

**虚函数**：通过基类指针、引用访问（***基类和派生类的同名***）虚函数





---

#### Struct 和 Union区别

参考博客

[Struct 和 Union区别--CSDN](https://blog.csdn.net/firefly_2002/article/details/7954458)



---

#### 红黑树和AVL树的定义，特点，以及二者区别

平衡二叉树（AVL树）：

平衡二叉树又称为AVL树，是一种特殊的二叉排序树。其左右子树都是平衡二叉树，且左右子树高度之差的绝对值不超过1。一句话表述为：以树中所有结点为根的树的左右子树高度之差的绝对值不超过1。将二叉树上结点的左子树深度减去右子树深度的值称为平衡因子BF，那么平衡二叉树上的所有结点的平衡因子只可能是-1、0和1。只要二叉树上有一个结点的平衡因子的绝对值大于1，则该二叉树就是不平衡的。



红黑树：

红黑树是一种二叉查找树，但在每个节点增加一个存储位表示节点的颜色，可以是红或黑（非红即黑）。通过对任何一条从根到叶子的路径上各个节点着色的方式的限制，红黑树确保没有一条路径会比其它路径长出两倍，因此，红黑树是一种弱平衡二叉树，相对于要求严格的AVL树来说，它的旋转次数少，所以对于搜索，插入，删除操作较多的情况下，通常使用红黑树。

性质：

1. 每个节点非红即黑

2. 根节点是黑的;

3. 每个叶节点（叶节点即树尾端NULL指针或NULL节点）都是黑的;

4. 如果一个节点是红色的，则它的子节点必须是黑色的。

5. 对于任意节点而言，其到叶子点树NULL指针的每条路径都包含相同数目的黑节点;



区别：

AVL 树是高度平衡的，频繁的插入和删除，会引起频繁的rebalance，导致效率下降；红黑树不是高度平衡的，算是一种折中，插入最多两次旋转，删除最多三次旋转。





---

#### 请你说一说map和unordered_map的底层实现

map底层是基于红黑树实现的，因此map内部元素排列是有序的。而unordered_map底层则是基于哈希表实现的，因此其元素的排列顺序是杂乱无序的。

对于map，其底层是基于红黑树实现的，优点如下：

1)有序性，这是map结构最大的优点，其元素的有序性在很多应用中都会简化很多的操作

2)map的查找、删除、增加等一系列操作时间复杂度稳定，都为logn

缺点如下：

1）查找、删除、增加等操作平均时间复杂度较慢，与n相关

对于unordered_map来说，其底层是一个哈希表，优点如下：

查找、删除、添加的速度快，时间复杂度为常数级O(c)

缺点如下：

因为unordered_map内部基于哈希表，以（key,value）对的形式存储，因此空间占用率高

Unordered_map的查找、删除、添加的时间复杂度不稳定，平均为O(c)，取决于哈希函数。极端情况下可能为O(n)



---

#### vector 实现原理



---

#### 数组和链表的区别



---

#### C++内存泄漏问题

[C++造成内存泄漏的原因汇总--CSDN](https://blog.csdn.net/qq_18824491/article/details/78902636?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)



---

#### 自旋锁和互斥锁

自旋锁是一种互斥锁的实现方式而已，相比一般的互斥锁会在等待期间放弃cpu，自旋锁（spinlock）则是不断循环并测试锁的状态，这样就一直占着cpu。

**自旋锁与互斥锁的区别**：线程在申请自旋锁的时候，线程不会被挂起，而是处于忙等的状态。

[自旋锁和互斥锁的区别--简书](https://www.jianshu.com/p/a7f349ddcf82)













---





# 常见面试题目

常见C++岗位面试题目

收集



---



---

## 大数据处理类型





比如说100Gurl，内存只有1G，求topk问题

* hash+分治



---

## 计算机体系结构问题



---

#### 计算机缓存Cache以及Cache Line详解

参考

[计算机中的cacheline--CSDN](https://blog.csdn.net/qq_21125183/article/details/80590934)

高速缓存其实就是一组称之为缓存行(cache line)的固定大小的数据块，其大小是以突发读或者突发写周期的大小为基础的。

    每个高速缓存行完全是在一个突发读操作周期中进行填充或者下载的。即使处理器只存取一个字节的存储器，高速缓存控制器也启动整个存取器访问周期并请求整个数据块。缓存行第一个字节的地址总是突发周期尺寸的倍数。缓存行的起始位置总是与突发周期的开头保持一致。

当从内存中取单元到cache中时，会一次取一个cacheline大小的内存区域到cache中，然后存进相应的cacheline中。

例如：我们要取地址 (t, s, b) 内存单元，发生了cache miss，那么系统会取 (t, s, 00…000) 到 (t, s, FF…FFF)的内存单元，将其放入相应的cacheline中。









## 最近常见面试算法题





[[面试题07. 重建二叉树](https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/)]

[[面试题09. 用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)]

[[面试题10- II. 青蛙跳台阶问题](https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/)]

[[面试题12. 矩阵中的路径](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/)]

[[面试题19. 正则表达式匹配](https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/)]

[[面试题22. 链表中倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)]

[[面试题24. 反转链表](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)]

[[面试题25. 合并两个排序的链表](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/)]

[[面试题27. 二叉树的镜像](https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/)]

[[面试题35. 复杂链表的复制](https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/)]

[[面试题33. 二叉搜索树的后序遍历序列](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/)]

[[面试题40. 最小的k个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/)]

[[面试题47. 礼物的最大价值](https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/)]

[[面试题48. 最长不含重复字符的子字符串](https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/)]

[[面试题52. 两个链表的第一个公共节点](https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/)]

[[面试题54. 二叉搜索树的第k大节点](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/)]

[[面试题51. 数组中的逆序对](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)]

[[面试题63. 股票的最大利润](https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/)]

[[面试题68 - I. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/)]

[[面试题59 - I. 滑动窗口的最大值](https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/)]

[[42. 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)]

[[4. 寻找两个有序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)]

[[146. LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/)] * 必刷

[[25. K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)] * 必刷

[[215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)]

[[93. 复原IP地址](https://leetcode-cn.com/problems/restore-ip-addresses/)]

[[46. 全排列](https://leetcode-cn.com/problems/permutations/)]





