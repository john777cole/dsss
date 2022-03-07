import java.io.*;
import java.lang.Thread;
import java.util.concurrent.TimeUnit;
import java.lang.Math;
import java.util.Random;
class thread1 extends Thread
{
 double i;
 public void run()
 {
  while(1>0)
  {
   Random random = new Random();  
   int i = random.nextInt(50);
   System.out.println(i);
   
   if(i%2==0)
   {
  thread2 t2=new thread2(i);
  t2.start();
   }
   else
    new thread3(i).start();
    try{
   TimeUnit.SECONDS.sleep(1);}
   catch(Exception e)
   {
       System.out.println(e);
   }
 
  }  
 }
}
class thread2 extends Thread
{
 double i;
 thread2(double i)
 {this.i=i;}
 public void run()
 {
  System.out.println(i*i);
 }
}
class thread3 extends Thread
{
 double i;
 thread3(double i)
 {this.i=i;}
 public void run()
 {
  System.out.println(i*i*i);
 }
}
class threethreads
{
 public static void main(String a[])
 {
  thread1 t=new thread1();
  t.start();
 }
}
