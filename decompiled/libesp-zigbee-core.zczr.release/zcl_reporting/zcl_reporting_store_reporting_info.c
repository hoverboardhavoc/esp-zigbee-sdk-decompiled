/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_store_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_reporting_store_reporting_info(char *param_1)

{
  undefined4 uStack_2c;
  undefined2 uStack_28;
  char cStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 auStack_19 [17];
  
  memset(&uStack_2c,0,0x1b);
  zcl_reporting_remove_stored_reporting_info(param_1);
  uStack_28 = *(undefined2 *)(param_1 + 4);
  uStack_2c = *(undefined4 *)param_1;
  cStack_26 = param_1[8];
  uStack_25 = (undefined1)*(undefined2 *)(param_1 + 6);
  uStack_24 = (undefined1)((ushort)*(undefined2 *)(param_1 + 6) >> 8);
  uStack_23 = (undefined1)*(undefined4 *)(param_1 + 0x30);
  uStack_22 = (undefined1)((uint)*(undefined4 *)(param_1 + 0x30) >> 8);
  uStack_21 = (undefined1)*(undefined2 *)(param_1 + 0x10);
  uStack_20 = (undefined1)((ushort)*(undefined2 *)(param_1 + 0x10) >> 8);
  if (*param_1 == '\0') {
    uStack_1f = (undefined1)*(undefined2 *)(param_1 + 0x12);
    uStack_1e = (undefined1)((ushort)*(undefined2 *)(param_1 + 0x12) >> 8);
    uStack_1d = (undefined1)*(undefined4 *)(param_1 + 0x28);
    uStack_1c = (undefined1)((uint)*(undefined4 *)(param_1 + 0x28) >> 8);
    uStack_1b = (undefined1)*(undefined2 *)(param_1 + 0x2a);
    uStack_1a = (undefined1)((ushort)*(undefined2 *)(param_1 + 0x2a) >> 8);
    memcpy(auStack_19,param_1 + 0x18,8);
  }
  ds_internal_add_entry(10,&uStack_2c,0x1b);
  return;
}

