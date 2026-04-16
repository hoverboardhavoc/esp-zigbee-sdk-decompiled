/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_lock_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_address_lock_ref(nwk_addr_ref_t ref)

{
  undefined2 in_register_0000202a;
  int iVar1;
  int iVar2;
  
  iVar1 = core_globals_get();
  do_lock_ref((nwk_addr_table_t *)(iVar1 + 0xcb0),ref);
  iVar2 = *(int *)(iVar1 + 0xcb4) + CONCAT22(in_register_0000202a,ref) * 0x10;
  if ((*(byte *)(iVar2 + 0xf) & 4) != 0) {
    do_lock_ref((nwk_addr_table_t *)(iVar1 + 0xcb0),*(nwk_addr_ref_t *)(iVar2 + 0xc));
  }
  return;
}

