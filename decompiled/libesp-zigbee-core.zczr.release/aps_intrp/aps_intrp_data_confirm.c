/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_intrp.o -> aps_intrp_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_intrp_data_confirm(aps_intrp_data_cnf_t *cnf)

{
  log_write(3,"aps_intrp.c",">>>>>>>>>>>>>>>>>>>>");
  log_write(3,"aps_intrp.c",
            "Tx Inter-PAN Frame Done (0x%02x): 0x%04x, profile(0x%04x) cluster(0x%04x)",cnf->status,
            (cnf->dst_addr).u.short_addr,cnf->cluster_id,cnf->profile_id);
  log_write(3,"aps_intrp.c","<<<<<<<<<<<<<<<<<<<<");
  if (cnf->asdu != (zmsg_t *)0x0) {
    zmsg_free();
    return;
  }
  return;
}

