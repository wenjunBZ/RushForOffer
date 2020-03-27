#pragma once


#include<iostream>
#include<sstream>
#include <algorithm>
#include<stack>
#include<vector>
#include<string>
#include <map>
#include<unordered_map>
using namespace std;



struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution
{

public:

    

    bool isValid(string s)
    {
        /*
        给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

        有效字符串需满足：

        左括号必须用相同类型的右括号闭合。
        左括号必须以正确的顺序闭合。
        注意空字符串可被认为是有效字符串。

        */
        if (s.empty())
        {
            return true;
        }
        stack<char> MyStack;
        int length = s.length();
        char single;
        for (int i = 0; i < length; ++i)
        {
            single = s.at(i);
            if (single == '{' || single == '(' || single == '[')
                MyStack.push(single);
            else if (single == '}' && !MyStack.empty() && MyStack.top() == '{')
                MyStack.pop();
            else if (single == ']' && !MyStack.empty() && MyStack.top() == '[')
                MyStack.pop();
            else if (single == ')' && !MyStack.empty() && MyStack.top() == '(')
                MyStack.pop();
            else
                return false;
        }
        return MyStack.empty();


    }



    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {


        ListNode* head = new ListNode(0);
        ListNode* ret = head;
        ListNode* p = l1;
        ListNode* q = l2;
        while (p != NULL && q != NULL) {
            if (p->val < q->val) {
                head->next = p;
                p = p->next;
            }
            else {
                head->next = q;
                q = q->next;
            }
            head = head->next;
        }
        head->next = p == NULL ? q : p;
        return ret->next;

    }

    int removeDuplicates(vector<int>& nums) {

        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[i] != nums[j]) {
                ++i;

                nums[i] = nums[j];
            }
        }

        return i + 1;

    }

    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                ++i;
            }
        }

        return i;
    }

    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int sum = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {

            if (sum < 0)
                sum = nums[i];
            else
                sum += nums[i];
            result = max(result, sum);

        }
        return result;
    }

    /* 爬楼梯
    *假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
    *每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
    *注意：给定 n 是一个正整数。
    */
    int climbStairs(int n) {

        /*
            斐波那契公式


        double sqrt5 = sqrt(5);
        double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return (int)(fibn / sqrt5);
        */

        /*
        动态规划
        */
        if (n == 1)
            return 1;
        int* dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        int result = 0;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        result = dp[n];
        delete[]dp;
        return result;

    }

    /*
    给定一个二叉树，找出其最大深度。
    二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
    说明: 叶子节点是指没有子节点的节点。
    */
    int maxDepth(TreeNode* root) {
        /*
        可以采用递归
        */
        int result = maxDepthlen(root);
        return result;
        /*
        TODO： 非递归
        */
    }
    int maxDepthlen(TreeNode* node)
    {
        if (node == NULL)
            return 0;
        if (node->left == NULL && node->right == NULL)
            return 1;
        else
            return max(maxDepthlen(node->left), maxDepthlen(node->right)) + 1;
    }

    /*136. 只出现一次的数字
    给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
    */
    int singleNumber(vector<int>& nums) {

        //线性复杂度下，可以使用数组来作为哈希表，但是使用额外的空间数组

        //非额外空间实现 异或运算
        int result = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            result = result ^ nums[i];
        }
        return result;
    }

    /*121. 买卖股票的最佳时机
    给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
    如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
    注意你不能在买入股票前卖出股票。
    */
    int maxProfit(vector<int>& prices) {

        if (prices.size() <= 1)
            return 0;

        //动态规划
        //前i天的最大收益 = max{前i-1天的最大收益，第i天的价格-前i-1天中的最小价格}
        int min_Price = prices[0];
        int max_Profit = 0;


        for (int i = 1; i < prices.size(); ++i)
        {
            max_Profit = max(max_Profit, prices[i] - min_Price);
            min_Price = min(min_Price, prices[i]);

        }
        return max_Profit;
    }

    /*11. 盛最多水的容器
    给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
    在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
    找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
    说明：你不能倾斜容器，且 n 的值至少为 2。
    */
    int maxArea(vector<int>& height) {
        //动态规划(双指针法)
        //竖线i容纳最多的水=max{前i-1个容纳最多的水，前i-1个最高柱子和第i个柱子围绕形成的水}

        int max_Area = 0;
        int begin_Index = 0;
        int end_Index = height.size() - 1;

        while (begin_Index < end_Index)
        {
            max_Area = max(max_Area, min(height[begin_Index], height[end_Index]) * (end_Index - begin_Index));
            if (height[begin_Index] < height[end_Index])
                begin_Index++;
            else
                end_Index--;
        }
        return max_Area;

    }

    /*17. 电话号码的字母组合
    给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
    给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
    */
    vector<string> letterCombinations(string digits) {
        //全排列问题
        vector<string> result;
        if (digits.size() == 0) 
            return result;
        result = { "" };
        for (int i = 0; i < digits.size(); i++) {
            char now = digits[i];
            vector<string> temp;
            if (now == '7') {
                for (int j = 0; j < result.size(); j++) {
                    temp.push_back(result[j] + 'p');
                    temp.push_back(result[j] + 'q');
                    temp.push_back(result[j] + 'r');
                    temp.push_back(result[j] + 's');
                }
            }
            else if (now == '8') {
                for (int j = 0; j < result.size(); j++) {
                    temp.push_back(result[j] + 't');
                    temp.push_back(result[j] + 'u');
                    temp.push_back(result[j] + 'v');
                }
            }
            else if (now == '9') {
                for (int j = 0; j < result.size(); j++) {
                    temp.push_back(result[j] + 'w');
                    temp.push_back(result[j] + 'x');
                    temp.push_back(result[j] + 'y');
                    temp.push_back(result[j] + 'z');
                }
            }
            else {
                for (int j = 0; j < result.size(); j++) {
                    int k = (now - '2') * 3;
                    char a = 'a' + k;
                    char b = 'a' + k + 1;
                    char c = 'a' + k + 2;
                    temp.push_back(result[j] + a);
                    temp.push_back(result[j] + b);
                    temp.push_back(result[j] + c);
                }
            }
            result = temp;
        }
        return result;
    }

    /*19. 删除链表的倒数第N个节点
    给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
    示例：
    给定一个链表: 1->2->3->4->5, 和 n = 2.
    当删除了倒数第二个节点后，链表变为 1->2->3->5.
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        /*
        空间复杂度为O（n）
        map<int, ListNode*> NodeAddrees;
        ListNode* p = head;
        int i = 1;
        while (p!=nullptr)
        {
           
            NodeAddrees.insert(pair<int , ListNode*>(i, p));
            i++;
            p = p->next;
        }
       i--;
        if(i-n-1<0)
            return head->next;
        NodeAddrees[i - n]->next = NodeAddrees[i - n + 2];
        return head;
        */
        /*
        双指针
        */
        ListNode* newNode = new ListNode(NULL);
        newNode->next = head;  //添加头节点，便于操作
        ListNode *p1, *p2;
        p1=p2= newNode;
        int i = 0;
        
     
        while (p2->next)
        {
            if (i < n)
            {
                p2 = p2->next;
                i++;
            }
            else
            {
                p2 = p2->next;
                p1 = p1->next;
            }
        }
        p1->next = p1->next->next;
        return newNode->next;
    }

    /*101. 对称二叉树
    给定一个二叉树，检查它是否是镜像对称的。
    例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
        1
       / \
      2   2
     / \ / \
    3  4 4  3
    但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
        1
       / \
      2   2
       \   \
       3    3
    */
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return isS(root->left, root->right);

    }
    bool isS(TreeNode* node_left,TreeNode* node_right)
    {
        if (node_left == NULL && node_right == NULL)
            return true;
        if ((node_left == NULL && node_right) || (node_left && node_right == NULL))
            return false;
        if (node_left->val != node_right->val)
            return false;
        return isS(node_left->left, node_right->right) && isS(node_left->right, node_right->left);

    }

    /*括号生成
    给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
    例如，给出 n = 3，生成结果为：
    [
      "((()))",
      "(()())",
      "(())()",
      "()(())",
      "()()()"
    ]
    bfs+剪枝函数
    */
    vector<string> generateParenthesis(int n) {
        string str;
        vector<string> result;
        generateP(result,str,0,0,n);
        return result;
    }
    void generateP(vector<string>& result, string str, int left_count, int right_count, int n)
    {
        if (left_count > n || right_count > n || right_count > left_count)
            return;
        if (left_count == n && right_count == n)
        {
            result.push_back(str);
            return;

        }
        generateP(result, str + '(', left_count+1, right_count, n);
        generateP(result, str + ')', left_count, right_count+1, n);
        return;
    }

    /*
    206. 反转链表
    反转一个单链表。

    示例:
    输入: 1->2->3->4->5->NULL
    输出: 5->4->3->2->1->NULL
    */
    ListNode* reverseList(ListNode* head) 
    {

        ListNode* p = head;
        ListNode* pAhead;
        while (p!=NULL&&head->next!=NULL)
        {
            pAhead = head->next;
            head->next = pAhead->next;
            pAhead->next = p;
            p = pAhead;
        }
        return p;
    }
    /*42. 接雨水
    给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此
    排列的柱子，下雨之后能接多少雨水。
    //双指针法
    */
    int trap(vector<int>& height) 
    {
        int length = height.size();
        if (length <= 1)
            return 0;
        int result = 0;
        int leftIndex = 0, rightIndex = length - 1;
        int lefMax = 0;
        int rightMax = 0;
        while (leftIndex<rightIndex)
        {
            if (height[leftIndex] < height[rightIndex])
            {
                if (height[leftIndex] > lefMax)
                    lefMax = height[leftIndex];
                else
                    result += lefMax - height[leftIndex];
                leftIndex++;
            }
            else
            {
                if (height[rightIndex] > rightMax)
                    rightMax = height[rightIndex];
                else
                    result += rightMax - height[rightIndex];
                rightIndex--;
            }
        }
        return result;
    }
    /*146. LRU缓存机制
    运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

    获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
    写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

    进阶:

    你是否可以在 O(1) 时间复杂度内完成这两种操作？
    
    */
    class LRUCache 
    {
        unordered_map<int ,list<pair<int, int>>::iterator> mapLRU;
        list<pair<int ,int>>  listLRU;
        int size;
    public:
        LRUCache(int capacity) {
            size = capacity;
        }

        int get(int key) {
            if (mapLRU.find(key) == mapLRU.end())
                return -1;
            else {
                int value = mapLRU[key]->second;
                listLRU.erase(mapLRU[key]);
                listLRU.push_front(make_pair(key, value));
                mapLRU[key] = listLRU.begin();
                return value;
            }
        }

        void put(int key, int value) {
            if (mapLRU.find(key) != mapLRU.end())
                listLRU.erase(mapLRU[key]);
            else if (listLRU.size() >= size) {
                mapLRU.erase(listLRU.back().first);
                listLRU.pop_back();
            }
            listLRU.push_front(make_pair(key, value));
            mapLRU[key] = listLRU.begin();
        }

    };

    /*25. K 个一组翻转链表
    给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

    k 是一个正整数，它的值小于或等于链表的长度。

    如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
    
    */
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        int allNodes = 0;
        ListNode* p=head;
        ListNode* ppre = head;
        while (p!=NULL)
        {
            allNodes++;
            ppre = p;
            p = p->next;
        }
        if (k == 1)
        {
            //原地反转，leetcode原地反转的结果不是整体反过来
            //head = reverseList(head,ppre);
            return head;
        }
        int counts = allNodes / k;
        ListNode* tail;
        ListNode* lastTail;
        ListNode* newHead = head;
        if (counts >= 1)
        {
            for (int i = 1; i < k; i++)
                newHead = newHead->next;
        }
        lastTail = newHead;
        newHead = newHead->next;
        counts--;
        head=reverseList(head, lastTail);
        lastTail->next = newHead;
        while (counts>=1)
        {
            ListNode* q = newHead;
            for (int i = 1; i < k; i++)
                newHead = newHead->next;
            tail = newHead;
            newHead = newHead->next;
            counts--;
            lastTail->next=reverseList(q, tail);
            lastTail = tail;
            lastTail->next = newHead;

        }
        return head;
    }
    ListNode* reverseList(ListNode* head,ListNode* &tail)
    {

        ListNode* p = head;
        ListNode* pAhead;
        while (head->next != tail)
        {
            pAhead = head->next;
            head->next = pAhead->next;
            pAhead->next = p;
            p = pAhead;
        }
        pAhead = head->next;
        pAhead->next = p;
        head->next = NULL;
            
        tail = head;
        return pAhead;
    }


    /*1. 两数之和
    给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

    你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。*/
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //HashTable
        
        map<int, int> myMap;
        int length = nums.size();
        vector<int> result;
        for (int i = 0; i < length; i++)
        {
            if (myMap.count(target - nums[i]))
            {
                result.push_back(i);
                result.push_back(myMap[target - nums[i]]);
                
                return result;
            }
            else
            {
                myMap[nums[i]] = i;
            }
        }
    }

    /*3. 无重复字符的最长子串
    给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
    */
    int lengthOfLongestSubstring(string s) {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        unordered_map<char, int> hash;
        while (end < sSize)
        {
            char tmpChar = s[end];
            //仅当s[start,end) 中存在s[end]时更新start
            if (hash.find(tmpChar) != hash.end() && hash[tmpChar] >= start)
            {
                start = hash[tmpChar] + 1;
                length = end - start;
            }
            hash[tmpChar] = end;

            end++;
            length++;
            result = max(result, length);
        }
        return result;

    }
    /*2. 两数相加
    给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
    如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
    您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
    示例：

    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* headL1 = l1;
        ListNode* headL2 = l2;
        int flag = 0;//是否进位
        ListNode* newHead = new ListNode(0);
        ListNode* pNewHead = newHead;
        while (headL1 && headL2)
        {
            ListNode* newNode = new ListNode(0);
            pNewHead->next = newNode;

            int result = headL1->val + headL2->val + flag;

            flag = result / 10;
            result %= 10;

            newNode->val = result;
            pNewHead = pNewHead->next;
            headL1 = headL1->next;
            headL2 = headL2->next;

        }
        while (headL1)
        {
            ListNode* newNode = new ListNode(0);
            pNewHead->next = newNode;

            int result = headL1->val + flag;
            flag = result / 10;
            result %= 10;
            newNode->val = result;

            pNewHead = pNewHead->next;
            headL1 = headL1->next;

        }
        while (headL2)
        {
            ListNode* newNode = new ListNode(0);
            pNewHead->next = newNode;
            int result = headL2->val + flag;
            flag = result / 10;
            result %= 10;
            newNode->val = result;

            pNewHead = pNewHead->next;
            headL2 = headL2->next;

        }
        if (flag)
        {
            ListNode* newNode = new ListNode(flag);
            pNewHead->next = newNode;

        }

        return newHead->next;
    }

    /*56. 合并区间
    给出一个区间的集合，请合并所有重叠的区间。
    //先排序，后合并
    */
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int length = intervals.size();
        if (length <= 1)
            return intervals;
       
        
        vector<vector<int>> result;
       
        std::sort(intervals.begin(), intervals.end());
        int saveIndex=0, nextIndex=1;
        while (nextIndex<length)
        {
            if (intervals[nextIndex][0] > intervals[saveIndex][1])
            {
                result.push_back(intervals[saveIndex]);
                saveIndex = nextIndex;
                nextIndex++;
            }
            else if (intervals[nextIndex][0] < intervals[saveIndex][1] &&
                intervals[nextIndex][1] < intervals[saveIndex][1])
            {
                nextIndex++;
            }
            else
            {
                intervals[saveIndex][1] = intervals[nextIndex][1];
                nextIndex++;
            }

            
        }
        result.push_back(intervals[saveIndex]);
        return result;

    }

	/*33. 搜索旋转排序数组
		假设按照升序排序的数组在预先未知的某个点上进行了旋转。

		(例如，数组[0, 1, 2, 4, 5, 6, 7] 可能变为[4, 5, 6, 7, 0, 1, 2])。

		搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 - 1 。

		你可以假设数组中不存在重复的元素。

		你的算法时间复杂度必须是 O(log n) 级别。

	   示例 1:

    输入: nums = [4,5,6,7,0,1,2], target = 0
    输出: 4
    示例 2:

    输入: nums = [4,5,6,7,0,1,2], target = 3
    输出: -1

    //先找到有序分区
    */
    int search(vector<int>& nums, int target)
    {
        int resultIndex = -1;
        int length = nums.size();
        if (length == 1)
            return target == nums[0] ? 0 : -1;
        int middle = length / 2;
        int beginIndex = 0;
        int endIndex = length - 1;
        while (beginIndex < endIndex)
        {
            if (target == nums[middle])
                return middle;
             if (nums[middle] < nums[endIndex])
            {//右区间有序
                 if (nums[middle]<target && target< nums[endIndex])
                     beginIndex = middle + 1;
                 else
                     endIndex = middle - 1;
            }
            else
            {//左区间有序
                 if (nums[beginIndex]<=target && nums[middle]>target)
                     endIndex = middle - 1;
                     
                 else
                     beginIndex = middle + 1;
                     
             }
            middle = (beginIndex + endIndex) / 2;

        }
        return resultIndex;
    }
    /*322. 零钱兑换
    给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

    示例 1:

    输入: coins = [1, 2, 5], amount = 11
    输出: 3 
    解释: 11 = 5 + 5 + 1
    示例 2:

    输入: coins = [2], amount = 3
    输出: -1
    
    */
    int coinChange(vector<int>& coins, int amount)
    {
        int length = coins.size() - 1;

        sort(coins.rbegin(), coins.rend());
        //贪心+dfs
        int result = INT_MAX;
        coinchangeCore(coins, amount, 0, 0, result);

        if (result == INT_MAX)
            return -1;
        return result;


    }
    void  coinchangeCore(vector<int>& coins, int amount, int index, int counts, int& result)
    {
        if (amount == 0)
        {
            result = min(result, counts);
            return;
        }
        if (index == coins.size())
            return;
        for (int k = amount / coins[index]; k >= 0 && k + counts < result; k--)
            coinchangeCore(coins, amount - k * coins[index], index + 1, counts + k, result);
    }
    

    /*1013. 将数组分成和相等的三个部分
    给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。

    形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。

    */
    bool canThreePartsEqualSum(vector<int>& A) 
    {
        //双指针法
        int allSum = 0;
        for (auto var : A)
        {
            allSum += var;
        }
        if (allSum % 3 != 0)
            return false;
        int leftIndex = 0;
        int leftSum = 0;
        int rightIndex = A.size() - 1;
        int rightSum = 0;
        int counts=0;
        while (leftIndex + 1 < rightIndex)
        {
            if (leftSum  == allSum/3 && rightSum  == allSum/3)
                return true;
            if (leftSum != allSum / 3)
                leftSum += A[leftIndex++];
            if (rightSum != allSum / 3)
                rightSum += A[rightIndex--];

        }
        return false;
    }

    /*
    7. 整数反转
    给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
    假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

    */
    int reverse(int x)
    {
        //考虑溢出
        int result = 0;
        while (x != 0) {
            int pop = x % 10;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7))
                return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8))
                return 0;
            result = result * 10 + pop;
            x /= 10;
        }
        return result;

    }
    /*23. 合并K个排序链表
    合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

    示例:

    输入:
    [
      1->4->5,
      1->3->4,
      2->6
    ]
    输出: 1->1->2->3->4->4->5->6
    */
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        //一个一个合并，复杂度O（kN）
        ListNode* newhead(0);
        for (int i = 0; i < lists.size(); i++)
        {
            newhead = mergeTwoLists(lists[i], newhead);
        }
        ListNode* p = newhead;
        return p;
    }
    /*
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = new ListNode(0);
        ListNode* ret = head;
        ListNode* p = l1;
        ListNode* q = l2;
        while (p != NULL && q != NULL) {
            if (p->val < q->val) {
                head->next = p;
                p = p->next;
            }
            else {
                head->next = q;
                q = q->next;
            }
            head = head->next;
        }
        head->next = p == NULL ? q : p;
        return ret->next;
    }*/
    /*93. 复原IP地址
    给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

    示例:

    输入: "25525511135"
    输出: ["255.255.11.135", "255.255.111.35"]
    
    */
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        string ip;
        restoreIpAddressesCore(result, s, 0, ip);

        return result;
    }
    void restoreIpAddressesCore(vector<string>& result, string s, int n, string ip) {
        if (n == 4) {
            if (s.empty()) result.push_back(ip);
        }
        else {
            for (int k = 1; k < 4; ++k) {
                if (s.size() < k)
                    break;
                int val = stoi(s.substr(0, k));
                if (val > 255 || k != std::to_string(val).size())
                    continue; //剪枝
                restoreIpAddressesCore(result, s.substr(k), n + 1, ip + s.substr(0, k) + (n == 3 ? "" : "."));
            }
        }
        return;
    }
    /*1071. 字符串的最大公因子
    对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。

    返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。
    //gcd 辗转相除法的运用

    */
    /*
    string gcdOfStrings(string str1, string str2)
    {
        int lengthStr1 = str1.length();
        int lengthStr2 = str2.length();
        string T = str1.substr(0, _gcd(lengthStr1, lengthStr2));
        if (checkOfStrings(str1, T) && checkOfStrings(str2, T))
            return T;
        return "";

    }
    bool checkOfStrings(string str1, string  str2)
    {
        int counts = str1.length() / str2.length();
        string tmp = "";
        for (int i = 1; i <= counts; ++i)
            tmp = tmp + str2;
        return tmp == str1;
    }
    */
    /*78. 子集
    给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
    说明：解集不能包含重复的子集。
    示例:

    输入: nums = [1,2,3]
    输出:
    [
      [3],
      [1],
      [2],
      [1,2,3],
      [1,3],
      [2,3],
      [1,2],
      []
    ]
    
    */

    vector<vector<int>> subsets(vector<int>& nums) {
        //set<vector<int>> tmpResult;
        vector<vector<int>> result;
        int length = nums.size();
        vector<int> numsCopy = nums;
        vector<int> tmp;
        result.push_back(tmp);
        //tmpResult.insert(tmp);
        for (int i = 0; i < length; ++i)
        {
            int length2 = result.size();
            for (int j = 0; j < length2; ++j)
            {
                tmp = result[j];
                tmp.push_back(nums[i]);
                result.push_back(tmp);
                //tmpResult.insert(tmp);
            }

        }

        return result;
    }

    /*
        79. 单词搜索
    给定一个二维网格和一个单词，找出该单词是否存在于网格中。

    单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。   
        回溯dfs解决
    */
    bool exist(vector<vector<char>>& board, string word) {

        int row = board.size();
        int line = board[0].size();

        vector<vector<bool>> haspassed(row, vector<bool>(line, false));
        int curlen = 0;
        for (int indexRow = 0; indexRow < row; ++indexRow)
        {
            for (int indexLine = 0; indexLine < line; ++indexLine)
            {
                if (haspas(board, haspassed, indexRow, indexLine, row, line, word, curlen))
                    return true;
            }
        }
        return false;
    }
    bool haspas(const vector<vector<char>>& board, vector<vector<bool>>& haspassed,
        int indexRow, int indexLine, const int& row, const int& line, const string& str, int& curlen)
    {
        bool result = false;
        if (curlen == str.size())
            return true;
        if (indexRow >= 0 && indexRow < row && indexLine >= 0 && indexLine < line
            && board[indexRow][indexLine] == str[curlen]
            && haspassed[indexRow][indexLine] == false)
        {
            haspassed[indexRow][indexLine] = true;
            curlen++;
            result = true;

            result = haspas(board, haspassed, indexRow - 1, indexLine, row, line, str, curlen)
                || haspas(board, haspassed, indexRow + 1, indexLine, row, line, str, curlen)
                || haspas(board, haspassed, indexRow, indexLine - 1, row, line, str, curlen)
                || haspas(board, haspassed, indexRow, indexLine + 1, row, line, str, curlen);

            if (result == false)
            {
                curlen--;
                haspassed[indexRow][indexLine] = false;
            }
        }

        return result;
    }


    /*
    92. 反转链表 II
    反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

    说明:
    1 ≤ m ≤ n ≤ 链表长度。

    示例:

    输入: 1->2->3->4->5->NULL, m = 2, n = 4
    输出: 1->4->3->2->5->NULL
    
    */
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {

        ListNode* newHead = new ListNode(-1);
        newHead->next = head;

        // 第m-1个节点
        ListNode* pre = newHead;
        for (int i = 1; i < m; i++) {
            pre = pre->next;
        }
        ListNode* tmp, * cur = pre->next, * mNode = pre->next;

        for (int i = m; i <= n; i++) {
            tmp = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = tmp;
        }
        mNode->next = cur;

        return newHead->next;
    }
    /*200. 岛屿数量
    给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
    DFS,将一个1旁边的1全部变为0
    */
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };
    int numIslands(vector<vector<char>>& grid)
    {
        const int rows = grid.size();
        if (rows == 0)
            return 0;
        const int lines = grid[0].size();

        int result = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < lines; ++j)
            {
                if (grid[i][j] == '1')
                {
                    numIslandsDFS(grid, i, j, rows, lines);
                    result++;
                }
            }
        }
        return result;
    }
    void numIslandsDFS(vector<vector<char>>& grid, int row, int line, int Row, int Line)
    {
        if (grid[row][line] == '0')
            return;
        grid[row][line] = '0';
        for (int i = 0; i < 4; i++)
        {
            int x = row + dx[i];
            int y = line + dy[i];
            if (x >= 0 && x < Row && y >= 0 && y < Line)
            {
                if (grid[x][y] == '0')
                    continue;
                numIslandsDFS(grid, x, y, Row, Line);
            }
        }
        return;
    }

    /*143. 重排链表
    给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
    将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
    //可以直接做，暴力
    //也可以用栈
    */
    void reorderList(ListNode* head)
    {
        ListNode* p = head;
        if (p == nullptr)
            return;

        while (p != nullptr && p->next != nullptr)
        {
            ListNode* q = p;
            ListNode* qPre = p;
            while (q != nullptr && q->next != nullptr)
            {
                qPre = q;
                q = q->next;
            }
            qPre->next = nullptr;
            q->next = p->next;
            p->next = q;
            p = p->next->next;
        }
        return;
    }
    /*
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* p = head;
        while (p) {
            s.push(p);
            p = p->next;
        }
        if (s.size() <= 2) {
            return;
        }

        p = head;
        int size = s.size();
        for (int i = 0; i < size / 2; i++) {
            ListNode* next = p->next;
            p->next = s.top();
            s.pop();
            p->next->next = next;
            p = next;
        }
        p->next = NULL;
        return;
    }
    */

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m)  //保证数组1一定最短
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
        int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度

        while (lo <= hi)   //二分
        {
            c1 = (lo + hi) / 2;  //c1是二分的结果
            c2 = m + n - c1;

            LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
            LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

            if (LMax1 > RMin2)
                hi = c1 - 1;
            else if (LMax2 > RMin1)
                lo = c1 + 1;
            else
                break;
        }
        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
    }

    /*
    93. 复原IP地址
        给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

        示例 :

    输入: "25525511135"
    输出 : ["255.255.11.135", "255.255.111.35"]

    深度优先搜索dfs+剪纸
    */
    vector<string> restoreIpAddresses(string s) {
        string ip;
        vector<string> result;
        restoreIpAddressesCore(s, 0, ip, result);
        return result;
    }
    void restoreIpAddressesCore(string s, int n, string ip, vector<string>& result) {
        if (n == 4) {
            if (s.empty()) result.push_back(ip);
        }
        else {
            for (int k = 1; k < 4; ++k) {
                if (s.size() < k)
                    break;
                int val = stoi(s.substr(0, k));
                if (val > 255 || k != std::to_string(val).size())
                    continue; //剪枝
                restoreIpAddressesCore(
                    s.substr(k), n + 1, ip + s.substr(0, k) + (n == 3 ? "" : "."), result
                );
            }
        }
        return;
    }
    

};

