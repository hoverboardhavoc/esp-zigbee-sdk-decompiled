/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_dup.o -> aps_dup_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_dup_table_add(int *param_1,undefined2 *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  undefined2 *puVar7;
  ushort uVar8;
  
  iVar3 = *param_1;
  uVar8 = *(ushort *)(param_1 + 2);
  uVar4 = mempool_alloc_idx(param_1[1],(uint)uVar8);
  if (uVar4 < uVar8) {
    puVar7 = (undefined2 *)(iVar3 + uVar4 * 4);
  }
  else {
    puVar7 = (undefined2 *)0x0;
  }
  if (puVar7 == (undefined2 *)0x0) {
    uVar8 = 0xff;
    uVar4 = 0;
    uVar5 = 0;
    while (uVar5 = bitmap_find_next_bit(param_1[1],(short)param_1[2],uVar5),
          uVar5 < *(ushort *)(param_1 + 2)) {
      uVar6 = *(ushort *)(*param_1 + uVar5 * 4 + 2) >> 8 & 0x3f;
      if (uVar6 < uVar8) {
        uVar4 = uVar5;
        uVar8 = uVar6;
      }
      uVar5 = uVar5 + 1 & 0xffff;
    }
    puVar7 = (undefined2 *)(*param_1 + uVar4 * 4);
  }
  *puVar7 = *param_2;
  *(undefined1 *)(puVar7 + 1) = *(undefined1 *)((int)param_2 + 0xd);
  *(byte *)((int)puVar7 + 3) =
       ((*(byte *)(param_2 + 6) & 0xc) == 0) << 6 | *(byte *)((int)puVar7 + 3) & 0xbf;
  bVar2 = ((*(byte *)(param_2 + 6) & 3) == 1) << 7;
  bVar1 = *(byte *)((int)puVar7 + 3);
  *(byte *)((int)puVar7 + 3) = bVar2 | bVar1 & 0x7f;
  *(byte *)((int)puVar7 + 3) = bVar2 | bVar1 & 0x40 | 7;
  iVar3 = time_ticker_is_receiver_registered(4);
  if (iVar3 == 0) {
    time_ticker_register_receiver(4);
  }
  return;
}

