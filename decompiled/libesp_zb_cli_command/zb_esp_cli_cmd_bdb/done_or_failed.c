/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> done_or_failed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void done_or_failed(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(3,0x10000,&_LC1,uVar1,0x10000);
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log_write(3,0x10000,&_LC2,uVar1,0x10000);
  }
  return;
}

