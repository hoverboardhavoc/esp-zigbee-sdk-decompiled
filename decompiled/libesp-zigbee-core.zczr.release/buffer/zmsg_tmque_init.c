/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_tmque_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_tmque_init(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined2 *)(param_1 + 8) = 0;
  micro_timer_init(param_1 + 0xc,zmsg_tmq_handle_timer,param_1);
  return;
}

