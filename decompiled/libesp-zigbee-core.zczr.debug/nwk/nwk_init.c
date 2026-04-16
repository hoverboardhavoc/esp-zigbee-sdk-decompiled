/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

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

