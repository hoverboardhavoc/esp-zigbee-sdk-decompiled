/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> secur_api.o -> ezb_secur_broadcast_switch_network_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_secur_broadcast_switch_network_key(undefined1 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  
  iVar1 = aps_secur_is_tc();
  if (iVar1 == 0) {
    uVar2 = 0xd;
  }
  else {
    uStack_1c = 0xffffffff;
    uStack_18 = 0xffffffff;
    uStack_14 = param_1;
    uVar2 = apsme_switch_key_request(&uStack_1c);
  }
  return uVar2;
}

