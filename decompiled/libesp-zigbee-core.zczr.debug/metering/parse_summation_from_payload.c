/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> parse_summation_from_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint parse_summation_from_payload(undefined4 param_1,undefined4 param_2,uint param_3,int *param_4)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  
  if (param_3 != 0) {
    pvVar2 = calloc(param_3,8);
    *param_4 = (int)pvVar2;
    if (pvVar2 == (void *)0x0) {
      param_3 = 0x89;
    }
    else {
      for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xff) {
        iVar3 = zcl_packet_read_variable_attr_value(param_1,param_2,0x25,*param_4 + uVar1 * 8);
        if (iVar3 != 6) {
          return 0x80;
        }
      }
      param_3 = 0;
    }
  }
  return param_3;
}

