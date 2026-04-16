/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_set_ed_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_set_ed_timeout(nwk_ed_timeout_t timeout)

{
  _Bool _Var1;
  undefined3 in_register_00002029;
  undefined3 extraout_var;
  ezb_err_t eVar2;
  int iVar3;
  
  if (CONCAT31(in_register_00002029,timeout) < 0xf) {
    _Var1 = nwk_is_device_zed();
    if (CONCAT31(extraout_var,_Var1) == 0) {
      iVar3 = core_globals_get();
      *(nwk_ed_timeout_t *)(iVar3 + 0xa29) = timeout;
      eVar2 = 0;
    }
    else {
      nwk_ed_set_timeout(CONCAT31(in_register_00002029,timeout));
      eVar2 = 0;
    }
  }
  else {
    eVar2 = 2;
  }
  return eVar2;
}

