/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_core.o -> zdo_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_confirm_handler(undefined2 *param_1,int *param_2)

{
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  if (((param_1 != (undefined2 *)0x0) && (param_2 != (int *)0x0)) && (*param_2 != 0)) {
    uStack_20 = *(undefined4 *)(param_1 + 1);
    uStack_1c = *(undefined4 *)(param_1 + 3);
    _uStack_24 = CONCAT22(*param_1,(ushort)*(byte *)(param_1 + 8));
    uStack_14 = param_1[7];
    uStack_18 = *(undefined4 *)(param_1 + 5);
    zmsg_read_bytes(*(undefined4 *)(param_1 + 10),0,1,(int)&uStack_24 + 1);
    (*(code *)*param_2)(&uStack_24,param_2[1],(code *)*param_2);
  }
  return;
}

