/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> secur_ic.o -> secur_ic_remove_stored_ic
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void secur_ic_remove_stored_ic(ezb_extaddr_t *addr)

{
  undefined1 auStack_30 [4];
  ds_ic_info_iterator_t itor;
  
  secur_ic_get_stored_ic(addr,(ds_ic_info_iterator_t *)auStack_30);
  ds_ic_info_delete((ds_ic_info_iterator_t *)auStack_30);
  return;
}

