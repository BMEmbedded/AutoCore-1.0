module engine_position_detector(

    input clk,

    input crank_sensor,

    output reg [7:0] engine_position

);

reg [7:0] counter = 0;

reg [1:0] state = 0;

always @(posedge clk) begin

    case(state)

        0: begin

            if (crank_sensor == 1) begin

                counter <= 0;

                state <= 1;

            end

        end

        1: begin

            if (crank_sensor == 1) begin

                if (counter < 255) begin

                    counter <= counter + 1;

                end

            end else begin

                state <= 0;

                engine_position <= counter;

            end

        end

    endcase

end

endmodule

