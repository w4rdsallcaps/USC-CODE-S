// Author: Kineth M Noval
// Course Schedule: Tues 7:30 AM -> 10:30 AM
// Filename: tb_nbit_ALU.v

`timescale 1ns/1ps

module tb_nbit_ALU;

    parameter n = 4;

    reg  [n-1:0] A, B;
    reg          CB_in;
    reg  [2:0]   Mode;
    wire [n-1:0] Result;
    wire         CB_out;

    integer pass_count = 0;
    integer fail_count = 0;

    nbit_ALU #(.n(n)) uut (
    .A(A), .B(B), .CB_in(CB_in), .Mode(Mode),
    .Result(Result), .CB_out(CB_out)
);

    task check(
        input [2:0]   m,
        input [n-1:0] a, b,
        input         cin,
        input [n-1:0] exp_r,
        input         exp_c
    );
    begin
        Mode = m; A = a; B = b; CB_in = cin;
        #10;
        if (Result === exp_r && CB_out === exp_c) begin
            pass_count = pass_count + 1;
            $display("PASS | t=%0t Mode=%b A=%b B=%b CBin=%b -> Result=%b CBout=%b",
                      $time, Mode, A, B, CB_in, Result, CB_out);
        end else begin
            fail_count = fail_count + 1;
            $display("FAIL | t=%0t Mode=%b A=%b B=%b CBin=%b -> Result=%b CBout=%b (expected %b, %b)",
                      $time, Mode, A, B, CB_in, Result, CB_out, exp_r, exp_c);
        end
    end
    endtask

    initial begin
 

        $display("========== n-bit ALU Test (n = %0d) ==========", n);

        // ---- 000: ADD with carry ----
        $display("--- ADD (000) ---");
        check(3'b000, 4'd3,  4'd2,  1'b0, 4'd5,  1'b0);   // 3+2 = 5
        check(3'b000, 4'd9,  4'd7,  1'b0, 4'd0,  1'b1);   // 9+7 = 16 -> carry
        check(3'b000, 4'd15, 4'd15, 1'b0, 4'd14, 1'b1);   // 15+15 = 30
        check(3'b000, 4'd5,  4'd3,  1'b1, 4'd9,  1'b0);   // 5+3+1 = 9

        // ---- 001: SUBTRACT with borrow ----
        $display("--- SUB (001) ---");
        check(3'b001, 4'd9,  4'd4,  1'b0, 4'd5,  1'b0);   // 9-4 = 5
        check(3'b001, 4'd4,  4'd9,  1'b0, 4'd11, 1'b1);   // 4-9 -> borrow
        check(3'b001, 4'd7,  4'd7,  1'b0, 4'd0,  1'b0);   // 7-7 = 0
        check(3'b001, 4'd8,  4'd3,  1'b1, 4'd4,  1'b0);   // 8-3-1 = 4
        check(3'b001, 4'd0,  4'd1,  1'b0, 4'd15, 1'b1);   // 0-1 -> borrow

        // ---- 010: AND ----
        $display("--- AND (010) ---");
        check(3'b010, 4'b1100, 4'b1010, 1'b0, 4'b1000, 1'b0);
        check(3'b010, 4'b1111, 4'b0101, 1'b0, 4'b0101, 1'b0);
        check(3'b010, 4'b0110, 4'b0011, 1'b0, 4'b0010, 1'b0);

        // ---- 011: OR ----
        $display("--- OR (011) ---");
        check(3'b011, 4'b1100, 4'b1010, 1'b0, 4'b1110, 1'b0);
        check(3'b011, 4'b0001, 4'b0100, 1'b0, 4'b0101, 1'b0);
        check(3'b011, 4'b0000, 4'b0000, 1'b0, 4'b0000, 1'b0);

        // ---- 100: XOR ----
        $display("--- XOR (100) ---");
        check(3'b100, 4'b1100, 4'b1010, 1'b0, 4'b0110, 1'b0);
        check(3'b100, 4'b1111, 4'b1111, 1'b0, 4'b0000, 1'b0);
        check(3'b100, 4'b0101, 4'b0011, 1'b0, 4'b0110, 1'b0);

        // ---- 101: Complement of A ----
        $display("--- NOT A (101) ---");
        check(3'b101, 4'b0000, 4'd0, 1'b0, 4'b1111, 1'b0);
        check(3'b101, 4'b1010, 4'd0, 1'b0, 4'b0101, 1'b0);
        check(3'b101, 4'b1111, 4'd0, 1'b0, 4'b0000, 1'b0);

        // ---- 110: Increment A ----
        $display("--- INC A (110) ---");
        check(3'b110, 4'd3,  4'd0, 1'b0, 4'd4,  1'b0);
        check(3'b110, 4'd9,  4'd0, 1'b0, 4'd10, 1'b0);
        check(3'b110, 4'd15, 4'd0, 1'b0, 4'd0,  1'b0);    

        // ---- 111: Decrement A ----
        $display("--- DEC A (111) ---");
        check(3'b111, 4'd5, 4'd0, 1'b0, 4'd4,  1'b0);
        check(3'b111, 4'd8, 4'd0, 1'b0, 4'd7,  1'b0);
        check(3'b111, 4'd0, 4'd0, 1'b0, 4'd15, 1'b0);     

        $display("==============================================");
        $display("Tests passed: %0d | Tests failed: %0d", pass_count, fail_count);
        $display("==============================================");
        $finish;
    end

endmodule