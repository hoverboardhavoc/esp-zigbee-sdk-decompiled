/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_deinit(void)

{
  time_ticker_unregister_receiver(1);
  nwk_dev_ctx_deinit();
  nwk_fwd_deinit();
  nwk_mm_disable_interface(0);
  nwk_route_table_deinit();
  nwk_route_disc_table_deinit();
  nwk_route_record_table_deinit();
  nwk_neighbor_table_deinit();
  nwk_address_deinit();
  random_deinit();
  return;
}

