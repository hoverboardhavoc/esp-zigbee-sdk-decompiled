/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> append_summation_to_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 append_summation_to_payload(undefined4 param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    if (param_3 == 0) {
      return 1;
    }
    uVar1 = 0;
  }
  while( true ) {
    if (param_2 <= uVar1) {
      return 0;
    }
    iVar2 = zcl_packet_append_variable_attr_value(param_1,0x25,uVar1 * 8 + param_3);
    if (iVar2 != 0) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return 0x89;
}

