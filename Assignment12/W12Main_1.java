/**
 * Make sure you have a file called EvenStack in the same directory
 *
 * Compile:
 * javac -J-Xmx10m -J-Xms5m W12Main_1.java
 *
 * Run:
 * java -Xmx5m -Xms5m W12Main_1
 */

public class W12Main_1
{
    public static void main(String[] args) 
    {
        EvenStack stack = new EvenStack();
 
        stack.push(1);
        stack.push(20);
        stack.push(65);
        stack.push(32);
        stack.push(2);
        stack.push(6);
        stack.push(13);
        stack.push(9);
        stack.push(4);
        stack.push(7);
        stack.push(8);
        
        System.out.println(stack);

        System.out.println( stack.pop() );
        stack.push(35);
         
        System.out.println( stack.pop() );
        System.out.println( stack.pop() );
        System.out.println( stack.pop() );
        System.out.println( stack.pop() );
        System.out.println( stack.pop() );
        System.out.println( stack.pop() );
        System.out.println( stack.pop() );
        System.out.println( stack.pop() );
        System.out.println( stack.pop() );
        System.out.println( stack.pop() );
        System.out.println( stack.pop() );
        System.out.println( stack.pop() );
         
        System.out.println( stack );
    }
}
