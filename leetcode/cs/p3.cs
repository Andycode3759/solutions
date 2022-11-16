public class Solution {
    public int Try(string str,int max)
    {
        Dictionary<char,int> showedUp = new Dictionary<char,int>();
        for(int i=0;i<str.Length;i++)
        {
            if(showedUp.ContainsKey(str[i]))
            {
                max = i>max? i : max;
                return Try(str.Substring(showedUp[str[i]]+1),max);
            }
            showedUp.Add(str[i],i);
        }
        return str.Length>max? str.Length:max;
    }
    public int LengthOfLongestSubstring(string s) {
        return Try(s,0);
    }
}

//从第一个字符开始，逐一记录出现过的字符
//如果现在位置的字符已经有过记录，那就记录长度
//从上一个出现过的字符后一位开始重复这一过程
//如果到了字符串结尾，结束