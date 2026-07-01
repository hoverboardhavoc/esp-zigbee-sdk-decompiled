/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
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
  undefined3 extraout_var_00;
  int iVar2;
  
  _Var1 = aps_secur_key_pair_is_ready_for_init_join(key_pair);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    _Var1 = aps_secur_is_centralized();
    if ((CONCAT31(extraout_var_00,_Var1) == 0) ||
       (iVar2 = secur_ic_get_tclk(key_pair->link_key), iVar2 != 0)) {
      aps_secur_key_pair_setup_global_tclk(key_pair);
    }
    else {
      aps_secur_key_pair_setup_ic_key_continue(key_pair);
    }
  }
  return 0;
}

