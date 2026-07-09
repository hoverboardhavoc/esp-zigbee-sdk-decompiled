/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> metering.o -> parse_tou_info_no_billing_set_from_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
parse_tou_info_no_billing_set_from_payload(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  uint __nmemb;
  
  iVar4 = zcl_packet_read_variable_attr_value(0x25,param_3);
  if ((iVar4 == 6) && (iVar4 = af_read_le8(param_1,param_2,param_3 + 8), iVar4 == 1)) {
    __nmemb = (uint)*(byte *)(param_3 + 8);
    if (__nmemb == 0) {
      return 0;
    }
    pvVar2 = calloc(__nmemb,8);
    *(int *)(param_3 + 0xc) = (int)pvVar2;
    uVar3 = 0x89;
    if (pvVar2 != (void *)0x0) {
      uVar1 = 0;
      do {
        iVar4 = zcl_packet_read_variable_attr_value
                          (param_1,param_2,0x25,uVar1 * 8 + *(int *)(param_3 + 0xc));
        if (iVar4 != 6) {
          return 0x80;
        }
        uVar1 = uVar1 + 1;
      } while (__nmemb != uVar1);
      uVar3 = 0;
    }
    return uVar3;
  }
  return 0x80;
}

