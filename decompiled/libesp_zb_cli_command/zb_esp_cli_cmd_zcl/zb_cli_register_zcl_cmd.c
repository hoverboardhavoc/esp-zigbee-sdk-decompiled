/*
 * Last changed at upstream commit a67793c7af0a02d983345915fecc5d8fce7a0945
 * https://github.com/espressif/esp-zigbee-sdk/commit/a67793c7af0a02d983345915fecc5d8fce7a0945
 * Upstream date: 2024-02-22 20:57:09 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.2(af7a8c4d)
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

