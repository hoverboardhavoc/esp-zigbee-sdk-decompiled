/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> metering.o -> append_summation_to_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 append_summation_to_payload(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_2 == 0) || (uVar2 = 1, param_3 != 0)) {
    iVar1 = param_3 + param_2 * 8;
    do {
      if (param_3 == iVar1) {
        return 0;
      }
      iVar3 = zcl_packet_append_variable_attr_value(param_1,0x25,param_3);
      param_3 = param_3 + 8;
    } while (iVar3 == 0);
    uVar2 = 0x89;
  }
  return uVar2;
}

