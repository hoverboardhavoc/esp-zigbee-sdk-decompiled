/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> core_api.o -> ezb_core_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_core_init(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = core_globals_inited();
  if (iVar1 == 0) {
    core_globals_init();
    mempool_init();
    datasets_init();
    tm_sched_init();
    time_ticker_init();
    ezb_plat_crypto_init();
    mac_init();
    nwk_init();
    aps_init();
    af_init();
    bdb_comm_init();
    uVar2 = 0;
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}

