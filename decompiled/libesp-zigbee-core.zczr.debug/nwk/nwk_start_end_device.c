/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_start_end_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_start_end_device(void)

{
  _Bool _Var1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  
  _Var1 = nwk_is_joined_and_authed();
  if ((CONCAT31(extraout_var,_Var1) != 0) &&
     (_Var1 = nwk_is_device_zed(), CONCAT31(extraout_var_00,_Var1) != 0)) {
    iVar2 = core_globals_get();
    if (*(char *)(iVar2 + 0x9ee) == '\0') {
      nwk_pim_start_poll();
    }
    nwk_ed_start_keepalive();
    return 0;
  }
  return 0x2c2;
}

