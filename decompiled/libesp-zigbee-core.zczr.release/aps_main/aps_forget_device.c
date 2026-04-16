/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_forget_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_forget_device(ezb_shortaddr_t short_addr,ezb_extaddr_t *ext_addr)

{
  undefined2 in_register_0000202a;
  int iVar1;
  
  aps_retrans_purge(CONCAT22(in_register_0000202a,short_addr));
  aps_bind_table_remove_dst_all(ext_addr);
  iVar1 = aps_secur_get_key_pair_by_addr(ext_addr);
  if (iVar1 != 0) {
    aps_secur_delete_key_pair();
    return;
  }
  return;
}

