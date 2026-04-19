# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        #head → dummy node (starting point)
        #root → final result ka starting pointer (isse return karenge)
        #carry → carry value (jaise normal addition me hota hai)
        head = ListNode(0)
        root = head
        carry = 0
       
        #Loop chalega jab tak l1 ya l2 me kuch hai
        while l1 or l2 :
            
            #Values nikaalo
            v1=l1.val if l1 else 0
            v2=l2.val if l2 else 0
            #Sum calculate karo
            s=v1+v2+carry
            #Carry aur digit alag karo
            carry = s // 10
            head.next=ListNode(s % 10)
            head=head.next
            #Next nodes pe move karo
            if l1:
                l1=l1.next
            if l2:
                l2=l2.next
        #Loop ke baad agar carry bacha ho
        if carry:
            head.next=ListNode(carry)
        return root.next