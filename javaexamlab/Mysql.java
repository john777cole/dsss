import java.sql.*; //PROGRAM TO IMPLEMENT SQL QUERIES
import java.util.Scanner;
class Mysql
{
public static void main(String arg[])
{
try
{
Scanner sc =new Scanner(System.in);
Class.forName("com.mysql.jdbc.Driver"); //REGISTER DRIVER
Connection con =DriverManager.getConnection("jdbc:mysql://localhost:3306/RISHI","mec","mec");
Statement stmt=con.createStatement();
ResultSet rs=stmt.executeQuery("SELECT * FROM DICTIONARY");
System.out.println("\nENTER WORD : ");
String w=sc.nextLine();
while(rs.next())
{
String word=rs.getString("WORD");
String meaning =rs.getString("MEANING");
boolean r = word.equals(w);
if(r)
System.out.println(word+" "+meaning);
}
con.close();
}
catch(Exception e)
{
System.out.println(e);
}
}
} 
