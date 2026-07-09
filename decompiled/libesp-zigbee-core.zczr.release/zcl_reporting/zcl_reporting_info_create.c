/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_info_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_reporting_info_create
               (undefined1 param_1,undefined2 param_2,int param_3,undefined2 param_4,
               undefined1 param_5,undefined2 param_6,undefined2 param_7)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x38);
  if (puVar1 != (undefined1 *)0x0) {
    puVar1[1] = param_1;
    *puVar1 = (char)param_3;
    *(undefined2 *)(puVar1 + 4) = param_4;
    puVar1[8] = param_5;
    *(undefined2 *)(puVar1 + 6) = param_6;
    *(undefined2 *)(puVar1 + 2) = param_2;
    *(undefined2 *)(puVar1 + 0x30) = param_7;
    *(undefined4 *)(puVar1 + 0xc) = 0x7fffffff;
    puVar1[9] = 0;
    *(undefined4 *)(puVar1 + 0x34) = 0;
    if (param_3 == 0) {
      *(undefined4 *)(puVar1 + 0x28) = 5;
      *(undefined4 *)(puVar1 + 0x10) = 5;
    }
    else {
      *(undefined2 *)(puVar1 + 0x10) = 0;
    }
  }
  return;
}

