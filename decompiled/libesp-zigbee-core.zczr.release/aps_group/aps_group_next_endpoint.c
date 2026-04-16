/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> aps_group_next_endpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t aps_group_next_endpoint(aps_group_t *group,uint8_t start_ep)

{
  uint8_t uVar1;
  undefined3 in_register_0000202d;
  
  uVar1 = bitmap_find_next_bit(group->ep_in_grp,0xff,CONCAT31(in_register_0000202d,start_ep));
  return uVar1;
}

