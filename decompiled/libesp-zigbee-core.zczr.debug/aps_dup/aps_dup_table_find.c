/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_dup.o -> aps_dup_table_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short * aps_dup_table_find(int *param_1,short *param_2)

{
  byte bVar1;
  uint uVar2;
  short *psVar3;
  
  bVar1 = *(byte *)(param_2 + 6);
  uVar2 = 0;
  while( true ) {
    uVar2 = bitmap_find_next_bit(param_1[1],(short)param_1[2],uVar2);
    if (*(ushort *)(param_1 + 2) <= uVar2) {
      return (short *)0x0;
    }
    psVar3 = (short *)(*param_1 + uVar2 * 4);
    if ((((*psVar3 == *param_2) && ((char)psVar3[1] == *(char *)((int)param_2 + 0xd))) &&
        (((ushort)psVar3[1] >> 0xe & 1) == (ushort)((bVar1 & 0xc) == 0))) &&
       ((ushort)psVar3[1] >> 0xf == (ushort)((bVar1 & 3) == 1))) break;
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return psVar3;
}

