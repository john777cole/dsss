import java.io.*;
import java.util.*;
public class errorchecked {
public static void checkAge(int age) throws ArithmeticException {
    if (age < 18) {
      throw new ArithmeticException("Access denied - You must be at least 18 years old.");
    }
    else {
      System.out.println("Access granted - You are old enough!");
    }
  }

  public static void main(String[] args) {
    int n;    
  Scanner in = new Scanner(System.in);
  System.out.println("Enter the number: ");
  n = in.nextInt();
  try{
      checkAge(n);
  }
  catch(ArithmeticException e){
      System.out.println(e);
  }
    int val1, val2;
      try {
         System.out.println("Try Block Start");
         val1 = 0;
         val2 = 10 / val1;
         System.out.println(val2);
         System.out.println("Try Block End");
      }
      catch (ArithmeticException e) {
         System.out.println("ArithmeticException divide by Zero");
      }
      finally {
            System.out.println ("Finally Block");
  }
}}

