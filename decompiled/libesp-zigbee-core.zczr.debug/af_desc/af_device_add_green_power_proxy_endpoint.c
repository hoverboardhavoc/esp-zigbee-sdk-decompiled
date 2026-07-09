/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_add_green_power_proxy_endpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int af_device_add_green_power_proxy_endpoint(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_28 = 0xa1e000f2;
  uStack_24 = 0x60;
  iVar1 = nwk_is_device_zczr();
  if (iVar1 == 0) {
    uVar3 = 0;
    uVar2 = 0;
    iVar1 = 0xd;
  }
  else if (param_1 == 0) {
    iVar1 = 3;
    uVar2 = 0;
    uVar3 = 0;
  }
  else {
    uVar2 = af_create_endpoint_desc(&uStack_28);
    uVar3 = zcl_create_cluster_desc(0x21,2,0);
    iVar1 = af_endpoint_add_cluster_desc(uVar2,uVar3);
    if (iVar1 == 0) {
      iVar1 = af_device_add_endpoint_desc(param_1,uVar2);
      if (iVar1 == 0) {
        uVar3 = 0;
        uVar2 = 0;
      }
      else {
        uVar3 = 0;
      }
    }
  }
  zcl_free_cluster_desc(uVar3);
  af_free_endpoint_desc(uVar2);
  return iVar1;
}

