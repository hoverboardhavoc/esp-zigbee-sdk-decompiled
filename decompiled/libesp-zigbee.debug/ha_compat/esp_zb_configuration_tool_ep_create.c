/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> ha_compat.o -> esp_zb_configuration_tool_ep_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_configuration_tool_ep_create(ushort param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  
  uVar1 = esp_zb_ep_list_create();
  uStack_18 = CONCAT22(0x104,param_1 & 0xff);
  uVar2 = esp_zb_configuration_tool_clusters_create(param_2);
  esp_zb_ep_list_add_ep(uVar1,uVar2,uStack_18,5);
  return uVar1;
}

