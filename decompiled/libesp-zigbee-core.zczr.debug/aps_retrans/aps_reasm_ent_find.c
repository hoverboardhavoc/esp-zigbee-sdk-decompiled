/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_reasm_ent_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_reasm_ent_find(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    uVar2 = bitmap_find_next_bit(param_1 + 0x500,0x20,uVar2);
    uVar2 = uVar2 & 0xff;
    if (0x1f < uVar2) {
      return 0;
    }
    iVar1 = uVar2 * 0x28 + param_1;
    if ((*(byte *)(iVar1 + 0xe) == param_3) && (*(ushort *)(iVar1 + 0xc) == param_2)) break;
    uVar2 = uVar2 + 1 & 0xff;
  }
  return iVar1;
}

