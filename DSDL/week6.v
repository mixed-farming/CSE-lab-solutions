LAB – 6


Exercise : 

1. Write behavioral Verilog code for a negative edge triggered T FF with 
asynchronous active low reset.
Verilog code:
module l6q1(t,clock,reset,q);
input t,clock,reset;
output q;
reg q;
always@ (negedge clock or negedge reset)
begin 
if(!reset)
q<=0;
else 
case(t)
0:q<=q;
1:q<=~q;
endcase 
end
endmodule

2. Write behavioral Verilog code for a positive edge-triggered JK FF with 
synchronous active high reset.
Verilog code:
module l6q2(j,k,clock,reset,q);
input j,k,clock,reset;
output q;
reg q;
always@ (posedge clock)
begin
if(reset)
q<=0;
else 
case({j,k})
0:q<=q;
1:q<=0;
2:q<=1;
3:q<=~q;
endcase
end
endmodule

3. Design and simulate the following counters 
a) 4-bit ring counter.
Verilog code:
module ring(clk,q);
input clk;
output[3:0]q;
wire [1:0]count;
wire en=1;
bitcounter2 one(clk,count[1:0]);
d2to4 two(en,count[1:0],q[3:0]);
endmodule
module dff11(clk,d,q);
input clk,d;
output q;
reg q;
always@(posedge clk)
begin 
q=d;
end
endmodule
module d2to4(en,w,y);
input en;
input [1:0]w;
output [3:0]y;
reg [3:0]y;
always@(en or w)
begin
y=0;
if(en==1)
case(w)
0:y[3]=1;
1:y[2]=1;
2:y[1]=1;
3:y[0]=1;
endcase
end
endmodule
module bitcounter2(clk,q);
input clk;
output[1:0]q;
dff11 ffo(clk,q[1]^q[0],q[1]);
dff11 ff1(clk,~q[0],q[0]);
endmodule

b) 5 bit Johnson counter.
Verilog code:
module john(clk,q);
input clk;
output [4:0]q;
dff1 ffo(clk,~q[4],q[0]);
dff1 ff1(clk,q[0],q[1]);
dff1 ff2(clk,q[1],q[2]);
dff1 ff3(clk,q[2],q[3]);
dff1 ff4(clk,q[3],q[4]);
endmodule
module dff1(clk,d,q);
input clk,d;
output q;
reg q;
always@(posedge clk)
begin
q=d;
end
endmodule

**********
