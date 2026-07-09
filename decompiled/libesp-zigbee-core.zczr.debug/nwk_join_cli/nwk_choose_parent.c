/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_choose_parent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_choose_parent(uint param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = core_globals_get();
  uVar5 = 0;
  iVar7 = 0;
  do {
    uVar5 = bitmap_find_next_bit(iVar3 + 0xba4,6,uVar5);
    uVar5 = uVar5 & 0xff;
    if (5 < uVar5) {
      return iVar7;
    }
    iVar2 = iVar3 + 0xb2c + uVar5 * 0x14;
    iVar6 = iVar7;
    if (((*(byte *)(uVar5 * 0x14 + iVar3 + 0x1000 + -0x4cc) == param_1) &&
        (bVar1 = *(byte *)(uVar5 * 0x14 + iVar3 + 0x1000 + -0x4cb), iVar4 = core_globals_get(),
        *(byte *)(iVar4 + 0xa37) <= bVar1)) &&
       (iVar4 = *(int *)(iVar3 + uVar5 * 0x14 + 0xb3c), iVar4 << 2 < 0)) {
      if (param_3 == 0) {
_L0:
        iVar6 = iVar2;
        if ((iVar7 != 0) && (iVar4 = nwk_compare_parent(iVar2,iVar7), iVar6 = iVar7, iVar4 != 0)) {
          iVar6 = iVar2;
        }
      }
      else if (iVar4 << 1 < 0) {
        if (param_2 == 0) {
          iVar4 = iVar4 << 0x11;
        }
        else {
          iVar4 = iVar4 << 0x10;
        }
        if (iVar4 < 0) goto _L0;
      }
    }
    uVar5 = uVar5 + 1 & 0xff;
    iVar7 = iVar6;
  } while( true );
}

