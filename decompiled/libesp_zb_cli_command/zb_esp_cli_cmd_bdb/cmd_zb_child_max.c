/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_child_max
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_child_max(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  byte abStack_11 [13];
  
  abStack_11[0] = 0xff;
  if (param_1 != 0) {
    if (m_stack_is_started == '\0') {
      iVar1 = parse_str_digit(abStack_11);
      if (iVar1 == 0) {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC46,uVar2,0x10000);
      }
      else if (abStack_11[0] < 0x21) {
        zb_set_max_children();
        uVar2 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC45,uVar2,0x10000,abStack_11[0]);
      }
      else {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_L0,uVar2,0x10000);
      }
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC22,uVar2,0x10000);
    }
  }
  return;
}

