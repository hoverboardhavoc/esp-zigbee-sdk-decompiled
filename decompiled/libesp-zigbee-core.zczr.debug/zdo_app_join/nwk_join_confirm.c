/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> nwk_join_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_join_confirm(byte *param_1)

{
  int iVar1;
  
  if (*param_1 == 0) {
    zdo_comm_perform_next_op();
  }
  else if ((param_1[1] == 0) || (param_1[1] == 3)) {
    iVar1 = core_globals_get();
    *(ushort *)(iVar1 + 0xcc2) = *(ushort *)(iVar1 + 0xcc2) | 0x20;
    zdo_comm_perform_next_op();
  }
  else {
    zdo_comm_signal_comm_done(*param_1 | 0x200);
  }
  return;
}

