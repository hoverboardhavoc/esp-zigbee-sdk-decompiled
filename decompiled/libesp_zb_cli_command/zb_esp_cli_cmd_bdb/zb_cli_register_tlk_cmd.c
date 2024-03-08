/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
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
  uint unaff_s6;
  undefined *puStack_24;
  char *pcStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 *puStack_14;
  
  tlk_args = arg_lit0(&_LC133,"timeout","Configure Touchlink target timeout");
  DAT_00014830 = arg_lit0(&_LC121,"RSSI threshold","Configure RSSI threshold");
  DAT_00014834 = arg_lit0(&_LC164,"master key","Configure Touchlink target master key");
  DAT_00014838 = arg_end(0);
  puStack_24 = &_LC3;
  pcStack_20 = "ZigBee touchlink command";
  uStack_1c = 0;
  pcStack_18 = zb_cli_tlk_cmd_cb;
  puStack_14 = &tlk_args;
  iVar1 = esp_console_cmd_register(&puStack_24);
  if (iVar1 == 0) {
    return;
  }
  _esp_error_check_failed
            ("/home/xieqinan/ESP/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd_bdb.c",0x57a,
             "zb_cli_register_tlk_cmd","esp_console_cmd_register(&tlk_cmd)");
  if (unaff_s6 < 0x1482d) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

