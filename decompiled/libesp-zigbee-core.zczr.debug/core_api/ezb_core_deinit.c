/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> core_api.o -> ezb_core_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_core_deinit(void)

{
  int iVar1;
  
  iVar1 = core_globals_inited();
  if (iVar1 != 0) {
    bdb_comm_deinit();
    af_deinit();
    aps_deinit();
    nwk_deinit();
    mac_deinit();
    time_ticker_deinit();
    tm_sched_deinit();
    datasets_deinit();
    mempool_deinit();
    core_globals_deinit();
  }
  return;
}

