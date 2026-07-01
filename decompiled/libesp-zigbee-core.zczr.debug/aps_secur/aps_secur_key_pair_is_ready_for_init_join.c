/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_is_ready_for_init_join
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_secur_key_pair_is_ready_for_init_join(aps_device_key_pair_t *key_pair)

{
  _Bool _Var1;
  undefined3 extraout_var;
  
  if (((key_pair->field_8).flags & 6) == 0) {
    _Var1 = secur_is_key_valid(key_pair->link_key);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      _Var1 = false;
    }
    else {
      _Var1 = true;
    }
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

