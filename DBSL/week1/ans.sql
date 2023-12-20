1.) create table EMPLOYEE(
emp_no number(5),
emp_name varchar(20),
emp_address varchar(30));

2.) 

insert into EMPLOYEE(emp_no, emp_name, emp_address) values(1, 'Manoj', 'Bengaluru');

insert into EMPLOYEE(emp_no, emp_name, emp_address) values(2, 'Anusha', 'Hyderabad');

insert into EMPLOYEE(emp_no, emp_name, emp_address) values(3, 'Sangeetha', 'Manipal');

insert into EMPLOYEE(emp_no, emp_name, emp_address) values(4, 'Nikhila', 'Mangalore');

insert into EMPLOYEE(emp_no, emp_name, emp_address) values(5, 'Shriraksha', 'Mangalore');

3.) Select * from employee;

4.) Select emp_name from employee where emp_address='Manipal';

5.) alter table employee add(salary number(4));

6.) Update employee set salary='100';

7.) desc EMPLOYEE;

8.) Delete from employee where emp_address='Mangalore';

9.) Rename employee to employee1;

10.) drop table employee1;
