#include<vector>
using std::vector;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
        //starting at end, move nums1 elements up n spaces to avoid n^2 movement
        for (int i = m - 1; i >= 0; i--)
        {
            nums1[n + i] = nums1[i];
        }
        
        int first_empty = 0;
        int i = n, j = 0; //positions in nums1 and nums2
        //compare elements of nums1 to elements of nums2, moving smaller to
        //beginning of empty region
        //check for lists being empty with m and n
        while(i < n + m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                nums1[first_empty] = nums1[i];
                i++;
            }
            else //nums2 has smallest value
            {
                nums1[first_empty] = nums2[j];
                j++;
            }
            first_empty++;
        }
        //copy any remaining elements from nums1 or nums2
        if(i < n + m) //copy rest of nums1
        {
            for(; i < n + m; i++)
            {
                nums1[first_empty] = nums1[i];
                first_empty++;
            }
        }
        if(j < n) //copy rest of nums2
        {
            for(; j < n; j++)
            {
                nums1[first_empty] = nums2[j];
                first_empty++;
            }
        }
}
