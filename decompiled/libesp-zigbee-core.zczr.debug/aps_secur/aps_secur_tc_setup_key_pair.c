/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  bool bVar2;
  _Bool _Var3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  ezb_err_t eVar4;
  int iVar5;
  
  _Var3 = aps_secur_is_centralized();
  if (CONCAT31(extraout_var,_Var3) == 0) {
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
  _Var3 = aps_secur_is_centralized();
  if (CONCAT31(extraout_var_00,_Var3) == 0) {
    bVar2 = true;
  }
  else {
    iVar5 = core_globals_get();
    if ((*(ushort *)(iVar5 + 0x9bc) & 6) == 4) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
  }
  if ((bVar1) && (iVar5 = secur_ic_get_key(key_pair,key_pair->link_key), iVar5 == 0)) {
    aps_secur_key_pair_setup_ic_key_continue(key_pair);
  }
  else {
    bVar1 = bVar2;
    if (bVar2) {
      aps_secur_key_pair_setup_global_tclk(key_pair);
      return 0;
    }
  }
  if (bVar1) {
    eVar4 = 0;
  }
  else {
    eVar4 = -1;
  }
  return eVar4;
}

