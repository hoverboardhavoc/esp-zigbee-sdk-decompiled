/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_remove_dst_all
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_bind_table_remove_dst_all(ezb_extaddr_t *dst_addr)

{
  aps_bind_dst_t *dst;
  undefined1 auStack_1c [4];
  ezb_address_t bind_dst_addr;
  
  auStack_1c[0] = '\x03';
  memcpy(auStack_1c + 2,dst_addr,8);
  while (dst = bind_table_find_dst((ezb_address_t *)auStack_1c,0xff), dst != (aps_bind_dst_t *)0x0)
  {
    bind_table_remove_dst(dst);
  }
  return;
}

