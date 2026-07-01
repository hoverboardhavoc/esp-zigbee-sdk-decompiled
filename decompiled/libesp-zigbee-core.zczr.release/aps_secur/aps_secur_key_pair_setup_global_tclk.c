/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_key_pair_setup_global_tclk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_key_pair_setup_global_tclk(aps_device_key_pair_t *key_pair)

{
  _Bool _Var1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined1 *__src;
  
  iVar2 = core_globals_get();
  _Var1 = secur_is_key_valid((uint8_t *)(iVar2 + 0x990));
  if (CONCAT31(extraout_var,_Var1) == 0) {
    _Var1 = aps_secur_is_centralized();
    if (CONCAT31(extraout_var_00,_Var1) == 0) {
      __src = s_secur_wellknown_secret_0;
    }
    else {
      __src = s_secur_wellknown_secret_0;
    }
  }
  else {
    iVar2 = core_globals_get();
    __src = (undefined1 *)(iVar2 + 0x990);
  }
  key_pair->incoming_frame_cntr = 0;
  key_pair->outgoing_frame_cntr = 0;
  *(byte *)&key_pair->field_8 = *(byte *)&key_pair->field_8 & 0x38 | 1;
  key_pair->timeout = 0xffff;
  memcpy(key_pair->link_key,__src,0x10);
  return;
}

