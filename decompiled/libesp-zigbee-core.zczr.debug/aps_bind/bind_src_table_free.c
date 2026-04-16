/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_src_table_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bind_src_table_free(aps_bind_src_t *src)

{
  _Bool _Var1;
  undefined3 extraout_var;
  int iVar2;
  size_t sVar3;
  void *blk_base;
  bitmap_t *blk_busy;
  
  _Var1 = bind_src_is_empty(src);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    __assert_func("//build/esp-zigbee/src/core/aps/aps_bind.c",99,"bind_src_table_free",
                  "bind_src_is_empty(src)");
  }
  else if (src->addr_ref == 0xffff) goto _L0;
  nwk_address_unlock_ref();
_L0:
  iVar2 = core_globals_get();
  blk_base = *(void **)(iVar2 + 0x968);
  iVar2 = core_globals_get();
  blk_busy = *(bitmap_t **)(iVar2 + 0x96c);
  sVar3 = bind_src_size();
  iVar2 = core_globals_get();
  mempool_free_ent(blk_base,blk_busy,(uint16_t)sVar3,*(uint16_t *)(iVar2 + 0x970),src);
  return;
}

