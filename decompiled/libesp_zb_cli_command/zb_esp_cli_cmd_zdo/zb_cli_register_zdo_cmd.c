/*
 * Last changed at upstream commit 37b2129eea9960f95d70bf2e6607337834e2750d
 * https://github.com/espressif/esp-zigbee-sdk/commit/37b2129eea9960f95d70bf2e6607337834e2750d
 * Upstream date: 2023-10-10 17:40:24 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.0(8d71c0ae)
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
  undefined *puStack_24;
  char *pcStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 *puStack_14;
  
  zdo_args = arg_lit0(&_LC107,"match_desc","Send match descriptor request.");
  DAT_00014558 = arg_lit0(&_LC110,"simple_desc_req","send Simple Descriptor Request");
  DAT_0001455c = arg_str0(&_LC114,"active_ep","<active_ep>","Send Active Endpoint Request");
  DAT_00014560 = arg_str0(&_LC118,"nwk_addr","<nwk_addr>","get network address by EUI64");
  DAT_00014564 = arg_str0(&_LC122,"ieee_addr","<ieee_addr>","get ieee_addr by nwk_addr");
  DAT_00014568 = arg_lit0(&_LC125,"eui64","get EUI64 address of zigbee device");
  DAT_0001456c = arg_lit0(&_LC128,"short","Get the short 16-bit address of the Zigbee device.");
  DAT_00014570 = arg_lit0(&_LC131,"bind_on/bind_off",
                          "Create/Remove a binding between two endpoints on two nodes");
  DAT_00014574 = arg_str0(&_LC135,"mgmt_bind","<mgmt_bind>","get binding table");
  DAT_00014578 = arg_lit0(&_LC138,"leave","ask device to leave the network");
  DAT_0001457c = arg_lit0(&_LC141,&_LC140,"ask device to return its neighbor table");
  DAT_00014580 = arg_end(2);
  puStack_24 = &_LC0;
  pcStack_20 = "ZigBee zdo command";
  uStack_1c = 0;
  pcStack_18 = zb_cli_zdo_cmd_cb;
  puStack_14 = &zdo_args;
  iVar1 = esp_console_cmd_register(&puStack_24);
  if (iVar1 == 0) {
    return;
  }
  _esp_error_check_failed
            ("/home/xieqinan/ESP/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd_zdo.c",0x6ef,
             "zb_cli_register_zdo_cmd","esp_console_cmd_register(&zdo_cmd)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

