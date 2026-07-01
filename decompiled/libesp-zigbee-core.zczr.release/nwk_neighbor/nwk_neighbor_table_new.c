/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_new
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_neighbor_t * nwk_neighbor_table_new(_Bool is_router)

{
  uint uVar1;
  uint16_t uVar2;
  undefined3 in_register_00002029;
  int iVar3;
  nwk_neighbor_t *pnVar4;
  uint uVar5;
  undefined2 extraout_var;
  uint uVar6;
  nwk_neighbor_t *pnVar7;
  uint uVar8;
  int iVar9;
  
  iVar9 = CONCAT31(in_register_00002029,is_router);
  iVar3 = core_globals_get();
  pnVar7 = (nwk_neighbor_t *)
           ((int)(uint)*(ushort *)(iVar3 + 0xb24) - (uint)*(ushort *)(iVar3 + 0xb26) & 0xffff);
  pnVar4 = (nwk_neighbor_t *)0x0;
  if (iVar9 == 0) {
    pnVar4 = pnVar7;
    pnVar7 = (nwk_neighbor_t *)(uint)*(ushort *)(iVar3 + 0xb24);
  }
  uVar1 = iVar3 + 0x1000;
  pnVar4 = (nwk_neighbor_t *)bitmap_find_next_zero_bit(*(undefined4 *)(iVar3 + 0xb1c),pnVar4);
  if (pnVar4 < pnVar7) {
    uVar8 = 1 << ((uint)pnVar4 & 7) & 0xff;
    uVar5 = __atomic_fetch_or_1(((uint)pnVar4 >> 3) + *(int *)(iVar3 + 0xb1c),uVar8,5);
    if ((uVar8 & uVar5) == 0) goto _L0;
    do {
      while( true ) {
        __assert_func(0,0,0,0);
_L0:
        pnVar4 = (nwk_neighbor_t *)(*(int *)(uVar1 - 0x4e0) + (int)pnVar4 * 0x1c);
        if (iVar9 == 0) break;
        if ((int)(uint)*(ushort *)(uVar1 - 0x4d6) <
            (int)((uint)*(ushort *)(uVar1 - 0x4dc) - (uint)*(ushort *)(uVar1 - 0x4da))) {
          *(ushort *)(uVar1 - 0x4d6) = *(ushort *)(uVar1 - 0x4d6) + 1;
          if (pnVar4 != (nwk_neighbor_t *)0x0) goto _L0;
_L0:
          uVar5 = 0;
          uVar1 = (uint)*(ushort *)(iVar3 + 0xb24) - (uint)*(ushort *)(iVar3 + 0xb26) & 0xffff;
          iVar9 = 0x1c0003c0;
          while (uVar5 = bitmap_find_next_bit(*(undefined4 *)(iVar3 + 0xb1c),uVar1,uVar5),
                uVar5 < uVar1) {
            pnVar4 = (nwk_neighbor_t *)(*(int *)(iVar3 + 0xb20) + uVar5 * 0x1c);
            if (((*(uint *)&pnVar4->field_0xc & 3) < 2) &&
               ((*(uint *)&pnVar4->field_0xc & 0x1c0003c0) == 0x80)) goto _L113;
            uVar5 = uVar5 + 1 & 0xffff;
          }
          uVar5 = 0xffff;
          uVar6 = 0;
          iVar9 = 0x1c;
          uVar8 = uVar1;
          while (uVar6 = bitmap_find_next_bit(*(undefined4 *)(iVar3 + 0xb1c),uVar1,uVar6),
                uVar6 < uVar1) {
            pnVar4 = (nwk_neighbor_t *)(*(int *)(iVar3 + 0xb20) + uVar6 * 0x1c);
            if ((((*(uint *)&pnVar4->field_0xc & 3) < 2) &&
                ((*(uint *)&pnVar4->field_0xc & 0x3c0) == 0x80)) &&
               (10 < (pnVar4->dev).r.router_age)) {
              uVar2 = nwk_neighbor_get_router_rank(pnVar4);
              if (CONCAT22(extraout_var,uVar2) < uVar5) {
                uVar5 = CONCAT22(extraout_var,uVar2);
                uVar8 = uVar6;
              }
            }
            uVar6 = uVar6 + 1 & 0xffff;
          }
          if (uVar1 == uVar8) {
            return (nwk_neighbor_t *)0x0;
          }
          pnVar4 = (nwk_neighbor_t *)(*(int *)(iVar3 + 0xb20) + uVar8 * 0x1c);
          iVar3 = iVar3 + 0x1000;
          if (pnVar4 == (nwk_neighbor_t *)0x0) {
            return (nwk_neighbor_t *)0x0;
          }
_L113:
          if ((*(uint *)&pnVar4->field_0xc & 0x3c0) != 0x240) {
            if (pnVar4->addr_ref != 0xffff) {
              nwk_address_unlock_ref();
            }
            goto _L0;
          }
        }
      }
    } while ((uint)*(ushort *)(uVar1 - 0x4da) <= (uint)*(ushort *)(uVar1 - 0x4d8));
    *(ushort *)(uVar1 - 0x4d8) = *(ushort *)(uVar1 - 0x4d8) + 1;
    if (pnVar4 != (nwk_neighbor_t *)0x0) {
_L0:
      memset(pnVar4->lqa,0,0x1a);
      pnVar4->addr_ref = 0xffff;
      *(undefined4 *)&pnVar4->field_0xc = 0x1c0000c3;
      nwk_neighbor_clear_lqa(pnVar4);
      return pnVar4;
    }
  }
  else if (iVar9 != 0) goto _L0;
  return (nwk_neighbor_t *)0x0;
}

