/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> custom.o -> ezb_zcl_custom_cluster_handlers_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zcl_custom_cluster_handlers_register(undefined2 *param_1)

{
  undefined4 uVar1;
  undefined2 uStack_24;
  undefined1 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (param_1 == (undefined2 *)0x0) {
    uVar1 = 2;
  }
  else {
    uStack_24 = *param_1;
    uStack_22 = *(undefined1 *)(param_1 + 1);
    uStack_20 = *(undefined4 *)(param_1 + 2);
    uStack_1c = *(undefined4 *)(param_1 + 4);
    uStack_18 = *(undefined4 *)(param_1 + 6);
    uStack_14 = *(undefined4 *)(param_1 + 8);
    uVar1 = zcl_cluster_template_add(&uStack_24);
  }
  return uVar1;
}

