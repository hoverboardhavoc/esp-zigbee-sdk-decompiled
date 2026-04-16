/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> core_api.o -> ezb_core_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ezb_core_deinit(void)

{
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
  return;
}

