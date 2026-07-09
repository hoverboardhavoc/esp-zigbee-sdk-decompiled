/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> append_block_info_set_to_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int append_block_info_set_to_payload(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 auStack_14 [2];
  
  iVar1 = zcl_packet_append_variable_attr_value(0x25,param_2);
  if (iVar1 == 0) {
    auStack_14[0] = *(undefined4 *)(param_2 + 8);
    iVar1 = zmsg_append_bytes(param_1,4,auStack_14);
    if (iVar1 == 0) {
      auStack_14[0] = *(undefined4 *)(param_2 + 0xc);
      iVar1 = zmsg_append_bytes(param_1,4,auStack_14);
      if (iVar1 == 0) {
        auStack_14[0] = *(undefined4 *)(param_2 + 0x10);
        iVar1 = zmsg_append_bytes(param_1,4,auStack_14);
        if (iVar1 == 0) {
          auStack_14[0] = *(undefined4 *)(param_2 + 0x14);
          iVar1 = zmsg_append_bytes(param_1,4,auStack_14);
          if (iVar1 == 0) {
            auStack_14[0]._0_1_ = *(undefined1 *)(param_2 + 0x18);
            iVar1 = zmsg_append_bytes(param_1,1,auStack_14);
            if (iVar1 == 0) {
              auStack_14[0]._0_1_ = *(undefined1 *)(param_2 + 0x19);
              iVar1 = zmsg_append_bytes(param_1,1,auStack_14);
              if (iVar1 == 0) {
                iVar1 = append_summation_to_payload
                                  (param_1,*(undefined1 *)(param_2 + 0x19),
                                   *(undefined4 *)(param_2 + 0x1c));
                if (iVar1 == 0) {
                  auStack_14[0] = CONCAT31(auStack_14[0]._1_3_,*(undefined1 *)(param_2 + 0x20));
                  iVar1 = zmsg_append_bytes(param_1,1,auStack_14);
                  if (iVar1 == 0) {
                    iVar1 = append_summation_to_payload
                                      (param_1,*(undefined1 *)(param_2 + 0x20),
                                       *(undefined4 *)(param_2 + 0x24));
                  }
                  else {
                    iVar1 = 0x89;
                  }
                }
              }
              else {
                iVar1 = 0x89;
              }
            }
            else {
              iVar1 = 0x89;
            }
          }
          else {
            iVar1 = 0x89;
          }
        }
        else {
          iVar1 = 0x89;
        }
      }
      else {
        iVar1 = 0x89;
      }
    }
    else {
      iVar1 = 0x89;
    }
  }
  else {
    iVar1 = 0x89;
  }
  return iVar1;
}

