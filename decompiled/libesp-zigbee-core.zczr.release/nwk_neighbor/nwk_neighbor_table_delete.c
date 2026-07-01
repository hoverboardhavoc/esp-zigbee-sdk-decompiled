/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_neighbor_table_delete(nwk_neighbor_t *nbr)

{
  uint uVar1;
  int iVar2;
  uint16_t uVar3;
  int iVar4;
  uint uVar5;
  undefined2 extraout_var;
  uint uVar6;
  
  iVar4 = core_globals_get();
  uVar1 = ((int)nbr - *(int *)(iVar4 + 0xb20) >> 2) * -0x49249249;
  if ((uVar1 & 0xffff) < (uint)*(ushort *)(iVar4 + 0xb24)) goto _L171;
  do {
    while( true ) {
      do {
        iVar4 = __assert_func(0,0,0,0);
_L171:
        if (nbr->addr_ref != 0xffff) {
          nwk_address_unlock_ref();
        }
        uVar6 = 1 << (uVar1 & 7) & 0xff;
        uVar1 = (uVar1 << 0x10) >> 0x13;
        uVar5 = __atomic_fetch_and_1(*(int *)(iVar4 + 0xb1c) + uVar1,~uVar6 & 0xff,5);
      } while ((uVar6 & uVar5) == 0);
      iVar2 = *(int *)(iVar4 + 0xb20);
      uVar3 = nwk_neighbor_table_get_router_capacity();
      uVar5 = *(uint *)&nbr->field_0xc & 3;
      uVar1 = ((int)nbr - iVar2 >> 2) * -0x49249249 & 0xffff;
      if (uVar1 < CONCAT22(extraout_var,uVar3)) break;
      if (uVar5 == 2) {
        nwk_neighbor_table_remove_stored_child(nbr);
        if (*(short *)(iVar4 + 0xb28) != 0) {
          *(short *)(iVar4 + 0xb28) = *(short *)(iVar4 + 0xb28) + -1;
          return;
        }
      }
    }
  } while ((1 < uVar5) || (*(short *)(iVar4 + 0xb2a) == 0));
  *(short *)(iVar4 + 0xb2a) = *(short *)(iVar4 + 0xb2a) + -1;
  return;
}

