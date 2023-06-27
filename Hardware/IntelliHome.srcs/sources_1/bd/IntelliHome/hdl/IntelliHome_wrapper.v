//Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2017.4 (win64) Build 2086221 Fri Dec 15 20:55:39 MST 2017
//Date        : Wed May 31 17:55:30 2023
//Host        : DESKTOP-4QOUN6P running 64-bit major release  (build 9200)
//Command     : generate_target IntelliHome_wrapper.bd
//Design      : IntelliHome_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module IntelliHome_wrapper
   (DDR_addr,
    DDR_ba,
    DDR_cas_n,
    DDR_ck_n,
    DDR_ck_p,
    DDR_cke,
    DDR_cs_n,
    DDR_dm,
    DDR_dq,
    DDR_dqs_n,
    DDR_dqs_p,
    DDR_odt,
    DDR_ras_n,
    DDR_reset_n,
    DDR_we_n,
    ESP_RX,
    ESP_TX,
    FIXED_IO_ddr_vrn,
    FIXED_IO_ddr_vrp,
    FIXED_IO_mio,
    FIXED_IO_ps_clk,
    FIXED_IO_ps_porb,
    FIXED_IO_ps_srstb,
    GPIO_0_0_tri_io,
    IIC_0_TOF_scl_io,
    IIC_0_TOF_sda_io,
    IIC_1_RGB_scl_io,
    IIC_1_RGB_sda_io,
    servo_0,
    servo_1);
  inout [14:0]DDR_addr;
  inout [2:0]DDR_ba;
  inout DDR_cas_n;
  inout DDR_ck_n;
  inout DDR_ck_p;
  inout DDR_cke;
  inout DDR_cs_n;
  inout [3:0]DDR_dm;
  inout [31:0]DDR_dq;
  inout [3:0]DDR_dqs_n;
  inout [3:0]DDR_dqs_p;
  inout DDR_odt;
  inout DDR_ras_n;
  inout DDR_reset_n;
  inout DDR_we_n;
  output ESP_RX;
  input ESP_TX;
  inout FIXED_IO_ddr_vrn;
  inout FIXED_IO_ddr_vrp;
  inout [53:0]FIXED_IO_mio;
  inout FIXED_IO_ps_clk;
  inout FIXED_IO_ps_porb;
  inout FIXED_IO_ps_srstb;
  inout [5:0]GPIO_0_0_tri_io;
  inout IIC_0_TOF_scl_io;
  inout IIC_0_TOF_sda_io;
  inout IIC_1_RGB_scl_io;
  inout IIC_1_RGB_sda_io;
  output servo_0;
  output servo_1;

  wire [14:0]DDR_addr;
  wire [2:0]DDR_ba;
  wire DDR_cas_n;
  wire DDR_ck_n;
  wire DDR_ck_p;
  wire DDR_cke;
  wire DDR_cs_n;
  wire [3:0]DDR_dm;
  wire [31:0]DDR_dq;
  wire [3:0]DDR_dqs_n;
  wire [3:0]DDR_dqs_p;
  wire DDR_odt;
  wire DDR_ras_n;
  wire DDR_reset_n;
  wire DDR_we_n;
  wire ESP_RX;
  wire ESP_TX;
  wire FIXED_IO_ddr_vrn;
  wire FIXED_IO_ddr_vrp;
  wire [53:0]FIXED_IO_mio;
  wire FIXED_IO_ps_clk;
  wire FIXED_IO_ps_porb;
  wire FIXED_IO_ps_srstb;
  wire [0:0]GPIO_0_0_tri_i_0;
  wire [1:1]GPIO_0_0_tri_i_1;
  wire [2:2]GPIO_0_0_tri_i_2;
  wire [3:3]GPIO_0_0_tri_i_3;
  wire [4:4]GPIO_0_0_tri_i_4;
  wire [5:5]GPIO_0_0_tri_i_5;
  wire [0:0]GPIO_0_0_tri_io_0;
  wire [1:1]GPIO_0_0_tri_io_1;
  wire [2:2]GPIO_0_0_tri_io_2;
  wire [3:3]GPIO_0_0_tri_io_3;
  wire [4:4]GPIO_0_0_tri_io_4;
  wire [5:5]GPIO_0_0_tri_io_5;
  wire [0:0]GPIO_0_0_tri_o_0;
  wire [1:1]GPIO_0_0_tri_o_1;
  wire [2:2]GPIO_0_0_tri_o_2;
  wire [3:3]GPIO_0_0_tri_o_3;
  wire [4:4]GPIO_0_0_tri_o_4;
  wire [5:5]GPIO_0_0_tri_o_5;
  wire [0:0]GPIO_0_0_tri_t_0;
  wire [1:1]GPIO_0_0_tri_t_1;
  wire [2:2]GPIO_0_0_tri_t_2;
  wire [3:3]GPIO_0_0_tri_t_3;
  wire [4:4]GPIO_0_0_tri_t_4;
  wire [5:5]GPIO_0_0_tri_t_5;
  wire IIC_0_TOF_scl_i;
  wire IIC_0_TOF_scl_io;
  wire IIC_0_TOF_scl_o;
  wire IIC_0_TOF_scl_t;
  wire IIC_0_TOF_sda_i;
  wire IIC_0_TOF_sda_io;
  wire IIC_0_TOF_sda_o;
  wire IIC_0_TOF_sda_t;
  wire IIC_1_RGB_scl_i;
  wire IIC_1_RGB_scl_io;
  wire IIC_1_RGB_scl_o;
  wire IIC_1_RGB_scl_t;
  wire IIC_1_RGB_sda_i;
  wire IIC_1_RGB_sda_io;
  wire IIC_1_RGB_sda_o;
  wire IIC_1_RGB_sda_t;
  wire servo_0;
  wire servo_1;

  IOBUF GPIO_0_0_tri_iobuf_0
       (.I(GPIO_0_0_tri_o_0),
        .IO(GPIO_0_0_tri_io[0]),
        .O(GPIO_0_0_tri_i_0),
        .T(GPIO_0_0_tri_t_0));
  IOBUF GPIO_0_0_tri_iobuf_1
       (.I(GPIO_0_0_tri_o_1),
        .IO(GPIO_0_0_tri_io[1]),
        .O(GPIO_0_0_tri_i_1),
        .T(GPIO_0_0_tri_t_1));
  IOBUF GPIO_0_0_tri_iobuf_2
       (.I(GPIO_0_0_tri_o_2),
        .IO(GPIO_0_0_tri_io[2]),
        .O(GPIO_0_0_tri_i_2),
        .T(GPIO_0_0_tri_t_2));
  IOBUF GPIO_0_0_tri_iobuf_3
       (.I(GPIO_0_0_tri_o_3),
        .IO(GPIO_0_0_tri_io[3]),
        .O(GPIO_0_0_tri_i_3),
        .T(GPIO_0_0_tri_t_3));
  IOBUF GPIO_0_0_tri_iobuf_4
       (.I(GPIO_0_0_tri_o_4),
        .IO(GPIO_0_0_tri_io[4]),
        .O(GPIO_0_0_tri_i_4),
        .T(GPIO_0_0_tri_t_4));
  IOBUF GPIO_0_0_tri_iobuf_5
       (.I(GPIO_0_0_tri_o_5),
        .IO(GPIO_0_0_tri_io[5]),
        .O(GPIO_0_0_tri_i_5),
        .T(GPIO_0_0_tri_t_5));
  IOBUF IIC_0_TOF_scl_iobuf
       (.I(IIC_0_TOF_scl_o),
        .IO(IIC_0_TOF_scl_io),
        .O(IIC_0_TOF_scl_i),
        .T(IIC_0_TOF_scl_t));
  IOBUF IIC_0_TOF_sda_iobuf
       (.I(IIC_0_TOF_sda_o),
        .IO(IIC_0_TOF_sda_io),
        .O(IIC_0_TOF_sda_i),
        .T(IIC_0_TOF_sda_t));
  IOBUF IIC_1_RGB_scl_iobuf
       (.I(IIC_1_RGB_scl_o),
        .IO(IIC_1_RGB_scl_io),
        .O(IIC_1_RGB_scl_i),
        .T(IIC_1_RGB_scl_t));
  IOBUF IIC_1_RGB_sda_iobuf
       (.I(IIC_1_RGB_sda_o),
        .IO(IIC_1_RGB_sda_io),
        .O(IIC_1_RGB_sda_i),
        .T(IIC_1_RGB_sda_t));
  IntelliHome IntelliHome_i
       (.DDR_addr(DDR_addr),
        .DDR_ba(DDR_ba),
        .DDR_cas_n(DDR_cas_n),
        .DDR_ck_n(DDR_ck_n),
        .DDR_ck_p(DDR_ck_p),
        .DDR_cke(DDR_cke),
        .DDR_cs_n(DDR_cs_n),
        .DDR_dm(DDR_dm),
        .DDR_dq(DDR_dq),
        .DDR_dqs_n(DDR_dqs_n),
        .DDR_dqs_p(DDR_dqs_p),
        .DDR_odt(DDR_odt),
        .DDR_ras_n(DDR_ras_n),
        .DDR_reset_n(DDR_reset_n),
        .DDR_we_n(DDR_we_n),
        .ESP_RX(ESP_RX),
        .ESP_TX(ESP_TX),
        .FIXED_IO_ddr_vrn(FIXED_IO_ddr_vrn),
        .FIXED_IO_ddr_vrp(FIXED_IO_ddr_vrp),
        .FIXED_IO_mio(FIXED_IO_mio),
        .FIXED_IO_ps_clk(FIXED_IO_ps_clk),
        .FIXED_IO_ps_porb(FIXED_IO_ps_porb),
        .FIXED_IO_ps_srstb(FIXED_IO_ps_srstb),
        .GPIO_0_0_tri_i({GPIO_0_0_tri_i_5,GPIO_0_0_tri_i_4,GPIO_0_0_tri_i_3,GPIO_0_0_tri_i_2,GPIO_0_0_tri_i_1,GPIO_0_0_tri_i_0}),
        .GPIO_0_0_tri_o({GPIO_0_0_tri_o_5,GPIO_0_0_tri_o_4,GPIO_0_0_tri_o_3,GPIO_0_0_tri_o_2,GPIO_0_0_tri_o_1,GPIO_0_0_tri_o_0}),
        .GPIO_0_0_tri_t({GPIO_0_0_tri_t_5,GPIO_0_0_tri_t_4,GPIO_0_0_tri_t_3,GPIO_0_0_tri_t_2,GPIO_0_0_tri_t_1,GPIO_0_0_tri_t_0}),
        .IIC_0_TOF_scl_i(IIC_0_TOF_scl_i),
        .IIC_0_TOF_scl_o(IIC_0_TOF_scl_o),
        .IIC_0_TOF_scl_t(IIC_0_TOF_scl_t),
        .IIC_0_TOF_sda_i(IIC_0_TOF_sda_i),
        .IIC_0_TOF_sda_o(IIC_0_TOF_sda_o),
        .IIC_0_TOF_sda_t(IIC_0_TOF_sda_t),
        .IIC_1_RGB_scl_i(IIC_1_RGB_scl_i),
        .IIC_1_RGB_scl_o(IIC_1_RGB_scl_o),
        .IIC_1_RGB_scl_t(IIC_1_RGB_scl_t),
        .IIC_1_RGB_sda_i(IIC_1_RGB_sda_i),
        .IIC_1_RGB_sda_o(IIC_1_RGB_sda_o),
        .IIC_1_RGB_sda_t(IIC_1_RGB_sda_t),
        .servo_0(servo_0),
        .servo_1(servo_1));
endmodule
