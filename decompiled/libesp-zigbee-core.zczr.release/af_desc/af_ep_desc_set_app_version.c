/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_ep_desc_set_app_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_ep_desc_set_app_version(int param_1,byte param_2)

{
  int iVar1;
  byte extraout_a1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    param_1 = __assert_func(0,0,0);
    param_2 = extraout_a1;
  }
  iVar1 = af_device_desc_is_registered();
  uVar2 = 3;
  if (iVar1 == 0) {
    *(byte *)(param_1 + 0x12) = *(byte *)(param_1 + 0x12) & 0xf0 | param_2 & 0xf;
    uVar2 = 0;
  }
  return uVar2;
}

