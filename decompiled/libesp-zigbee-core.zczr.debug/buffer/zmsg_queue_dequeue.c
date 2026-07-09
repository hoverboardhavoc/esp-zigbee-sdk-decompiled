/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_queue_dequeue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_queue_dequeue(int param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *param_2;
  if ((iVar3 != 0) && (piVar2 = (int *)param_2[1], piVar2 != (int *)0x0)) {
    *(int **)(iVar3 + 4) = piVar2;
    *piVar2 = iVar3;
    *param_2 = 0;
    param_2[1] = 0;
    *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + -1;
    return;
  }
  uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x1ed,
                        "zmsg_queue_dequeue","dlist_node_is_on_list(&msg->node)");
  zmsg_queue_dequeue();
  zmsg_free(uVar1);
  return;
}

