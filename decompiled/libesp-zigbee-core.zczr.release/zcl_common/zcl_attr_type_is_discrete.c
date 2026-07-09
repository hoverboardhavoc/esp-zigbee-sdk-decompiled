/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_attr_type_is_discrete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_attr_type_is_discrete(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((param_1 - 1U & 0xff) < 0xfe) {
    iVar1 = zcl_attr_type_is_analog();
    uVar2 = 0;
    if (iVar1 == 0) {
      uVar2 = zcl_attr_type_is_composite(param_1);
      uVar2 = (uVar2 ^ 1) & 0xff;
    }
    return uVar2 & 1;
  }
  return 0;
}

