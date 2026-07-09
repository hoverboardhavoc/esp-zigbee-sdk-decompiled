/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short * nwk_neighbor_table_deinit(void)

{
  uint uVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  short *psVar9;
  uint uVar10;
  
  iVar2 = core_globals_get();
  if (((*(short *)(iVar2 + 0xb24) != 0) && (*(int *)(iVar2 + 0xb20) != 0)) &&
     (*(int *)(iVar2 + 0xb1c) != 0)) {
    mm_free();
    *(undefined4 *)(iVar2 + 0xb20) = 0;
    psVar3 = (short *)mm_free(*(undefined4 *)(iVar2 + 0xb1c));
    *(undefined4 *)(iVar2 + 0xb1c) = 0;
    return psVar3;
  }
  iVar4 = __assert_func(0,0,0,0);
  iVar2 = core_globals_get();
  psVar9 = (short *)((int)(uint)*(ushort *)(iVar2 + 0xb24) - (uint)*(ushort *)(iVar2 + 0xb26) &
                    0xffff);
  psVar3 = (short *)0x0;
  if (iVar4 == 0) {
    psVar3 = psVar9;
    psVar9 = (short *)(uint)*(ushort *)(iVar2 + 0xb24);
  }
  uVar1 = iVar2 + 0x1000;
  psVar3 = (short *)bitmap_find_next_zero_bit(*(undefined4 *)(iVar2 + 0xb1c),psVar3);
  if (psVar3 < psVar9) {
    uVar10 = 1 << ((uint)psVar3 & 7) & 0xff;
    uVar5 = __atomic_fetch_or_1(((uint)psVar3 >> 3) + *(int *)(iVar2 + 0xb1c),uVar10,5);
    if ((uVar10 & uVar5) == 0) goto _L0;
    do {
      while( true ) {
        __assert_func(0,0,0,0);
_L0:
        psVar3 = (short *)(*(int *)(uVar1 - 0x4e0) + (int)psVar3 * 0x1c);
        if (iVar4 == 0) break;
        if ((int)(uint)*(ushort *)(uVar1 - 0x4d6) <
            (int)((uint)*(ushort *)(uVar1 - 0x4dc) - (uint)*(ushort *)(uVar1 - 0x4da))) {
          *(ushort *)(uVar1 - 0x4d6) = *(ushort *)(uVar1 - 0x4d6) + 1;
          if (psVar3 != (short *)0x0) goto _L0;
_L0:
          uVar5 = 0;
          uVar1 = (uint)*(ushort *)(iVar2 + 0xb24) - (uint)*(ushort *)(iVar2 + 0xb26) & 0xffff;
          iVar4 = 0x1c0003c0;
          while (uVar5 = bitmap_find_next_bit(*(undefined4 *)(iVar2 + 0xb1c),uVar1,uVar5),
                uVar5 < uVar1) {
            psVar3 = (short *)(*(int *)(iVar2 + 0xb20) + uVar5 * 0x1c);
            if (((*(uint *)(psVar3 + 6) & 3) < 2) && ((*(uint *)(psVar3 + 6) & 0x1c0003c0) == 0x80))
            goto _L113;
            uVar5 = uVar5 + 1 & 0xffff;
          }
          uVar5 = 0xffff;
          uVar7 = 0;
          iVar4 = 0x1c;
          uVar10 = uVar1;
          while (uVar7 = bitmap_find_next_bit(*(undefined4 *)(iVar2 + 0xb1c),uVar1,uVar7),
                uVar7 < uVar1) {
            iVar6 = *(int *)(iVar2 + 0xb20) + uVar7 * 0x1c;
            uVar8 = *(uint *)(iVar6 + 0xc);
            if ((((uVar8 & 3) < 2) && ((uVar8 & 0x3c0) == 0x80)) &&
               ((10 < *(ushort *)(iVar6 + 0x12) &&
                (uVar8 = nwk_neighbor_get_router_rank(), uVar8 < uVar5)))) {
              uVar5 = uVar8;
              uVar10 = uVar7;
            }
            uVar7 = uVar7 + 1 & 0xffff;
          }
          if (uVar1 == uVar10) {
            return (short *)0x0;
          }
          psVar3 = (short *)(*(int *)(iVar2 + 0xb20) + uVar10 * 0x1c);
          iVar2 = iVar2 + 0x1000;
          if (psVar3 == (short *)0x0) {
            return (short *)0x0;
          }
_L113:
          if ((*(uint *)(psVar3 + 6) & 0x3c0) != 0x240) {
            if (*psVar3 != -1) {
              nwk_address_unlock_ref();
            }
            goto _L0;
          }
        }
      }
    } while ((uint)*(ushort *)(uVar1 - 0x4da) <= (uint)*(ushort *)(uVar1 - 0x4d8));
    *(ushort *)(uVar1 - 0x4d8) = *(ushort *)(uVar1 - 0x4d8) + 1;
    if (psVar3 != (short *)0x0) {
_L0:
      memset(psVar3 + 1,0,0x1a);
      *psVar3 = -1;
      psVar3[6] = 0xc3;
      psVar3[7] = 0x1c00;
      nwk_neighbor_clear_lqa(psVar3);
      return psVar3;
    }
  }
  else if (iVar4 != 0) goto _L0;
  return (short *)0x0;
}

