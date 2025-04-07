class Solution {
    public: Node * rearrange(Node * head)
    {
        //CODE HERE
        Node * eS = NULL, * eE = NULL, * oS = NULL, * oE = NULL;
        for (Node * curr = head; curr != NULL; curr = curr -> next) {
            int x = curr -> val;
            if (x % 2 == 0) {
                if (eS == NULL) {
                    eS = curr;
                    eE = eS;
                } else {
                    eE -> next = curr;
                    eE = eE -> next;
                }
            } else {
                if (oS == NULL) {
                    oS = curr;
                    oE = oS;
                } else {
                    oE -> next = curr;
                    oE = oE -> next;
                }
            }
        }
        if (eS == NULL || oS == NULL)
            return head;
        eE-> next = oS;
        oE -> next = NULL;
        return eS;
    }
};
