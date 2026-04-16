/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_dst_table_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bind_dst_table_free(aps_bind_dst_t *dst)

{
  int iVar1;
  void *blk_base;
  bitmap_t *blk_busy;
  
  if (dst->ref_cnt == '\0') {
    if (((*(ushort *)&dst->ref_cnt >> 8 & 1) != 0) || ((dst->field_0).extaddr.addr_ref == 0xffff))
    goto _L0;
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/aps/aps_bind.c",0x6c,"bind_dst_table_free",
                  "dst->ref_cnt == 0");
  }
  nwk_address_unlock_ref();
_L0:
  iVar1 = core_globals_get();
  blk_base = *(void **)(iVar1 + 0x974);
  iVar1 = core_globals_get();
  blk_busy = *(bitmap_t **)(iVar1 + 0x978);
  iVar1 = core_globals_get();
  mempool_free_ent(blk_base,blk_busy,6,*(uint16_t *)(iVar1 + 0x97c),dst);
  return;
}

