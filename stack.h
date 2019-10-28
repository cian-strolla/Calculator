struct stack {

  int MAXSIZE = 100;
  int stack[100];
  int top = -1;

  int isempty() {

      if(top == -1) {
        return 1;
      }
      else {
        return 0;
      }
    }

  int isfull() {

      if(top == MAXSIZE) {
        return 1;
      }
      else {
        return 0;
      }
    }

  int peek() {
      return stack[top];
    }

  int pop() {
      int data;

      if(!isempty()) {
        data = stack[top];
        top = top - 1;
        return data;
      } else {
        return -1;
      }
    }

  int push(int data) {

      if(!isfull()) {
        top = top + 1;
        stack[top] = data;
      } else {
        return -1;
      }
    }
 }
