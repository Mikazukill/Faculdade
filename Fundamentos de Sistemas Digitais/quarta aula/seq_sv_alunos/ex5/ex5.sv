/**************************************************************
    Fernando Moraes - 20/abril/2025
**************************************************************/

// ************************************************************
// MÓDULO EX5 — Registradores com multiplexadores condicionais
// ************************************************************

module ex5 (
    
    input logic [7:0]  X,
    input logic        SA,
    input logic        enableA,
    input logic [7:0]  Y,
    input logic        SB,
    input logic        enableB,
    input logic        reset,
    input logic        clock,
    output logic       RB
);

    logic [7:0] xmux;
    logic [7:0] ymux;
    logic [7:0] regA;
    logic [7:0] regB;

    assign xmux = SA ? X : regB;

    always_comb

        begin

            if(SA)

                begin
                    xmux = X;
                end

            else

                begin
                    xmux = regB;
                end

        end

endmodule