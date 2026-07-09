/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_init(void)

{
  random_init();
  nwk_pib_reset();
  nwk_secur_init();
  nwk_address_init(0x40);
  nwk_neighbor_table_init(0x40);
  nwk_neighbor_table_set_ed_capacity(0x14);
  nwk_route_table_init(0x40);
  nwk_route_disc_table_init(0x20);
  nwk_route_record_table_init(0x40);
  nwk_mm_enable_interface(0);
  nwk_fwd_init();
  nwk_dev_ctx_init();
  return;
}

