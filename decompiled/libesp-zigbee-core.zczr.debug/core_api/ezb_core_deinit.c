/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> core_api.o -> ezb_core_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

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

