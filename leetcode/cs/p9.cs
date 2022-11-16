public class Solution {
    public bool IsPalindrome(int x) {
        string s = x.ToString();
        int size = s.Length;
        for(int i=0;i<(size+1)/2;i++)
        {
            if(s[i]!=s[size-i-1])
            return false;
        }
        return true;
    }
}