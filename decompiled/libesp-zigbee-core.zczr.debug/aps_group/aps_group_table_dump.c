/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_dump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_group_table_dump(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = core_globals_get();
  log_write(3,"aps_group.c","Dump APS Group Table");
  uVar5 = 0;
  while (uVar5 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar3 + 0x960),*(undefined2 *)(iVar3 + 0x964),uVar5),
        uVar5 < *(ushort *)(iVar3 + 0x964)) {
    puVar2 = (undefined2 *)(*(int *)(iVar3 + 0x95c) + uVar5 * 0x22);
    uVar1 = *puVar2;
    iVar4 = group_is_empty(puVar2);
    if (iVar4 == 0) {
      iVar4 = -0x4bc;
    }
    else {
      iVar4 = -0x4c4;
    }
    log_write(3,"aps_group.c","Group 0x%04x:%s",uVar1,core_globals_get + iVar4);
    iVar4 = 0xff;
    while (iVar4 = aps_group_next_endpoint(puVar2,iVar4 + 1U & 0xff), iVar4 != 0xff) {
      log_write(3,"aps_group.c","  - Endpoint %d",iVar4);
    }
    uVar5 = uVar5 + 1 & 0xffff;
  }
  return;
}

