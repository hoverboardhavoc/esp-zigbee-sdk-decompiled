/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_custom_cluster_handlers_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_custom_cluster_handlers_update(uint3 *param_1)

{
  uint3 uVar1;
  uint uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined *puStack_14;
  
  uVar1 = *param_1;
  zcl_cluster_template_remove((short)*param_1,*(undefined1 *)((int)param_1 + 2));
  uStack_18 = 0;
  uStack_24 = (uint)uVar1;
  uStack_20 = *(undefined4 *)(param_1 + 1);
  uStack_1c = *(undefined4 *)(param_1 + 2);
  puStack_14 = &zb_zcl_custom_cluster_cmd_handler;
  ezb_zcl_custom_cluster_handlers_register(&uStack_24);
  esp_zigbee_err_to_esp();
  return;
}

