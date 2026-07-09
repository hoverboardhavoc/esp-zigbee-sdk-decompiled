/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_tmque_enqueue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_tmque_enqueue(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_3 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x240,
                  "zmsg_tmque_enqueue","tmo_ms != 0");
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar2 = micro_timer_get_now();
    param_2[6] = param_3 * 1000 + iVar2;
    puVar1 = (undefined4 *)*param_1;
    while ((puVar1 != param_1 && (iVar2 = zmsg_timestamp_ge(puVar1,param_2), iVar2 == 0))) {
      puVar1 = (undefined4 *)*puVar1;
    }
  }
  puVar3 = (undefined4 *)puVar1[1];
  puVar1[1] = param_2;
  *param_2 = puVar1;
  param_2[1] = puVar3;
  *puVar3 = param_2;
  *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
  if (param_2 == (undefined4 *)*param_1) {
    micro_timer_fire_at(param_1 + 3,param_2[6]);
  }
  return;
}

