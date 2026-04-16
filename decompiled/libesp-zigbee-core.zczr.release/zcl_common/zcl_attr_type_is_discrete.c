/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_attr_type_is_discrete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_attr_type_is_discrete(zcl_attr_type_t attr_type)

{
  _Bool _Var1;
  _Bool _Var2;
  undefined3 extraout_var;
  
  if ((byte)(attr_type - 1) < 0xfe) {
    _Var1 = zcl_attr_type_is_analog(attr_type);
    _Var2 = false;
    if (CONCAT31(extraout_var,_Var1) == 0) {
      _Var2 = zcl_attr_type_is_composite(attr_type);
      _Var2 = !_Var2;
    }
    return _Var2;
  }
  return false;
}

