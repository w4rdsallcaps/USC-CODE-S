`timescale 1 ns / 1 ps
module tb_temp ();
    reg [3:0]    I;
    wire            O;
    
    temp UUT (I, O);
    
    initial begin
        $display("All possible inputs");
        I = 4'b0000;    #5
        I = 4'b0001;    #5
        I = 4'b0010;    #5
        I = 4'b0011;    #5
        I = 4'b0100;    #5
        I = 4'b0101;    #5
        I = 4'b0110;    #5
        I = 4'b0111;    #5
        I = 4'b1000;    #5
        I = 4'b1001;    #5
        I = 4'b1010;    #5
        I = 4'b1011;    #5
        I = 4'b1100;    #5
        I = 4'b1101;    #5
        I = 4'b1110;    #5
        I = 4'b1111;    #5
        $display("Test finished at %2d ns", $time);        
        $stop;
    end
    
    initial begin
        $monitor("%4b = %1b", I, O);
    end
    
    
endmodule