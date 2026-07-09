/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_desc.o -> zcl_attr_desc_set_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_attr_desc_set_value(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_a1;
  
  if (param_1 == 0) {
    param_1 = __assert_func(0,0,0);
    param_2 = extraout_a1;
  }
  iVar1 = af_device_desc_is_registered();
  iVar2 = 3;
  if (iVar1 == 0) {
    iVar2 = zcl_write_attr_value(*(undefined4 *)(param_1 + 8),param_2,*(undefined1 *)(param_1 + 2));
    iVar2 = iVar2 + -1;
  }
  return iVar2;
}

