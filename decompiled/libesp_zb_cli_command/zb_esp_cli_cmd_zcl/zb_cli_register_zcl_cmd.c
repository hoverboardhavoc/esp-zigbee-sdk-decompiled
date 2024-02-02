/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl.o -> zb_cli_register_zcl_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void zb_cli_register_zcl_cmd(void)

{
  int iVar1;
  undefined *puStack_2c;
  char *pcStack_28;
  undefined4 uStack_24;
  code *pcStack_20;
  undefined4 *puStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  zcl_args = arg_lit0(&_LC4,&_LC3,"Send a generic command to the remote node");
  DAT_000103cc = arg_lit0(&_LC7,&_LC6,"Write/Read the attribute value to the remote node");
  DAT_000103d0 = arg_lit0(&_LC10,"subscribe",
                          "Subscribe/Unsubscribe to the attribute changes on the remote node");
  DAT_000103d4 = arg_lit0(&_LC13,&_LC12,"Start the commissioning process");
  DAT_000103d8 = arg_end(4);
  uStack_24 = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  puStack_2c = &_LC14;
  pcStack_28 = "ZigBee zcl command";
  pcStack_20 = zb_cli_zcl_cmd_cb;
  puStack_1c = &zcl_args;
  iVar1 = esp_console_cmd_register(&puStack_2c);
  if (iVar1 == 0) {
    return;
  }
  _esp_error_check_failed
            ("/home/xieqinan/ESP/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd_zcl.c",0x66,
             "zb_cli_register_zcl_cmd","esp_console_cmd_register(&zcl_cmd)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

