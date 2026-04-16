/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_is_device_zczr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_is_device_zczr(void)

{
  _Bool _Var1;
  undefined3 extraout_var;
  int iVar2;
  undefined3 extraout_var_00;
  
  _Var1 = nwk_is_device_zc();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    _Var1 = nwk_is_device_zr();
    iVar2 = CONCAT31(extraout_var_00,_Var1);
    if (iVar2 != 0) {
      iVar2 = 1;
    }
  }
  else {
    iVar2 = 1;
  }
  return SUB41(iVar2,0);
}

