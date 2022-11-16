/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode c1=l1,c2=l2;
        ListNode sumHead = new ListNode();
        ListNode sum = sumHead;
        int extra=0;
        while(true)
        {
            
            if(c1==null) c1=new ListNode();
            if(c2==null) c2=new ListNode();
            int value = c1.val+c2.val+extra;
            extra=0;
            if(value>=10)
            {
                extra=1;
                value-=10;
            }
            
            sum.val=value;
            if(c1.next==null && c2.next==null)
            {
                if(extra==1)
                    sum.next=new ListNode(1,null);
                return sumHead;
            }
            sum.next=new ListNode();
            sum=sum.next;
            c1=c1.next;
            c2=c2.next;
        }
        
    }
}