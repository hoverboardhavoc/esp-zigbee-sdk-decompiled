/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
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
  
  zdo_args = arg_lit0(&_LC108,"match_desc","Send match descriptor request.");
  DAT_00014694 = arg_lit0(&_LC111,"simple_desc_req","send Simple Descriptor Request");
  DAT_00014698 = arg_str0(&_LC115,"active_ep","<active_ep>","Send Active Endpoint Request");
  DAT_0001469c = arg_str0(&_LC119,"nwk_addr","<nwk_addr>","get network address by EUI64");
  DAT_000146a0 = arg_str0(&_LC123,"ieee_addr","<ieee_addr>","get ieee_addr by nwk_addr");
  DAT_000146a4 = arg_lit0(&_LC126,"eui64","get EUI64 address of zigbee device");
  DAT_000146a8 = arg_lit0(&_LC129,"short","Get the short 16-bit address of the Zigbee device.");
  DAT_000146ac = arg_lit0(&_LC132,"bind_on/bind_off",
                          "Create/Remove a binding between two endpoints on two nodes");
  DAT_000146b0 = arg_str0(&_LC136,"mgmt_bind","<mgmt_bind>","get binding table");
  DAT_000146b4 = arg_lit0(&_LC139,"leave","ask device to leave the network");
  DAT_000146b8 = arg_lit0(&_LC142,&_LC141,"ask device to return its neighbor table");
  DAT_000146bc = arg_lit0(&_LC145,"announcement","ask device to send announcement");
  DAT_000146c0 = arg_end(2);
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
            ("/builds/thread_zigbee/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd_zdo.c",
             0x705,"zb_cli_register_zdo_cmd","esp_console_cmd_register(&zdo_cmd)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

