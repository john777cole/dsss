import java.util.*;

class QuickSort {

 
   int partition(int array[], int low, int high) {
    
   
    int pivot = array[high];
    
   
    int i = (low - 1);

    
    for (int j = low; j < high; j++) {
      if (array[j] <= pivot) {


        i++;

      
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }

    }

 
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

 
    return (i + 1);
  }

   void quickSort(int array[], int low, int high) {
    if (low < high) {

     
      int pi = partition(array, low, high);
      
     
      quickSort(array, low, pi - 1);

    
      quickSort(array, pi + 1, high);
    }
  }
}


class Quick {
  public static void main(String args[]) {

   int n,i;
  Scanner in = new Scanner(System.in);
 
  System.out.println("Enter the number of elements of the array:");
  n = in.nextInt();
   
  int A[] = new int[n]; 
  
  System.out.println("Enter the elements of array:");
 
  for ( i= 0 ; i < n ; i++ )
 { 
 
 A[i] = in.nextInt(); 
 }

   
    Quicksort.quickSort(A, 0, n - 1);

    System.out.println("Sorted Array in Ascending Order ");
    System.out.println(Arrays.toString(A));
  }
}
