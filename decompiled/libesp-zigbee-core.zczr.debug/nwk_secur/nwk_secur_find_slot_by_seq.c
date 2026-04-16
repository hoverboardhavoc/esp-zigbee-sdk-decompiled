/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_secur.o -> nwk_secur_find_slot_by_seq
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t nwk_secur_find_slot_by_seq(nwk_secur_context_t *secur_ctx,uint8_t key_seq)

{
  byte bVar1;
  undefined3 in_register_0000202d;
  uint uVar2;
  byte abStack_11 [4];
  bitmap_t valid_slots;
  
  abStack_11[0] = (byte)((uint)*(undefined4 *)(secur_ctx->material_set[1].key + 0xf) >> 0x1d) & 3;
  uVar2 = 0;
  while( true ) {
    bVar1 = bitmap_find_next_bit(abStack_11,2,uVar2);
    uVar2 = (uint)bVar1;
    if ((1 < uVar2) ||
       ((uint)secur_ctx->material_set[uVar2].key_seq == CONCAT31(in_register_0000202d,key_seq)))
    break;
    uVar2 = uVar2 + 1 & 0xff;
  }
  return bVar1;
}

