/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_tmque_dequeue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_tmque_dequeue(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  if ((param_2 == (int *)*param_1) && ((param_1 == param_2 || (param_2 != (int *)param_1[1])))) {
    micro_timer_fire_at(param_1 + 3,*(undefined4 *)(*param_2 + 0x18));
  }
  iVar3 = *param_2;
  if ((iVar3 != 0) && (piVar4 = (int *)param_2[1], piVar4 != (int *)0x0)) {
    *(int **)(iVar3 + 4) = piVar4;
    *piVar4 = iVar3;
    iVar3 = param_1[2];
    *param_2 = 0;
    param_2[1] = 0;
    *(short *)(param_1 + 2) = (short)iVar3 + -1;
    return;
  }
  puVar2 = (undefined4 *)zmsg_get_next_chunk_part_0();
  iVar3 = micro_timer_get_now();
  puVar1 = (undefined4 *)*puVar2;
  while ((puVar1 != puVar2 && (-1 < iVar3 - puVar1[6]))) {
    puVar5 = (undefined4 *)puVar1[1];
    zmsg_queue_dequeue(puVar2,puVar1);
    if ((code *)puVar2[7] == (code *)0x0) {
      zmsg_free(puVar1);
    }
    else {
      (*(code *)puVar2[7])();
    }
    puVar1 = (undefined4 *)*puVar5;
  }
  puVar1 = (undefined4 *)*puVar2;
  if ((puVar2 != puVar1) && (puVar1 != (undefined4 *)0x0)) {
    micro_timer_fire_at(puVar2 + 3,puVar1[6]);
    return;
  }
  return;
}

