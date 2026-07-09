/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ezb_zcl_ota_upgrade_add_ota_file
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * ezb_zcl_ota_upgrade_add_ota_file(void *param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  ushort uVar8;
  void *__dest;
  int iVar9;
  undefined1 *puVar10;
  
  if (param_1 == (void *)0x0) {
    __dest = (void *)0x0;
  }
  else {
    ota_upgrade_get_file_table();
    __dest = (void *)ota_upgrade_file_table_get_empty_entry();
    if (__dest != (void *)0x0) {
      memcpy(__dest,param_1,0x38);
      uVar8 = *(ushort *)((int)__dest + 8);
      if ((uVar8 & 1) == 0) {
        iVar9 = 0x38;
      }
      else {
        *(undefined1 *)((int)__dest + 0x38) = *(undefined1 *)((int)param_1 + 0x38);
        iVar9 = 0x39;
      }
      if ((uVar8 & 2) != 0) {
        puVar10 = (undefined1 *)((int)param_1 + iVar9);
        uVar1 = puVar10[1];
        uVar2 = puVar10[2];
        uVar3 = puVar10[3];
        uVar4 = puVar10[4];
        uVar5 = puVar10[5];
        uVar6 = puVar10[6];
        uVar7 = puVar10[7];
        *(undefined1 *)((int)__dest + 0x39) = *puVar10;
        *(undefined1 *)((int)__dest + 0x3a) = uVar1;
        *(undefined1 *)((int)__dest + 0x3b) = uVar2;
        *(undefined1 *)((int)__dest + 0x3c) = uVar3;
        *(undefined1 *)((int)__dest + 0x3d) = uVar4;
        *(undefined1 *)((int)__dest + 0x3e) = uVar5;
        *(undefined1 *)((int)__dest + 0x3f) = uVar6;
        *(undefined1 *)((int)__dest + 0x40) = uVar7;
        iVar9 = iVar9 + 8;
      }
      if ((uVar8 & 4) != 0) {
        *(undefined1 *)((int)__dest + 0x41) = *(undefined1 *)((int)param_1 + iVar9);
        *(undefined1 *)((int)__dest + 0x42) = ((undefined1 *)((int)param_1 + iVar9))[1];
        puVar10 = (undefined1 *)(iVar9 + 2 + (int)param_1);
        *(undefined1 *)((int)__dest + 0x43) = *puVar10;
        *(undefined1 *)((int)__dest + 0x44) = puVar10[1];
      }
      if (*(int *)((int)__dest + 0x34) == param_2) {
        *(void **)((int)__dest + 0x48) = param_1;
      }
      else {
        *(undefined4 *)((int)__dest + 0x34) = 0;
      }
    }
  }
  return __dest;
}

