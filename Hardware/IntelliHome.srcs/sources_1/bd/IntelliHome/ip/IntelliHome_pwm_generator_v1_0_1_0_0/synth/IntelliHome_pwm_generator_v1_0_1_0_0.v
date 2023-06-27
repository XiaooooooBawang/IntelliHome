// (c) Copyright 1995-2023 Xilinx, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 
// DO NOT MODIFY THIS FILE.


// IP VLNV: xilinx.com:module_ref:pwm_generator_v1_0_1:1.0
// IP Revision: 1

(* X_CORE_INFO = "pwm_generator_v1_0_1,Vivado 2017.4" *)
(* CHECK_LICENSE_TYPE = "IntelliHome_pwm_generator_v1_0_1_0_0,pwm_generator_v1_0_1,{}" *)
(* CORE_GENERATION_INFO = "IntelliHome_pwm_generator_v1_0_1_0_0,pwm_generator_v1_0_1,{x_ipProduct=Vivado 2017.4,x_ipVendor=xilinx.com,x_ipLibrary=module_ref,x_ipName=pwm_generator_v1_0_1,x_ipVersion=1.0,x_ipCoreRevision=1,x_ipLanguage=VERILOG,x_ipSimLanguage=MIXED,C_S01_AXI_DATA_WIDTH=32,C_S01_AXI_ADDR_WIDTH=4}" *)
(* DowngradeIPIdentifiedWarnings = "yes" *)
module IntelliHome_pwm_generator_v1_0_1_0_0 (
  pwm_out,
  S01_axi_aclk,
  S01_axi_aresetn,
  S01_axi_awaddr,
  S01_axi_awprot,
  S01_axi_awvalid,
  S01_axi_awready,
  S01_axi_wdata,
  S01_axi_wstrb,
  S01_axi_wvalid,
  S01_axi_wready,
  S01_axi_bresp,
  S01_axi_bvalid,
  S01_axi_bready,
  S01_axi_araddr,
  S01_axi_arprot,
  S01_axi_arvalid,
  S01_axi_arready,
  S01_axi_rdata,
  S01_axi_rresp,
  S01_axi_rvalid,
  S01_axi_rready
);

output wire pwm_out;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S01_axi_aclk, ASSOCIATED_BUSIF S01_axi, ASSOCIATED_RESET S01_axi_aresetn, FREQ_HZ 100000000, PHASE 0.000, CLK_DOMAIN IntelliHome_processing_system7_0_0_FCLK_CLK0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 S01_axi_aclk CLK" *)
input wire S01_axi_aclk;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S01_axi_aresetn, POLARITY ACTIVE_LOW" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:reset:1.0 S01_axi_aresetn RST" *)
input wire S01_axi_aresetn;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi AWADDR" *)
input wire [3 : 0] S01_axi_awaddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi AWPROT" *)
input wire [2 : 0] S01_axi_awprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi AWVALID" *)
input wire S01_axi_awvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi AWREADY" *)
output wire S01_axi_awready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi WDATA" *)
input wire [31 : 0] S01_axi_wdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi WSTRB" *)
input wire [3 : 0] S01_axi_wstrb;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi WVALID" *)
input wire S01_axi_wvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi WREADY" *)
output wire S01_axi_wready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi BRESP" *)
output wire [1 : 0] S01_axi_bresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi BVALID" *)
output wire S01_axi_bvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi BREADY" *)
input wire S01_axi_bready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi ARADDR" *)
input wire [3 : 0] S01_axi_araddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi ARPROT" *)
input wire [2 : 0] S01_axi_arprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi ARVALID" *)
input wire S01_axi_arvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi ARREADY" *)
output wire S01_axi_arready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi RDATA" *)
output wire [31 : 0] S01_axi_rdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi RRESP" *)
output wire [1 : 0] S01_axi_rresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi RVALID" *)
output wire S01_axi_rvalid;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S01_axi, DATA_WIDTH 32, PROTOCOL AXI4LITE, FREQ_HZ 100000000, ID_WIDTH 0, ADDR_WIDTH 4, AWUSER_WIDTH 0, ARUSER_WIDTH 0, WUSER_WIDTH 0, RUSER_WIDTH 0, BUSER_WIDTH 0, READ_WRITE_MODE READ_WRITE, HAS_BURST 0, HAS_LOCK 0, HAS_PROT 1, HAS_CACHE 0, HAS_QOS 0, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 0, NUM_READ_OUTSTANDING 1, NUM_WRITE_OUTSTANDING 1, MAX_BURST_LENGTH 1, PHASE 0.000, CLK_DOMAIN IntelliHome_processing_system7_0_0_FCLK_CLK0, NUM_READ_THREADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_axi RREADY" *)
input wire S01_axi_rready;

  pwm_generator_v1_0_1 #(
    .C_S01_AXI_DATA_WIDTH(32),
    .C_S01_AXI_ADDR_WIDTH(4)
  ) inst (
    .pwm_out(pwm_out),
    .S01_axi_aclk(S01_axi_aclk),
    .S01_axi_aresetn(S01_axi_aresetn),
    .S01_axi_awaddr(S01_axi_awaddr),
    .S01_axi_awprot(S01_axi_awprot),
    .S01_axi_awvalid(S01_axi_awvalid),
    .S01_axi_awready(S01_axi_awready),
    .S01_axi_wdata(S01_axi_wdata),
    .S01_axi_wstrb(S01_axi_wstrb),
    .S01_axi_wvalid(S01_axi_wvalid),
    .S01_axi_wready(S01_axi_wready),
    .S01_axi_bresp(S01_axi_bresp),
    .S01_axi_bvalid(S01_axi_bvalid),
    .S01_axi_bready(S01_axi_bready),
    .S01_axi_araddr(S01_axi_araddr),
    .S01_axi_arprot(S01_axi_arprot),
    .S01_axi_arvalid(S01_axi_arvalid),
    .S01_axi_arready(S01_axi_arready),
    .S01_axi_rdata(S01_axi_rdata),
    .S01_axi_rresp(S01_axi_rresp),
    .S01_axi_rvalid(S01_axi_rvalid),
    .S01_axi_rready(S01_axi_rready)
  );
endmodule
