/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_record_table_remove_by_next_hop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_route_record_table_remove_by_next_hop(ezb_shortaddr_t next_hop)

{
  undefined2 in_register_0000202a;
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = core_globals_get();
  uVar2 = 0;
  while( true ) {
    uVar2 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar1 + 0xcd8),*(undefined2 *)(iVar1 + 0xcdc),uVar2);
    if (*(ushort *)(iVar1 + 0xcdc) <= uVar2) break;
    iVar3 = *(int *)(iVar1 + 0xcd4) + uVar2 * 0x1c;
    if ((uint)*(ushort *)(iVar3 + (*(byte *)(iVar3 + 2) - 1) * 2 + 4) ==
        CONCAT22(in_register_0000202a,next_hop)) {
      mempool_free_idx(*(bitmap_t **)(iVar1 + 0xcd8),*(ushort *)(iVar1 + 0xcdc),(uint16_t)uVar2);
    }
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return;
}

