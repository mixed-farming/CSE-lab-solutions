LAB – 2
1) Define a class to represent a complex number called Complex. Provide the 
following methods and write a main method to test the class.:
1. To assign initial values to the Complex object.
2. To display a complex number in a+ib format.
3. To add 2 complex numbers. (the return type should be Complex)
4. To subtract 2 complex numbers .
CODE :
import java.util.Scanner;
class Complex {
 int real, imag;
 Scanner sc = new Scanner(System.in);
 void read() {
 real = sc.nextInt();
 imag = sc.nextInt();
 }
 void display() {
 System.out.println(real + " +i" + imag);
 }
 Complex add(Complex b) {
 Complex c = new Complex();
 c.real = real + b.real;
 c.imag = imag + b.imag;
 return c;
 }
 Complex subtract(Complex b) {
 Complex c = new Complex();
 c.real = real - b.real;
 c.imag = imag - b.imag;
 return c;
 }
}
class complex_arithmetic {
 public static void main (String[] args) {
 System.out.print("Enter the first complex number ");
 Complex a = new Complex();
 a.read();
 System.out.print("Enter the second complex number ");
 Complex b = new Complex();
 b.read();
 System.out.print("The first complex number is ");
 a.display();
 System.out.print("The second complex number is ");
 b.display();
 System.out.print("The sum of these 2 complex numbers is ");
 Complex c = a.add(b);
 c.display();
 System.out.print("The subtraction of these 2 complex numbers is ");
 c = a.subtract(b);
 c.display();
 }
}
OUTPUT :
2) Create a class called Time that has instance variables to represent hours, 
minutes and seconds. Provide the following methods and write a main method 
to test the class.:
To assign initial values to the Time object.
To display a Time object in the form of hh:mm:ss {24 hours format}
To add 2 Time objects (the return type should be a Time )
To subtract 2 Time objects (the return type should be a Time )
To compare 2 Time objects and to determine if they are equal or if the first is 
greater or smaller than the second one.
CODE : 
import java.util.Scanner;
class Time {
 int hours, seconds, minutes;
 Scanner sc = new Scanner(System.in);
 void read() {
 hours = sc.nextInt();
 minutes = sc.nextInt();
 seconds = sc.nextInt();
 }
 void display() {
 System.out.println(hours + ":" + minutes + ":" + seconds);
 }
 Time add(Time t) {
 Time sum = new Time();
 sum.seconds = t.seconds + seconds;
 sum.minutes = t.minutes + minutes;
 sum.hours = t.hours + hours;
 if (sum.seconds >= 60) {
 sum.minutes++;
 sum.seconds -= 60;
 }
 if (sum.minutes >= 60) {
 sum.hours++;
 sum.minutes -= 60;
 }
 if (sum.hours >= 24)
 sum.hours -= 24;
 return sum;
 }
 Time subtract(Time t) {
 Time sub = new Time();
 int res = this.compare(t);
 if (res == 0) {
 sub.seconds = 0;
 sub.minutes = 0;
 sub.hours = 0;
 return sub;
 }
 Time max = new Time();
 Time min = new Time();
 if (res == 1) {
 max = t;
 min = this;
 } else {
 max = this;
 min = t;
 }
 sub.seconds = max.seconds - min.seconds;
 sub.minutes = max.minutes - min.minutes;
 sub.hours = max.hours - min.hours;
 if (sub.seconds < 0) {
 sub.minutes--;
 sub.seconds += 60;
 }
 if (sub.minutes < 0) {
 sub.hours--;
 sub.minutes += 60;
 }
 return sub;
 }
 int compare(Time t) {
 if (t.hours == hours && t.seconds == seconds && t.minutes == minutes) {
 return 0;
 }
 if (t.hours > hours) {
 return 1;
 } else if (t.hours < hours) {
 return 2;
 } else if (t.minutes > minutes) {
 return 1;
 } else if (t.minutes < minutes) {
 return 2;
 } else if (t.seconds > seconds) {
 return 1;
 } else {
 return 2;
 }
 }
}
public class time {
 public static void main(String[] args) {
 Time s = new Time();
 Time t = new Time();
 System.out.print("Enter the first time (in 24 hours format) : ");
 s.read();
 System.out.print("Enter the second time (in 24 hours format) : ");
 t.read();
 int res = s.compare(t);
 if (res == 0)
 System.out.println("The 2 times are equal ");
 else if (res == 1)
 System.out.println("The second time is greater than the first time");
 else System.out.println("The first time is greater than the second time");
 System.out.println("The sum of the 2 times is " + s.add(t).hours + ":" + 
s.add(t).minutes + ":" + s.add(t).seconds);
 System.out.println("The difference of the 2 times is " + s.subtract(t).hours + ":" + 
s.subtract(t).minutes + ":" + s.subtract(t).seconds);
 }
}
OUTPUT : 
3) Consider the already defined Complex class. Provide a default constructor 
and parameterized constructor to this class. Also provide a display method. 
Illustrate all the constructors as well as the display method by defining 
Complex objects.
CODE :
import java.util.Scanner;
class Complex {
 int real, imag;
 Scanner sc = new Scanner(System.in);
 Complex() {
 real = 0;
 imag = 0;
 }
 Complex(int x, int y) {
 real = x;
 imag = y;
 }
 void read() {
 real = sc.nextInt();
 imag = sc.nextInt();
 }
 void display() {
 System.out.println("(" + real + ") +i(" + imag + ")");
 }
 Complex add(Complex b) {
 Complex c = new Complex();
 c.real = real + b.real;
 c.imag = imag + b.imag;
 return c;
 }
 Complex subtract(Complex b) {
 Complex c = new Complex();
 c.real = real - b.real;
 c.imag = imag - b.imag;
 return c;
 }
}
public class construct_complex {
 public static void main (String[] args) {
 Complex p = new Complex(); // default constructor invoked
 Complex q = new Complex(2, 3); // parameterized constructor invoked
 System.out.print("Complex number created by default constructor is : ");
 p.display();
 System.out.print("Complex number created by parameterized constructor is : ");
 q.display();
 System.out.print("Enter the first complex number : ");
 Complex a = new Complex();
 a.read();
 System.out.print("Enter the second complex number : ");
 Complex b = new Complex();
 b.read();
 System.out.print("The first complex number is : ");
 a.display();
 System.out.print("The second complex number is : ");
 b.display();
 System.out.print("The sum of these 2 complex numbers is : ");
 Complex c = a.add(b);
 c.display();
 System.out.print("The subtraction of these 2 complex numbers is : ");
 c = a.subtract(b);
 c.display();
 }
}
OUTPUT : 
4) Create a class called Counter that contains a static data member to count the 
number of Counter objects being created. Also define a static member function called 
showCount() which displays the number of objects created at any given point of time. 
Illustrate this.
CODE :
class Counter {
static int n = 0;
Counter() {
System.out.println("New object got created");
this.n++;
}
static void showCount() {
System.out.println("Number of Objects : " + n);
}
}
class testcount {
public static void main(String args[]) {
Counter a = new Counter();
Counter b = new Counter();
Counter.showCount();
Counter c = new Counter();
Counter.showCount();
}
}
OUTPUT :
**********
