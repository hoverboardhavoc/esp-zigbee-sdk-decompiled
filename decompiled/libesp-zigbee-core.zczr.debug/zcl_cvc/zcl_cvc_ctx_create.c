/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_cvc.o -> zcl_cvc_ctx_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_cvc_ctx_create(undefined1 *param_1,int *param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar2 = 0;
  }
  else if (*(short *)(param_1 + 0xc) == 0) {
    uVar2 = 0;
  }
  else if (param_2 == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    *(undefined1 *)*param_2 = *param_1;
    *(undefined4 *)(*param_2 + 0x14) = 0;
    if (*(int *)(param_1 + 0x10) == 0xffff) {
      iVar3 = 1;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x10) * (uint)*(ushort *)(param_1 + 0xc);
    }
    *(int *)(*param_2 + 0x10) = iVar3;
    if (*(int *)(param_1 + 0x10) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = *(undefined4 *)(*param_2 + 0x10);
    }
    *(undefined4 *)(*param_2 + 0x10) = uVar2;
    uVar4 = *(uint *)(param_1 + 0x10);
    if (uVar4 != 0) {
      uVar4 = 100 / *(ushort *)(param_1 + 0xc);
    }
    *(uint *)(*param_2 + 0x18) = uVar4;
    if (*(int *)(param_1 + 8) < *(int *)(param_1 + 4)) {
      uVar1 = 0xff;
    }
    else {
      uVar1 = 1;
    }
    *(undefined1 *)(*param_2 + 1) = uVar1;
    iVar3 = *(int *)(param_1 + 8);
    iVar5 = *(int *)(param_1 + 4);
    if (iVar5 < iVar3) {
      uVar4 = iVar3 - iVar5;
    }
    else {
      uVar4 = iVar5 - iVar3;
    }
    *(uint *)(*param_2 + 4) = uVar4 / *(uint *)(*param_2 + 0x10);
    iVar3 = *(int *)(param_1 + 8);
    iVar5 = *(int *)(param_1 + 4);
    if (iVar5 < iVar3) {
      uVar4 = iVar3 - iVar5;
    }
    else {
      uVar4 = iVar5 - iVar3;
    }
    *(uint *)(*param_2 + 8) = uVar4 % *(uint *)(*param_2 + 0x10);
    *(undefined4 *)(*param_2 + 0xc) = 0;
    *(undefined1 *)(*param_2 + 0x2c) = param_1[0x14];
    *(undefined4 *)(*param_2 + 0x34) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(*param_2 + 0x38) = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(*param_2 + 0x3c) = *(undefined4 *)(param_1 + 0x1c);
    milli_timer_init(*param_2 + 0x1c,0x10000);
    uVar2 = 1;
  }
  return uVar2;
}

