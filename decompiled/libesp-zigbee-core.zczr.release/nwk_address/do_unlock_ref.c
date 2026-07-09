/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> do_unlock_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void do_unlock_ref(undefined4 *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  
  iVar3 = check_table_ref(param_2,*param_1,*(undefined2 *)(param_1 + 2));
  if (iVar3 != 0) {
    iVar3 = param_1[1] + param_2 * 0x12;
    uVar6 = (uint)*(byte *)(iVar3 + 0x10);
    if (uVar6 == 0) {
      __assert_func(0,0,0,0);
    }
    *(char *)(iVar3 + 0x10) = (char)(uVar6 - 1);
    if ((uVar6 - 1 & 0xff) == 0) {
      if ((*(ushort *)(iVar3 + 0x10) >> 10 & 3) == 0) {
        iVar3 = param_1[1];
        iVar2 = param_2 * 0x12 + iVar3;
        if ((*(short *)(iVar2 + 10) == -1) || (*(short *)(iVar2 + 0xc) == -1)) {
          uVar4 = (undefined2)param_2;
          if ((uint)*(ushort *)((int)param_1 + 10) < (uint)*(ushort *)(param_1 + 2)) {
            uVar1 = *(ushort *)((uint)*(ushort *)((int)param_1 + 10) * 0x12 + iVar3 + 10);
            *(ushort *)(iVar2 + 10) = uVar1;
            iVar5 = (uint)uVar1 * 0x12 + iVar3;
            *(undefined2 *)(iVar2 + 0xc) = *(undefined2 *)(iVar5 + 0xc);
            if (uVar1 != 0xffff) {
              *(undefined2 *)(iVar5 + 0xc) = uVar4;
            }
            if (*(ushort *)(iVar2 + 0xc) != 0xffff) {
              *(undefined2 *)(iVar3 + (uint)*(ushort *)(iVar2 + 0xc) * 0x12 + 10) = uVar4;
            }
          }
          else {
            *(undefined2 *)(iVar2 + 10) = uVar4;
            *(undefined2 *)(iVar2 + 0xc) = uVar4;
          }
          *(undefined2 *)((int)param_1 + 10) = uVar4;
        }
        return;
      }
      iVar3 = core_globals_get();
      iVar2 = check_table_ref(param_2,*(undefined4 *)(iVar3 + 0xc4c),*(undefined2 *)(iVar3 + 0xc54))
      ;
      if (iVar2 != 0) {
        iVar2 = *(int *)(iVar3 + 0xc50) + param_2 * 0x12;
        if (*(char *)(iVar2 + 0x10) == '\0') {
          test_and_clr_bitmap(param_2,*(undefined4 *)(iVar3 + 0xc4c));
          addr_table_lru_remove(iVar3 + 0xc4c,param_2);
          memset((void *)(*(int *)(iVar3 + 0xc50) + param_2 * 0x12),0,0x12);
          return;
        }
        *(byte *)(iVar2 + 0x11) = *(byte *)(iVar2 + 0x11) | 8;
      }
      return;
    }
  }
  return;
}

