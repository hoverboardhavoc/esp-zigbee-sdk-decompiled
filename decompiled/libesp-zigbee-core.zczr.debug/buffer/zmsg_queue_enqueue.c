/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_queue_enqueue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_queue_enqueue(int param_1,int *param_2)

{
  int *extraout_a1;
  undefined4 *puVar1;
  
  if ((*param_2 != 0) && (param_2[1] != 0)) {
    param_1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x1e6,
                            "zmsg_queue_enqueue","!dlist_node_is_on_list(&msg->node)");
    param_2 = extraout_a1;
  }
  puVar1 = *(undefined4 **)(param_1 + 4);
  *(int **)(param_1 + 4) = param_2;
  *param_2 = param_1;
  param_2[1] = (int)puVar1;
  *puVar1 = param_2;
  *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + 1;
  return;
}

