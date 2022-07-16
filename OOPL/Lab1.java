LAB - 1
  
1.a. Write a method isPrime() to accept one integer parameter and to check whether that 
parameter is prime or not.
1.b. Using this method, generate first N prime numbers in the main method.
Code :
import java.util.Scanner;
class isPrime {
//main function
public static void main(String[] args) {
int N, count = 0, k = 2;
Scanner sc = new Scanner(System.in);
System.out.println("Enter the limit : ");
N = sc.nextInt();
System.out.println("First " + N + " prime numbers are : ");
while (count < N) {
if (isPrime(k)) {
System.out.print(k + " ");
count++;
}
k++;
}
}
//method
public static boolean isPrime(int n) {
int flag = 1;
for (int i = 2; i <= Math.sqrt(n); i++) {
if (n % i == 0) {
flag = 0;
break;
}
}
if (flag == 1) {
return (true);
} else {
return (false);
}
}
}

2. Arrange the elements in ascending and descending order using Bubble sort method.
Code : 
import java.util.Scanner;
class bubble_sort {
 public static void main(String[] args) {
 Scanner sc = new Scanner(System.in);
 int i, j, n;
 int [] a = new int[30];
 System.out.println("Enter the number of elements : ");
 n = sc.nextInt();
 System.out.println("Populate the array : ");
 for (i = 0; i < n; i++) {
 a[i] = sc.nextInt();
 }
 //ascending order
 for (i = 0; i < n - 1; i++) {
 for (j = 0; j < n - i - 1; j++) {
 if (a[j + 1] < a[j]) {
 int temp = a[j + 1];
 a[j + 1] = a[j];
 a[j] = temp;
 }
 }
 }
 //printing ascending order
 System.out.print("\nThe ascending order of numbers : ");
 for (i = 0; i < n; i++) {
 System.out.print(a[i] + " ");
 }
 //descending order
 for (i = 0; i < n - 1; i++) {
 for (j = 0; j < n - i - 1; j++) {
 if (a[j + 1] > a[j]) {
 int temp = a[j + 1];
 a[j + 1] = a[j];
 a[j] = temp;
 }
 }
 }
 //printing descending order
 System.out.print("\n\nThe descending order of numbers : ");
 for (i = 0; i < n; i++) {
 System.out.print(a[i] + " ");
 }
 }
}

3. Find the addition of two matrices and display the resultant matrix.
Code :
import java.util.Scanner;
class matrix_addition {
 public static void main(String[] args) {
 Scanner sc = new Scanner(System.in);
 int [][] a = new int [10][10],b = new int [10][10],c = new int [10][10];
 
 int m, n, p, q, i, j;
 System.out.println("Enter the dimensions of the 1st matrix : ");
 m = sc.nextInt();
 n = sc.nextInt();
 System.out.println("Enter the dimensions of the 2nd matrix : ");
 p = sc.nextInt();
 q = sc.nextInt();
 if ((m != p) || (n != q)) {
 System.out.println("\nThese two matrices cannot be added as they are of different 
order.");
 System.exit(0);
 } else {
 System.out.println("\nEnter the elements of 1st matrix : ");
 for (i = 0; i < m; i++) {
 for (j = 0; j < n; j++) {
 a[i][j] = sc.nextInt();
 }
 }
 System.out.println("\nEnter the elements of 2nd matrix : ");
 for (i = 0; i < p; i++) {
 for (j = 0; j < q; j++) {
 b[i][j] = sc.nextInt();
 }
 }
 //Addition of two matrices
 for (i = 0; i < m; i++) {
 for (j = 0; j < n; j++) {
 c[i][j] = a[i][j] + b[i][j];
 }
 }
 //Printing the resultant matrix
 System.out.println("\nThe resultant matrix is : ");
 for (i = 0; i < m; i++) {
 for (j = 0; j < n; j++) {
 System.out.print(c[i][j] + " ");
 }
 System.out.println();
 }
 }
 }
}
