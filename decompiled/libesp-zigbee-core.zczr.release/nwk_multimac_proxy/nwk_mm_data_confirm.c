/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac_proxy.o -> nwk_mm_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_mm_data_confirm(uint8_t iface_id,mac_data_cnf_t *cnf)

{
  undefined3 in_register_00002029;
  int iVar1;
  
  iVar1 = nwk_mm_iface_is_enabled();
  if (iVar1 != 0) {
    nwk_fwd_handle_data_confirm(CONCAT31(in_register_00002029,iface_id),cnf);
    return;
  }
  log_write(2,"nwk_multimac_proxy.c","MCPS-DATA.confirm from disabled iface[%d]");
  if ((cnf != (mac_data_cnf_t *)0x0) && (cnf->msdu != (zmsg_t *)0x0)) {
    zmsg_free();
    return;
  }
  return;
}

