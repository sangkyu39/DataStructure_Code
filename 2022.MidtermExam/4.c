int getSpecificNodeCount(ListType* L, int n) {
	Node* p = L->header->next;
	int cnt = 0;

	while (p != NULL) {
		if (n == p->elem) {
			cnt++;
		}
		p = p->next;
	}
	return cnt;
}