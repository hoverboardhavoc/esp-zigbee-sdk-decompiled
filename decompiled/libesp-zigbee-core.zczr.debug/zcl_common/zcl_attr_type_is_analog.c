/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_attr_type_is_analog
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_attr_type_is_analog(zcl_attr_type_t attr_type)

{
  undefined3 in_register_00002029;
  uint uVar1;
  
  uVar1 = CONCAT31(in_register_00002029,attr_type);
  if (0x3a < uVar1) {
    if (2 < (uVar1 + 0x20 & 0xff)) {
      return false;
    }
    return true;
  }
  if (uVar1 < 0x38) {
    if (0xf < (uVar1 - 0x20 & 0xff)) {
      return false;
    }
    return true;
  }
  return true;
}

