/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_remove_src
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_bind_table_remove_src(ezb_extaddr_t *src_addr,uint8_t src_ep,uint16_t cluster_id)

{
  uint uVar1;
  aps_bind_src_t *src;
  int iVar2;
  uint uVar3;
  
  src = bind_table_find_src(src_addr,src_ep,cluster_id);
  if (src != (aps_bind_src_t *)0x0) {
    uVar1 = 0;
    while( true ) {
      iVar2 = core_globals_get();
      uVar3 = bitmap_find_next_bit(src + 1,*(undefined2 *)(iVar2 + 0x97c),uVar1);
      iVar2 = core_globals_get();
      if (*(ushort *)(iVar2 + 0x97c) <= uVar3) break;
      iVar2 = core_globals_get();
      uVar1 = uVar3 + 1 & 0xffff;
      bind_table_unbind(src,(aps_bind_dst_t *)(*(int *)(iVar2 + 0x974) + uVar3 * 6));
    }
  }
  return;
}

