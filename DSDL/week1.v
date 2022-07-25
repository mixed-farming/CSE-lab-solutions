LAB 1

1) Write Verilog code to describe the following functions
f1 =ac’+bc+b’c’
f2 = (a+b’+c)(a+b+c’)(a’+b+c’)
Check whether f1 and f2 in question 1 are functionally equivalent or not.
Verilog code:
module lab1_1 (a,b,c,f1,f2);
input a,b,c;
output f1,f2;
assign f1 = (a&~c)|(b&c)|(~b&~c);
assign f2 = (a|~b|c)&(a|b|~c)&(~a|b|~c);
endmodule

Thus, f1 and f2 are functionally equivalent.

2) Simplify the following functions using K-map and implement the circuit using logic 
gates. Write
Verilog code and simulate the circuit
a) f(A,B,C,D) = Σm(1,3,4,9,10,12) + D(0,2,5,11)
b) f(A,B,C,D) = ΠM(6,9,10,11,12) + D(2,4,7,13)
Verilog code :
module lab1_2(A,B,C,D,f1,f2);
input A,B,C,D;
output f1,f2;
assign f1=(B&~C&~D)|(D&~B)|(C&~B);
assign f2=(~A|B|~C)&(~A|B|~D)&(A|~B|C)&(~B|C|D);
endmodule

3) Minimize the following expression using K-map and simulate using only NAND gates.
f(A,B,C,D)= πM(2,6,8,9,10,11,14)
Verilog code : 
module lab1_3(A,B,C,D,f);
input A,B,C,D;
output f;
wire g;
assign g = ~(~(A&(~(B&B)))&~(C&~(D&D)));
assign f=~(g&g);
endmodule

********
