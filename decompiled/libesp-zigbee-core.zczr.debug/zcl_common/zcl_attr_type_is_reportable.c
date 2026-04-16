/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_attr_type_is_reportable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_attr_type_is_reportable(zcl_attr_type_t attr_type)

{
  bool bVar1;
  
  bVar1 = 9 < (attr_type - 0x48 & 0xff);
  if ((!bVar1) && ((0x317U >> (attr_type - 0x48 & 0x1f) & 1) == 0)) {
    return true;
  }
  return bVar1;
}

