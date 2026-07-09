/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> metering.o -> append_block_info_set_to_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int append_block_info_set_to_payload(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = zcl_packet_append_variable_attr_value(0x25,param_2);
  if (((((iVar3 == 0) &&
        (iVar3 = zmsg_append_le32(param_1,*(undefined4 *)(param_2 + 8)), iVar3 == 0)) &&
       (iVar3 = zmsg_append_le32(param_1,*(undefined4 *)(param_2 + 0xc)), iVar3 == 0)) &&
      ((iVar3 = zmsg_append_le32(param_1,*(undefined4 *)(param_2 + 0x10)), iVar3 == 0 &&
       (iVar3 = zmsg_append_le32(param_1,*(undefined4 *)(param_2 + 0x14)), iVar3 == 0)))) &&
     ((iVar3 = zmsg_append_u8(param_1,*(undefined1 *)(param_2 + 0x18)), iVar3 == 0 &&
      (iVar3 = zmsg_append_u8(param_1,*(undefined1 *)(param_2 + 0x19)), iVar3 == 0)))) {
    iVar3 = append_summation_to_payload
                      (param_1,*(undefined1 *)(param_2 + 0x19),*(undefined4 *)(param_2 + 0x1c));
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = zmsg_append_u8(param_1,*(undefined1 *)(param_2 + 0x20));
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_2 + 0x24);
      if ((*(byte *)(param_2 + 0x20) == 0) || (iVar1 = 1, iVar3 != 0)) {
        iVar1 = iVar3 + (uint)*(byte *)(param_2 + 0x20) * 8;
        do {
          if (iVar3 == iVar1) {
            return 0;
          }
          iVar2 = zcl_packet_append_variable_attr_value(param_1,0x25,iVar3);
          iVar3 = iVar3 + 8;
        } while (iVar2 == 0);
        iVar1 = 0x89;
      }
      return iVar1;
    }
  }
  return 0x89;
}

