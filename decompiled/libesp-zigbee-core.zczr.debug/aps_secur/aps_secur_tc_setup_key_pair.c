/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_tc_setup_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_secur_tc_setup_key_pair(aps_device_key_pair_t *key_pair)

{
  bool bVar1;
  ezb_err_t eVar2;
  _Bool _Var3;
  _Bool _Var4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar5;
  bool bVar6;
  
  _Var3 = aps_secur_key_pair_is_ready_for_init_join(key_pair);
  _Var4 = aps_secur_is_centralized();
  if (CONCAT31(extraout_var_00,_Var4) == 0) {
    bVar1 = false;
  }
  else {
    iVar5 = core_globals_get();
    if ((*(ushort *)(iVar5 + 0x9bc) & 6) == 0) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  }
  _Var4 = aps_secur_is_centralized();
  if (CONCAT31(extraout_var_01,_Var4) == 0) {
    bVar6 = true;
  }
  else {
    iVar5 = core_globals_get();
    if ((*(ushort *)(iVar5 + 0x9bc) & 6) == 4) {
      bVar6 = false;
    }
    else {
      bVar6 = true;
    }
  }
  if (CONCAT31(extraout_var,_Var3) == 0) {
    if ((bVar1) && (iVar5 = secur_ic_get_key(key_pair,key_pair->link_key), iVar5 == 0)) {
      aps_secur_key_pair_setup_ic_key_continue(key_pair);
      return 0;
    }
    if (bVar6) {
      aps_secur_key_pair_setup_global_tclk(key_pair);
      return 0;
    }
  }
  if (CONCAT31(extraout_var,_Var3) == 0) {
    eVar2 = -1;
  }
  else {
    eVar2 = 0;
  }
  return eVar2;
}

