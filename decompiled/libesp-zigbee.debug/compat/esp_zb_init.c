/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> compat.o -> esp_zb_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_init(void *param_1)

{
  undefined1 auStack_54 [16];
  char *pcStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  memset(auStack_54,0,0x44);
  pcStack_44 = "zb_storage";
  memcpy(auStack_54,param_1,0x10);
  uStack_40 = s_platform_config;
  uStack_3c = DAT_00010480;
  uStack_38 = DAT_00010484;
  uStack_34 = DAT_00010488;
  uStack_30 = DAT_0001048c;
  uStack_2c = DAT_00010490;
  uStack_28 = DAT_00010494;
  uStack_24 = DAT_00010498;
  uStack_20 = DAT_0001049c;
  uStack_1c = DAT_000104a0;
  uStack_18 = DAT_000104a4;
  uStack_14 = DAT_000104a8;
  esp_zigbee_init(auStack_54);
  return;
}

