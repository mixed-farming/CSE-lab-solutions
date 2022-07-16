LAB – 4 – Inheritance and Packages
Code :
import java.util.*;
class DOB {
int date;
int month;
int year;
}
class Person {
private String name;
private DOB dob = new DOB();
Person(){
name = "";
dob.date = 1;
dob.month = 1;
dob.year = 2001;
}
Person(int dt, int mth, int yr, String Name) {
name = Name;
dob.date = dt;
dob.month = mth;
dob.year = yr;
}
String getName() {
return name;
}
DOB getDOB() {
return dob;
}
}
class CollegeGraduate extends Person {
private int yog;
private float gpa;
CollegeGraduate() {
super();
yog = 0;
gpa = 0;
}
CollegeGraduate(int dt, int mth, int yr, String Name, int YearOG, float GPA) {
super(dt, mth, yr, Name);
yog = YearOG;
gpa = GPA;
}
int getYOG() {
return yog;
}
float getGPA() {
return gpa;
}
void display() {
System.out.println("\nName = " + getName());
DOB dob = getDOB();
System.out.println("DOB = " + dob.date + "/" + dob.month + "/" + dob.year);
System.out.println("GPA = " + getGPA());
System.out.println("Year of graduation = " + getYOG());
}
}
public class lab4_1 {
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
System.out.println("Enter student details");
int dt, mth, yr, yog;
String Name;
float GPA;
System.out.print("Enter student's name: ");
Name = sc.next();
System.out.println("\nEnter student's Date of birth");
System.out.print("Date : ");
dt = sc.nextInt();
System.out.print("Month : ");
mth = sc.nextInt();
System.out.print("Year : ");
yr = sc.nextInt();
System.out.print("\nEnter student's GPA: ");
GPA = sc.nextFloat();
System.out.print("\nEnter student's year of graduation: ");
yog = sc.nextInt();
CollegeGraduate C = new CollegeGraduate(dt, mth, yr, Name, yog, GPA);
C.display();
}
}
Output :
“java programs\myPackages\p1\Max.java” is the location of the package.
Code :
package myPackages.p1;
public class Max {
public static int max(int x, int y, int z) {
int temp = x > y ? x : y;
int result = z > temp ? z : temp ;
return result;
}
public static float max(float x, float y, float z) {
float temp = x > y ? x : y;
float result = z > temp ? z : temp ;
return result;
}
public static int max(int [] arr) {
int maximum = 0;
for (int i = 0; i < arr.length; i++) {
if (arr[i] > maximum) {
maximum = arr[i];
}
}
return maximum;
}
public static int max(int [][] arr) {
int maximum = 0;
for (int i = 0; i < arr.length; i++) {
for (int j = 0; j < arr[i].length; j++) {
if (arr[i][j] > maximum) {
maximum = arr[i][j];
}
}
}
return maximum;
}
}
Main method :
import myPackages.p1.Max;
import java.util.Scanner;
public class lab4_2 {
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
System.out.println("Enter 3 integers to get their maximum");
int x = sc.nextInt();
int y = sc.nextInt();
int z = sc.nextInt();
System.out.println("The maximum of the 3 integers is " + 
Max.max(x, y, z));
System.out.println("Enter 3 floating point integers to get their 
maximum");
float a = sc.nextFloat();
float b = sc.nextFloat();
float c = sc.nextFloat();
System.out.println("The maximum of the 3 floating point integers is 
" + Max.max(a, b, c));
System.out.println("Enter the size of array");
int n = sc.nextInt();
int arr[] = new int[n];
System.out.println("Enter the array elements");
for (int i = 0; i < n; i++)
arr[i] = sc.nextInt();
System.out.println("The maximum of the array is " + 
Max.max(arr));
System.out.println("Enter the dimensions of the matrix");
int p = sc.nextInt();
int q = sc.nextInt();
int matrix[][] = new int[p][q];
System.out.println("Enter the matrix elements");
for (int i = 0; i < p; i++)
for (int j = 0; j < q; j++)
matrix[i][j] = sc.nextInt();
System.out.println("The maximum of the matrix is " + 
Max.max(matrix));
}
}
Output :
Code :
import java.util.Scanner;
abstract class Figure {
int dim1, dim2;
Figure(int x, int y) {
dim1 = x;
dim2 = y;
}
abstract int area();
}
class Rectangle extends Figure {
Rectangle(int x, int y) {
super(x, y);
}
int area() {
return dim1 * dim2;
}
}
class Triangle extends Figure {
Triangle(int x, int y) {
super(x, y);
}
int area() {
return dim1 * dim2 / 2;
}
}
class Square extends Figure {
Square(int x) {
super(x, x);
}
int area() {
return dim1 * dim2;
}
}
public class lab4_3 {
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
Figure f;
System.out.println("Enter the dimensions of rectangle");
int dim1 = sc.nextInt();
int dim2 = sc.nextInt();
Rectangle r = new Rectangle(dim1, dim2);
f = r;
System.out.println("The area of the rectangle is " + f.area());
System.out.println("Enter the base and height of triangle");
int base = sc.nextInt();
int height = sc.nextInt();
Triangle t = new Triangle(base, height);
f = t;
System.out.println("The area of the triangle is " + f.area());
System.out.println("Enter the dimension of square");
int side = sc.nextInt();
Square s = new Square(side);
f = s;
System.out.println("The area of the square is " + f.area());
}
}
Output :
**********
