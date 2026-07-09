/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_zcl_attr_list_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 * esp_zb_zcl_attr_list_create(undefined2 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)calloc(1,0x14);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = param_1;
    puVar1 = puVar1 + 6;
  }
  return puVar1;
}

