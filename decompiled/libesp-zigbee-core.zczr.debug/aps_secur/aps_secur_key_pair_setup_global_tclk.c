/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_setup_global_tclk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_key_pair_setup_global_tclk(aps_device_key_pair_t *key_pair)

{
  ushort uVar1;
  _Bool _Var2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint8_t *__src;
  ushort uVar4;
  
  iVar3 = core_globals_get();
  _Var2 = secur_is_key_valid((uint8_t *)(iVar3 + 0x990));
  if (CONCAT31(extraout_var,_Var2) == 0) {
    _Var2 = aps_secur_is_centralized();
    if (CONCAT31(extraout_var_00,_Var2) == 0) {
      __src = aps_secur_get_wellknown_secret('\x01');
    }
    else {
      __src = aps_secur_get_wellknown_secret('\0');
    }
  }
  else {
    iVar3 = core_globals_get();
    __src = (uint8_t *)(iVar3 + 0x990);
  }
  uVar1 = (key_pair->field_8).flags;
  uVar4 = uVar1 & 0xfff9;
  (key_pair->field_8).flags = uVar4;
  (key_pair->field_8).flags = uVar4 | 1;
  (key_pair->field_8).flags = uVar1 & 0xff39 | 1;
  key_pair->timeout = 0xffff;
  key_pair->incoming_frame_cntr = 0;
  key_pair->outgoing_frame_cntr = 0;
  memcpy(key_pair->link_key,__src,0x10);
  return;
}

