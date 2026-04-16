/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> secur_api.o -> ezb_secur_get_network_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_secur_get_network_key(uint8_t *key)

{
  _Bool _Var1;
  uint8_t *key_00;
  undefined3 extraout_var;
  ezb_err_t eVar2;
  
  if (key == (uint8_t *)0x0) {
    eVar2 = 2;
  }
  else {
    nwk_secur_get_current_key_seq();
    key_00 = (uint8_t *)nwk_secur_get_key_by_seq();
    _Var1 = secur_is_key_valid(key_00);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      eVar2 = 5;
    }
    else {
      memcpy(key,key_00,0x10);
      eVar2 = 0;
    }
  }
  return eVar2;
}

