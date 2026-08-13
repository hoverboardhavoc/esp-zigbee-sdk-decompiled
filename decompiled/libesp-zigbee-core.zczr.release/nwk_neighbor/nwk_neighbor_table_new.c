/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_new
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short * nwk_neighbor_table_new(int param_1)

{
  uint uVar1;
  int iVar2;
  short *psVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  short *psVar8;
  uint uVar9;
  
  iVar2 = core_globals_get();
  psVar8 = (short *)((int)(uint)*(ushort *)(iVar2 + 0xb24) - (uint)*(ushort *)(iVar2 + 0xb26) &
                    0xffff);
  psVar3 = (short *)0x0;
  if (param_1 == 0) {
    psVar3 = psVar8;
    psVar8 = (short *)(uint)*(ushort *)(iVar2 + 0xb24);
  }
  uVar1 = iVar2 + 0x1000;
  psVar3 = (short *)bitmap_find_next_zero_bit(*(undefined4 *)(iVar2 + 0xb1c),psVar3);
  if (psVar3 < psVar8) {
    uVar9 = 1 << ((uint)psVar3 & 7) & 0xff;
    uVar4 = __atomic_fetch_or_1(((uint)psVar3 >> 3) + *(int *)(iVar2 + 0xb1c),uVar9,5);
    if ((uVar9 & uVar4) == 0) goto _L0;
    do {
      while( true ) {
        __assert_func(0,0,0,0);
_L0:
        psVar3 = (short *)(*(int *)(uVar1 - 0x4e0) + (int)psVar3 * 0x1c);
        if (param_1 == 0) break;
        if ((int)(uint)*(ushort *)(uVar1 - 0x4d6) <
            (int)((uint)*(ushort *)(uVar1 - 0x4dc) - (uint)*(ushort *)(uVar1 - 0x4da))) {
          *(ushort *)(uVar1 - 0x4d6) = *(ushort *)(uVar1 - 0x4d6) + 1;
          if (psVar3 != (short *)0x0) goto _L0;
_L0:
          uVar4 = 0;
          uVar1 = (uint)*(ushort *)(iVar2 + 0xb24) - (uint)*(ushort *)(iVar2 + 0xb26) & 0xffff;
          param_1 = 0x1c0003c0;
          while (uVar4 = bitmap_find_next_bit(*(undefined4 *)(iVar2 + 0xb1c),uVar1,uVar4),
                uVar4 < uVar1) {
            psVar3 = (short *)(*(int *)(iVar2 + 0xb20) + uVar4 * 0x1c);
            if (((*(uint *)(psVar3 + 6) & 3) < 2) && ((*(uint *)(psVar3 + 6) & 0x1c0003c0) == 0x80))
            goto _L113;
            uVar4 = uVar4 + 1 & 0xffff;
          }
          uVar4 = 0xffff;
          uVar6 = 0;
          param_1 = 0x1c;
          uVar9 = uVar1;
          while (uVar6 = bitmap_find_next_bit(*(undefined4 *)(iVar2 + 0xb1c),uVar1,uVar6),
                uVar6 < uVar1) {
            iVar5 = *(int *)(iVar2 + 0xb20) + uVar6 * 0x1c;
            uVar7 = *(uint *)(iVar5 + 0xc);
            if (((((uVar7 & 3) < 2) && ((uVar7 & 0x3c0) == 0x80)) &&
                (10 < *(ushort *)(iVar5 + 0x12))) &&
               (uVar7 = nwk_neighbor_get_router_rank(), uVar7 < uVar4)) {
              uVar4 = uVar7;
              uVar9 = uVar6;
            }
            uVar6 = uVar6 + 1 & 0xffff;
          }
          if (uVar1 == uVar9) {
            return (short *)0x0;
          }
          psVar3 = (short *)(*(int *)(iVar2 + 0xb20) + uVar9 * 0x1c);
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
    nwk_update_beacon_payload();
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
  else if (param_1 != 0) goto _L0;
  return (short *)0x0;
}

