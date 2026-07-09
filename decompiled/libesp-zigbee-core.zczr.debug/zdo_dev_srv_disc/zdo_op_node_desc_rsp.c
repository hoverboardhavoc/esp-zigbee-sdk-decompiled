/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_op_node_desc_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zdo_op_node_desc_rsp(int param_1,byte *param_2,int param_3)

{
  uint unaff_s1;
  int iVar1;
  uint uVar2;
  ushort auStack_22 [7];
  
  if ((param_1 == 0) || (param_2 == (byte *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x292,
                  "zdo_op_node_desc_rsp","payload && rsp");
  }
  else {
    if (param_3 == 0) {
      auStack_22[0] = 0;
      uVar2 = zmsg_get_length();
      af_read_le8(param_1,auStack_22,param_2);
      af_read_le16(param_1,auStack_22,param_2 + 2);
      if (auStack_22[0] <= uVar2) {
        if (*param_2 == 0) {
          af_read_le16(param_1,auStack_22,param_2 + 4);
          af_read_le8(param_1,auStack_22,param_2 + 6);
          af_read_le16(param_1,auStack_22,param_2 + 8);
          af_read_le8(param_1,auStack_22,param_2 + 10);
          af_read_le16(param_1,auStack_22,param_2 + 0xc);
          af_read_le16(param_1,auStack_22,param_2 + 0xe);
          af_read_le16(param_1,auStack_22,param_2 + 0x10);
          af_read_le8(param_1,auStack_22,param_2 + 0x12);
        }
        else {
          memset(param_2 + 4,0,0x10);
        }
        if (auStack_22[0] <= uVar2) {
          return 0;
        }
      }
      return 0xfe;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,*param_2);
    iVar1 = zmsg_append_bytes(1,auStack_22);
    if (iVar1 != 0) {
      return 0x8a;
    }
    auStack_22[0] = *(ushort *)(param_2 + 2);
    iVar1 = zmsg_append_bytes(param_1,2,auStack_22);
    if (iVar1 != 0) {
      return 0x8a;
    }
    unaff_s1 = (uint)*param_2;
    if (unaff_s1 != 0) {
      return 0;
    }
  }
  auStack_22[0] = *(ushort *)(param_2 + 4);
  iVar1 = zmsg_append_bytes(param_1,2,auStack_22);
  if (iVar1 == 0) {
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,param_2[6]);
    iVar1 = zmsg_append_bytes(param_1,1,auStack_22);
    if (iVar1 == 0) {
      auStack_22[0] = *(ushort *)(param_2 + 8);
      iVar1 = zmsg_append_bytes(param_1,2,auStack_22);
      if (iVar1 == 0) {
        auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,param_2[10]);
        iVar1 = zmsg_append_bytes(param_1,1,auStack_22);
        if (iVar1 == 0) {
          auStack_22[0] = *(ushort *)(param_2 + 0xc);
          iVar1 = zmsg_append_bytes(param_1,2,auStack_22);
          if (iVar1 == 0) {
            auStack_22[0] = *(ushort *)(param_2 + 0xe);
            iVar1 = zmsg_append_bytes(param_1,2,auStack_22);
            if (iVar1 == 0) {
              auStack_22[0] = *(ushort *)(param_2 + 0x10);
              iVar1 = zmsg_append_bytes(param_1,2,auStack_22);
              if (iVar1 == 0) {
                auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,param_2[0x12]);
                iVar1 = zmsg_append_bytes(param_1,1,auStack_22);
                if (iVar1 != 0) {
                  unaff_s1 = 0x8a;
                }
              }
              else {
                unaff_s1 = 0x8a;
              }
            }
            else {
              unaff_s1 = 0x8a;
            }
          }
          else {
            unaff_s1 = 0x8a;
          }
        }
        else {
          unaff_s1 = 0x8a;
        }
      }
      else {
        unaff_s1 = 0x8a;
      }
    }
    else {
      unaff_s1 = 0x8a;
    }
  }
  else {
    unaff_s1 = 0x8a;
  }
  return unaff_s1;
}

