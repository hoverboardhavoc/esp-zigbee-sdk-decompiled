/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee.debug -> compat.o -> esp_zb_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_init(void *param_1)

{
  undefined1 auStack_54 [16];
  undefined *puStack_44;
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
  puStack_44 = &_L0;
  memcpy(auStack_54,param_1,0x10);
  uStack_40 = s_platform_config;
  uStack_3c = DAT_00010478;
  uStack_38 = DAT_0001047c;
  uStack_34 = DAT_00010480;
  uStack_30 = DAT_00010484;
  uStack_2c = DAT_00010488;
  uStack_28 = DAT_0001048c;
  uStack_24 = DAT_00010490;
  uStack_20 = DAT_00010494;
  uStack_1c = DAT_00010498;
  uStack_18 = DAT_0001049c;
  uStack_14 = DAT_000104a0;
  esp_zigbee_init(auStack_54);
  return;
}

