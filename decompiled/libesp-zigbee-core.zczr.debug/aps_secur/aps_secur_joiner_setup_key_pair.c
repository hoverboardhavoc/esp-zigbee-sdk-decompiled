/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_joiner_setup_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_secur_joiner_setup_key_pair(aps_device_key_pair_t *key_pair)

{
  _Bool _Var1;
  undefined3 extraout_var;
  int iVar2;
  
  _Var1 = aps_secur_is_centralized();
  if ((CONCAT31(extraout_var,_Var1) == 0) ||
     (iVar2 = secur_ic_get_tclk(key_pair->link_key), iVar2 != 0)) {
    aps_secur_key_pair_setup_global_tclk(key_pair);
  }
  else {
    aps_secur_key_pair_setup_ic_key_continue(key_pair);
  }
  return 0;
}

