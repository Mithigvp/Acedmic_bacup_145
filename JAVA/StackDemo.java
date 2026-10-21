class Stack {
    int top;
    int[] s;

    Stack() {
        top = -1;
        s = new int[5];
        System.out.println("stack");
    }

    Stack(int size) {
        top = -1;
        s = new int[size];
    }

    public void push(int value) {
        s[++top] = value;
    }

    public int pop() {
        return s[top--]; 
    }

    public void travese() {
        if (top < 0) {
            System.out.println("Stack is empty");
            return;
        }
        for (int i = top; i >= 0; i--) { 
            System.out.print(s[i] + "\t");
        }
        System.out.println();
    }
}

class NStack extends Stack {

    NStack() {
        System.out.println("NStack()");
    }

    NStack(int value) {
        super(value);
        System.out.println("NStack(int)");
    }
	
    public void push(int value) {
        
        if (top >= s.length - 1) { 
            System.out.println("Stack Overflow");
            System.exit(0);
        }
        super.push(value);
        System.out.println("MStack push()");
    }
}

class StackDemo {
    public static void main(String[] args) {
        NStack st = new NStack(4);
        st.push(10);
        st.push(20);
        st.push(30);
        st.push(40);
    
        st.travese();
    }
}
