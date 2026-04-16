/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_core.o -> aps_intrp_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_intrp_data_indication(aps_intrp_data_ind_t *ind)

{
  if (ind == (aps_intrp_data_ind_t *)0x0) {
    ind = (aps_intrp_data_ind_t *)__assert_func(0,0,0);
  }
  if (ind->profile_id == 0xc05e) {
    zcl_intrp_indication_handler();
  }
  zmsg_free(ind->asdu);
  return;
}

