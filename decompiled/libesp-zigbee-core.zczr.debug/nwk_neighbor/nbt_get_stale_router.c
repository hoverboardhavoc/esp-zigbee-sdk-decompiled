/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_get_stale_router
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nbt_get_stale_router(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar1 = (uint)*(ushort *)(param_1 + 2) - (uint)*(ushort *)((int)param_1 + 10) & 0xffff;
  uVar2 = 0;
  while (uVar2 = bitmap_find_next_bit(*param_1,uVar1,uVar2), uVar2 < uVar1) {
    iVar5 = uVar2 * 0x1c + param_1[1];
    uVar4 = *(uint *)(iVar5 + 0xc) & 3;
    if (((uVar4 == 0) || (uVar4 == 1)) && ((*(uint *)(iVar5 + 0xc) & 0x1c0003c0) == 0x80)) goto _L0;
    uVar2 = uVar2 + 1 & 0xffff;
  }
  uVar4 = 0xffff;
  uVar3 = 0;
  uVar2 = uVar1;
  while (uVar3 = bitmap_find_next_bit(*param_1,uVar1,uVar3), uVar3 < uVar1) {
    iVar5 = param_1[1] + uVar3 * 0x1c;
    uVar6 = *(uint *)(iVar5 + 0xc) & 3;
    if (((uVar6 == 0) || (uVar6 == 1)) &&
       (((*(uint *)(iVar5 + 0xc) & 0x3c0) == 0x80 &&
        ((10 < *(ushort *)(iVar5 + 0x12) && (uVar6 = nwk_neighbor_get_router_rank(), uVar6 < uVar4))
        )))) {
      uVar2 = uVar3;
      uVar4 = uVar6;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  }
  if (uVar2 != uVar1) {
    iVar5 = param_1[1] + uVar2 * 0x1c;
_L0:
    if (iVar5 == 0) {
      return 0;
    }
    if ((*(uint *)(iVar5 + 0xc) & 0x3c0) != 0x240) {
      return iVar5;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x15c,
                  "nbt_get_stale_router",
                  "stale_router == ((void *)0) || stale_router->relationship != NWK_RELATIONSHIP_BACKBONE_SIBLING"
                 );
  }
  return 0;
}

