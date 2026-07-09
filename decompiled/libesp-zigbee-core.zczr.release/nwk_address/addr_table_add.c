/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> addr_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint addr_table_add(undefined4 *param_1,undefined2 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined3 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_28;
  undefined4 uStack_24;
  
  local_28 = 0xffffffff;
  uStack_24 = 0xffffffff;
  uVar4 = bitmap_find_first_zero_bit(*param_1,*(undefined2 *)(param_1 + 2));
  uVar7 = (uint)*(ushort *)(param_1 + 2);
  if (uVar4 < uVar7) {
    test_and_set_bitmap(*param_1);
    iVar8 = param_1[1];
    iVar5 = uVar4 * 0x12 + iVar8;
    *(undefined2 *)(iVar5 + 0xc) = 0xffff;
    *(undefined2 *)(iVar5 + 10) = 0xffff;
    addr_table_lru_add(param_1,uVar4);
    uVar7 = (uint)*(ushort *)(param_1 + 2);
    if (uVar4 < uVar7) goto _L0;
  }
  if (uVar7 <= *(ushort *)((int)param_1 + 10)) {
    return 0xffff;
  }
  iVar8 = param_1[1];
  uVar4 = (uint)*(ushort *)((uint)*(ushort *)((int)param_1 + 10) * 0x12 + iVar8 + 10);
  addr_table_lru_update(param_1,uVar4);
  if (uVar7 <= uVar4) {
    return uVar4;
  }
_L0:
  puVar6 = (undefined1 *)(uVar4 * 0x12 + iVar8);
  *(undefined2 *)(puVar6 + 8) = param_2;
  if (param_3 == (undefined4 *)0x0) {
    param_3 = &local_28;
  }
  uVar1 = *param_3;
  uVar2 = *(undefined3 *)(param_3 + 1);
  uVar3 = param_3[1];
  *puVar6 = (char)*(undefined3 *)param_3;
  puVar6[1] = (char)((uint)uVar1 >> 8);
  puVar6[3] = (char)((uint)uVar1 >> 0x18);
  puVar6[5] = (char)((uint)uVar3 >> 8);
  puVar6[2] = (char)((uint)uVar1 >> 0x10);
  puVar6[4] = (char)uVar2;
  puVar6[6] = (char)((uint)uVar3 >> 0x10);
  puVar6[7] = (char)((uint)uVar3 >> 0x18);
  return uVar4;
}

