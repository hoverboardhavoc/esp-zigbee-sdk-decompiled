/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_cvc.o -> zcl_cvc_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_cvc_start(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = milli_timer_get_now();
  if ((param_1 != (undefined1 *)0x0) && (*(code **)(param_1 + 0x38) != (code *)0x0)) {
    uVar5 = *(uint *)(param_1 + 0x14);
    uVar4 = *(uint *)(param_1 + 0x10);
    if (uVar5 <= uVar4) {
      if (uVar5 == 0) {
        *(int *)(param_1 + 0x30) = iVar1;
      }
      else {
        iVar2 = *(int *)(param_1 + 0x34) + (int)(char)param_1[1] * *(int *)(param_1 + 4);
        *(int *)(param_1 + 0x34) = iVar2;
        uVar3 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 8);
        *(uint *)(param_1 + 0xc) = uVar3;
        if (uVar4 <= uVar3) {
          *(int *)(param_1 + 0x34) = iVar2 + (char)param_1[1];
          *(uint *)(param_1 + 0xc) = uVar3 - uVar4;
        }
      }
      if (param_1[0x2c] == '\x01') {
        *(undefined4 *)(param_1 + 0x14) = 1;
        iVar1 = *(int *)(param_1 + 0x18) + iVar1;
        iVar2 = 0xffff;
      }
      else {
        iVar2 = (*(uint *)(param_1 + 0x18) / 100) * (uVar4 - uVar5);
        *(uint *)(param_1 + 0x14) = uVar5 + 1;
        iVar1 = *(uint *)(param_1 + 0x18) * (uVar5 + 1) + *(int *)(param_1 + 0x30);
      }
      (**(code **)(param_1 + 0x38))
                (*param_1,*(undefined4 *)(param_1 + 0x34),iVar2,*(undefined4 *)(param_1 + 0x3c));
      milli_timer_fire_at(param_1 + 0x1c,iVar1);
    }
  }
  return;
}

