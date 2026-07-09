/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> compat.o -> esp_zb_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_init(void *param_1)

{
  undefined1 auStack_54 [16];
  char *pcStack_44;
  undefined1 auStack_40 [60];
  
  pcStack_44 = "zb_storage";
  memcpy(auStack_54,param_1,0x10);
  memcpy(auStack_40,s_platform_config,0x30);
  esp_zigbee_init(auStack_54);
  return;
}

