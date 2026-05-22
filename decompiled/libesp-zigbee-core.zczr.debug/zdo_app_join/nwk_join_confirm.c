/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> nwk_join_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_join_confirm(nwk_join_cnf_t *cnf)

{
  int iVar1;
  
  if (cnf->status == 0) {
    zdo_comm_perform_next_op();
  }
  else if ((cnf->join_method == '\0') || (cnf->join_method == '\x03')) {
    iVar1 = core_globals_get();
    *(ushort *)(iVar1 + 0xcc2) = *(ushort *)(iVar1 + 0xcc2) | 0x20;
    zdo_comm_perform_next_op();
  }
  else {
    zdo_comm_signal_comm_done(cnf->status | 0x200);
  }
  return;
}

