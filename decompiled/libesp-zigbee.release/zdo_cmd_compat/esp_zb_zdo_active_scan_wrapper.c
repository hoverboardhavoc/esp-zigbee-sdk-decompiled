/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_active_scan_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_active_scan_wrapper(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  void *__s1;
  
  uVar3 = (uint)*(byte *)(param_2 + 0x71);
  if (param_1 == 0) {
    puVar1 = (undefined4 *)0x0;
    if (uVar3 != 0) {
      puVar1 = param_2 + 1;
    }
    if ((code *)*param_2 != (code *)0x0) {
      (*(code *)*param_2)(0,uVar3,puVar1);
    }
    free(param_2);
    return;
  }
  if (uVar3 < 0x20) {
    __s1 = (void *)((int)param_2 + 7);
    for (iVar4 = 0; iVar4 < (int)uVar3; iVar4 = iVar4 + 1) {
      iVar2 = memcmp(__s1,(void *)(param_1 + 4),8);
      __s1 = (void *)((int)__s1 + 0xe);
      if (iVar2 == 0) {
        return;
      }
    }
    iVar4 = uVar3 * 0xe;
    *(undefined2 *)((int)param_2 + iVar4 + 4) = *(undefined2 *)(param_1 + 2);
    *(byte *)((int)param_2 + iVar4 + 6) = (byte)*(undefined2 *)(param_1 + 0x10) & 1;
    memcpy((void *)((int)param_2 + iVar4 + 7),(void *)(param_1 + 4),8);
    *(undefined1 *)((int)param_2 + iVar4 + 0xf) = *(undefined1 *)(param_1 + 0xd);
    *(byte *)((int)param_2 + iVar4 + 0x10) = (byte)(*(ushort *)(param_1 + 0x10) >> 1) & 1;
    *(byte *)((int)param_2 + iVar4 + 0x11) = (byte)(*(ushort *)(param_1 + 0x10) >> 2) & 1;
    *(char *)(param_2 + 0x71) = *(char *)(param_2 + 0x71) + '\x01';
  }
  return;
}

