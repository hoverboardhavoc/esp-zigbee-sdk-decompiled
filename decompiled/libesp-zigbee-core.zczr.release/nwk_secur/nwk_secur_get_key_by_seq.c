/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_secur.o -> nwk_secur_get_key_by_seq
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t * nwk_secur_get_key_by_seq(uint8_t key_seq)

{
  uint8_t uVar1;
  int iVar2;
  undefined3 extraout_var;
  uint8_t *puVar3;
  
  iVar2 = core_globals_get();
  uVar1 = nwk_secur_find_slot_by_seq((nwk_secur_context_t *)(iVar2 + 0x9fc),key_seq);
  if (CONCAT31(extraout_var,uVar1) < 2) {
    puVar3 = ((nwk_secur_context_t *)(iVar2 + 0x9fc))->material_set[0].key +
             (-CONCAT31(extraout_var,uVar1) & 0x11);
  }
  else {
    puVar3 = (uint8_t *)0x0;
  }
  return puVar3;
}

