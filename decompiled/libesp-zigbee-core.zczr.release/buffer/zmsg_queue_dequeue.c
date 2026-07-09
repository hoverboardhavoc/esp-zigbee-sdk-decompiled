/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_queue_dequeue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_queue_dequeue(int param_1,int *param_2)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  
  iVar4 = *param_2;
  if ((iVar4 != 0) && (piVar5 = (int *)param_2[1], piVar5 != (int *)0x0)) {
    *(int **)(iVar4 + 4) = piVar5;
    *piVar5 = iVar4;
    sVar1 = *(short *)(param_1 + 8);
    *param_2 = 0;
    param_2[1] = 0;
    *(short *)(param_1 + 8) = sVar1 + -1;
    return;
  }
  puVar3 = (undefined4 *)zmsg_get_next_chunk_part_0();
  iVar4 = micro_timer_get_now();
  puVar2 = (undefined4 *)*puVar3;
  while ((puVar2 != puVar3 && (-1 < iVar4 - puVar2[6]))) {
    puVar6 = (undefined4 *)puVar2[1];
    zmsg_queue_dequeue(puVar3,puVar2);
    if ((code *)puVar3[7] == (code *)0x0) {
      zmsg_free(puVar2);
    }
    else {
      (*(code *)puVar3[7])();
    }
    puVar2 = (undefined4 *)*puVar6;
  }
  puVar2 = (undefined4 *)*puVar3;
  if ((puVar3 != puVar2) && (puVar2 != (undefined4 *)0x0)) {
    micro_timer_fire_at(puVar3 + 3,puVar2[6]);
    return;
  }
  return;
}

