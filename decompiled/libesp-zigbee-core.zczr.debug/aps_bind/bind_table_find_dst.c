/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_table_find_dst
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

aps_bind_dst_t * bind_table_find_dst(ezb_address_t *dst_addr,uint8_t dst_ep)

{
  aps_bind_dst_t *dst;
  _Bool _Var1;
  int iVar2;
  undefined3 extraout_var;
  uint uVar3;
  
  iVar2 = core_globals_get();
  uVar3 = 0;
  while( true ) {
    uVar3 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar2 + 0x978),*(undefined2 *)(iVar2 + 0x97c),uVar3);
    if (*(ushort *)(iVar2 + 0x97c) <= uVar3) {
      return (aps_bind_dst_t *)0x0;
    }
    dst = (aps_bind_dst_t *)(*(int *)(iVar2 + 0x974) + uVar3 * 6);
    _Var1 = bind_dst_is_matched(dst,dst_addr,dst_ep);
    if (CONCAT31(extraout_var,_Var1) != 0) break;
    uVar3 = uVar3 + 1 & 0xffff;
  }
  return dst;
}

