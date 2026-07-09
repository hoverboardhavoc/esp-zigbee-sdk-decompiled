/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cli_stop_fast_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void poll_control_cli_stop_fast_poll(undefined4 *param_1)

{
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined2 uStack_20;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_28 = *param_1;
  uStack_24 = param_1[1];
  _uStack_20 = CONCAT13(*(undefined1 *)((int)param_1 + 0x15),
                        CONCAT12(*(undefined1 *)(param_1 + 5),*(undefined2 *)(param_1 + 2)));
  ezb_zcl_poll_control_fast_poll_stop_cmd_req(&uStack_28);
  mm_free(param_1[9]);
  mm_free(param_1);
  return;
}

