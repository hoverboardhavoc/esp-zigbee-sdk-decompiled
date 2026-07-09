/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> metering.o -> parse_summation_from_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
parse_summation_from_payload(undefined4 param_1,undefined4 param_2,size_t param_3,int *param_4)

{
  size_t sVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_3 == 0) {
    return 0;
  }
  pvVar2 = calloc(param_3,8);
  *param_4 = (int)pvVar2;
  uVar3 = 0x89;
  if (pvVar2 != (void *)0x0) {
    sVar1 = 0;
    do {
      iVar4 = zcl_packet_read_variable_attr_value(param_1,param_2,0x25,sVar1 * 8 + *param_4);
      if (iVar4 != 6) {
        return 0x80;
      }
      sVar1 = sVar1 + 1;
    } while (param_3 != sVar1);
    uVar3 = 0;
  }
  return uVar3;
}

