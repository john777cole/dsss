import java.io.*;

class Account
{
 double balance;
 double wamt;
 Account(double b)
 { balance = b; }
 
 synchronized public double withdraw()  /* function to withdraw*/
 {
  System.out.println("Withdraw Started.");
  System.out.println("Enter amount to withdraw : ");
  java.util.Scanner S = new java.util.Scanner(System.in);
  wamt = S.nextDouble();
  System.out.println("\nBalance before withdraw : "+balance);
  
  if(balance < wamt)
  {
     System.out.println("\nInsufficient balance waiting for deposit.\n");
     try{
       wait();
     } catch(Exception e){   
     }
   }
   
   balance = balance-wamt;
   System.out.println("After Withdraw : "+ balance);
   return wamt;
  }
  
  synchronized public void deposit(double damt)  /* function to deposit */
  {
   System.out.println("Deposit process started.");
   System.out.println("Balance before deposit : "+ balance);
   balance = balance + damt;
   System.out.println("Balance after deposit : "+ balance);
   this.notify();
  }
}

class Thread1 implements Runnable
{
 Account a;
 Thread1(Account a)
 {
  this.a = a;
  Thread t = new Thread(this);
  t.start();
 }
 
 public void run()
 {
  a.withdraw();
 }
}
 
class Thread2 implements Runnable
{
 Account a;
 Thread2(Account a)
 {
  this.a =a;
  Thread t = new Thread(this);
  t.start();
 }
 
 public void run()
 {
  a.deposit(2900);
 }
}
 
class Demo
{
 public static void main(String args[])
 {
  Account acc = new Account(10000);
  new Thread1(acc);
  new Thread2(acc);
 }
}

/* OUTPUT 
mec@cc-2-2:~/38_NIKITA$ javac Demo.java
mec@cc-2-2:~/38_NIKITA$ java Demo
Withdraw Started.
Enter amount to withdraw : 
500

Balance before withdraw : 10000.0
After Withdraw : 9500.0
Deposit process started.
Balance before deposit : 9500.0
Balance after deposit : 12400.0
mec@cc-2-2:~/38_NIKITA$ javac Demo.java
mec@cc-2-2:~/38_NIKITA$ java Demo
Withdraw Started.
Enter amount to withdraw : 
12000

Balance before withdraw : 10000.0

Insufficient balance waiting for deposit.

Deposit process started.
Balance before deposit : 10000.0
Balance after deposit : 12900.0
After Withdraw : 900.0

*/
