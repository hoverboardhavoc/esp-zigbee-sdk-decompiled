/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

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

