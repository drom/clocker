
module top (
  input      [7:0] d0, d1, d2,
  output reg [7:0] q0, q1, q2,
  input clk0, clk1, clk2, reset_n
);

always @ (posedge clk0 or negedge reset_n) if (~reset_n) q0 <= 0; else q0 <= d0;
always @ (posedge clk1 or negedge reset_n) if (~reset_n) q1 <= 0; else q1 <= d1;
always @ (posedge clk2 or negedge reset_n) if (~reset_n) q2 <= 0; else q2 <= d2;

endmodule
