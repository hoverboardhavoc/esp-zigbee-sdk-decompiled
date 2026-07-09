/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_log.o -> ezb_plat_log
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_plat_log(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (param_1 == 1) {
    uStack_18 = param_3;
    uStack_14 = param_4;
    uStack_10 = param_5;
    uStack_c = param_6;
    uStack_8 = param_7;
    uStack_4 = param_8;
    uVar1 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar1,0x10000);
    esp_log_writev(1,0x10000,param_2,&uStack_18);
    esp_log_write(1,0x10000,&_LC2);
  }
  return;
}

