/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x6c,
                  "bind_dst_table_free","dst->ref_cnt == 0");
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

