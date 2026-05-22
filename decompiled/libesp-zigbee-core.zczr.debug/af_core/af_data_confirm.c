/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_core.c",0xc4,
                         "af_data_confirm",0x10000);
  af_data_confirm(cnf_00);
  return;
}

