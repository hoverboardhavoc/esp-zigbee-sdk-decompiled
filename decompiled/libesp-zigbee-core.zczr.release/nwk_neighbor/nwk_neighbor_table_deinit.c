/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_neighbor_table_deinit(void)

{
  uint uVar1;
  uint16_t uVar2;
  int iVar3;
  int iVar4;
  nwk_neighbor_t *pnVar5;
  uint uVar6;
  undefined2 extraout_var;
  uint uVar7;
  nwk_neighbor_t *pnVar8;
  uint uVar9;
  
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0xb24) != 0) && (*(int *)(iVar3 + 0xb20) != 0)) &&
     (*(int *)(iVar3 + 0xb1c) != 0)) {
    mm_free();
    *(undefined4 *)(iVar3 + 0xb20) = 0;
    mm_free(*(undefined4 *)(iVar3 + 0xb1c));
    *(undefined4 *)(iVar3 + 0xb1c) = 0;
    return;
  }
  iVar4 = __assert_func(0,0,0,0);
  iVar3 = core_globals_get();
  pnVar8 = (nwk_neighbor_t *)
           ((int)(uint)*(ushort *)(iVar3 + 0xb24) - (uint)*(ushort *)(iVar3 + 0xb26) & 0xffff);
  pnVar5 = (nwk_neighbor_t *)0x0;
  if (iVar4 == 0) {
    pnVar5 = pnVar8;
    pnVar8 = (nwk_neighbor_t *)(uint)*(ushort *)(iVar3 + 0xb24);
  }
  uVar1 = iVar3 + 0x1000;
  pnVar5 = (nwk_neighbor_t *)bitmap_find_next_zero_bit(*(undefined4 *)(iVar3 + 0xb1c),pnVar5);
  if (pnVar5 < pnVar8) {
    uVar9 = 1 << ((uint)pnVar5 & 7) & 0xff;
    uVar6 = __atomic_fetch_or_1(((uint)pnVar5 >> 3) + *(int *)(iVar3 + 0xb1c),uVar9,5);
    if ((uVar9 & uVar6) == 0) goto _L0;
    do {
      while( true ) {
        __assert_func(0,0,0,0);
_L0:
        pnVar5 = (nwk_neighbor_t *)(*(int *)(uVar1 - 0x4e0) + (int)pnVar5 * 0x1c);
        if (iVar4 == 0) break;
        if ((int)(uint)*(ushort *)(uVar1 - 0x4d6) <
            (int)((uint)*(ushort *)(uVar1 - 0x4dc) - (uint)*(ushort *)(uVar1 - 0x4da))) {
          *(ushort *)(uVar1 - 0x4d6) = *(ushort *)(uVar1 - 0x4d6) + 1;
          if (pnVar5 != (nwk_neighbor_t *)0x0) goto _L0;
_L0:
          uVar6 = 0;
          uVar1 = (uint)*(ushort *)(iVar3 + 0xb24) - (uint)*(ushort *)(iVar3 + 0xb26) & 0xffff;
          iVar4 = 0x1c0003c0;
          while (uVar6 = bitmap_find_next_bit(*(undefined4 *)(iVar3 + 0xb1c),uVar1,uVar6),
                uVar6 < uVar1) {
            pnVar5 = (nwk_neighbor_t *)(*(int *)(iVar3 + 0xb20) + uVar6 * 0x1c);
            if (((*(uint *)&pnVar5->field_0xc & 3) < 2) &&
               ((*(uint *)&pnVar5->field_0xc & 0x1c0003c0) == 0x80)) goto _L113;
            uVar6 = uVar6 + 1 & 0xffff;
          }
          uVar6 = 0xffff;
          uVar7 = 0;
          iVar4 = 0x1c;
          uVar9 = uVar1;
          while (uVar7 = bitmap_find_next_bit(*(undefined4 *)(iVar3 + 0xb1c),uVar1,uVar7),
                uVar7 < uVar1) {
            pnVar5 = (nwk_neighbor_t *)(*(int *)(iVar3 + 0xb20) + uVar7 * 0x1c);
            if ((((*(uint *)&pnVar5->field_0xc & 3) < 2) &&
                ((*(uint *)&pnVar5->field_0xc & 0x3c0) == 0x80)) &&
               (10 < (pnVar5->dev).r.router_age)) {
              uVar2 = nwk_neighbor_get_router_rank(pnVar5);
              if (CONCAT22(extraout_var,uVar2) < uVar6) {
                uVar6 = CONCAT22(extraout_var,uVar2);
                uVar9 = uVar7;
              }
            }
            uVar7 = uVar7 + 1 & 0xffff;
          }
          if (uVar1 == uVar9) {
            return;
          }
          pnVar5 = (nwk_neighbor_t *)(*(int *)(iVar3 + 0xb20) + uVar9 * 0x1c);
          iVar3 = iVar3 + 0x1000;
          if (pnVar5 == (nwk_neighbor_t *)0x0) {
            return;
          }
_L113:
          if ((*(uint *)&pnVar5->field_0xc & 0x3c0) != 0x240) {
            if (pnVar5->addr_ref != 0xffff) {
              nwk_address_unlock_ref();
            }
            goto _L0;
          }
        }
      }
    } while ((uint)*(ushort *)(uVar1 - 0x4da) <= (uint)*(ushort *)(uVar1 - 0x4d8));
    *(ushort *)(uVar1 - 0x4d8) = *(ushort *)(uVar1 - 0x4d8) + 1;
    if (pnVar5 != (nwk_neighbor_t *)0x0) {
_L0:
      memset(pnVar5->lqa,0,0x1a);
      pnVar5->addr_ref = 0xffff;
      *(undefined4 *)&pnVar5->field_0xc = 0x1c0000c3;
      nwk_neighbor_clear_lqa(pnVar5);
    }
  }
  else if (iVar4 != 0) goto _L0;
  return;
}

