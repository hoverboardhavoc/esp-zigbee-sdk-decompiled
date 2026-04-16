/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> secur_api.o -> ezb_secur_set_network_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_secur_set_network_key(uint8_t *key)

{
  _Bool _Var1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  ezb_err_t eVar4;
  
  iVar2 = zdo_dev_joined();
  if (iVar2 == 0) {
    _Var1 = secur_is_key_valid(key);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      eVar4 = 2;
    }
    else {
      uVar3 = nwk_secur_get_current_key_seq();
      nwk_secur_set_key(key,uVar3);
      eVar4 = 0;
    }
  }
  else {
    eVar4 = 3;
  }
  return eVar4;
}

