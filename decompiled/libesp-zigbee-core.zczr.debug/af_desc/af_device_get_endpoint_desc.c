/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_get_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void af_device_get_endpoint_desc(undefined4 *param_1,uint param_2)

{
  byte *pbVar1;
  
  for (pbVar1 = (byte *)*param_1; (pbVar1 != (byte *)0x0 && (*pbVar1 != param_2));
      pbVar1 = *(byte **)(pbVar1 + 0x1c)) {
  }
  return;
}

