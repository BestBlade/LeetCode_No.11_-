/*----------------------------------------------------------------------------------------------|
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂	|
直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容|
纳最多的水。																					|
																								|
说明：你不能倾斜容器，且 n 的值至少为 2。														|
																								|
																								|
图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大	|
值为 49。																						|
																								|
示例：																							|
																								|
输入：[1,8,6,2,5,4,8,3,7]																		|
输出：49																						|
																								|
来源：力扣（LeetCode）																			|
链接：https://leetcode-cn.com/problems/container-with-most-water								|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。							|
-----------------------------------------------------------------------------------------------*/

/*	双指针法
*	执行用时：16 ms, 在所有 C++ 提交中击败了83.22%的用户
*	内存消耗：7.5 MB, 在所有 C++ 提交中击败了74.67%的用户
*/
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) 
{
	int size = height.size();
	int result = { 0 };

	int left = 0;
	int right = size - 1;

	while (left < right)
	{
		int area = min(height[left], height[right]) * (right - left);

		if (area > result)
		{
			result = area;
		}

		if (height[left] <= height[right])
		{
			left++;
		}
		else
		{
			right--;
		}

	}
	return result;
}

int main()
{
	vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };

	cout << maxArea(height) << endl;
}