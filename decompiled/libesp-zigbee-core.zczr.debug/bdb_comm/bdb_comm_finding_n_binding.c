/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_finding_n_binding
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_finding_n_binding(void)

{
  int iVar1;
  
  iVar1 = bdb_comm_is_on_network();
  if (iVar1 == 0) {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xd4c) = 3;
  }
  else {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xd4c) = 9;
  }
  bdb_comm_finish_fnb_initiator();
  return;
}

