module controlador
(
	input	logic 			sensor_ns,
	input	logic			sensor_lo,
	input	logic	[1:0]	modo,
	output	logic	[2:0]	nsLD,
	output	logic	[2:0]	loLD,
	output	logic			som
);

logic [2:0] cmd;

always_comb

	begin

		case (modo)
		
		2'b01 :

			cmd = 3'b100;

		2'b10 :

			cmd = 3'b101;

		2'b11 :

			cmd = 3'b110;

		default :

			begin
				case({sensor_ns,sensor_lo})
					
					2'b00:
						cmd = 3'b000;
					2'b10:
						cmd = 3'b001;
					2'b01:
						cmd = 3'b010;
					default:
						cmd = 3'b011;

				endcase

			end

		endcase
	end

	assign nsLD[2] = ~cmd[2] & (~cmd[1]|cmd[0]); //verde
	assign nsLD[1] = cmd[2] & cmd[1] & ~cmd[0]; //amarelo
	assign nsLD[0] = cmd[2] & ~cmd[1] | ~cmd[2] & cmd[1] & ~cmd [0]; //vermelho

	assign loLD[2] = ~cmd[2] & cmd[1] & ~cmd[0]; //verde
	assign loLD[1] = cmd[2] & cmd[1] & ~cmd[0]; //amarelo
	assign loLD[0] = ~cmd[1] | ~cmd[2] & cmd[0]; //vermelho

	assign som = cmd[2] & ~cmd[1] & ~cmd[0]; //som
	
endmodule