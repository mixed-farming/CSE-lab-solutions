LAB – 3 -Strings
1) Design a class which represents a Student. Every student record is made up 
of the following fields.
1. Registration number (int)
2. Full Name (String)
3. Date of joining (Gregorian calendar)
4. Semester (short)
5. GPA (float)
6. CGPA (float)
Whenever a student joins he will be given a new registration number. 
Registration number is calculated as follows. If year of joining is 2012 and he is 
the 80th student to join then his registration number will be 1280.
Write member functions to do the following.
1. Provide parameterized constructor to the class
2. Override toString method to display the student record
3. Create an array of student records to store minimum of 5 records in it. 
Input the records and display them.
4. Write a method to alphabetically sort the students based on Full name
5. Write a method to list all the student names containing a particular sub 
string. 
Test all the methods of the class by writing suitable main method.
CODE :
import java.util.*;
class Student { // creation of the class student
 static int count = 0;
 int Reg_No;
 String FullName;
 GregorianCalendar doj = new GregorianCalendar();
 short Sem;
 float GPA, CGPA;
 int cnt;
 Student() { // zero argument constructor
 Reg_No = 0;
 FullName = "";
 Sem = 0;
 GPA = 0;
 CGPA = 0;
 doj = new GregorianCalendar(2000, 1, 1);
 count++;
 cnt = count;
 }
 Student(int year, int month, int date, String name, short semester, float gpa, 
float cgpa) { // parameterized constructor
 FullName = name;
 Sem = semester;
 GPA = gpa;
 CGPA = cgpa;
 doj = new GregorianCalendar(year, month, date);
 cnt = ++count;
 int yr = doj.get(Calendar.YEAR) % 100;
 Reg_No = yr * 100 + cnt;
 }
 public String toString() { //Overriding the toString() method of java and 
displaying the student records
 System.out.println(" Registration number: " + Reg_No);
 return (" The name of student: " + FullName + "\n The dob of student: " + 
doj.get(Calendar.YEAR) + "/" +
 doj.get(Calendar.MONTH) + "/" + doj.get(Calendar.DATE) + "\n The 
semester of student: " + Sem +
 "\n The gpa of student: " + GPA + "\n The cgpa of student: " + CGPA);
 }
 static void Sort(Student std[], int n) { // Sort the student report 
alphabetically
 String[] arr = new String[n];
 for (int i = 0; i < n; i++)
 arr[i] = std[i].FullName;
 for (int a = 0; a < n - 1; a++) {
 for (int b = a + 1; b < n; b++) {
 if ((arr[a].compareToIgnoreCase(arr[b])) > 0) {
 Student t = std[a];
 std[a] = std[b];
 std[b] = t;
 }
 }
 }
 }
 static void particularSubString(Student std[], int n, String substrg) {
 int idx;
 String[] arr = new String[n];
 for (int i = 0; i < n; i++)
 arr[i] = std[i].FullName;
 for (int i = 0; i < n; i++) {
 idx = arr[i].indexOf(substrg);
 if (idx > 0)
 System.out.println(arr[i]);
 }
 }
}
public class stdreport {
 public static void main(String[] args) {
 Scanner sc = new Scanner(System.in);
 Student stud[] = new Student[20];
 int i, date, month, year, n;
 String Name, substrg;
 short sem;
 float gpa, cgpa;
 System.out.print(" Number of students: ");
 n = sc.nextInt();
 for (i = 0; i < n; i++) { // Entry for student record
 System.out.println(" Enter details for student " + (i + 1) + ":");
 System.out.print(" Enter Name: ");
 Name = sc.next();
 System.out.print(" Enter semester: ");
 sem = sc.nextShort();
 System.out.print(" Enter GPA: ");
 gpa = sc.nextFloat();
 System.out.print(" Enter CGPA: ");
 cgpa = sc.nextFloat();
 System.out.print(" Enter date of joining: ");
 date = sc.nextInt();
 System.out.print(" Month of joining: ");
 month = sc.nextInt();
 System.out.print(" Year of joining: ");
 year = sc.nextInt();
 System.out.println();
 stud[i] = new Student(year, month, date, Name, sem, gpa, cgpa);
 }
 Student.Sort(stud, n);
 for (i = 0; i < n; i++)
 System.out.println(stud[i].toString());
 System.out.print(" Enter the substring to be serached: ");
 substrg = sc.next();
 Student.particularSubString(stud, n, substrg);
 }
}
OUTPUT :


2. Write and execute a Java program to convert strings containing numbers into
comma-punctuated numbers, with a comma every third digit from the right.
CODE :
import java.util.Scanner;
public class comma {
 // Function to insert string
 public static String insertString(String originalString,String 
stringToBeInserted,int index) {
 // Create a new string
 String newString = originalString.substring(0, index )
 + stringToBeInserted
 + originalString.substring(index );
 // return the modified String
 return newString;
 }
 // Driver code
 public static void main(String[] args) {
 Scanner sc = new Scanner(System.in);
 System.out.print("Enter a string: ");
 String originalString = sc.nextLine(); //reads string.
 String stringToBeInserted = ",";
 int n_c, index, length;
 length = originalString.length();
 n_c = (length - 1) / 3;
 if (length % 3 == 0)
 index = 3;
 else
 index = length % 3;
 for (; index < length; index += 4) {
 originalString = insertString(originalString,stringToBeInserted,index);
 }
 System.out.println("String with comma-puntuations : " + originalString);
 }
}
OUTPUT :
**********
