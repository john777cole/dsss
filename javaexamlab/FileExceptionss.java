import java.util.*;
import java.io.*;

public class FileExceptionss
{
    public static void main(String arg[])
    {
        Scanner sc = new Scanner (System.in);
        try
        {            
            Writer w =new FileWriter("/home/ajay/Desktop/Filed.txt");
            System.out.println("FILE OPENED TO WRITE");
            System.out.println("Enter your degree and college : ");
            String s = sc.nextLine();
            w.write(s);
            w.close();
            System.out.println("FILE CLOSED AFTER WRITING");
            Reader r = new FileReader("/home/ajay/Desktop/Filed.txt");
            int ch = r.read();
            System.out.println("FILE OPENED TO READ");
            while(ch!=-1)
            {
                System.out.print((char)ch);
                ch=r.read();
            }
            r.close();
            System.out.println("\nFILE CLOSED AFTER READING");
        }

                
        catch(FileNotFoundException j)
         {
            System.out.println("FILE NOT FOUND ERROR !");
         } 
         
         catch(IOException j)
         {
            System.out.println("JAVA I/O ERROR !");
         } 

        catch(Exception j)
        {
            System.out.println("ERROR !");
        }
        

    }
}
