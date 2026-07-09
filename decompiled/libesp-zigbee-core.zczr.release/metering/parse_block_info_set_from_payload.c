/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> metering.o -> parse_block_info_set_from_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int parse_block_info_set_from_payload(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  uint __nmemb;
  
  iVar3 = zcl_packet_read_variable_attr_value(0x25,param_3);
  if ((((iVar3 == 6) && (iVar3 = af_read_le32(param_1,param_2,param_3 + 8), iVar3 == 4)) &&
      (iVar3 = af_read_le32(param_1,param_2,param_3 + 0xc), iVar3 == 4)) &&
     (((iVar3 = af_read_le32(param_1,param_2,param_3 + 0x10), iVar3 == 4 &&
       (iVar3 = af_read_le32(param_1,param_2,param_3 + 0x14), iVar3 == 4)) &&
      ((iVar3 = af_read_le8(param_1,param_2,param_3 + 0x18), iVar3 == 1 &&
       (iVar3 = af_read_le8(param_1,param_2,param_3 + 0x19), iVar3 == 1)))))) {
    iVar3 = parse_summation_from_payload
                      (param_1,param_2,*(undefined1 *)(param_3 + 0x19),param_3 + 0x1c);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = af_read_le8(param_1,param_2,param_3 + 0x20);
    if (iVar3 == 1) {
      __nmemb = (uint)*(byte *)(param_3 + 0x20);
      if (__nmemb == 0) {
        return 0;
      }
      pvVar2 = calloc(__nmemb,8);
      *(int *)(param_3 + 0x24) = (int)pvVar2;
      iVar3 = 0x89;
      if (pvVar2 != (void *)0x0) {
        uVar1 = 0;
        do {
          iVar3 = zcl_packet_read_variable_attr_value
                            (param_1,param_2,0x25,uVar1 * 8 + *(int *)(param_3 + 0x24));
          if (iVar3 != 6) {
            return 0x80;
          }
          uVar1 = uVar1 + 1;
        } while (__nmemb != uVar1);
        iVar3 = 0;
      }
      return iVar3;
    }
  }
  return 0x80;
}

