void spans(Stack *A, int X[], int S[]){
  for (int i = 0;i < N;i++){
    while (!isEmpty(A) && X[peek(A)] <= X[i]){
      pop(A);
    }
    if (isEmpty(A)){
      S[i] = i + 1;
    }
    else {
      S[i] = i - peek(A);
    }
    push(A, i);
  }
}