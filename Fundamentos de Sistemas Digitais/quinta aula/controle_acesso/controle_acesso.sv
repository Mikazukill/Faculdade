/*
	Prof. Marlon Moraes
	marlon.moraes@pucrs.br
*/

`timescale 1ns/1ps

module controle_acesso (
    input  logic clk,
    input  logic rst,
    input  logic S1,
    input  logic S2,
    output logic [3:0] passageiros,
    output logic [6:0] vagas,
    output logic buzzer

    logic c1, c2;

    typedef enum logic[1:0]
    {
        IDLE,
        ENTR_A,
        ENTR_B,
        ENTR_C
    } nome_estados;

    nome_estados estado_atual;

    always_ff @(posedge clk or posedge rst)
    begin
        if(rst == 1'b1) begin 
            estado_atual <= IDLE;
        end
    end 
    else begin 
        case (estado_atual) 
            IDLE:
                if(S1 == 1'b1 && S2 == 1'b0)begin
                    estado_atual <= ENT_A
                end
                else begin
                    estado_atual <= IDLE;
                end
            
            ENT_A: begin
                if(S1 == 1'b1 && S2 == 1'b1) begin
                    estado_atual <= ENT_B
                end
                else begin
                    
                end
            end

            ENT_B: begin
                if(S1 == 1'b0 && S2 == 1'b1) begin
                    estado_atual <= ENT_C
                end
                else begin

                end
            end

            ENT_C:begin
                if((S1 == 1'b0) && (S2 == 1'b0) && (estado_atual == ENT_B)) begin
                    estado_atual <= IDLE
                end
                else begin
                    estado_atual <= 
                end
            end

            default:begin
                estado_atual <= IDLE;
            end

            SAI_A: begin
                if((S1 == 1'b0) && (S2 == 1'b1) && (estado_atual == IDLE)) begin
                    
                end
            end
            SAI_B:
            SAI_C:
        endcase
    end

);
    assign c1 = (estado_atual == ENT_C) ? 1'b1 : 1'b0;
    assign c2 = 1'b0
endmodule

module tb_controle_acesso;

    logic clk;
    logic rst;
    logic S1;
    logic S2;

    logic [3:0] passageiros;
    logic [6:0] vagas;
    logic buzzer;

    // DUT
    controle_acesso dut (
        .clk(clk),
        .rst(rst),
        .S1(S1),
        .S2(S2),
        .passageiros(passageiros),
        .vagas(vagas),
        .buzzer(buzzer)
    );

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end


    initial begin
        rst = 1;
        S1  = 0;
        S2  = 0;

        repeat(3) @(posedge clk);		// espera três bordas de subida do clk.
        rst = 0;
    end

    //---------------------------------
    // Tarefa: Entrada
    //---------------------------------
    task entrada;
    begin
        @(posedge clk);
        S1 <= 1;

        @(posedge clk);
        S2 <= 1;

        @(posedge clk);
        S1 <= 0;

        @(posedge clk);
        S2 <= 0;

        @(posedge clk);
    end
    endtask

    //---------------------------------
    // Tarefa: Saída
    //---------------------------------
    task saida;
    begin
        @(posedge clk);
        S2 <= 1;

        @(posedge clk);
        S1 <= 1;

        @(posedge clk);
        S2 <= 0;

        @(posedge clk);
        S1 <= 0;

        @(posedge clk);
    end
    endtask

    //---------------------------------
    // Tarefa: Passageiro parado
    //---------------------------------
    task sensor_travado_S1;
    begin
        @(posedge clk);
        S1 <= 1;

        repeat(6) @(posedge clk);

        S1 <= 0;

        @(posedge clk);
    end
    endtask


    // Monitor
    initial begin
        $monitor("T=%0t S1=%b S2=%b passageiros=%0d vagas=%0d buzzer=%b",
                  $time, S1, S2, passageiros, vagas, buzzer);
    end




    // Casos de teste
    initial begin

        wait(!rst);						// espera até o rst baixar.

        entrada();						// simula o comportamento de entrada.

        entrada();						// simula o comportamento de entrada.

        saida();						// simula o comportamento de saída.

        repeat(10)						// repete 10 vezes a entrada.
            entrada();

        sensor_travado_S1();			// simula sensor travado.

        #100;
        $display("SIMULACAO FINALIZADA");
        $finish;
    end

endmodule