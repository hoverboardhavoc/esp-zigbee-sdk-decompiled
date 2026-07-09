/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> addr_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void addr_table_add(int param_1,undefined2 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined3 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_18 = 0xffffffff;
  uStack_14 = 0xffffffff;
  uVar4 = addr_table_new();
  if (*(ushort *)(param_1 + 8) <= uVar4) {
    uVar4 = addr_table_lru_reuse(param_1);
  }
  if (uVar4 < *(ushort *)(param_1 + 8)) {
    puVar5 = (undefined1 *)(*(int *)(param_1 + 4) + uVar4 * 0x12);
    *(undefined2 *)(puVar5 + 8) = param_2;
    if (param_3 == (undefined4 *)0x0) {
      param_3 = &local_18;
    }
    uVar1 = *param_3;
    uVar2 = *(undefined3 *)(param_3 + 1);
    uVar3 = param_3[1];
    *puVar5 = (char)*(undefined3 *)param_3;
    puVar5[1] = (char)((uint)uVar1 >> 8);
    puVar5[2] = (char)((uint)uVar1 >> 0x10);
    puVar5[3] = (char)((uint)uVar1 >> 0x18);
    puVar5[4] = (char)uVar2;
    puVar5[5] = (char)((uint)uVar3 >> 8);
    puVar5[6] = (char)((uint)uVar3 >> 0x10);
    puVar5[7] = (char)((uint)uVar3 >> 0x18);
  }
  return;
}

