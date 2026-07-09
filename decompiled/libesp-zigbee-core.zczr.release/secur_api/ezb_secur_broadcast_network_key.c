/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> secur_api.o -> ezb_secur_broadcast_network_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_secur_broadcast_network_key(void *param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 uStack_34;
  undefined1 auStack_33 [16];
  undefined1 uStack_23;
  undefined1 auStack_22 [22];
  
  if (param_1 != (void *)0x0) {
    iVar1 = aps_secur_is_tc();
    uVar2 = 0xd;
    if (iVar1 != 0) {
      memset(auStack_22,0,0x10);
      uStack_34 = 1;
      uStack_3c = 0xffffffff;
      uStack_38 = 0xffffffff;
      uStack_23 = param_2;
      memcpy(auStack_33,param_1,0x10);
      uVar2 = apsme_transport_key_request(&uStack_3c);
    }
    return uVar2;
  }
  return 2;
}

