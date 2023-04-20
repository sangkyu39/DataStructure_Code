void deleteSpecificNode(ListType* L, int n){
	Node* p = L->header->next;

	while (p->next != NULL) {
		if (n == p->next->elem) {
			p->next = p->next->next;
		}
		p = p->next;
	}
}