/**************************************************************
    Fernando Moraes - 20/abril/2025
**************************************************************/

// ************************************************************
// MÓDULO EX4 — Acumulador com Soma de Dois Operandos
// ************************************************************

module ex4 #(
    parameter int N = 8
)(
    input  logic             clock,
    input  logic             reset,
    output logic [N-1:0]     saida
);

logic [N-1:0] opA; //operador A.
logic [N-1:0] opB; //operador B.
logic [N-1:0] soma; //saída do somador.

always_ff @(posedge clock or posedge reset)
begin
    if(reset == 1'b1)
        begin
            opA <= '0;
        end
    else
        begin
            opA <= opA + 1;
        end
end
always_ff @(posedge clock or posedge reset)
begin
    if (reset == 1'b1)
        begin
            opB <= '0;
        end
    else
        begin
            opB <= soma;
        end
end

assign soma = opA + opB;
assign saida = opB;

endmodule
