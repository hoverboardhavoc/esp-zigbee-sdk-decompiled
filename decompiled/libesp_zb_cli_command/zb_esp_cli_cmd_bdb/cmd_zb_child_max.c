/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
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
        esp_log_write(1,0x10000,&_LC95,uVar2,0x10000);
      }
      else if (abStack_11[0] < 0x21) {
        if (m_default_role < 2) {
          zb_set_max_children();
          uVar2 = esp_log_timestamp();
          esp_log_write(3,0x10000,&_LC93,uVar2,0x10000,abStack_11[0]);
        }
        else {
          uVar2 = esp_log_timestamp();
          esp_log_write(3,0x10000,&_LC94,uVar2,0x10000);
        }
      }
      else {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_L0,uVar2,0x10000);
      }
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC13,uVar2,0x10000);
    }
  }
  return;
}

