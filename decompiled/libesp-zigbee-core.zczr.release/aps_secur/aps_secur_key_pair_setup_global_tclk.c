/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  key_pair->outgoing_frame_cntr = 0;
  *(byte *)&key_pair->field_8 = *(byte *)&key_pair->field_8 & 0x38 | 1;
  key_pair->timeout = 0xffff;
  key_pair->incoming_frame_cntr = 0xffffffff;
  memcpy(key_pair->link_key,__src,0x10);
  return;
}

