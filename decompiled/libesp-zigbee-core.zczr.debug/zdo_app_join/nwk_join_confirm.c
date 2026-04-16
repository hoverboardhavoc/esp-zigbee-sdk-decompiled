/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
    *(ushort *)(iVar1 + 0xd26) = *(ushort *)(iVar1 + 0xd26) | 0x20;
    zdo_comm_perform_next_op();
  }
  else {
    zdo_comm_signal_comm_done(cnf->status | 0x200);
  }
  return;
}

