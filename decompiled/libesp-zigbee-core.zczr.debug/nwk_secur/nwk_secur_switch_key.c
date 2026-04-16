/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_secur.o -> nwk_secur_switch_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_secur_switch_key(uint8_t key_seq)

{
  byte bVar1;
  int iVar2;
  undefined3 extraout_var;
  ezb_err_t eVar3;
  
  iVar2 = core_globals_get();
  bVar1 = nwk_secur_find_slot_by_seq((nwk_secur_context_t *)(iVar2 + 0x9fc),key_seq);
  if (CONCAT31(extraout_var,bVar1) < 2) {
    *(byte *)(iVar2 + 0xa23) = bVar1 & 1 | *(byte *)(iVar2 + 0xa23) & 0xfe;
    *(uint8_t *)(iVar2 + 0xa22) = key_seq;
    if (0x80000000 < *(uint *)(iVar2 + 0x9fc)) {
      *(undefined4 *)(iVar2 + 0x9fc) = 0;
    }
    ds_save_common_data();
    eVar3 = 0;
  }
  else {
    eVar3 = 5;
  }
  return eVar3;
}

