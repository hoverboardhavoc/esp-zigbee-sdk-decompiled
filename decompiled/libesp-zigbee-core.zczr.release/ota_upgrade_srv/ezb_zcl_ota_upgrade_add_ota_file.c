/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_srv.o -> ezb_zcl_ota_upgrade_add_ota_file
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * ezb_zcl_ota_upgrade_add_ota_file(void *param_1,int param_2)

{
  ushort uVar1;
  void *__dest;
  undefined1 *puVar2;
  byte *pbVar3;
  void *__src;
  int iVar4;
  uint uVar5;
  
  if ((param_1 == (void *)0x0) ||
     (pbVar3 = (byte *)ota_upgrade_get_file_table(), pbVar3 == (byte *)0x0)) {
_L0:
    __dest = (void *)0x0;
  }
  else {
    uVar5 = 0;
    do {
      if ((uint)*pbVar3 <= (uVar5 & 0xff)) goto _L0;
      iVar4 = uVar5 * 0x4c;
      uVar5 = uVar5 + 1;
      __dest = (void *)(*(int *)(pbVar3 + 4) + iVar4);
    } while (*(int *)((int)__dest + 0x34) != 0);
    memcpy(__dest,param_1,0x38);
    uVar1 = *(ushort *)((int)__dest + 8);
    iVar4 = 0x38;
    if ((uVar1 & 1) != 0) {
      iVar4 = 0x39;
      *(undefined1 *)((int)__dest + 0x38) = *(undefined1 *)((int)param_1 + 0x38);
    }
    if ((uVar1 & 2) != 0) {
      __src = (void *)((int)param_1 + iVar4);
      iVar4 = iVar4 + 8;
      memcpy((void *)((int)__dest + 0x39),__src,8);
    }
    if ((uVar1 & 4) != 0) {
      *(undefined1 *)((int)__dest + 0x41) = *(undefined1 *)((int)param_1 + iVar4);
      puVar2 = (undefined1 *)(iVar4 + 2 + (int)param_1);
      *(undefined1 *)((int)__dest + 0x42) = ((undefined1 *)((int)param_1 + iVar4))[1];
      *(undefined1 *)((int)__dest + 0x43) = *puVar2;
      *(undefined1 *)((int)__dest + 0x44) = puVar2[1];
    }
    if (*(int *)((int)__dest + 0x34) == param_2) {
      *(void **)((int)__dest + 0x48) = param_1;
    }
    else {
      *(undefined4 *)((int)__dest + 0x34) = 0;
    }
  }
  return __dest;
}

