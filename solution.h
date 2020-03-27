#pragma once
#include<iostream>
#include <algorithm>
#include<stack>
#include<vector>
#include<string>
#include <map>
#include <queue>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {

public:
	//Definition for singly - linked list.
	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(NULL) {}

	};
	//Definition for a binary tree node.
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}

	};

	// Definition for a Node.
	struct Node {
	public:
		int val;
		Node* next;
		Node* random;
		Node* left;
		Node* right;

		Node(int _val) {
			val = _val;
			next = NULL;
			random = NULL;
			left = NULL;
			right = NULL;
		}
		Node(int _val, Node* _left, Node* _right, Node* _next, Node* _random) {
			val = _val;
			left = _left;
			right = _right;
			next = _next;
			random = _random;
		}
	};
	int PartSort(vector<int>& array, int left, int right)
	{
		int& key = array[right];
		while (left < right)
		{
			while (left < right && array[left] <= key)
			{
				++left;
			}
			while (left < right && array[right] >= key)
			{
				--right;
			}
			swap(array[left], array[right]);
		}
		swap(array[left], key);
		return left;
	}


	/*面试题03. 数组中重复的数字

	在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
	数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每
	个数字重复了几次。请找出数组中任意一个重复的数字。
	*/
	int findRepeatNumber(vector<int>& nums) {
		int length = nums.size();

		if (length <= 0)
			return 0;
		for (int i = 0; i < length; ++i)
		{
			if (nums[i] < 0 || nums[i] >= length)
				return false;
		}
		for (int i = 0; i < length; ++i)
		{
			while (nums[i] != i)
			{
				/* code */
				if (nums[i] == nums[nums[i]])
				{

					return nums[i];
				}

				int temp = nums[i];
				nums[i] = nums[temp];
				nums[temp] = temp;
			}

		}
		return 0;


	}

	/*面试题04. 二维数组中的查找
	 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，
	 每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的
	 一个二维数组和一个整数，判断数组中是否含有该整数。
	[
	[1,   4,  7, 11, 15],
	[2,   5,  8, 12, 19],
	[3,   6,  9, 16, 22],
	[10, 13, 14, 17, 24],
	[18, 21, 23, 26, 30]
	]
	给定 target = 5，返回 true。
	给定 target = 20，返回 false。
	极限条件：
	[]      或者 [[]]
	0             0


	*/
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

		bool result = false;
		int matrixRow = matrix.size();
		if (matrixRow == 0)
			return result;
		int matrixColum = matrix[0].size();
		if (matrixColum == 0)
			return result;
		int findRow = 0;
		int findColum = matrixColum - 1;

		while (findRow < matrixRow && findColum >= 0)
		{
			if (matrix[findRow][findColum] == target)
			{
				result = true;
				break;
			}
			if (matrix[findRow][findColum] < target)
				findRow++;
			else
				findColum--;
		}
		return result;
	}

	/*面试题05. 替换空格
	请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
	示例 1：

	输入：s = "We are happy."
	输出："We%20are%20happy."
	*/
	string replaceSpace(string s) {
		//先统计空格数量，从后面往前移动，减少移动的次数
		string result;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
				result += "%20";
			else
				result += s[i];
		}
		return result;
	}

	/*
	面试题06.从尾到头打印链表
		输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。



		示例 1：

		输入：head = [1, 3, 2]
		输出：[2, 3, 1]
	*/
	vector<int> reversePrint(ListNode* head) {
		//使用栈即可
	}
	/*面试题07. 重建二叉树
	 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
	例如，给出
	前序遍历 preorder = [3,9,20,15,7]
	中序遍历 inorder = [9,3,15,20,7]
	返回如下的二叉树：
		3
	   / \
	  9  20
		/  \
	   15   7
	*/
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		TreeNode* root = constructTree(preorder, inorder, 0, 0, inorder.size() - 1);

		return root;
	}
	TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int root, int start, int end)
	{   //root 为前序遍历中根节点的下标
		// 中序的start和end
		if (start > end) return NULL;
		TreeNode* tree = new TreeNode(preorder[root]);
		int i = start;
		while (i < end && preorder[root] != inorder[i]) i++;
		tree->left = constructTree(preorder, inorder, root + 1, start, i - 1);
		tree->right = constructTree(preorder, inorder, root + 1 + i - start, i + 1, end);
		return tree;
	}
	/*
	面试题11.旋转数组的最小数字
		把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组[3, 4, 5, 1, 2] 为[1, 2, 3, 4, 5] 的一个旋转，该数组的最小值为1。

		示例 1：

		输入：[3, 4, 5, 1, 2]
		输出：1
		示例 2：

		输入：[2, 2, 2, 0, 1]
		输出：0
	 */
	int minArray(vector<int>& numbers) {
		if (numbers.size() == 0)
		{
			return 0;
		}
		int indexLeft = 0;
		int indexRight = numbers.size() - 1;
		int indexMid = indexLeft;

		while (numbers[indexLeft] >= numbers[indexRight])
		{
			if (indexRight - indexLeft == 1)
			{
				indexMid = indexRight;
				break;
			}
			indexMid = (indexLeft + indexRight) / 2;
			if (numbers[indexLeft] == numbers[indexRight] && numbers[indexRight] == numbers[indexMid])
			{
				int result = numbers[indexLeft];
				for (int i = indexLeft + 1; i <= indexRight; i++)
				{
					if (result > numbers[i])
						result = numbers[i];
				}
				return result;
			}
			if (numbers[indexLeft] <= numbers[indexMid])
				indexLeft = indexMid;
			else
				indexRight = indexMid;
		}
		return numbers[indexMid];
	}

	/*面试题12. 矩阵中的路径
	请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
	路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
	如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的
	3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

	[["a","b","c","e"],
	["s","f","c","s"],
	["a","d","e","e"]]
	但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一
	行第二个格子之后，路径不能再次进入这个格子。

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
			/*
			//向上
			if (indexRow - 1 >= 0 && haspassed[indexRow - 1][indexLine] == false && board[indexRow - 1][indexLine] == str[curlen])
			{
				result = haspas(board, haspassed, indexRow - 1, indexLine, row, line, str, curlen);

			}
			//向下
			else if (indexRow + 1 < row && haspassed[indexRow + 1][indexLine] == false)
			{
				result = haspas(board, haspassed, indexRow + 1, indexLine, row, line, str, curlen);

			}
			//向左
			else if (indexLine - 1 >= 0 && haspassed[indexRow][indexLine - 1] == false)
			{
				result = haspas(board, haspassed, indexRow, indexLine - 1, row, line, str, curlen);

			}
			//向右
			else if (indexLine + 1 < line && haspassed[indexRow][indexLine + 1] == false)
			{
				result = haspas(board, haspassed, indexRow, indexLine + 1, row, line, str, curlen);

			}
			*/

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


	/*面试题13. 机器人的运动范围
	地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
	一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、
	上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的
	数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，
	因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
	*/
	int movingCount(int m, int n, int k) {

		vector<vector<bool>> pass(m, vector<bool>(n, false));
		int row = m;
		int line = n;
		int curlen = 0;

		int result = canVisit(0, 0, row, line, k, pass);
		return result;

	}
	int canVisit(int indexRow, int indexLine, int row, int line, int max, vector<vector<bool>>& pass)
	{
		int counting = 0;
		if (canin(indexRow, indexLine, row, line, max, pass))
		{
			pass[indexRow][indexLine] = true;
			counting = 1 + canVisit(indexRow - 1, indexLine, row, line, max, pass)
				+ canVisit(indexRow + 1, indexLine, row, line, max, pass)
				+ canVisit(indexRow, indexLine - 1, row, line, max, pass)
				+ canVisit(indexRow, indexLine + 1, row, line, max, pass);

		}
		return counting;
	}
	bool canin(int indexRow, int indexLine, int row, int line, int max, vector<vector<bool>>& pass)
	{
		if (indexRow >= 0 && indexRow < row && indexLine >= 0 && indexLine < line
			&& ((sums(indexRow) + sums(indexLine)) <= max) && pass[indexRow][indexLine] == false
			)
			return true;
		return false;
	}
	int sums(int n)
	{
		int result = 0;
		while (n > 0)
		{
			result += n % 10;
			n /= 10;
		}
		return result;
	}

	/*面试题14- I. 剪绳子
	给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
	每段绳子的长度记为 k[0],k[1]...k[m] 。请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少？
	例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

	示例 1：

	输入: 2
	输出: 1
	解释: 2 = 1 + 1, 1 × 1 = 1
	动态规划或者贪心算法
	*/
	int cuttingRope(int n) {
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		if (n == 4)
			return 4;

		int timesThree = n / 3;
		int leftThree = n % 3;
		if (leftThree == 0)
			return pow(3, timesThree);
		if (leftThree == 1)
			return pow(3, timesThree - 1) * 4;
		return pow(3, timesThree) * 2;
	}


	/*面试题15. 二进制中1的个数
	请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，
	把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。
	示例 1：
	输入：00000000000000000000000000001011
	输出：3
	解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
	*/
	int hammingWeight(uint32_t n) {
		int result;
		while (n)
		{
			++result;
			n = (n - 1) & n;
		}
	}
	/*TIPS:
	把一个整数减去 1 之后在和原来的整数做按位与运算，得到的结果相当于把二进制表示中最右边的1编程0
	很多二进制的问题可以用这种思路

	*/
	/*面试题16. 数值的整数次方
	实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。
	*/

	double myPow(double x, long n)
	{
		if (abs(x - 0.0) <= 0.000001 && n < 0)
			return 0.0;
		unsigned long absN = (unsigned long)(n);
		if (n < 0)
			absN = (unsigned long)(-n);

		double result = pows(x, absN);
		if (n < 0)
			return 1.0 / result;
		return result;
	}
	double pows(double x, unsigned long n)
	{
		if (n == 0)
			return 1;
		if (n == 1)
			return x;
		double result = pows(x, n >> 1);
		result *= result;
		if (n & 0x1 == 1)
			result *= x;
		return result;
	}
	/*面试题19. 正则表达式匹配
	请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'
	表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
	在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"
	与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
	递归有时候会超时或者栈溢出
	*/
	bool isMatch(string s, string p) {

		return isMatchCore(s, p, 0, 0);
	}
	bool isMatchCore(string s, string p, int indexS, int indexP)
	{
		if (indexP == p.size())
		{
			if (indexS == s.size())
				return true;
			return false;
		}
		if (p[indexP + 1] == '*')
		{
			if (p[indexP] == s[indexS] || (indexS != s.size() && p[indexP] == '.'))
				return isMatchCore(s, p, indexS + 1, indexP + 2) ||
				isMatchCore(s, p, indexS + 1, indexP) ||
				isMatchCore(s, p, indexS, indexP + 2);
			else
				return isMatchCore(s, p, indexS, indexP + 2);
		}
		if (s[indexS] == p[indexP] || (indexS != s.size() && p[indexP] == '.'))
			return isMatchCore(s, p, indexS + 1, indexP + 1);
		return false;

	}
	/*面试题21. 调整数组顺序使奇数位于偶数前面
	输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
	使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

	示例：
	输入：nums = [1,2,3,4]
	输出：[1,3,2,4]
	注：[3,1,2,4] 也是正确的答案之一。
	*/

	vector<int> exchange(vector<int>& nums)
	{
		int indexBegin = 0;
		int indexEnd = nums.size() - 1;
		int temp;
		while (indexBegin < indexEnd)
		{
			while (indexBegin < indexEnd && !isEvent(nums[indexBegin]))
			{
				indexBegin++;
			}
			while (indexBegin < indexEnd && isEvent(nums[indexEnd]))
			{
				indexEnd--;
			}
			if (indexBegin < indexEnd)
			{
				temp = nums[indexBegin];
				nums[indexBegin] = nums[indexEnd];
				nums[indexEnd] = temp;
			}
		}
		return nums;
	}
	bool isEvent(int n)
	{
		if ((n & 0x1) == 0)
			return true;
		return false;
	}

	/*面试题22.链表中倒数第k个节点
		输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。



		示例：

		给定一个链表 : 1->2->3->4->5, 和 k = 2.

		返回链表 4->5.
	 */
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* pAhead, * qBehind;
		pAhead = head; qBehind = head;
		for (int i = 0; i < k; i++)
			pAhead = pAhead->next;
		while (pAhead) {
			pAhead = pAhead->next;
			qBehind = qBehind->next;
		}
		return qBehind;
	}
	/*
	 TIPS:
	 当用一个指针遍历链表不能解决问题的时候，可以尝试用两个指针来遍历链表。可以让其中一个指针走快
	 一些。或者让他再链表上先走几步。快慢指针
	*/
	/*
	链表反转，非递归
	*/
	ListNode* reverseList(ListNode* head) {
		ListNode* pAhead = NULL;
		ListNode* pBehind = NULL;
		ListNode* pNode = head;
		ListNode* newHead = NULL;
		/*
		while (pNode != NULL)
		{
			pAhead = pNode->next;
			if (pAhead == NULL)
				newHead = pNode;
			pNode->next = pBehind;
			pBehind = pNode;
			pNode = pAhead;
		}
		return newHead;
		*/
		//双指针法，魔改
		pNode = head;
		while (pNode != NULL)
		{
			pAhead = head->next;
			if (head->next == NULL)
				break;
			head->next = pAhead->next;

			pAhead->next = pNode;

			pNode = pAhead;

		}
		return pNode;

	}

	/*面试题26. 树的子结构
	 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
	 B是A的子结构， 即 A中有出现和B相同的结构和节点值。
	*/

	bool isSubStructure(TreeNode* A, TreeNode* B)
	{

		bool result = false;
		if (A != NULL && B != NULL)
		{
			if (A->val == B->val)
				result = isSubStructureCore(A, B);
			else
			{
				result = isSubStructure(A->left, B) || isSubStructure(A->right, B);
			}
		}
		return result;

	}
	bool isSubStructureCore(TreeNode* A, TreeNode* B)
	{
		if (B == NULL)
			return true;
		if (A == NULL)
			return false;
		if (A->val != B->val)
			return false;
		return isSubStructureCore(A->left, B->left) && isSubStructureCore(A->right, B->right);
	}
	/*
	面试题29.顺时针打印矩阵
		输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
	 */
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{

		//判断是否为空
		if (matrix.size() == 0 || matrix[0].size() == 0) return {};
		vector<int> res;
		int top = 0;
		int bottom = matrix.size() - 1;
		int left = 0;
		int right = matrix[0].size() - 1;
		while (true) {
			for (int i = left; i <= right; i++) {
				res.push_back(matrix[top][i]);
			}
			//top下移
			top++;
			if (top > bottom) break;

			for (int i = top; i <= bottom; i++) {
				res.push_back(matrix[i][right]);
			}

			right--;
			if (right < left) break;
			for (int i = right; i >= left; i--) {
				res.push_back(matrix[bottom][i]);
			}
			bottom--;
			if (bottom < top) break;
			for (int i = bottom; i >= top; i--) {
				res.push_back(matrix[i][left]);
			}
			left++;
			if (left > right) break;
		}
		return res;
	}

	/*面试题31. 栈的压入、弹出序列
	输入两个整数序列，第一个序列表示栈的压入顺序，
	请判断第二个序列是否为该栈的弹出顺序。假设压入
	栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是
	某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应
	的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
	*/
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
	{
		int length = pushed.size();
		stack<int> myStack;
		int indexPop = 0;
		for (int indexPushed = 0; indexPushed < length; indexPushed++)
		{
			myStack.push(pushed[indexPushed]);
			while (!myStack.empty() && indexPop < length && myStack.top() == popped[indexPop])
			{
				myStack.pop();
				indexPop++;
			}
		}
		return indexPop == length;

	}


	/*面试题32 - I. 从上到下打印二叉树
	从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
	*/
	vector<int> levelOrder(TreeNode* root)
	{
		vector<int> result;
		if (root == NULL)
			return result;
		queue<TreeNode*> myQueue;

		myQueue.push(root);
		TreeNode* node;
		while (!myQueue.empty())
		{
			node = myQueue.front();
			myQueue.pop();
			result.push_back(node->val);
			if (node->left)
				myQueue.push(node->left);
			if (node->right)
				myQueue.push(node->right);

		}
		return result;

	}
	/*面试题33. 二叉搜索树的后序遍历序列
	输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
	如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
	参考以下这颗二叉搜索树：

		 5
		/ \
	   2   6
	  / \
	 1   3
	 输入: [1,6,3,2,5]
	输出: false
	*/
	bool verifyPostorder(vector<int>& postorder) {
		int length = postorder.size();
		if (length == 0)
			return true;

		return verifyPostorderCore(postorder, 0, length - 1);

	}
	bool verifyPostorderCore(vector<int>& postorder, int leftlen, int length)
	{
		if (leftlen >= length)
			return true;
		int root = postorder[length];

		//搜索左子树
		int i = leftlen;
		for (; i < length; ++i)
		{
			if (postorder[i] > root)
				break;
		}
		int j = i;
		for (; j < length; ++j)
		{
			if (postorder[j] < root)
				return false;
		}
		bool leftPos = true;
		if (i > leftlen)
			leftPos = verifyPostorderCore(postorder, leftlen, i - 1);
		bool righyPos = true;
		if (i < length)
			righyPos = verifyPostorderCore(postorder, i, length - 1);

		return (leftPos && righyPos);
	}

	/*面试题34. 二叉树中和为某一值的路径
	输入一棵二叉树和一个整数，打印出二叉树中节点值的和
	为输入整数的所有路径。从树的根节点开始往下一直到叶
	节点所经过的节点形成一条路径。

	*/

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> path;
		vector<vector<int>> result;
		findPath(root, sum, path, result);
		return result;
	}

	void findPath(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& result)
	{
		if (root == NULL) return;
		path.push_back(root->val);
		sum -= root->val;
		if (root->right == NULL && root->left == NULL)
		{
			if (sum == 0)
			{
				result.push_back(path);
			}
			path.pop_back();
			return;
		}
		findPath(root->left, sum, path, result);
		findPath(root->right, sum, path, result);
		sum += root->val;
		path.pop_back();
	}

	/*面试题35. 复杂链表的复制
	请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，
	每个节点除了有一个 next 指针指向下一个节点，还有一个 random
	指针指向链表中的任意节点或者 null。

	*/
	Node* copyRandomList(Node* head) {
		//Step1 copy all
		cloneAll(head);
		//step2 connect 
		connectNode(head);
		Node* newHead;
		//step reconnect 
		//newHead = reconnectNode(head);
		//return newHead;
		return reconnectNode(head);
	}
	void cloneAll(Node* head)
	{
		Node* p = head;
		while (p != nullptr)
		{
			Node* newNode = new Node(0);
			newNode->val = p->val;
			newNode->next = p->next;
			newNode->random = nullptr;
			p->next = newNode;
			p = p->next->next;
		}
	}
	void connectNode(Node* head)
	{
		Node* p = head;
		while (p != nullptr)
		{
			if (p->random != nullptr)
				p->next->random = p->random->next;
			p = p->next->next;
		}
	}
	Node* reconnectNode(Node* head)
	{
		Node* p = head;
		Node* newHead = nullptr;
		Node* newHeadNode = nullptr;

		if (p != nullptr)
		{
			newHead = newHeadNode = p->next;
			p->next = newHeadNode->next;
			p = p->next;
		}
		while (p != nullptr)
		{
			newHeadNode->next = p->next;
			newHeadNode = newHeadNode->next;
			p->next = newHeadNode->next;
			p = p->next;
		}
		return newHead;
	}
	/*面试题36. 二叉搜索树与双向链表
		输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
		要求不能创建任何新的节点，只能调整树中节点指针的指向。

	*/

	Node* treeToDoublyList(Node* root) {
		if (!root) return nullptr;
		Node* head = nullptr, * pre = nullptr;
		convertNode(root, head, pre);
		head->left = pre;
		pre->right = head;
		return head;
	}
	void convertNode(Node* root, Node*& head, Node*& pre) {
		if (!root)  return;
		convertNode(root->left, head, pre);
		if (!head) {
			head = root;   // 找到head
			pre = root;    // 对pre进行初始化
		}
		else {
			pre->right = root;
			root->left = pre;
			pre = root;
		}
		convertNode(root->right, head, pre);
		unordered_set<int> uniq;
		uniq.count(1);
	}
	/* 参考《剑指offer》
	Node* treeToDoublyList(Node* root) {
		if(root == nullptr) return root;
		Node * pLastNode = nullptr;  // 指向已经转换为链表的最后一个节点
		treeToDoublyListCore(root, &pLastNode);
		Node * pHeadNode = pLastNode;  // 指向链表的头节点
		while(pHeadNode != nullptr && pHeadNode->left != nullptr)
			pHeadNode = pHeadNode->left;
		pLastNode->right = pHeadNode;
		pHeadNode->left = pLastNode;
		return pHeadNode;
	}
	void treeToDoublyListCore(Node* curr, Node** pLastNode)
	{
		if(curr == nullptr) return;

		if(curr->left != nullptr)
			treeToDoublyListCore(curr->left,pLastNode);

		// 当前节点的left指向pLastNode(已经排序链表的最后一个节点)
		curr->left = *pLastNode;
		if(*pLastNode != nullptr)
			(*pLastNode)->right = curr;
		*pLastNode = curr; // 更新指向链表最后一个节点的指针

		if(curr->right != nullptr)
			treeToDoublyListCore(curr->right,pLastNode);
	}
	*/
	/*面试题38. 字符串的排列
	输入一个字符串，打印出该字符串中字符的所有排列。
	你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
	示例:

	输入：s = "abc"
	输出：["abc","acb","bac","bca","cab","cba"]
	*/
	vector<string> permutation(string s) {
		vector<string> result = { "" };
		if (s.size() == 0)
			return result;
		permutationCore(s, &s[0], result);
		return result;
	}
	void permutationCore(string& s, char* p, vector<string>& result)
	{
		if (*p == '\0')
			result.push_back(s);
		else
		{
			unordered_set<char> uniq;
			for (char* pch = p; *pch != '\0'; pch++)
			{
				if (uniq.count(*pch))
					continue;
				char temp;
				temp = *p;
				*p = *pch;
				*pch = temp;
				uniq.insert(*pch);
				permutationCore(s, p + 1, result);
				//回溯
				temp = *p;
				*p = *pch;
				*pch = temp;
			}
		}
	}

	/*面试题39. 数组中出现次数超过一半的数字
	数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

	你可以假设数组是非空的，并且给定的数组总是存在多数元素。*/
	int majorityElement(vector<int>& nums)
	{
		/*使用hashmap*/
		/*
		map<int, int> myMap;
		int length = nums.size();
		for (int i = 0; i < length; ++i)
		{
			myMap[nums[i]]++;
			if (myMap[nums[i]] > length / 2)
				return nums[i];
		}
		return 0;
		*/

		/*投票法*/
		int length = nums.size();
		if (length <= 0)
			return 0;
		int result = nums[0];
		int count = 1;
		for (int i = 1; i < length; ++i)
		{
			if (nums[i] == result)
				count++;
			else
				count--;
			if (count <= 0)
			{
				count = 0;
				result = nums[i + 1];
			}
		}
		return result;
	}
	/*面试题40. 最小的k个数
	输入整数数组 arr ，找出其中最小的 k 个数。例如，
	输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。*/
	vector<int> getLeastNumbers(vector<int>& arr, int k)
	{
		/*利用快排*/
		/*
		vector<int> result;
		int length = arr.size();
		if (length == 0 || k <= 0)
			return result;
		int start = 0;
		int end = length - 1;
		int index = PartSort(arr, start, end);
		while (index!=k-1)
		{
			if (index < k - 1)
			{
				end = index - 1;
				index = PartSort(arr, start, end);
			}
			else
			{
				start = index + 1;
				index = PartSort(arr, start, end);
			}
		}
		for (int i = 0; i < k; ++i)
			result.push_back(arr[i]);

		return result;
		*/

		/*时间复杂度位O（n*logK）的算法*/
		multiset<int, greater<int>> kSet;

		multiset<int, greater<int>>::iterator kSetIterator;
		vector<int> result;
		int length = arr.size();
		if (length == 0 || k <= 0)
			return result;
		for (int i = 0; i < length; ++i)
		{
			if (kSet.size() < k)
			{
				kSet.insert(arr[i]);
			}
			else
			{
				kSetIterator = kSet.begin();
				if (arr[i] < *(kSet.begin()))
				{
					kSet.erase(kSetIterator);
					kSet.insert(arr[i]);
				}
			}
		}
		for (auto number : kSet)
		{
			result.push_back(number);
		}
		return result;



	}
	/*面试题42. 连续子数组的最大和
	输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

	要求时间复杂度为O(n)。
	*/
	int maxSubArray(vector<int>& nums)
	{
		//类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
		int result = INT_MIN;
		int length = nums.size();
		//dp[i]表示nums中以nums[i]结尾的最大子序和
		vector<int> dp(length);
		dp[0] = nums[0];
		result = dp[0];
		for (int i = 1; i < length; i++)
		{
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			result = max(result, dp[i]);
		}

		return result;
	}

	/*面试题43. 1～n整数中1出现的次数
		输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

		例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。
	  可以暴力
	  也可以找规律
	*/

	int countDigitOne(int n)
	{
		if (n <= 0)
			return 0;
		char strN[40];
		sprintf_s(strN, "%d", n);
		int result = 0;
		result = countDigitOneCore(strN);
		return result;
	}

	int countDigitOneCore(const char* strN)
	{
		if (strN == NULL || *strN < '0' || *strN>'9' || *strN == '\0')
			return 0;
		int firstNumber = *strN - '0';

		int strNlen = strlen(strN);
		if (strNlen == 1 && firstNumber == 0)
			return 0;
		if (strNlen == 1 && firstNumber >= 1)
			return 1;

		//假设为21345
		//numFirstDigit 是数字100000-19999 的第一位中的数目
		int numFirstDigit = 0;
		if (firstNumber > 1)
			numFirstDigit = pow(10, strNlen - 1);
		else if (firstNumber == 1)
			numFirstDigit = atoi(strN + 1) + 1;

		//numOtherDigit是1346-21345 除第一位之外的数位中的数目
		int numOhterDigit = firstNumber * (strNlen - 1) * pow(10, strNlen - 2);

		//numRecursive 是1-1345中的数目
		int numRecursice = countDigitOneCore(strN + 1);
		return numFirstDigit + numOhterDigit + numRecursice;
	}

	/*面试题44. 数字序列中某一位的数字
	数字以0123456789101112131415…的格式序列化到一个字符序列中。
	在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

	请写一个函数，求任意第n位对应的数字。
	找规律问题1
	*/

	int findNthDigit(int n)
	{
		if (n <= 0)
			return 0;
		//digit表示当前的位数
		int digits = 1;
		while (true)
		{
			//numbers表示位数为ditgit的数字，序列化所占的位数
			int numbers = countDigit(digits);
			if (n < numbers * digits)
			{

			}
			n -= digits * numbers;
			digits++;

		}
		return -1;
	}
	int findNthDigit(int n, int digits)
	{
		int number = beginNumber(digits) + n / digits;
		int indexFromRight = digits - n % digits;
		for (int i = 1; i < indexFromRight; i++)
		{
			number /= 10;
		}
		return number % 10;

	}
	int countDigit(int digits)
	{
		if (digits == 1)
			return 10;
		int count = pow(10, digits - 1);

		return 9 * count;
	}
	int beginNumber(int digits)
	{
		if (digits == 1)
			return 0;
		return pow(10, digits - 1);
	}
	/*面试题45. 把数组排成最小的数
	输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
	打印能拼接出的所有数字中最小的一个。

	*/
	string minNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), [](int a, int b) {
			string astr = to_string(a);
			string bstr = to_string(b);
			return (astr + bstr).compare(bstr + astr) < 0;
			});

		string ans;
		int size = nums.size();
		for (int i = 0; i < size; ++i) {
			ans += to_string(nums[i]);
		}

		return ans;
	}
	/*面试题46. 把数字翻译成字符串
	 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，
	 1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
	 一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有
	 多少种不同的翻译方法。


	*/
	int translateNum(int num)
	{
		/*
		 从后往前数
		*/

		if (num < 0)
			return 0;
		string numString = to_string(num);

		int numStringLen = numString.length();

		vector<int> dp(numStringLen);
		int count = 0;
		for (int i = numStringLen - 1; i >= 0; --i)
		{
			count = 0;
			if (i < numStringLen - 1)
				count = dp[i + 1];
			else
				count = 1;
			if (i < numStringLen - 1)
			{
				int dig1 = numString[i] - '0';
				int dig2 = numString[i + 1] - '0';
				int convertNum = dig1 * 10 + dig2;
				if (convertNum >= 10 && convertNum <= 25)
				{
					if (i < numStringLen - 2)
						count += dp[i + 2];
					else
						count += 1;
				}
			}
			dp[i] = count;
		}
		int result = dp[0];
		return result;
	}

	/*面试题47.礼物的最大价值
	   在一个 m* n 的棋盘的每一格都放有一个礼物，每个礼物都
	   有一定的价值（价值大于 0）。你可以从棋盘的左上角开始
	   拿格子里的礼物，并每次向右或者向下移动一格、直到到达
	   棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计
	   算你最多能拿到多少价值的礼物？
	   //动态规划
    */
	int maxValue(vector<vector<int>>& grid) 
	{
		//优化空间，使用一维数组。
		if (!grid.size() || !grid[0].size()) {
			return 0;
		}
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < m; i++) 
		{
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		}
		for (int j = 1; j < n; j++) 
		{
			dp[0][j] = dp[0][j - 1] + grid[0][j];
		}
		for (int i = 1; i < m; i++) 
		{
			for (int j = 1; j < n; j++) 
			{
				dp[i][j] = max(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
			}
		}
		int result = dp[m - 1][n - 1];  
		return result;
	}

	/*面试题48. 最长不含重复字符的子字符串
	请从字符串中找出一个最长的不包含重复字符的子字符串，
	计算该最长子字符串的长度。
	//滑动窗口
	*/
	/*
	TIPS：滑动窗口
	 设立左指针a和右指针b，
	 右指针向右伸缩
	 {
		对每个A[b]判断是否在之前的数组出现过
			如果出现，指针a指向出现过的位置的下一个位置；
		更新右指针和最大长度
	*/
	int lengthOfLongestSubstring(string s) 
	{
		int sLen = s.length();
		if (sLen <= 0)
			return 0;
		map<char, int> myMap;
		int start = 0;
		int end = 0;
		int result = 0;
		int length = 0;
		while(end<sLen)
		{
			if (myMap.count(s[end]))
			{
				start = max(myMap[s[end]],start);
				length = end - start;
			}
			
			myMap[s[end]]=end+1;
			end++;
			length++;
			result = max(result, length);
			
		}
		return result;
	}
	/*面试题49. 丑数
		我们把只包含因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
	*/
	int nthUglyNumber(int n) {
		int pre_2 = 0, pre_3 = 0, pre_5 = 0;
		int result = 1;
		vector<int> uglyNums(n, 0);
		uglyNums[0] = 1;
		for (int i = 1; i < n; i++) {
			int next_2 = uglyNums[pre_2] * 2;
			int next_3 = uglyNums[pre_3] * 3;
			int next_5 = uglyNums[pre_5] * 5;
			if (next_2 <= next_3 && next_2 <= next_5) 
			{
				pre_2++;
				result = next_2;
			}
			if (next_3 <= next_2 && next_3 <= next_5) {
				pre_3++;
				result = next_3;
			}
			if (next_5 <= next_2 && next_5 <= next_3) {
				pre_5++;
				result = next_5;
			}
			uglyNums[i] = result;
			
		}
		return result;
	}
	/*面试题50. 第一个只出现一次的字符
	在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。
	s = "abaccdeff"
	返回 "b"

	s = "" 
	返回 " "
	*/
	char firstUniqChar(string s) 
	{
		char result = ' ';
		if (s.length() == 0)
			return result;

		map<char, int> myMap;
		for (int i = 0; i < s.length(); ++i)
		{
			if (myMap.count(s[i]))
				myMap[s[i]]++;
			else
			{
				myMap[s[i]] = 1;
			}
		}
		for (int i = 0; i < s.length(); ++i)
		{
			if (myMap[s[i]] == 1)
			{
				result = s[i];
				return result;
			}
		}
		return result;
	}
	/*TIPS：
	 如果需要判断多个字符是不是再某个字符串里出现过多次或者统计多个字符在某个字符串中出现的次数，
	 那么可以考虑基于数组创建一个简单的哈希表，这样可以用很小的空间消耗换来时间效率的提升
	*/

	/*面试题51. 数组中的逆序对
	 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，
	 求出这个数组中的逆序对的总数。
	 示例 1:
	输入: [7,5,6,4]
	输出: 5
	*/
	int reversePairs(vector<int>& nums) 
	{
		//归并排序过程统计
		int length = nums.size();
		int result = 0;
		if (length <= 0)
			return 0;
		vector<int> copys(nums);
		result = reversePairsCore(nums, copys, 0, length - 1);
		return result;
		
	}
	int reversePairsCore(vector<int>& nums, vector<int>& copys, int start, int end)
	{
		if (start == end)
		{
			copys[end] = nums[start];
			return 0;
		}
		int mid = (end-start) / 2;
		//注意此处参数顺序
		int leftCount = reversePairsCore(copys, nums, start, start+mid);
		int rightCount= reversePairsCore(copys, nums, start+mid+1, end);

		int i = start+mid;
		int j = end;
		int indexCopys = end;
		int countResult = 0;
		while (i>=start&&j>=start+mid+1)
		{
			if (nums[i] > nums[j])
			{
				copys[indexCopys--] = nums[i--];
				countResult += j - start - mid;
			}
			else
				copys[indexCopys--] = nums[j--];
		}

		while (i>=start)
		{
			copys[indexCopys--] = nums[i--];
		}
		while (j>=start+mid+1)
		{
			copys[indexCopys--] = nums[j--];
		}
		return leftCount + rightCount + countResult;
	}

	/*面试题52. 两个链表的第一个公共节点
	输入两个链表，找出它们的第一个公共节点。
	*/
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
	{
		if (headA == NULL || headB == NULL)
			return NULL;
		//本人想法是利用map存储一支链表，但是会使用O（m，n）的空间

		//更简洁的方法
		int lenHeadA = listNodeLength(headA);
		int lenHeadB = listNodeLength(headB);
		
		ListNode* longerList;
		ListNode* shorterList;
		int more = 0;
		if (lenHeadA > lenHeadB)
		{
			more = lenHeadA - lenHeadB;
			longerList = headA;
			shorterList = headB;
		}
		else
		{
			more = lenHeadB - lenHeadA;
			longerList = headB;
			shorterList = headA;
		}
		while (more>0)
		{
			longerList = longerList->next;
			more--;
		}
		while (longerList!=NULL&&shorterList!=NULL&&longerList!=shorterList)
		{
			longerList = longerList->next;
			shorterList = shorterList->next;
		}
		ListNode* result = longerList;
		return result;
	}
	int listNodeLength(ListNode* head)
	{
		ListNode* p = head;
		int len = 0;
		while (p!=NULL)
		{
			len++;
			p = p->next;
		}
		return len;
	}

	/*面试题53 - I. 在排序数组中查找数字 I
	统计一个数字在排序数组中出现的次数。
	*/
	int search(vector<int>& nums, int target) 
	{
		int length = nums.size();
		if (length == 0)
			return 0;
		int result = searchCore(nums, target, 0, length - 1);
		return result;
	}
	int searchCore(const vector<int>& nums, int target, int start, int end)
	{
		if (start == end)
		{
			if (target == nums[start])
				return 1;
			else
				return 0;
		}
		int mid = (start + end) / 2;
		return searchCore(nums, target, start, mid) + searchCore(nums, target, mid + 1, end);
	}
	
	/*面试题53 - II. 0～n-1中缺失的数字
	一个长度为n-1的递增排序数组中的所有数字都是唯一的，.
	并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数
	字中有且只有一个数字不在该数组中，请找出这个数字。
	
	*/
	int missingNumber(vector<int>& nums)
	{
	int low = 0;
	int high = nums.size() - 1;
	while (low < high) {
		int mid = low + ((high - low) >> 1);
		if (nums[mid] != mid) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return nums[low] == low ? nums[low] + 1 : nums[low] - 1;
	}

	/*面试题54. 二叉搜索树的第k大节点
	给定一棵二叉搜索树，请找出其中第k大的节点。
	*/
	int kthLargest(TreeNode* root, int k) 
	{
		//中序遍历即可
		vector<int> datas;
		kthLargestCore(root, datas);
		int result = datas[datas.size()-k];
		return result;
	}
	void kthLargestCore(TreeNode *node, vector<int>& datas)
	{
		if (node == NULL)
			return;
		kthLargestCore(node->left, datas);
		datas.push_back(node->val);
		kthLargestCore(node->right, datas);
	}
	/*面试题55 - I. 二叉树的深度
	输入一棵二叉树的根节点，求该树的深度。
	从根节点到叶节点依次经过的节点（含根、叶节点）
	形成树的一条路径，最长路径的长度为树的深度。

	*/
	int maxDepth(TreeNode* root) 
	{
		//树的dfs
		int result = 0;
		result=maxDepthCore(root);
		return result;
	}
	int maxDepthCore(TreeNode* node)
	{
		if (node == NULL)
			return 0;

		return 1 + max(maxDepthCore(node->left), maxDepthCore(node->right));
	}

	/*面试题55 - II. 平衡二叉树
	输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
	如果某二叉树中任意节点的左右子树的深度相差不超过1，
	那么它就是一棵平衡二叉树。
	
	*/
	bool isBalanced(TreeNode* root) 
	{
		int depth = 0;
		return isBalancedCore(root, depth);
	}
	bool isBalancedCore(TreeNode* node, int& depth)
	{
		if (node == NULL)
		{
			depth = 0;
			return true;
		}
		int leftdepth = 0;
		int rightdepth = 0;
		if(isBalancedCore(node->left,leftdepth)&&isBalancedCore(node->right,rightdepth))
		{
			int difference=leftdepth-rightdepth;
			if (abs(difference) <= 1)
			{
				depth = 1 + max(leftdepth, rightdepth);
				return true;
			}
		}
		return false;
	}

	/*面试题56 - I.数组中数字出现的次数
	一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
	请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，
	空间复杂度是O(1)。
	*/
	//本题采用异或大法
	vector<int> singleNumbers(vector<int>& nums) 
	{
		int num1 = 0, num2 = 0;
		vector<int> result;
		int number = 0;
		int length = nums.size();
		for (int i = 0; i < length; ++i)
		{
			number ^= nums[i];
		}
		int indexOf1 = number & (-number);//找到第一个1出现的位置
		for (int i = 0; i < length; ++i)
		{
			if ((nums[i] & indexOf1) == indexOf1)
				num1 ^= nums[i];
			else
				num2 ^= nums[i];
		}
		result.push_back(num1);
		result.push_back(num2);
		return result;
	}
	/*面试题56 - II. 数组中数字出现的次数 II	
	在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。
	请找出那个只出现一次的数字。
	 //Hashtable 即可
	*/
	
	/*面试题57. 和为s的两个数字
	输入一个递增排序的数组和一个数字s，在数组中查找两个数，
	使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
	*/
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		/*
		//HashTable
		map<int,int>myMap;
		hashmap<int, int> re;
		int length = nums.size();
		vector<int> result;
		for (int i = 0; i < length; i++)
		{
			if (myMap.count(target - nums[i]))
			{
				result.push_back(nums[i]);
				result.push_back(target - nums[i]);
				return result;
			}
			else
			{
				myMap[nums[i]] = target - nums[i];
			}
		}
		*/
		int length = nums.size();
		vector<int> result;
		int num1 = 0;
		int num2 = length - 1;
		while (num2>num1)
		{
			int sum = nums[num1] + nums[num2];
			if (sum == target)
			{
				result.push_back(nums[num1]);
				result.push_back(nums[num2]); 
					return result;
			}
			else if (sum < target)
				num1++;
			else
				num2--;
			
		}
		return result;
	}

	/*面试题57 - II. 和为s的连续正数序列
	输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
	序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
	输入：target = 9
	输出：[[2,3,4],[4,5]]
	示例 2：
	输入：target = 15
	输出：[[1,2,3,4,5],[4,5,6],[7,8]]
	*/
	vector<vector<int>> findContinuousSequence(int target) 
	{
		int startIndex = 0;
		int endIndex = 1;

		int sum = 0;
		int middle = (1 + target) / 2;
		vector<vector<int>> result;
		while (startIndex < middle)
		{

			
			sum += endIndex;
			endIndex++;
			
			if (sum == target)
			{
				vector<int> tmp;
				for (int i = startIndex + 1; i < endIndex; i++)
				{
					tmp.push_back(i);
				}
				result.push_back(tmp);
			}
			while(sum > target&& startIndex < middle)
			{
				startIndex++;
				sum -= startIndex;
				if (sum == target)
				{
					vector<int> tmp;
					for (int i = startIndex + 1; i < endIndex; i++)
					{
						tmp.push_back(i);
					}
					result.push_back(tmp);
				}
			}
		}
		return result;
	}

	/*面试题58 - I. 翻转单词顺序
	输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，
	标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

	*/
	string reverseWords(string s) 
	{
		/*
		if (s.empty())return s;
		int len = 0;
		string result = "";
		for (int m = s.size() - 1; m >= 0; m--)
		{
			if (s[m] == ' ' && len != 0)
			{
				result += s.substr(m + 1, len) + " "; 
				len = 0; 
				continue;
			}
			if (s[m] != ' ')len++;
		}
		if (len != 0) result += s.substr(0, len);
		
		return result;
		*/
		
		//我的思路，用栈
		stack<string> words;
		string word = "";
		string result = "";
		for (int i = 0; i < s.size(); i++)
		{
			word = "";
			while (i < s.size() && s[i] != ' ')
			{
				word += s[i];
				i++;
			}
			if (word.size() > 0)
			{
				words.push(word);
			}
		}
		while (!words.empty())
		{
			result += words.top();
			result += " ";
			words.pop();
		}
		//删除最后一个空格
		result.erase(result.end() - 1);
		return result;
		

		

	}
	/*
	面试题58 - II. 左旋转字符串
	字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
	请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"
	和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
	*/
	string reverseLeftWords(string s, int n) 
	{
		
		return s.substr(n, s.length() - 1) + s.substr(0, n);
		//也可以用栈
		
	}

	/*面试题59 - I. 滑动窗口的最大值
	给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
	
	*/
	vector<int> maxSlidingWindow(vector<int>& nums, int k) 
	{

		vector<int> maxWindows;
		if (nums.size() >= k && k >= 1)
		{
			deque<int> index;
			//初始化
			for (int i = 0; i < k; i++)
			{
				while (!index.empty()&&nums[i]>=nums[index.back()])
				{
					index.pop_back();
				}
				index.push_back(i);
			}
			for (int i = k; i < nums.size(); i++)
			{
				maxWindows.push_back(nums[index.front()]);
				while (!index.empty() && nums[i] >= nums[index.back()])
				{
					index.pop_back();
				}
				if (!index.empty() && index.front() <= (int)(i - k))
					index.pop_front();
			}
			maxWindows.push_back(nums[index.front()]);

		}
		return maxWindows;

	}


	/*面试题59 - II. 队列的最大值
	请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的时间复杂度都是O(1)。

	若队列为空，pop_front 和 max_value 需要返回 -1
	
	*/
	class MaxQueue {
		queue<int> q;
		deque<int> d;
	public:
		MaxQueue() {
		}

		int max_value() {
			if (d.empty())
				return -1;
			return d.front();
		}

		void push_back(int value) {
			while (!d.empty() && d.back() < value) {
				d.pop_back();
			}
			d.push_back(value);
			q.push(value);
		}

		int pop_front() {
			if (q.empty())
				return -1;
			int ans = q.front();
			if (ans == d.front()) {
				d.pop_front();
			}
			q.pop();
			return ans;
		}
	};

	
	/*面试题60. n个骰子的点数
	把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
	你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。
	 //动态规划
	 dp[i][j]表示当n=i时，和为j出现的排列情况总数；
	状态转移方程：dp[i][j]=dp[i-1][j-1]+dp[i-1][j-2]+dp[i-1][j-3]+dp[i-1][j-4]+dp[i-1][j-5]+dp[i-1][j-6];
	初始条件：dp[1][1]=dp[1][2]=dp[1][3]=dp[1][4]=dp[1][5]=dp[1][6]=1;

	*/
	
	vector<double> twoSum(int n) 
	{
		//假设有6个数字
		int maxnum = 6;
		vector<vector<int>> dp(n + 1, vector<int>(maxnum * n + 1, 0));
		double num = pow(maxnum, n);
		vector<double> result((maxnum-1) * n + 1, 1 / (double)maxnum);
		//初始状态
		
		for (int i = 1; i <= maxnum; i++)
			dp[1][i] = 1;
		for (int i = 2; i <= n; i++) 
		{      //从2到n计算dp
			for (int j = i; j <= i * maxnum; j++) 
			{  //表示当n=i时候的点数和取值从i到6i
				for (int k = 1; k <= maxnum; k++) 
				{  //dp[i][j]=dp[i-1][j-1]+dp[i-1][j-2]+dp[i-1][j-3]+dp[i-1][j-4]+dp[i-1][j-5]+dp[i-1][j-6];
					if (j - k > 0)
						dp[i][j] += dp[i - 1][j - k]; //第i个骰子点数一定比i-1个骰子点数大
					if (i == n)
						result[j - i] = (dp[i][j]*1.0)/ num;
				}
			}
		}
		return result;

	}

	/*
	面试题61. 扑克牌中的顺子
	从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
	2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以
	看成任意数字。A 不能视为 14。	

	输入: [1,2,3,4,5]
	输出: True
	示例 2:
	输入: [0,0,1,2,5]
	输出: True
	*/
	bool isStraight(vector<int>& nums) 
	{
		/*
		先排序，后统计0的个数，最后看0的个数和空缺数字的个数是否相等
		*/
		
			sort(nums.begin(), nums.end());
			int numberOfZero = 0;
			for (int i = 0; i < nums.size() && nums[i] == 0; ++i)
				numberOfZero++;
			int second = numberOfZero;
			int first = second + 1;
			int del = 0;
			while (first < nums.size())
			{
				if (nums[first] == nums[second])
					return false;
				del += nums[first] - nums[second] - 1;
				second = first;
				first++;
			}
			return  del > numberOfZero ? false : true;

	}


	
	/*
	面试题62. 圆圈中最后剩下的数字
	0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。

	例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
	*/
	int lastRemaining(int n, int m) 
	{
		//约瑟夫环问题
		//方法一：一个个遍历
		//方法二：做运算
		int last;
		for (int i = 2; i <= n; i++)
			last = (last + m) % i;
		return last;

	}
	/*面试题63. 股票的最大利润
	假设把某股票的价格按照时间先后顺序存储在数组中，
	请问买卖该股票一次可能获得的最大利润是多少？
	
	*/
	int maxProfit(vector<int>& prices) 
	{
		//动态规划
		int length = prices.size();
		int minIn = prices[0];
		int maxProfitResult = 0;
		for (int i = 1; i < length; i++)
		{
			
			maxProfitResult = max(maxProfitResult, prices[i] - minIn);
			minIn = min(minIn, prices[i]);
		}
		return maxProfitResult;
	}
	/*面试题64. 求1+2+…+n
	求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
	
	*/
	int sumNums(int n) {
		n && (n += sumNums(n - 1));
		return n;
	}
	/*面试题65. 不用加减乘除做加法
	写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
	//考虑位运算
	*/
	int add(int a, int b) {
		while (b != 0) {
			int plus = a ^ b;   // 求没有进位的和
			b = (unsigned int)(a & b) << 1;   // 求进位
			a = plus;
		}
		return a;
	}
	/*面试题68 - II. 二叉树的最近公共祖先
	给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

	百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，
	最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽
	可能大（一个节点也可以是它自己的祖先）。”

	//后序遍历递归法
	//我的想法：前序遍历，找到路径，然后变为链表的公共节点。
	*/
	/*
	(递归) O(n)

	当我们用递归去做这个题时不要被题目误导，应该要明确一点
	这个函数的功能有三个：给定两个节点 p 和 q

	如果 p 和 q 都存在，则返回它们的公共祖先；
	如果只存在一个，则返回存在的一个；
	如果 p 和 q 都不存在，则返回NULL
	本题说给定的两个节点都存在，那自然还是能用上面的函数来解决

	具体思路：
	（1） 如果当前结点 root 等于NULL，则直接返回NULL
	（2） 如果 root 等于 p 或者 q ，那这棵树一定返回 p 或者 q
	（3） 然后递归左右子树，因为是递归，使用函数后可认为左右子树已经算出结果，用 left和 right 表示
	（4） 此时若left为空，那最终结果只要看 right；若 right 为空，那最终结果只要看 left
	（5） 如果 left 和 right 都非空，因为只给了p 和 q 两个结点，都非空，说明一边一个，因此 root 是他们的最近公共祖先
	（6） 如果 left 和 right 都为空，则返回空（其实已经包含在前面的情况中了）

	时间复杂度是O(n)：每个结点最多遍历一次或用主定理，空间复杂度是O(n)：需要系统栈空间
	*/
	/*
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// 若root包含p 返回p
		// 若root包含q 返回q
		// 若root都不包含 返回NULL
		// 若以root的子树中包含p和q 返回root(最近公共祖先)
		if (!root || root == p || root == q) return root;

		auto left = lowestCommonAncestor(root->left, p, q);
		auto right = lowestCommonAncestor(root->right, p, q);

		if (!left) return right;
		if (!right) return left;

		return root;
	}
	*/
	void getPath(TreeNode* root, TreeNode* end, vector<TreeNode*>& path) {
		stack<TreeNode*> stk;
		TreeNode* p = root, * prev = nullptr;
		while (p || !stk.empty()) {
			while (p) {
				stk.push(p);
				path.push_back(p);
				if (p == end) return;
				p = p->left;
			}
			p = stk.top();
			if (!p->right || p->right == prev) 
			{
				path.pop_back();
				stk.pop();
				prev = p;
				p = nullptr;
			}
			else 
			{
				p = p->right;
			}
		}
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path1, path2;
		getPath(root, p, path1);
		getPath(root, q, path2);
		int n = min(path1.size(), path2.size());
		TreeNode* last = nullptr;
		for (int i = 0; i < n; i++) {
			if (path1[i] != path2[i]) return last;
			last = path1[i];
		}
		return last;
	}



	
};
