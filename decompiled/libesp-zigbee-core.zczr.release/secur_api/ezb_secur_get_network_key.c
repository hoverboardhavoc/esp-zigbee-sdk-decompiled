/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> secur_api.o -> ezb_secur_get_network_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_secur_get_network_key(void *param_1)

{
  void *__src;
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != (void *)0x0) {
    nwk_secur_get_current_key_seq();
    __src = (void *)nwk_secur_get_key_by_seq();
    iVar1 = secur_is_key_valid();
    uVar2 = 5;
    if (iVar1 != 0) {
      memcpy(param_1,__src,0x10);
      uVar2 = 0;
    }
    return uVar2;
  }
  return 2;
}

