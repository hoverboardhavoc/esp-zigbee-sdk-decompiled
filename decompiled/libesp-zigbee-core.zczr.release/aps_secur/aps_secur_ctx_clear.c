/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_ctx_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_secur_ctx_clear(void)

{
  _Bool _Var1;
  undefined3 extraout_var;
  int iVar2;
  undefined2 auStack_12 [2];
  nwk_addr_ref_t ref;
  
  aps_secur_key_pair_set_clear();
  _Var1 = aps_secur_is_centralized();
  if (CONCAT31(extraout_var,_Var1) != 0) {
    iVar2 = core_globals_get();
    iVar2 = nwk_address_ref_by_extended(iVar2 + 0x9ac,auStack_12);
    if (iVar2 == 0) {
      nwk_address_unlock_ref(auStack_12[0]);
    }
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0x9ac) = 0;
    *(undefined1 *)(iVar2 + 0x9ad) = 0;
    *(undefined1 *)(iVar2 + 0x9ae) = 0;
    *(undefined1 *)(iVar2 + 0x9af) = 0;
    *(undefined1 *)(iVar2 + 0x9b0) = 0;
    *(undefined1 *)(iVar2 + 0x9b1) = 0;
    *(undefined1 *)(iVar2 + 0x9b2) = 0;
    *(undefined1 *)(iVar2 + 0x9b3) = 0;
  }
  return;
}

