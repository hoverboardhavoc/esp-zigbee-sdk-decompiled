/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_price_get_tier_labels_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_price_get_tier_labels_handler(undefined4 *param_1,code *param_2)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  iStack_14 = 0;
  uStack_2c = *param_1;
  uStack_28 = param_1[3];
  if (param_2 != (code *)0x0) {
    (*param_2)(0x4d,&uStack_2c,param_2);
    uVar1 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 4) = uVar1;
  }
  if (((char)uStack_18 == '\0') || (iStack_14 == 0)) {
    *(undefined1 *)(param_1 + 4) = 0x8b;
  }
  else {
    *(undefined1 *)(param_1 + 4) = 0;
    puVar2 = (undefined4 *)calloc(1,0x14);
    param_1[5] = puVar2;
    *puVar2 = uStack_24;
    puVar2[1] = uStack_20;
    puVar2[2] = uStack_1c;
    *(undefined1 *)(puVar2 + 3) = 0;
    *(undefined1 *)((int)puVar2 + 0xd) = 1;
    *(char *)((int)puVar2 + 0xe) = (char)uStack_18;
    puVar2[4] = iStack_14;
    param_1[6] = free_memory_in_data_cnf;
    param_1[7] = puVar2;
  }
  return;
}

