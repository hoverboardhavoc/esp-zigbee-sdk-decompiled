/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_iface_mlme_asso_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_iface_mlme_asso_response(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_2c [2];
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  
  uVar3 = *param_1;
  iVar1 = zmsg_alloc(0);
  if (iVar1 == 0) {
    iVar2 = 1;
  }
  else {
    iVar2 = prepare_asso_rsp_msg(uVar3,iVar1,param_2);
    if (iVar2 == 0) {
      auStack_2c[0] = 3;
      uStack_2a = *param_2;
      uStack_28 = param_2[1];
      uStack_26 = param_2[2];
      uStack_24 = param_2[3];
      mac_indirect_transmit(uVar3,auStack_2c,iVar1);
      return 0;
    }
  }
  if (iVar1 != 0) {
    zmsg_free(iVar1);
  }
  return iVar2;
}

