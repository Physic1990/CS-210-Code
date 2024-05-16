public class EvenStack {
  private static final int MAX_SIZE = 10;
  private int[] stack;
  private int size;

  public EvenStack() {
    this.stack = new int[MAX_SIZE];
    this.size = 0;
  }

  public void push(int e) {
    if (this.size == MAX_SIZE) {
      System.out.println("Error: EvenStack is full");
      return;
    }

    System.out.println("Pushing: " + e);
    this.stack[this.size++] = e;
  }

  public int pop() {
    if (this.size == 0) {
      System.out.println("Error: EvenStack is empty");
      return -1;
    }

    // Pop even elements first
    for (int i = this.size - 1; i >= 0; i--) {
      if (this.stack[i] % 2 == 0) {
        int e = this.stack[i];
        this.stack[i] = 0;
        this.size--;
        return e;
      }
    }

    // If there are no even elements, pop the last odd element
    int e = this.stack[this.size - 1];
    this.stack[this.size - 1] = 0;
    this.size--;
    return e;
  }

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("[");

    // Pop all elements in the order they would be popped
    while (this.size > 0) {
      sb.append(pop());
      if (this.size > 0) {
        sb.append(", ");
      }
    }

    sb.append("]");
    return sb.toString();
  }
}

