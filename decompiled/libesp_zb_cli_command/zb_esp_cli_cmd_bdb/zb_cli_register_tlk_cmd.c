/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> zb_cli_register_tlk_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void zb_cli_register_tlk_cmd(void)

{
  int iVar1;
  undefined *puStack_2c;
  char *pcStack_28;
  undefined4 uStack_24;
  code *pcStack_20;
  undefined4 *puStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  tlk_args = arg_lit0(&_LC127,"timeout","Configure Touchlink target timeout");
  DAT_00014854 = arg_lit0(&_LC115,"RSSI threshold","Configure RSSI threshold");
  DAT_00014858 = arg_lit0(&_LC158,"master key","Configure Touchlink target master key");
  DAT_0001485c = arg_end(0);
  uStack_24 = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  puStack_2c = &_LC177;
  pcStack_28 = "ZigBee touchlink command";
  pcStack_20 = zb_cli_tlk_cmd_cb;
  puStack_1c = &tlk_args;
  iVar1 = esp_console_cmd_register(&puStack_2c);
  if (iVar1 == 0) {
    return;
  }
  _esp_error_check_failed
            ("/home/xieqinan/ESP/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd_bdb.c",0x4f3,
             "zb_cli_register_tlk_cmd","esp_console_cmd_register(&tlk_cmd)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

