/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_device_remove_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte * af_device_remove_endpoint_desc(byte *param_1,uint param_2)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = af_device_desc_is_registered();
  if (iVar2 == 0) {
    pbVar1 = param_1;
    if (param_1 != (byte *)0x0) {
      pbVar1 = *(byte **)param_1;
      while (pbVar1 != (byte *)0x0) {
        pbVar3 = *(byte **)param_1;
        if ((pbVar3 != (byte *)0x0) && (*pbVar3 == param_2)) {
          *(undefined4 *)param_1 = *(undefined4 *)(pbVar1 + 0x1c);
          pbVar1[0x1c] = 0;
          pbVar1[0x1d] = 0;
          pbVar1[0x1e] = 0;
          pbVar1[0x1f] = 0;
          return pbVar1;
        }
        param_1 = pbVar3 + 0x1c;
        pbVar1 = *(byte **)(pbVar3 + 0x1c);
      }
    }
  }
  else {
    pbVar1 = (byte *)0x0;
  }
  return pbVar1;
}

