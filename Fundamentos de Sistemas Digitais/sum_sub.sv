module sum_sub #(parameter N = 4)
    (   input logic [N-1:0] A, B,
        input logic mode,
        output logic [N-1:0] Sum,
        output logic Cout,
        output logic ov
    );

   logic [N:0] carry; // vetor de N+1 bits para carregar Cin até Cout
   logic [N-1:0] bb;


   assign carry[0] = mode;

   // Geração de N instâncias de FA
   genvar i;
   generate
    for (i = 0; i < N; i++) begin 

        assign bb[i] = B[i] ^ mode;
        FA fa_inst (.a (A[i]), .b (bb[i]), .c (carry[i]), .sum (Sum[i]), .cout (carry[i+1]));
       end
   endgenerate

   assign Cout = carry[N];

   assign ov = carry[N] ^carry[N-1];

endmodule

