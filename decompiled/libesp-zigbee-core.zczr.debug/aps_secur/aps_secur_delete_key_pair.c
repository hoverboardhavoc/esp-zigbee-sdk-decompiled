/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_delete_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_delete_key_pair(aps_device_key_pair_t *key_pair)

{
  int iVar1;
  void *blk_base;
  bitmap_t *blk_busy;
  
  aps_secur_remove_stored_key_pair(key_pair);
  iVar1 = core_globals_get();
  blk_base = *(void **)(iVar1 + 0x9a0);
  iVar1 = core_globals_get();
  blk_busy = *(bitmap_t **)(iVar1 + 0x9a4);
  iVar1 = core_globals_get();
  mempool_free_ent(blk_base,blk_busy,0x38,*(uint16_t *)(iVar1 + 0x9a8),key_pair);
  return;
}

