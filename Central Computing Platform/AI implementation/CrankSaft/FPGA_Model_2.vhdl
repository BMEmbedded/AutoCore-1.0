module crank_shaft(

  input clk,           // Clock input

  input reset_n,       // Active low reset input

  input crank_signal,  // Crank signal input

  output reg result    // Output signal indicating position of crank shaft

);

// Define constants

parameter POS_THRESHOLD = 10;  // Threshold for positive edge detection

parameter NEG_THRESHOLD = -10; // Threshold for negative edge detection

parameter SAMPLE_WINDOW = 20;  // Number of samples to use for edge detection

// Define state variables

reg [15:0] sample_buffer;   // Buffer to store previous samples

reg [3:0] sample_index = 0; // Index into sample buffer

reg state = 0;              // State variable for state machine

reg prev_sample = 0;        // Previous sample value for edge detection

reg cur_sample = 0;         // Current sample value for edge detection

reg cur_pos_edge = 0;       // Current positive edge flag

reg prev_pos_edge = 0;      // Previous positive edge flag

reg cur_neg_edge = 0;       // Current negative edge flag

reg prev_neg_edge = 0;      // Previous negative edge flag

// Edge detection state machine

always @ (posedge clk) begin

  if (!reset_n) begin

    state <= 0; // Reset state machine

    sample_index <= 0; // Reset sample buffer index

    sample_buffer <= 0; // Reset sample buffer

  end

  else begin

    case (state)

      0: begin // Wait for rising edge

        prev_sample <= cur_sample;

        cur_sample <= crank_signal;

        sample_buffer[sample_index] <= crank_signal;

        sample_index <= sample_index + 1;

        if (sample_index == SAMPLE_WINDOW) begin

          state <= 1;

          prev_pos_edge <= 0;

          cur_pos_edge <= 0;

          prev_neg_edge <= 0;

          cur_neg_edge <= 0;

        end

      end

      1: begin // Detect edges

        prev_sample <= cur_sample;

        cur_sample <= crank_signal;

        sample_buffer[sample_index] <= crank_signal;

        sample_index <= sample_index + 1;

        if (sample_index == SAMPLE_WINDOW) begin

          cur_pos_edge <= (cur_sample - sample_buffer[0] > POS_THRESHOLD);

          cur_neg_edge <= (cur_sample - sample_buffer[0] < NEG_THRESHOLD);

          prev_pos_edge <= cur_pos_edge;

          prev_neg_edge <= cur_neg_edge;

          state <= 2;

        end

      end

      2: begin // Determine crank shaft position

        prev_sample <= cur_sample;

        cur_sample <= crank_signal;

        sample_buffer[sample_index] <= crank_signal;

        sample_index <= sample_index + 1;

        if (sample_index == SAMPLE_WINDOW) begin

          if (prev_pos_edge && !cur_pos_edge) begin // Positive edge

            if (prev_sample > 0 && cur_sample < 0) begin // Ensure valid edge

              result <= result + 1; // Increment position

            end

          end

          else if (prev_neg_edge && !cur_neg_edge) begin // Negative edge

            if (prev_sample < 0 && cur_sample > 0) begin // Ensure valid edge

              result <= result - 1; // Decrement position

            end

          end

          state <= 1; // Return to edge detection

        end

      end

    endcase

  end

end

endmodule

