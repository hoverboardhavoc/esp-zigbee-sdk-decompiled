/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> core_api.o -> ezb_core_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_core_init(void)

{
  int iVar1;
  ezb_err_t eVar2;
  
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
    eVar2 = 0;
  }
  else {
    eVar2 = 3;
  }
  return eVar2;
}

