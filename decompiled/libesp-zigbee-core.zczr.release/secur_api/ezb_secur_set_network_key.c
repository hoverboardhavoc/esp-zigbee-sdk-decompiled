/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> secur_api.o -> ezb_secur_set_network_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_secur_set_network_key(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zdo_dev_joined();
  uVar2 = 3;
  if (iVar1 == 0) {
    iVar1 = secur_is_key_valid(param_1);
    uVar2 = 2;
    if (iVar1 != 0) {
      uVar2 = nwk_secur_get_current_key_seq();
      nwk_secur_set_key(param_1,uVar2);
      uVar2 = 0;
    }
  }
  return uVar2;
}

