/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> poll_control_cli_stop_fast_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void poll_control_cli_stop_fast_poll(void *param_1)

{
  undefined1 auStack_28 [10];
  undefined2 uStack_1e;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  memcpy(auStack_28,param_1,10);
  uStack_1e = *(undefined2 *)((int)param_1 + 0x14);
  ezb_zcl_poll_control_fast_poll_stop_cmd_req(auStack_28);
  mm_free(*(undefined4 *)((int)param_1 + 0x24));
  mm_free(param_1);
  return;
}

