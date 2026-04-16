/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void af_data_confirm(aps_apsde_data_cnf_t *cnf)

{
  aps_apsde_data_cnf_t *cnf_00;
  
  if (cnf != (aps_apsde_data_cnf_t *)0x0) {
    af_data_schedule_cnf_cb(cnf);
    zmsg_free(cnf->asdu);
    return;
  }
  cnf_00 = (aps_apsde_data_cnf_t *)
           __assert_func("//build/esp-zigbee/src/core/af/af_core.c",0xc4,"af_data_confirm",0x10000);
  af_data_confirm(cnf_00);
  return;
}

