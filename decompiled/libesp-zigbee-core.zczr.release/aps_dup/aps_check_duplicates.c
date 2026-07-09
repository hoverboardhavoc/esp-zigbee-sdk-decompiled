/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_dup.o -> aps_check_duplicates
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_check_duplicates(short *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  short *psVar6;
  uint uVar7;
  ushort uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  
  if ((*(byte *)(param_1 + 6) & 3) == 2) {
    return 0;
  }
  if (((char)param_1[7] != '\x0e') && (1 < (byte)((char)param_1[7] - 0x11U))) {
    iVar2 = core_globals_get();
    bVar1 = *(byte *)(param_1 + 6);
    uVar4 = 0;
    while( true ) {
      uVar4 = bitmap_find_next_bit
                        (*(undefined4 *)(iVar2 + 0x988),*(undefined2 *)(iVar2 + 0x98c),uVar4);
      uVar10 = (uint)*(ushort *)(iVar2 + 0x98c);
      iVar9 = *(int *)(iVar2 + 0x984);
      if (uVar10 <= uVar4) break;
      psVar6 = (short *)(uVar4 * 4 + iVar9);
      if ((((*psVar6 == *param_1) && ((char)psVar6[1] == *(char *)((int)param_1 + 0xd))) &&
          ((ushort)((bVar1 & 0xc) == 0) == ((ushort)psVar6[1] >> 0xe & 1))) &&
         ((ushort)psVar6[1] >> 0xf == (ushort)((bVar1 & 3) == 1))) {
        return 1;
      }
      uVar4 = uVar4 + 1 & 0xffff;
    }
    iVar11 = *(int *)(iVar2 + 0x988);
    do {
      uVar4 = bitmap_find_first_zero_bit(iVar11,uVar10);
      if (uVar10 <= uVar4) goto _L0;
      uVar7 = 1 << (uVar4 & 7) & 0xff;
      uVar3 = __atomic_fetch_or_1((uVar4 >> 3) + iVar11,uVar7,5);
    } while ((uVar7 & uVar3) != 0);
    psVar6 = (short *)(uVar4 * 4 + iVar9);
    if (psVar6 == (short *)0x0) {
_L0:
      uVar8 = 0xff;
      uVar4 = 0;
      uVar10 = 0;
      while( true ) {
        uVar10 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar2 + 0x988),*(undefined2 *)(iVar2 + 0x98c),uVar10);
        if (*(ushort *)(iVar2 + 0x98c) <= uVar10) break;
        uVar5 = *(ushort *)(*(int *)(iVar2 + 0x984) + uVar10 * 4 + 2) >> 8 & 0x3f;
        if (uVar5 < uVar8) {
          uVar4 = uVar10;
          uVar8 = uVar5;
        }
        uVar10 = uVar10 + 1 & 0xffff;
      }
      psVar6 = (short *)(*(int *)(iVar2 + 0x984) + uVar4 * 4);
    }
    *psVar6 = *param_1;
    *(undefined1 *)(psVar6 + 1) = *(undefined1 *)((int)param_1 + 0xd);
    *(byte *)((int)psVar6 + 3) =
         ((*(byte *)(param_1 + 6) & 3) == 1) << 7 | ((*(byte *)(param_1 + 6) & 0xc) == 0) << 6 | 7U;
    iVar2 = time_ticker_is_receiver_registered(4);
    if (iVar2 == 0) {
      time_ticker_register_receiver(4);
    }
  }
  return 0;
}

