/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> aps_group_table_is_endpoint_in_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_group_table_is_endpoint_in_group(uint8_t endpoint,ezb_shortaddr_t group_addr)

{
  bool bVar1;
  undefined3 in_register_00002029;
  aps_group_t *paVar2;
  
  paVar2 = group_table_find(group_addr);
  if (paVar2 == (aps_group_t *)0x0) {
    bVar1 = false;
  }
  else {
    fence();
    fence();
    bVar1 = ((uint)paVar2->ep_in_grp[CONCAT31(in_register_00002029,endpoint) >> 3] &
            1 << (endpoint & 7)) != 0;
  }
  return bVar1;
}

