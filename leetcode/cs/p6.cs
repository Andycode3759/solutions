public class Solution {
    public string Convert(string s, int numRows) {
        if(numRows==1)
        {
            return s;
        }
        StringBuilder[] matrix = new StringBuilder[numRows];
        for(int i=0;i<matrix.Length;i++)
        {
            matrix[i] = new StringBuilder();
        }
        int direction = 1; //1 = down, -1 = up
        int nowRow=0;
        for(int i=0;i<s.Length;i++)
        {
            matrix[nowRow].Append(s[i]);
            nowRow+=direction;
            if(nowRow==0||nowRow==numRows-1)
            {
                direction*=-1; //turn back!
            }
        }
        string result = "";
        foreach(StringBuilder str in matrix)
        {
            result+=str.ToString();
        }
        return result;
    }
}