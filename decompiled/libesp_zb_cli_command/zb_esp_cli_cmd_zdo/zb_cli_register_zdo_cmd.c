/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
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
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 *puStack_14;
  
  zdo_args = arg_lit0(&_LC106,"match_desc","Send match descriptor request.");
  DAT_00014608 = arg_lit0(&_LC109,"simple_desc_req","send Simple Descriptor Request");
  DAT_0001460c = arg_str0(&_LC113,"active_ep","<active_ep>","Send Active Endpoint Request");
  DAT_00014610 = arg_str0(&_LC117,"nwk_addr","<nwk_addr>","get network address by EUI64");
  DAT_00014614 = arg_str0(&_LC121,"ieee_addr","<ieee_addr>","get ieee_addr by nwk_addr");
  DAT_00014618 = arg_lit0(&_LC124,"eui64","get EUI64 address of zigbee device");
  DAT_0001461c = arg_lit0(&_LC127,"short","Get the short 16-bit address of the Zigbee device.");
  DAT_00014620 = arg_lit0(&_LC130,"bind_on/bind_off",
                          "Create/Remove a binding between two endpoints on two nodes");
  DAT_00014624 = arg_str0(&_LC134,"mgmt_bind","<mgmt_bind>","get binding table");
  DAT_00014628 = arg_lit0(&_LC137,"leave","ask device to leave the network");
  DAT_0001462c = arg_lit0(&_LC140,&_LC139,"ask device to return its neighbor table");
  DAT_00014630 = arg_end(2);
  uStack_24 = 0x145b4;
  uStack_20 = 0x145b8;
  uStack_1c = 0;
  pcStack_18 = zb_cli_zdo_cmd_cb;
  puStack_14 = &zdo_args;
  iVar1 = esp_console_cmd_register(&uStack_24);
  if (iVar1 == 0) {
    return;
  }
  _esp_error_check_failed
            ("/home/likunqiao/esp/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd_zdo.c",0x6ef
             ,"zb_cli_register_zdo_cmd","esp_console_cmd_register(&zdo_cmd)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

