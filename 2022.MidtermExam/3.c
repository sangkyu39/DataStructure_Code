int sumOfElement(ListType* L) {
	int sum = 0;
	Node* p = L->header->next;

	while (p != NULL) {
		sum += p->elem;
		p = p->next;
	}

	return sum;
}

int getMax(ListType* L) {
	Node* p = L->header->next;
	int max = p->elem;

	while (p != NULL) {
		if (max < p->elem) {
			max = p->elem;
		}
		p = p->next;
	}
	return max;
}