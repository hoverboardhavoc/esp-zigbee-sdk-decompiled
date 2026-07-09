/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_remove_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int af_device_remove_endpoint_desc(byte *param_1,uint param_2)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = af_device_desc_is_registered();
  if (iVar1 == 0) {
    if (param_1 == (byte *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)param_1;
      while ((iVar1 != 0 &&
             ((pbVar2 = *(byte **)param_1, pbVar2 == (byte *)0x0 || (*pbVar2 != param_2))))) {
        iVar1 = *(int *)(pbVar2 + 0x1c);
        param_1 = pbVar2 + 0x1c;
      }
      if (param_1 == (byte *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)param_1;
        if (iVar1 != 0) {
          *(undefined4 *)param_1 = *(undefined4 *)(iVar1 + 0x1c);
          *(undefined4 *)(iVar1 + 0x1c) = 0;
        }
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

