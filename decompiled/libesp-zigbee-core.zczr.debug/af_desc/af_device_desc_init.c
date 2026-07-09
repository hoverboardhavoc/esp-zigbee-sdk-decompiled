/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int af_device_desc_init(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == (int *)0x0) {
    iVar2 = 2;
  }
  else {
    uVar4 = 0;
    for (iVar1 = *param_1; iVar2 = 0, iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
      iVar2 = af_ep_desc_init(iVar1);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = af_device_simple_desc_init(iVar1);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = af_ep_reporting_info_init(iVar1);
      if (iVar2 != 0) {
        return iVar2;
      }
      uVar3 = af_dev_get_max_endpoint_num();
      if (uVar3 <= uVar4) {
        return 2;
      }
      uVar4 = uVar4 + 1 & 0xff;
    }
    zcl_reporting_start();
  }
  return iVar2;
}

