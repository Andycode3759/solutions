public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int,List<int>> ioi = new Dictionary<int,List<int>>(); //index of index
        for(int i=0;i<nums.Length;i++)
        {
            if(!ioi.ContainsKey(nums[i])) ioi[nums[i]] = new List<int>();
            ioi[nums[i]].Add(i);
        }
        int resA,resB;
        for(int i=0;i<ioi.Count;i++)
        {
            int adder=Enumerable.ElementAt<int>(ioi.Keys,i);
            resA=ioi[adder][0];
            if(ioi.ContainsKey(target-adder))
            {
                if(target==adder*2) {
                    if(ioi[adder].Count>1)
                        resB=ioi[adder][1];
                    else
                        continue;
                }
                else resB=ioi[target-adder][0];
                return new int[]{resA,resB};
            }
            else continue;
        }
        return new int[]{0,0};
    }
}