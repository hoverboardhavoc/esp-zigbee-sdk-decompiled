/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_price_get_tier_labels_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_price_get_tier_labels_handler(undefined2 *param_1,code *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  
  uStack_2a = param_1[1];
  uStack_2c = *param_1;
  uStack_28 = *(undefined4 *)(param_1 + 6);
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  iStack_14 = 0;
  if (param_2 != (code *)0x0) {
    (*param_2)(0x4d,&uStack_2c,param_2);
  }
  iVar2 = iStack_14;
  cVar1 = (char)uStack_18;
  if (((char)uStack_18 == '\0') || (iStack_14 == 0)) {
    *(undefined1 *)(param_1 + 8) = 0x8b;
  }
  else {
    *(undefined1 *)(param_1 + 8) = 0;
    puVar3 = (undefined4 *)calloc(1,0x14);
    *(undefined4 **)(param_1 + 10) = puVar3;
    *(char *)((int)puVar3 + 0xe) = cVar1;
    *puVar3 = uStack_24;
    puVar3[4] = iVar2;
    *(undefined4 **)(param_1 + 0xe) = puVar3;
    puVar3[1] = uStack_20;
    puVar3[2] = uStack_1c;
    *(undefined2 *)(puVar3 + 3) = 0x100;
    *(code **)(param_1 + 0xc) = free_memory_in_data_cnf;
  }
  return;
}

