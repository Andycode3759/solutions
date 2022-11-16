/*
//----!!BAD SOLUTION!!----//
    Reason:
        答案错误
    Input:
        42
*/
public class Solution {
    public int MyAtoi(string s) {
        s=s.Trim();
        long num=0;
        bool isNegative = false;
        bool signed = false;
        bool hasRealNum = false;
        bool first = false;
        if(s[0]=='-'&&!signed)
            {
                isNegative = true;
                signed = true;
            }
            if(s[0]=='+'&&!signed)
            {
                signed = true;
            }
        foreach(char ch in s)
        {
            if(!first)
            {
                first=true;
                continue;
            }
            if(ch!=' ')
            {
                hasRealNum = true;
            }
            if(!hasRealNum) continue;
            
            if("0123456789".Contains(ch))
            {
                num*=10;
                num+=long.Parse(ch.ToString());
            }
            else
            {
        break;
            }
        }
                        if(!isNegative && num>=2147483647)
                {
                    return 2147483647;
                }
                if(isNegative && num>=2147483648)
                {
                    return -2147483648;
                }
                return (int)(isNegative?-num:num);
    }
}