/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_price_publish_tier_labels_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_price_publish_tier_labels_handler(undefined2 *param_1,code *param_2)

{
  undefined1 uVar1;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined2 uStack_18;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined4 uStack_14;
  
  uStack_26 = param_1[1];
  uStack_28 = *param_1;
  uStack_20 = *(undefined4 *)(param_1 + 8);
  uStack_16 = *(undefined1 *)(param_1 + 0xd);
  uStack_1c = *(undefined4 *)(param_1 + 10);
  uStack_24 = *(undefined4 *)(param_1 + 6);
  uStack_14 = *(undefined4 *)(param_1 + 0xe);
  uStack_18 = param_1[0xc];
  uStack_15 = 0;
  if (param_2 != (code *)0x0) {
    (*param_2)(0x50,&uStack_28);
    uVar1 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 0x10) = uVar1;
  }
  return;
}

