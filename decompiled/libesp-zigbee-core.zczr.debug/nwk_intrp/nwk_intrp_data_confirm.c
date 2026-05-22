/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_intrp.o -> nwk_intrp_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_intrp_data_confirm(nwk_intrp_data_cnf_t *cnf)

{
  log_write(3,"INTRP_NWK",">>>>>>>>>>>>>>>>>>>>");
  log_write(3,"INTRP_NWK",0x1031c,cnf->status);
  log_write(3,"INTRP_NWK","<<<<<<<<<<<<<<<<<<<<");
  zmsg_dump(3,"INTRP_NWK",cnf->nsdu);
  if (cnf->nsdu != (zmsg_t *)0x0) {
    zmsg_free();
  }
  return;
}

