/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_core.o -> zdo_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_confirm_handler(void *param_1,int *param_2)

{
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (((param_1 != (void *)0x0) && (param_2 != (int *)0x0)) && (*param_2 != 0)) {
    uStack_24 = (uint)*(byte *)((int)param_1 + 0x10);
    memcpy((void *)((int)&uStack_24 + 2),param_1,10);
    uStack_14 = *(undefined2 *)((int)param_1 + 0xe);
    uStack_18 = *(undefined4 *)((int)param_1 + 10);
    zmsg_read_bytes(*(undefined4 *)((int)param_1 + 0x14),0,1,(int)&uStack_24 + 1);
    (*(code *)*param_2)(&uStack_24,param_2[1],(code *)*param_2);
  }
  return;
}

