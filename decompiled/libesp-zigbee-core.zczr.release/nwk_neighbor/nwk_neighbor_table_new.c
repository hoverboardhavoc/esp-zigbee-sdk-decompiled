/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  nwk_neighbor_t *pnVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = CONCAT31(in_register_00002029,is_router);
  iVar3 = core_globals_get();
  pnVar6 = (nwk_neighbor_t *)
           ((int)(uint)*(ushort *)(iVar3 + 0xb24) - (uint)*(ushort *)(iVar3 + 0xb26) & 0xffff);
  pnVar4 = (nwk_neighbor_t *)0x0;
  if (uVar8 == 0) {
    pnVar4 = pnVar6;
    pnVar6 = (nwk_neighbor_t *)(uint)*(ushort *)(iVar3 + 0xb24);
  }
  uVar1 = iVar3 + 0x1000;
  pnVar4 = (nwk_neighbor_t *)bitmap_find_next_zero_bit(*(undefined4 *)(iVar3 + 0xb1c),pnVar4);
  if (pnVar4 < pnVar6) {
    uVar7 = 1 << ((uint)pnVar4 & 7) & 0xff;
    uVar5 = __atomic_fetch_or_1(((uint)pnVar4 >> 3) + *(int *)(iVar3 + 0xb1c),uVar7,5);
    if ((uVar7 & uVar5) == 0) goto _L0;
    do {
      while( true ) {
        __assert_func(0,0,0,0);
_L0:
        pnVar4 = (nwk_neighbor_t *)(*(int *)(uVar1 - 0x4e0) + (int)pnVar4 * 0x20);
        if (uVar8 == 0) break;
        if ((int)(uint)*(ushort *)(uVar1 - 0x4d6) <
            (int)((uint)*(ushort *)(uVar1 - 0x4dc) - (uint)*(ushort *)(uVar1 - 0x4da))) {
          *(ushort *)(uVar1 - 0x4d6) = *(ushort *)(uVar1 - 0x4d6) + 1;
          if (pnVar4 != (nwk_neighbor_t *)0x0) goto _L0;
_L0:
          uVar5 = 0;
          uVar1 = (uint)*(ushort *)(iVar3 + 0xb24) - (uint)*(ushort *)(iVar3 + 0xb26) & 0xffff;
          uVar8 = 0x1c0003c0;
          while (uVar5 = bitmap_find_next_bit(*(undefined4 *)(iVar3 + 0xb1c),uVar1,uVar5),
                uVar5 < uVar1) {
            pnVar4 = (nwk_neighbor_t *)(*(int *)(iVar3 + 0xb20) + uVar5 * 0x20);
            if (((*(uint *)&pnVar4->field_0xc & 3) < 2) &&
               ((*(uint *)&pnVar4->field_0xc & 0x1c0003c0) == 0x80)) goto _L111;
            uVar5 = uVar5 + 1 & 0xffff;
          }
          uVar8 = 0xffff;
          uVar7 = 0;
          uVar5 = uVar1;
          while (uVar7 = bitmap_find_next_bit(*(undefined4 *)(iVar3 + 0xb1c),uVar1,uVar7),
                uVar7 < uVar1) {
            pnVar4 = (nwk_neighbor_t *)(*(int *)(iVar3 + 0xb20) + uVar7 * 0x20);
            if ((((*(uint *)&pnVar4->field_0xc & 3) < 2) &&
                ((*(uint *)&pnVar4->field_0xc & 0x3c0) == 0x80)) &&
               (10 < (pnVar4->dev).r.router_age)) {
              uVar2 = nwk_neighbor_get_router_rank(pnVar4);
              if (CONCAT22(extraout_var,uVar2) < uVar8) {
                uVar5 = uVar7;
                uVar8 = CONCAT22(extraout_var,uVar2);
              }
            }
            uVar7 = uVar7 + 1 & 0xffff;
          }
          if (uVar1 == uVar5) {
            return (nwk_neighbor_t *)0x0;
          }
          pnVar4 = (nwk_neighbor_t *)(*(int *)(iVar3 + 0xb20) + uVar5 * 0x20);
          iVar3 = iVar3 + 0x1000;
          if (pnVar4 == (nwk_neighbor_t *)0x0) {
            return (nwk_neighbor_t *)0x0;
          }
_L111:
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
      memset(pnVar4->lqa,0,0x1e);
      pnVar4->addr_ref = 0xffff;
      *(undefined4 *)&pnVar4->field_0xc = 0x1c0000c3;
      nwk_neighbor_clear_lqa(pnVar4);
      return pnVar4;
    }
  }
  else if (uVar8 != 0) goto _L0;
  return (nwk_neighbor_t *)0x0;
}

