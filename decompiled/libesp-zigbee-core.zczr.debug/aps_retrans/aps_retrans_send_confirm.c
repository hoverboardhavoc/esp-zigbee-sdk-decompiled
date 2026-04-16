/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_send_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_retrans_send_confirm(aps_retrans_ent_t *retrans,ezb_err_t error)

{
  int iVar1;
  zmsg_t *pzVar2;
  
  pzVar2 = retrans->tx_msg;
  retrans->tx_msg = (zmsg_t *)0x0;
  iVar1 = core_globals_get();
  aps_retrans_ent_delete((aps_tx_context_t *)(iVar1 + 0x38),retrans);
  aps_send_confirm(pzVar2,error);
  iVar1 = core_globals_get();
  tasklet_post(iVar1 + 0x38);
  return;
}

