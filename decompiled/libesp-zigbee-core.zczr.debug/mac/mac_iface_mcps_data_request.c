/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_iface_mcps_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_iface_mcps_data_request(undefined4 *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = *param_1;
  iVar1 = mac_is_enabled(uVar3);
  if (iVar1 == 0) {
    iVar1 = 3;
  }
  else if (param_2 == (int *)0x0) {
    iVar1 = 2;
  }
  else {
    iVar4 = *param_2;
    if (iVar4 == 0) {
      iVar1 = 2;
    }
    else {
      iVar1 = prepare_data_msg(uVar3,iVar4,param_2);
      if (iVar1 == 0) {
        uVar2 = zmsg_get_length(iVar4);
        if (uVar2 < 0x7e) {
          if ((*(byte *)((int)param_2 + 0x1a) & 2) == 0) {
            mac_direct_transmit(uVar3,iVar4);
          }
          else {
            mac_indirect_transmit(uVar3,(int)param_2 + 0xe,iVar4);
          }
        }
        else {
          iVar1 = 4;
        }
      }
    }
  }
  return iVar1;
}

