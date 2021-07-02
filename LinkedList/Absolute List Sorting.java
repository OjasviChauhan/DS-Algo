  // https://practice.geeksforgeeks.org/problems/absolute-list-sorting/1#
  
  Node sortList(Node head) {
	Node t = head;
        while(t.next != null){
            if(t.next.data < 0){
                Node f = t.next;
                t.next = f.next;
                f.next = head;
                head = f;
            }
            else t = t.next;
        }
        return head;
  }
