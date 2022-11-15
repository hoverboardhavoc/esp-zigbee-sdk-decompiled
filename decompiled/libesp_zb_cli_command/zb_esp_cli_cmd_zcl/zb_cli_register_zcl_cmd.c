/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
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
  undefined *puStack_24;
  char *pcStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 *puStack_14;
  
  zcl_args = arg_lit0(&_LC7,&_LC6,"Send a generic command to the remote node");
  DAT_000103b8 = arg_lit0(&_LC10,&_LC9,"Write/Read the attribute value to the remote node");
  DAT_000103bc = arg_lit0(&_LC13,"subscribe",
                          "Subscribe/Unsubscribe to the attribute changes on the remote node");
  DAT_000103c0 = arg_lit0(&_LC16,&_LC15,"Start the commissioning process");
  DAT_000103c4 = arg_end(4);
  puStack_24 = &_LC0;
  pcStack_20 = "ZigBee zcl command";
  uStack_1c = 0;
  pcStack_18 = zb_cli_zcl_cmd_cb;
  puStack_14 = &zcl_args;
  iVar1 = esp_console_cmd_register(&puStack_24);
  if (iVar1 == 0) {
    return;
  }
  _esp_error_check_failed
            ("/home/likunqiao/esp/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd_zcl.c",0x66,
             "zb_cli_register_zcl_cmd","esp_console_cmd_register(&zcl_cmd)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

