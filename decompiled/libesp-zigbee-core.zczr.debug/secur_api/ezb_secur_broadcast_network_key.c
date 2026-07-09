/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> secur_api.o -> ezb_secur_broadcast_network_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_secur_broadcast_network_key(void *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  if (param_1 == (void *)0x0) {
    uVar2 = 2;
  }
  else {
    iVar1 = aps_secur_is_tc();
    if (iVar1 == 0) {
      uVar2 = 0xd;
    }
    else {
      uStack_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_20 = 0;
      uStack_1c = 0;
      uStack_18 = 0;
      uStack_14 = 0;
      uStack_34 = 1;
      iStack_24 = (param_2 & 0xff) << 8;
      uStack_3c = 0xffffffff;
      uStack_38 = 0xffffffff;
      memcpy((void *)((int)&uStack_34 + 1),param_1,0x10);
      uVar2 = apsme_transport_key_request(&uStack_3c);
    }
  }
  return uVar2;
}

