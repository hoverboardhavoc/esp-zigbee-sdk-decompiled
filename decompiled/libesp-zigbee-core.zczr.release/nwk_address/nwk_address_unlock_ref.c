/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_unlock_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_address_unlock_ref(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar3 = core_globals_get();
  do_unlock_ref(param_1);
  iVar8 = *(int *)(iVar3 + 0xc50) + param_1 * 0x12;
  if ((*(byte *)(iVar8 + 0x11) & 4) == 0) {
    return;
  }
  uVar2 = *(ushort *)(iVar8 + 0xe);
  uVar4 = (uint)uVar2;
  iVar8 = check_table_ref(uVar4,*(undefined4 *)(iVar3 + 0xc4c),*(undefined2 *)(iVar3 + 0xc54));
  if (iVar8 != 0) {
    iVar8 = *(int *)(iVar3 + 0xc50) + uVar4 * 0x12;
    uVar7 = (uint)*(byte *)(iVar8 + 0x10);
    if (uVar7 == 0) {
      __assert_func(0,0,0,0);
    }
    *(char *)(iVar8 + 0x10) = (char)(uVar7 - 1);
    if ((uVar7 - 1 & 0xff) == 0) {
      if ((*(ushort *)(iVar8 + 0x10) >> 10 & 3) == 0) {
        iVar8 = *(int *)(iVar3 + 0xc50);
        iVar6 = uVar4 * 0x12 + iVar8;
        if ((*(short *)(iVar6 + 10) == -1) || (*(short *)(iVar6 + 0xc) == -1)) {
          if ((uint)*(ushort *)(iVar3 + 0xc56) < (uint)*(ushort *)(iVar3 + 0xc54)) {
            uVar1 = *(ushort *)((uint)*(ushort *)(iVar3 + 0xc56) * 0x12 + iVar8 + 10);
            *(ushort *)(iVar6 + 10) = uVar1;
            iVar5 = (uint)uVar1 * 0x12 + iVar8;
            *(undefined2 *)(iVar6 + 0xc) = *(undefined2 *)(iVar5 + 0xc);
            if (uVar1 != 0xffff) {
              *(ushort *)(iVar5 + 0xc) = uVar2;
            }
            if (*(ushort *)(iVar6 + 0xc) != 0xffff) {
              *(ushort *)(iVar8 + (uint)*(ushort *)(iVar6 + 0xc) * 0x12 + 10) = uVar2;
            }
          }
          else {
            *(ushort *)(iVar6 + 10) = uVar2;
            *(ushort *)(iVar6 + 0xc) = uVar2;
          }
          *(ushort *)(iVar3 + 0xc56) = uVar2;
        }
        return;
      }
      iVar3 = core_globals_get();
      iVar8 = check_table_ref(uVar4,*(undefined4 *)(iVar3 + 0xc4c),*(undefined2 *)(iVar3 + 0xc54));
      if (iVar8 != 0) {
        iVar8 = *(int *)(iVar3 + 0xc50) + uVar4 * 0x12;
        if (*(char *)(iVar8 + 0x10) == '\0') {
          test_and_clr_bitmap(uVar4,*(undefined4 *)(iVar3 + 0xc4c));
          addr_table_lru_remove(iVar3 + 0xc4c,uVar4);
          memset((void *)(*(int *)(iVar3 + 0xc50) + uVar4 * 0x12),0,0x12);
          return;
        }
        *(byte *)(iVar8 + 0x11) = *(byte *)(iVar8 + 0x11) | 8;
      }
      return;
    }
  }
  return;
}

