/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_intrp.o -> nwk_intrp_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_intrp_data_indication(nwk_intrp_data_ind_t *ind)

{
  log_write(3,"INTRP_NWK",">>>>>>>>>>>>>>>>>>>>");
  log_write(3,"INTRP_NWK","NWK Rx Inter-PAN Frame: 0x%04x:%d->0x%04x:%d, lqi(%d), rssi(%d)",
            (ind->src_addr).u.short_addr,ind->src_panid,(ind->dst_addr).u.short_addr,ind->dst_panid,
            ind->lqi);
  log_write(3,"INTRP_NWK","<<<<<<<<<<<<<<<<<<<<");
  zmsg_dump(3,"INTRP_NWK",ind->nsdu);
  if (ind->nsdu != (zmsg_t *)0x0) {
    zmsg_free();
    return;
  }
  return;
}

