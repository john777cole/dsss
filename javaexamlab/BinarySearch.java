import java.io.*;
import java.util.*;
class BinarySearch{  
 public static void binarySearch(int arr[], int first, int last, int key){  
   int mid = (first + last)/2;  
   while( first <= last ){  
      if ( arr[mid] < key ){  
        first = mid + 1;     
      }else if ( arr[mid] == key ){  
        System.out.println("Element is found at index: " + mid);  
        break;  
      }else{  
         last = mid - 1;  
      }  
      mid = (first + last)/2;  
   }  
   if ( first > last ){  
      System.out.println("Element is not found!");  
   }  
 }  
 public static void main(String args[]){  
        int n,i;
  Scanner in = new Scanner(System.in);
 
  System.out.println("Enter the number of elements of the array:");
  n = in.nextInt();
   
  int arr[] = new int[n]; 
  
  System.out.println("Enter the elements of array:");
 
  for ( i= 0 ; i < n ; i++ )
 { 
 
 arr[i] = in.nextInt(); 
 } 
 
  System.out.println("Enter the number: "); 
  int key = in.nextInt();  
        int last=n-1;  
        binarySearch(arr,0,last,key);     
 }  
}  
