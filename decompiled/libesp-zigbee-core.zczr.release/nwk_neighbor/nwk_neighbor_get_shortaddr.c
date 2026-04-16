/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_get_shortaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ezb_shortaddr_t nwk_neighbor_get_shortaddr(nwk_neighbor_t *nbr)

{
  undefined1 uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 extraout_a1;
  undefined4 uVar4;
  
  uVar4 = 0;
  iVar2 = __assert_func(0,0,0);
  uVar1 = nwk_calculate_lqa_raw(extraout_a1,uVar4);
  pvVar3 = memmove((void *)(iVar2 + 3),(void *)(iVar2 + 2),2);
  *(undefined1 *)(iVar2 + 2) = uVar1;
  *(char *)(iVar2 + 5) = (char)uVar4;
  return (ezb_shortaddr_t)pvVar3;
}

