/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short * nwk_neighbor_table_init(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  short *psVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  short *psVar10;
  uint uVar11;
  
  iVar2 = core_globals_get();
  if ((((*(short *)(iVar2 + 0xb24) == 0) || (*(int *)(iVar2 + 0xb20) == 0)) ||
      (*(int *)(iVar2 + 0xb1c) == 0)) && (param_1 != 0)) {
    memset((void *)(iVar2 + 0xb1c),0,0x10);
    *(short *)(iVar2 + 0xb24) = (short)param_1;
    uVar3 = mm_calloc(param_1,0x1c);
    *(undefined4 *)(iVar2 + 0xb20) = uVar3;
    psVar4 = (short *)mm_calloc(*(ushort *)(iVar2 + 0xb24) + 7 >> 3,1);
    *(short *)(iVar2 + 0xb26) = (short)(param_1 >> 1);
    *(short **)(iVar2 + 0xb1c) = psVar4;
    return psVar4;
  }
  __assert_func(0,0,0,0);
  iVar2 = core_globals_get();
  if (((*(short *)(iVar2 + 0xb24) != 0) && (*(int *)(iVar2 + 0xb20) != 0)) &&
     (*(int *)(iVar2 + 0xb1c) != 0)) {
    mm_free();
    *(undefined4 *)(iVar2 + 0xb20) = 0;
    psVar4 = (short *)mm_free(*(undefined4 *)(iVar2 + 0xb1c));
    *(undefined4 *)(iVar2 + 0xb1c) = 0;
    return psVar4;
  }
  iVar5 = __assert_func(0,0,0,0);
  iVar2 = core_globals_get();
  psVar10 = (short *)((int)(uint)*(ushort *)(iVar2 + 0xb24) - (uint)*(ushort *)(iVar2 + 0xb26) &
                     0xffff);
  psVar4 = (short *)0x0;
  if (iVar5 == 0) {
    psVar4 = psVar10;
    psVar10 = (short *)(uint)*(ushort *)(iVar2 + 0xb24);
  }
  uVar1 = iVar2 + 0x1000;
  psVar4 = (short *)bitmap_find_next_zero_bit(*(undefined4 *)(iVar2 + 0xb1c),psVar4);
  if (psVar4 < psVar10) {
    uVar11 = 1 << ((uint)psVar4 & 7) & 0xff;
    uVar6 = __atomic_fetch_or_1(((uint)psVar4 >> 3) + *(int *)(iVar2 + 0xb1c),uVar11,5);
    if ((uVar11 & uVar6) == 0) goto _L0;
    do {
      while( true ) {
        __assert_func(0,0,0,0);
_L0:
        psVar4 = (short *)(*(int *)(uVar1 - 0x4e0) + (int)psVar4 * 0x1c);
        if (iVar5 == 0) break;
        if ((int)(uint)*(ushort *)(uVar1 - 0x4d6) <
            (int)((uint)*(ushort *)(uVar1 - 0x4dc) - (uint)*(ushort *)(uVar1 - 0x4da))) {
          *(ushort *)(uVar1 - 0x4d6) = *(ushort *)(uVar1 - 0x4d6) + 1;
          if (psVar4 != (short *)0x0) goto _L0;
_L0:
          uVar6 = 0;
          uVar1 = (uint)*(ushort *)(iVar2 + 0xb24) - (uint)*(ushort *)(iVar2 + 0xb26) & 0xffff;
          iVar5 = 0x1c0003c0;
          while (uVar6 = bitmap_find_next_bit(*(undefined4 *)(iVar2 + 0xb1c),uVar1,uVar6),
                uVar6 < uVar1) {
            psVar4 = (short *)(*(int *)(iVar2 + 0xb20) + uVar6 * 0x1c);
            if (((*(uint *)(psVar4 + 6) & 3) < 2) && ((*(uint *)(psVar4 + 6) & 0x1c0003c0) == 0x80))
            goto _L113;
            uVar6 = uVar6 + 1 & 0xffff;
          }
          uVar6 = 0xffff;
          uVar8 = 0;
          iVar5 = 0x1c;
          uVar11 = uVar1;
          while (uVar8 = bitmap_find_next_bit(*(undefined4 *)(iVar2 + 0xb1c),uVar1,uVar8),
                uVar8 < uVar1) {
            iVar7 = *(int *)(iVar2 + 0xb20) + uVar8 * 0x1c;
            uVar9 = *(uint *)(iVar7 + 0xc);
            if (((((uVar9 & 3) < 2) && ((uVar9 & 0x3c0) == 0x80)) &&
                (10 < *(ushort *)(iVar7 + 0x12))) &&
               (uVar9 = nwk_neighbor_get_router_rank(), uVar9 < uVar6)) {
              uVar6 = uVar9;
              uVar11 = uVar8;
            }
            uVar8 = uVar8 + 1 & 0xffff;
          }
          if (uVar1 == uVar11) {
            return (short *)0x0;
          }
          psVar4 = (short *)(*(int *)(iVar2 + 0xb20) + uVar11 * 0x1c);
          iVar2 = iVar2 + 0x1000;
          if (psVar4 == (short *)0x0) {
            return (short *)0x0;
          }
_L113:
          if ((*(uint *)(psVar4 + 6) & 0x3c0) != 0x240) {
            if (*psVar4 != -1) {
              nwk_address_unlock_ref();
            }
            goto _L0;
          }
        }
      }
    } while ((uint)*(ushort *)(uVar1 - 0x4da) <= (uint)*(ushort *)(uVar1 - 0x4d8));
    *(ushort *)(uVar1 - 0x4d8) = *(ushort *)(uVar1 - 0x4d8) + 1;
    if (psVar4 != (short *)0x0) {
_L0:
      memset(psVar4 + 1,0,0x1a);
      *psVar4 = -1;
      psVar4[6] = 0xc3;
      psVar4[7] = 0x1c00;
      nwk_neighbor_clear_lqa(psVar4);
      return psVar4;
    }
  }
  else if (iVar5 != 0) goto _L0;
  return (short *)0x0;
}

