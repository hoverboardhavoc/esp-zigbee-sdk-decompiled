/*
 * Last changed at upstream commit d7e241034cb0adc2116988a320badb285c391de3
 * https://github.com/espressif/esp-zigbee-sdk/commit/d7e241034cb0adc2116988a320badb285c391de3
 * Upstream date: 2024-02-06 17:30:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.1(0cd72dc5)
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
  undefined *puStack_2c;
  char *pcStack_28;
  undefined4 uStack_24;
  code *pcStack_20;
  undefined4 *puStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  zdo_args = arg_lit0(&_LC105,"match_desc","Send match descriptor request.");
  DAT_00014670 = arg_lit0(&_LC108,"simple_desc_req","send Simple Descriptor Request");
  DAT_00014674 = arg_str0(&_LC112,"active_ep","<active_ep>","Send Active Endpoint Request");
  DAT_00014678 = arg_str0(&_LC116,"nwk_addr","<nwk_addr>","get network address by EUI64");
  DAT_0001467c = arg_str0(&_LC120,"ieee_addr","<ieee_addr>","get ieee_addr by nwk_addr");
  DAT_00014680 = arg_lit0(&_LC123,"eui64","get EUI64 address of zigbee device");
  DAT_00014684 = arg_lit0(&_LC126,"short","Get the short 16-bit address of the Zigbee device.");
  DAT_00014688 = arg_lit0(&_LC129,"bind_on/bind_off",
                          "Create/Remove a binding between two endpoints on two nodes");
  DAT_0001468c = arg_str0(&_LC133,"mgmt_bind","<mgmt_bind>","get binding table");
  DAT_00014690 = arg_lit0(&_LC136,"leave","ask device to leave the network");
  DAT_00014694 = arg_lit0(&_LC139,&_LC138,"ask device to return its neighbor table");
  DAT_00014698 = arg_lit0(&_LC142,"announcement","ask device to send announcement");
  DAT_0001469c = arg_end(2);
  uStack_24 = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  puStack_2c = &_LC143;
  pcStack_28 = "ZigBee zdo command";
  pcStack_20 = zb_cli_zdo_cmd_cb;
  puStack_1c = &zdo_args;
  iVar1 = esp_console_cmd_register(&puStack_2c);
  if (iVar1 == 0) {
    return;
  }
  _esp_error_check_failed
            ("/home/xiaqilin/esp/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd_zdo.c",0x705,
             "zb_cli_register_zdo_cmd","esp_console_cmd_register(&zdo_cmd)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

