/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee.release -> compat.o -> esp_zb_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_init(void *param_1)

{
  undefined1 auStack_54 [16];
  undefined *puStack_44;
  undefined1 auStack_40 [60];
  
  puStack_44 = &_LC0;
  memcpy(auStack_54,param_1,0x10);
  memcpy(auStack_40,s_platform_config,0x30);
  esp_zigbee_init(auStack_54);
  return;
}

