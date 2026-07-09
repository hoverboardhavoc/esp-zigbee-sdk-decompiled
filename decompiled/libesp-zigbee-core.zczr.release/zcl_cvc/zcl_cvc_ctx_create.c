/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_cvc.o -> zcl_cvc_ctx_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_cvc_ctx_create(undefined1 *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  
  if (param_1 == (undefined1 *)0x0) {
    return 0;
  }
  uVar7 = (uint)*(ushort *)(param_1 + 0xc);
  if ((uVar7 == 0) || (param_2 == (undefined4 *)0x0)) {
    return 0;
  }
  puVar2 = (undefined1 *)*param_2;
  *puVar2 = *param_1;
  iVar3 = *(int *)(param_1 + 0x10);
  *(undefined4 *)(puVar2 + 0x14) = 0;
  if (iVar3 == 0xffff) {
    uVar4 = 1;
_L0:
    uVar7 = 100 / uVar7;
  }
  else {
    if (iVar3 != 0) {
      uVar4 = uVar7 * iVar3;
      goto _L0;
    }
    uVar4 = 1;
    uVar7 = 0;
  }
  *(uint *)(puVar2 + 0x18) = uVar7;
  iVar3 = *(int *)(param_1 + 4);
  iVar5 = *(int *)(param_1 + 8);
  *(uint *)(puVar2 + 0x10) = uVar4;
  if (iVar5 < iVar3) {
    puVar2[1] = 0xff;
  }
  else {
    puVar2[1] = 1;
    if (iVar3 < iVar5) {
      uVar7 = iVar5 - iVar3;
      goto _L0;
    }
  }
  uVar7 = iVar3 - iVar5;
_L0:
  *(undefined4 *)(puVar2 + 0xc) = 0;
  *(uint *)(puVar2 + 4) = uVar7 / uVar4;
  *(uint *)(puVar2 + 8) = uVar7 % uVar4;
  uVar1 = param_1[0x14];
  *(int *)(puVar2 + 0x34) = iVar3;
  puVar2[0x2c] = uVar1;
  uVar6 = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(puVar2 + 0x38) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(puVar2 + 0x3c) = uVar6;
  milli_timer_init(puVar2 + 0x1c,0x10000);
  return 1;
}

