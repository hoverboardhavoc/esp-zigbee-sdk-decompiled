/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_joiner_setup_key_pair
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
  
  if ((((key_pair->field_8).flags & 6) != 0) ||
     (_Var1 = secur_is_key_valid(key_pair->link_key), CONCAT31(extraout_var,_Var1) == 0)) {
    _Var1 = aps_secur_is_centralized();
    if (CONCAT31(extraout_var_00,_Var1) != 0) {
      iVar2 = secur_ic_get_tclk(key_pair->link_key);
      if (iVar2 == 0) {
        memcpy(key_pair->passphrase,key_pair->link_key,0x10);
        key_pair->incoming_frame_cntr = 0;
        key_pair->outgoing_frame_cntr = 0;
        *(byte *)&key_pair->field_8 = *(byte *)&key_pair->field_8 & 0x38 | 0x40;
        key_pair->timeout = 0xffff;
        return 0;
      }
    }
    aps_secur_key_pair_setup_global_tclk(key_pair);
  }
  return 0;
}

