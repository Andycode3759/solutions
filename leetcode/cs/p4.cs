public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] array = new int[nums1.Length+nums2.Length];
        nums1.CopyTo(array,0);
        nums2.CopyTo(array,nums1.Length);
        Array.Sort(array);
        if(array.Length%2==1)
        {
            return (double)array[array.Length/2];
        }
        else
        {
            return (array[array.Length/2-1]+array[array.Length/2])/2.0;
        }
    }
}