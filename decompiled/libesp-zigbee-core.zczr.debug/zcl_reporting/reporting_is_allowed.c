/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> reporting_is_allowed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000102f0) */
/* WARNING: Unknown calling convention */

_Bool reporting_is_allowed(uint16_t min_interval,uint16_t max_interval)

{
  _Bool _Var1;
  undefined2 in_register_0000202a;
  int iVar2;
  undefined2 in_register_0000202e;
  int iVar3;
  
  iVar3 = CONCAT22(in_register_0000202e,max_interval);
  iVar2 = CONCAT22(in_register_0000202a,min_interval);
  if (iVar2 == 0 && iVar3 == 0) {
    _Var1 = true;
  }
  else if (iVar2 == 0) {
    if (iVar3 == 0xffff) {
      _Var1 = false;
    }
    else {
      _Var1 = true;
    }
  }
  else if (iVar2 == 0xffff) {
    if (iVar3 == 0) {
      _Var1 = false;
    }
    else {
      _Var1 = false;
    }
  }
  else if (iVar3 == 0) {
    _Var1 = true;
  }
  else if (iVar3 == 0xffff) {
    _Var1 = false;
  }
  else {
    _Var1 = true;
  }
  return _Var1;
}

