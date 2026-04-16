/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_secur.o -> nwk_secur_set_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_secur_set_key(uint8_t *key,uint8_t key_seq)

{
  uint uVar1;
  uint8_t uVar2;
  int iVar3;
  undefined3 extraout_var;
  nwk_secur_context_t *secur_ctx;
  
  iVar3 = core_globals_get();
  secur_ctx = (nwk_secur_context_t *)(iVar3 + 0x9fc);
  uVar2 = nwk_secur_find_slot_by_seq(secur_ctx,key_seq);
  uVar1 = CONCAT31(extraout_var,uVar2);
  if (1 < uVar1) {
    uVar1 = *(byte *)(iVar3 + 0xa23) & 1 ^ 1;
  }
  *(byte *)(iVar3 + 0xa23) =
       (byte)(((1 << (uVar1 & 0x1f) | *(uint *)(iVar3 + 0xa20) >> 0x1d) & 3) << 5) |
       *(byte *)(iVar3 + 0xa23) & 0x9f;
  if (key == (uint8_t *)0x0) {
    random_crypto_fill_buffer(secur_ctx->material_set[0].key + (-uVar1 & 0x11),0x10);
  }
  else {
    memcpy(secur_ctx->material_set[0].key + (-uVar1 & 0x11),key,0x10);
  }
  *(uint8_t *)(iVar3 + uVar1 * 0x11 + 0xa10) = key_seq;
  return;
}

