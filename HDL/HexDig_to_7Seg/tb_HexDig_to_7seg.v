// Author: Kineth M Noval
// Course Schedule: Tuesday 7:30 AM -> 10:30 AM
// Filename: tb_HexDig_to_7seg.v


`timescale 1ns / 1ps

module tb_HexDig_to_7seg;
    reg [3:0] Hex;
    reg DP;
    wire [7:0] SSeg;
    integer i;

    HexDig_to_7seg uut (
        .Hex(Hex), 
        .DP(DP), 
        .SSeg(SSeg)
    );

    initial begin
        $display("Time\t Hex\t DP\t SSeg (DP G F E D C B A)");
        $monitor("%0t\t %h\t %b\t %b", $time, Hex, DP, SSeg);

        DP = 0;
        for (i = 0; i < 16; i = i + 1) begin
            Hex = i;
            #10;
        end

        DP = 1;
        for (i = 0; i < 16; i = i + 1) begin
            Hex = i;
            #10;
        end
        
        $finish;
    end
	 
endmodule
