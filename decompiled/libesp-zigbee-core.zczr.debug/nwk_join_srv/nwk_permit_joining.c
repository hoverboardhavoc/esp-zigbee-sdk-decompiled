/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_permit_joining
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_permit_joining(uint8_t permit_duration)

{
  _Bool _Var1;
  undefined3 extraout_var;
  ezb_err_t eVar2;
  
  _Var1 = nwk_is_router_started();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    eVar2 = 0x2c2;
  }
  else {
    nwk_set_permit_joining_duration(permit_duration);
    eVar2 = 0;
  }
  return eVar2;
}

