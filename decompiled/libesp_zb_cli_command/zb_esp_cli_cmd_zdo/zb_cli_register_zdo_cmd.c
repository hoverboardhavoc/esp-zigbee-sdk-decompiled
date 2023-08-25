/*
 * Last changed at upstream commit 62f83e9155a8a668183e90087b29cd6791297d4c
 * https://github.com/espressif/esp-zigbee-sdk/commit/62f83e9155a8a668183e90087b29cd6791297d4c
 * Upstream date: 2023-08-25 15:56:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.1(b4845e06)
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
  
  zdo_args = arg_lit0(&_LC106,"match_desc","Send match descriptor request.");
  DAT_00014544 = arg_lit0(&_LC109,"simple_desc_req","send Simple Descriptor Request");
  DAT_00014548 = arg_str0(&_LC113,"active_ep","<active_ep>","Send Active Endpoint Request");
  DAT_0001454c = arg_str0(&_LC117,"nwk_addr","<nwk_addr>","get network address by EUI64");
  DAT_00014550 = arg_str0(&_LC121,"ieee_addr","<ieee_addr>","get ieee_addr by nwk_addr");
  DAT_00014554 = arg_lit0(&_LC124,"eui64","get EUI64 address of zigbee device");
  DAT_00014558 = arg_lit0(&_LC127,"short","Get the short 16-bit address of the Zigbee device.");
  DAT_0001455c = arg_lit0(&_LC130,"bind_on/bind_off",
                          "Create/Remove a binding between two endpoints on two nodes");
  DAT_00014560 = arg_str0(&_LC134,"mgmt_bind","<mgmt_bind>","get binding table");
  DAT_00014564 = arg_lit0(&_LC137,"leave","ask device to leave the network");
  DAT_00014568 = arg_lit0(&_LC140,&_LC139,"ask device to return its neighbor table");
  DAT_0001456c = arg_end(2);
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

