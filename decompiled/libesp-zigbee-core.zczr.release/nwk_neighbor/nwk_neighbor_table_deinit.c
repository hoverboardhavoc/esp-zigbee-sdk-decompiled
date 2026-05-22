/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  uint uVar4;
  nwk_neighbor_t *pnVar5;
  uint uVar6;
  undefined2 extraout_var;
  nwk_neighbor_t *pnVar7;
  uint uVar8;
  
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0xb24) != 0) && (*(int *)(iVar3 + 0xb20) != 0)) &&
     (*(int *)(iVar3 + 0xb1c) != 0)) {
    mm_free();
    *(undefined4 *)(iVar3 + 0xb20) = 0;
    mm_free(*(undefined4 *)(iVar3 + 0xb1c));
    *(undefined4 *)(iVar3 + 0xb1c) = 0;
    return;
  }
  uVar4 = __assert_func(0,0,0,0);
  iVar3 = core_globals_get();
  pnVar7 = (nwk_neighbor_t *)
           ((int)(uint)*(ushort *)(iVar3 + 0xb24) - (uint)*(ushort *)(iVar3 + 0xb26) & 0xffff);
  pnVar5 = (nwk_neighbor_t *)0x0;
  if (uVar4 == 0) {
    pnVar5 = pnVar7;
    pnVar7 = (nwk_neighbor_t *)(uint)*(ushort *)(iVar3 + 0xb24);
  }
  uVar1 = iVar3 + 0x1000;
  pnVar5 = (nwk_neighbor_t *)bitmap_find_next_zero_bit(*(undefined4 *)(iVar3 + 0xb1c),pnVar5);
  if (pnVar5 < pnVar7) {
    uVar8 = 1 << ((uint)pnVar5 & 7) & 0xff;
    uVar6 = __atomic_fetch_or_1(((uint)pnVar5 >> 3) + *(int *)(iVar3 + 0xb1c),uVar8,5);
    if ((uVar8 & uVar6) == 0) goto _L0;
    do {
      while( true ) {
        __assert_func(0,0,0,0);
_L0:
        pnVar5 = (nwk_neighbor_t *)(*(int *)(uVar1 - 0x4e0) + (int)pnVar5 * 0x20);
        if (uVar4 == 0) break;
        if ((int)(uint)*(ushort *)(uVar1 - 0x4d6) <
            (int)((uint)*(ushort *)(uVar1 - 0x4dc) - (uint)*(ushort *)(uVar1 - 0x4da))) {
          *(ushort *)(uVar1 - 0x4d6) = *(ushort *)(uVar1 - 0x4d6) + 1;
          if (pnVar5 != (nwk_neighbor_t *)0x0) goto _L0;
_L0:
          uVar6 = 0;
          uVar1 = (uint)*(ushort *)(iVar3 + 0xb24) - (uint)*(ushort *)(iVar3 + 0xb26) & 0xffff;
          uVar4 = 0x1c0003c0;
          while (uVar6 = bitmap_find_next_bit(*(undefined4 *)(iVar3 + 0xb1c),uVar1,uVar6),
                uVar6 < uVar1) {
            pnVar5 = (nwk_neighbor_t *)(*(int *)(iVar3 + 0xb20) + uVar6 * 0x20);
            if (((*(uint *)&pnVar5->field_0xc & 3) < 2) &&
               ((*(uint *)&pnVar5->field_0xc & 0x1c0003c0) == 0x80)) goto _L113;
            uVar6 = uVar6 + 1 & 0xffff;
          }
          uVar4 = 0xffff;
          uVar8 = 0;
          uVar6 = uVar1;
          while (uVar8 = bitmap_find_next_bit(*(undefined4 *)(iVar3 + 0xb1c),uVar1,uVar8),
                uVar8 < uVar1) {
            pnVar5 = (nwk_neighbor_t *)(*(int *)(iVar3 + 0xb20) + uVar8 * 0x20);
            if ((((*(uint *)&pnVar5->field_0xc & 3) < 2) &&
                ((*(uint *)&pnVar5->field_0xc & 0x3c0) == 0x80)) &&
               (10 < (pnVar5->dev).r.router_age)) {
              uVar2 = nwk_neighbor_get_router_rank(pnVar5);
              if (CONCAT22(extraout_var,uVar2) < uVar4) {
                uVar6 = uVar8;
                uVar4 = CONCAT22(extraout_var,uVar2);
              }
            }
            uVar8 = uVar8 + 1 & 0xffff;
          }
          if (uVar1 == uVar6) {
            return;
          }
          pnVar5 = (nwk_neighbor_t *)(*(int *)(iVar3 + 0xb20) + uVar6 * 0x20);
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
      memset(pnVar5->lqa,0,0x1e);
      pnVar5->addr_ref = 0xffff;
      *(undefined4 *)&pnVar5->field_0xc = 0x1c0000c3;
      nwk_neighbor_clear_lqa(pnVar5);
    }
  }
  else if (uVar4 != 0) goto _L0;
  return;
}

