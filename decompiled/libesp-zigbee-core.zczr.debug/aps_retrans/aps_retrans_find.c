/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

aps_retrans_ent_t *
aps_retrans_find(aps_tx_context_t *ctx,ezb_shortaddr_t dst_addr,uint8_t aps_cntr)

{
  undefined2 in_register_0000202e;
  undefined3 in_register_00002031;
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    uVar1 = bitmap_find_next_bit(ctx->ent_in_use,0x20,uVar1);
    uVar1 = uVar1 & 0xff;
    if (0x1f < uVar1) {
      return (aps_retrans_ent_t *)0x0;
    }
    if (((uint)ctx->ents[uVar1].aps_cntr == CONCAT31(in_register_00002031,aps_cntr)) &&
       ((uint)ctx->ents[uVar1].dst_addr == CONCAT22(in_register_0000202e,dst_addr))) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return ctx->ents + uVar1;
}

