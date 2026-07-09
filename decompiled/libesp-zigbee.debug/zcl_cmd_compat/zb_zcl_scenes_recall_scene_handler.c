/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_scenes_recall_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_scenes_recall_scene_handler(undefined4 *param_1,code *param_2)

{
  undefined1 uVar1;
  undefined4 uStack_24;
  uint uStack_20;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0;
  uStack_24 = *param_1;
  uStack_20 = (uint)*(uint3 *)(param_1 + 3);
  uStack_1c = (uint)*(ushort *)(param_1 + 4);
  uStack_18 = param_1[5];
  if (param_2 != (code *)0x0) {
    (*param_2)(0x16,&uStack_24,param_2);
    uVar1 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 6) = uVar1;
  }
  return;
}

