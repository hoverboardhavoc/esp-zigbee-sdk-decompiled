/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> zb_cli_register_zdo_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void zb_cli_register_zdo_cmd(void)

{
  int iVar1;
  undefined *puStack_28;
  char *pcStack_24;
  undefined4 uStack_20;
  code *pcStack_1c;
  undefined4 *puStack_18;
  undefined4 uStack_14;
  
  zdo_args = arg_lit0(&_LC104,"match_desc","Send match descriptor request.");
  DAT_00014568 = arg_lit0(&_LC107,"simple_desc_req","send Simple Descriptor Request");
  DAT_0001456c = arg_str0(&_LC111,"active_ep","<active_ep>","Send Active Endpoint Request");
  DAT_00014570 = arg_str0(&_LC115,"nwk_addr","<nwk_addr>","get network address by EUI64");
  DAT_00014574 = arg_str0(&_LC119,"ieee_addr","<ieee_addr>","get ieee_addr by nwk_addr");
  DAT_00014578 = arg_lit0(&_LC122,"eui64","get EUI64 address of zigbee device");
  DAT_0001457c = arg_lit0(&_LC125,"short","Get the short 16-bit address of the Zigbee device.");
  DAT_00014580 = arg_lit0(&_LC128,"bind_on/bind_off",
                          "Create/Remove a binding between two endpoints on two nodes");
  DAT_00014584 = arg_str0(&_LC132,"mgmt_bind","<mgmt_bind>","get binding table");
  DAT_00014588 = arg_lit0(&_LC135,"leave","ask device to leave the network");
  DAT_0001458c = arg_lit0(&_LC138,&_LC137,"ask device to return its neighbor table");
  DAT_00014590 = arg_end(2);
  uStack_20 = 0;
  uStack_14 = 0;
  puStack_28 = &_LC139;
  pcStack_24 = "ZigBee zdo command";
  pcStack_1c = zb_cli_zdo_cmd_cb;
  puStack_18 = &zdo_args;
  iVar1 = esp_console_cmd_register(&puStack_28);
  if (iVar1 == 0) {
    return;
  }
  _esp_error_check_failed
            ("/home/xieqinan/ESP/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd_zdo.c",0x6ef,
             "zb_cli_register_zdo_cmd","esp_console_cmd_register(&zdo_cmd)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

