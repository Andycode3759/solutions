public class Solution {
    public int Reverse(int x) {
        var num = x.ToString().Reverse();
        
        int result=0;
        foreach(char ch in num)
        {
            if(ch=='-')
            {
                result*=-1;
            }
            else
            {
                checked{
                try
                {
                    result*=10;
                    result+=int.Parse(ch.ToString());
                }
                catch(Exception)
                {
                    return 0;
                }
            }}
        }
        return result;
    }
}