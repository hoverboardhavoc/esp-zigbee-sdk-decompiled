/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
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
  esp_log_write(3,&_LC3,&_L0,uVar1,&_LC3,uStack_11,uStack_12,uStack_13);
  uVar1 = esp_log_timestamp();
  esp_log_write(3,&_LC3,&_LC7,uVar1,&_LC3);
  return;
}

