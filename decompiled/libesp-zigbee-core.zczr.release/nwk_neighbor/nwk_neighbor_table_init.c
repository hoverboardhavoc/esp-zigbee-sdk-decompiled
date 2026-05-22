/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_neighbor_table_init(uint16_t capacity)

{
  uint uVar1;
  uint16_t uVar2;
  undefined2 in_register_0000202a;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  nwk_neighbor_t *pnVar6;
  uint uVar7;
  undefined2 extraout_var;
  nwk_neighbor_t *pnVar8;
  uint uVar9;
  
  uVar5 = CONCAT22(in_register_0000202a,capacity);
  iVar3 = core_globals_get();
  if ((((*(short *)(iVar3 + 0xb24) == 0) || (*(int *)(iVar3 + 0xb20) == 0)) ||
      (*(int *)(iVar3 + 0xb1c) == 0)) && (uVar5 != 0)) {
    memset((void *)(iVar3 + 0xb1c),0,0x10);
    *(uint16_t *)(iVar3 + 0xb24) = capacity;
    uVar4 = mm_calloc(uVar5,0x20);
    *(undefined4 *)(iVar3 + 0xb20) = uVar4;
    uVar4 = mm_calloc(*(ushort *)(iVar3 + 0xb24) + 7 >> 3,1);
    *(short *)(iVar3 + 0xb26) = (short)(uVar5 >> 1);
    *(undefined4 *)(iVar3 + 0xb1c) = uVar4;
    return;
  }
  __assert_func(0,0,0,0);
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0xb24) != 0) && (*(int *)(iVar3 + 0xb20) != 0)) &&
     (*(int *)(iVar3 + 0xb1c) != 0)) {
    mm_free();
    *(undefined4 *)(iVar3 + 0xb20) = 0;
    mm_free(*(undefined4 *)(iVar3 + 0xb1c));
    *(undefined4 *)(iVar3 + 0xb1c) = 0;
    return;
  }
  uVar5 = __assert_func(0,0,0,0);
  iVar3 = core_globals_get();
  pnVar8 = (nwk_neighbor_t *)
           ((int)(uint)*(ushort *)(iVar3 + 0xb24) - (uint)*(ushort *)(iVar3 + 0xb26) & 0xffff);
  pnVar6 = (nwk_neighbor_t *)0x0;
  if (uVar5 == 0) {
    pnVar6 = pnVar8;
    pnVar8 = (nwk_neighbor_t *)(uint)*(ushort *)(iVar3 + 0xb24);
  }
  uVar1 = iVar3 + 0x1000;
  pnVar6 = (nwk_neighbor_t *)bitmap_find_next_zero_bit(*(undefined4 *)(iVar3 + 0xb1c),pnVar6);
  if (pnVar6 < pnVar8) {
    uVar9 = 1 << ((uint)pnVar6 & 7) & 0xff;
    uVar7 = __atomic_fetch_or_1(((uint)pnVar6 >> 3) + *(int *)(iVar3 + 0xb1c),uVar9,5);
    if ((uVar9 & uVar7) == 0) goto _L0;
    do {
      while( true ) {
        __assert_func(0,0,0,0);
_L0:
        pnVar6 = (nwk_neighbor_t *)(*(int *)(uVar1 - 0x4e0) + (int)pnVar6 * 0x20);
        if (uVar5 == 0) break;
        if ((int)(uint)*(ushort *)(uVar1 - 0x4d6) <
            (int)((uint)*(ushort *)(uVar1 - 0x4dc) - (uint)*(ushort *)(uVar1 - 0x4da))) {
          *(ushort *)(uVar1 - 0x4d6) = *(ushort *)(uVar1 - 0x4d6) + 1;
          if (pnVar6 != (nwk_neighbor_t *)0x0) goto _L0;
_L0:
          uVar7 = 0;
          uVar1 = (uint)*(ushort *)(iVar3 + 0xb24) - (uint)*(ushort *)(iVar3 + 0xb26) & 0xffff;
          uVar5 = 0x1c0003c0;
          while (uVar7 = bitmap_find_next_bit(*(undefined4 *)(iVar3 + 0xb1c),uVar1,uVar7),
                uVar7 < uVar1) {
            pnVar6 = (nwk_neighbor_t *)(*(int *)(iVar3 + 0xb20) + uVar7 * 0x20);
            if (((*(uint *)&pnVar6->field_0xc & 3) < 2) &&
               ((*(uint *)&pnVar6->field_0xc & 0x1c0003c0) == 0x80)) goto _L113;
            uVar7 = uVar7 + 1 & 0xffff;
          }
          uVar5 = 0xffff;
          uVar9 = 0;
          uVar7 = uVar1;
          while (uVar9 = bitmap_find_next_bit(*(undefined4 *)(iVar3 + 0xb1c),uVar1,uVar9),
                uVar9 < uVar1) {
            pnVar6 = (nwk_neighbor_t *)(*(int *)(iVar3 + 0xb20) + uVar9 * 0x20);
            if ((((*(uint *)&pnVar6->field_0xc & 3) < 2) &&
                ((*(uint *)&pnVar6->field_0xc & 0x3c0) == 0x80)) &&
               (10 < (pnVar6->dev).r.router_age)) {
              uVar2 = nwk_neighbor_get_router_rank(pnVar6);
              if (CONCAT22(extraout_var,uVar2) < uVar5) {
                uVar7 = uVar9;
                uVar5 = CONCAT22(extraout_var,uVar2);
              }
            }
            uVar9 = uVar9 + 1 & 0xffff;
          }
          if (uVar1 == uVar7) {
            return;
          }
          pnVar6 = (nwk_neighbor_t *)(*(int *)(iVar3 + 0xb20) + uVar7 * 0x20);
          iVar3 = iVar3 + 0x1000;
          if (pnVar6 == (nwk_neighbor_t *)0x0) {
            return;
          }
_L113:
          if ((*(uint *)&pnVar6->field_0xc & 0x3c0) != 0x240) {
            if (pnVar6->addr_ref != 0xffff) {
              nwk_address_unlock_ref();
            }
            goto _L0;
          }
        }
      }
    } while ((uint)*(ushort *)(uVar1 - 0x4da) <= (uint)*(ushort *)(uVar1 - 0x4d8));
    *(ushort *)(uVar1 - 0x4d8) = *(ushort *)(uVar1 - 0x4d8) + 1;
    if (pnVar6 != (nwk_neighbor_t *)0x0) {
_L0:
      memset(pnVar6->lqa,0,0x1e);
      pnVar6->addr_ref = 0xffff;
      *(undefined4 *)&pnVar6->field_0xc = 0x1c0000c3;
      nwk_neighbor_clear_lqa(pnVar6);
    }
  }
  else if (uVar5 != 0) goto _L0;
  return;
}

