/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> radio_spinel_receive_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void radio_spinel_receive_done(undefined1 *param_1,byte *param_2)

{
  undefined1 *puStack_28;
  undefined1 uStack_24;
  byte bStack_23;
  undefined1 auStack_22 [2];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  byte bStack_18;
  byte bStack_17;
  byte bStack_16;
  
  memset(auStack_22,0,0x12);
  puStack_28 = param_1 + 1;
  uStack_24 = *param_1;
  uStack_20 = *(undefined4 *)(param_2 + 8);
  bStack_23 = param_2[2];
  bStack_18 = param_2[3];
  bStack_17 = param_2[4];
  bStack_16 = *param_2 & 1;
  uStack_1c = *(undefined4 *)(param_2 + 0xc);
  ezb_plat_radio_receive_done(&puStack_28,0);
  return;
}

