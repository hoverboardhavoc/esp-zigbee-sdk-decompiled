/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> ha_compat.o -> esp_zb_on_off_light_ep_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_on_off_light_ep_create(undefined1 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  
  uVar1 = esp_zb_ep_list_create();
  uStack_18 = CONCAT31(0x10400,param_1);
  uVar2 = esp_zb_on_off_light_clusters_create(param_2);
  esp_zb_ep_list_add_ep(uVar1,uVar2,uStack_18,0x100);
  return uVar1;
}

