/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_eui64
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_eui64(void)

{
  undefined4 uVar1;
  undefined1 auStack_18 [5];
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  zb_get_long_address(auStack_18);
  uVar1 = esp_log_timestamp();
  esp_log_write(3,&_LC0,&_L0,uVar1,&_LC0,uStack_11,uStack_12,uStack_13);
  uVar1 = esp_log_timestamp();
  esp_log_write(3,&_LC0,&_LC4,uVar1,&_LC0);
  return;
}

