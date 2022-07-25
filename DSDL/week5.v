LAB – 5


Exercises :

1. Design and simulate a combinational circuit with external gates and a 4 to 16 
decoder built using a decoder tree of 2 to 4 decoders to implement the functions 
below. F= ab’c + a’cd + bcd’ , G=acd’ + a’b’c and H=a’b’c’ + abc + a’cd 
Verilog code :
module dec2to4(x,y,e,f);
input x,y,e;
output [3:0]f;
reg [3:0]f;
always @ (x or y)
begin
f=0;
if(e==1)
begin
case({x,y})
0:f[0]=1;
1:f[1]=1;
2:f[2]=1;
3:f[3]=1;
endcase
end
end
endmodule
module l5q1(a,b,c,d,e,f,g,h);
input a,b,c,d,e;
output f,g,h;
wire [3:0]m;
wire [15:0]y;
dec2to4 stage0(a,b,e,m);
dec2to4 stage1(c,d,m[0],y[3:0]);
dec2to4 stage2(c,d,m[1],y[7:4]);
dec2to4 stage3(c,d,m[2],y[11:8]);
dec2to4 stage4(c,d,m[3],y[15:12]);
assign f=y[3]|y[6]|y[7]|y[10]|y[11]|y[14];
assign g=y[2]|y[3]|y[10]|y[14];
assign h=y[0]|y[1]|y[3]|y[7]|y[14]|y[15];
endmodule

2. Design and implement a full adder using 2 to 4 decoder(s) and other gates. 
Verilog code :
module dec2to4(x,y,e,f);
input x,y,e;
output [3:0]f;
reg [3:0]f;
always @ (x or y)
begin
f=0;
if(e==1)
begin
case({x,y})
0:f[0]=1;
1:f[1]=1;
2:f[2]=1;
3:f[3]=1;
endcase
end
end
endmodule
module l5q2(cin,x,y,s,cout);
input cin,x,y;
output s,cout;
wire [7:0]m;
dec2to4 stage1(x,y,~cin,m[3:0]);
dec2to4 stage2(x,y,cin,m[7:4]);
assign s=m[1]|m[2]|m[4]|m[7];
assign cout=m[3]|m[5]|m[6]|m[7];
endmodule

3. Design and simulate the circuit with 3 to 8 decoder(s) and external gates to 
implement the functions below. F(a, b, c, d)= Σm(2,4,7,9) G (a, b, c, d)= Σm 
(0,3,15) H(a, b, c, d)= Σm(0,2,10,12)
Verilog code :
module dec3to8(q,e,f);
input [2:0]q;
input e;
output [7:0]f;
integer k;
reg [7:0]f;
always @ (q or e)
begin
f=0;
if(e==1)
for(k=0;k<8;k=k+1)
if(q==k)
f[k]=1;
end
endmodule
module l5q3(a,b,c,d,F,G,H);
input a,b,c,d;
output F,G,H;
wire [2:0]q;
wire [15:0]y;
assign q={b,c,d};
dec3to8 stage1(q,~a,y[7:0]);
dec3to8 stage2(q,a,y[15:8]);
assign F=y[2]|y[4]|y[7]|y[9];
assign G=y[0]|y[3]|y[15];
assign H=y[0]|y[2]|y[10]|y[12];
endmodule

**********
