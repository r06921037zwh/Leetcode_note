def removeDuplicateFromUnsortedList1(head):
    if head == None or head.next == None:
      return head

    outerIndex = head
    innerPrev = head
    innerCur = head.next                                     
    while outerIndex:
      while innerCur:
        if innerCur.val != outerIndex.val:
          innerPrev = innerPrev.next
          innerCur = innerCur.next
        else:
          innerPrev.next = innerCur.next
          innerCur = innerPrev.next

      outerIndex = outerIndex.next
      innerPrev = outerIndex
      innerCur = outerIndex.next
          
def removeDuplicateFromUnsortedList2(head):
    if head == None or head.next == None:
      return head

    hash = set()
    while head:
      if head.val not in hash:
        hash.add(head.val)
        head = head.next
      else:
        head.next = head.next.next
        head = head.next
