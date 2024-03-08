/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
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
    esp_log_write(3,0x10000,&_LC7,uVar1,0x10000);
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log_write(3,0x10000,&_LC8,uVar1,0x10000);
  }
  return;
}

