/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ota_upgrade_cluster_srv_query_next_image_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010728) */

void ota_upgrade_cluster_srv_query_next_image_req_handler(int param_1,int param_2)

{
  ushort *unaff_s0;
  uint uVar1;
  uint uVar2;
  uint unaff_s1;
  int iVar3;
  byte *pbVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uStack_48;
  short sStack_44;
  short sStack_42;
  undefined4 uStack_40;
  undefined2 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  ushort auStack_22 [3];
  
  auStack_22[0] = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_srv.c",
                  0xfc,"ota_upgrade_cluster_srv_query_next_image_req_handler","packet && rsp");
_L0:
    af_read_le16(*(undefined4 *)(param_1 + 0x24),unaff_s0,&uStack_28);
  }
  else {
    unaff_s1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    unaff_s0 = auStack_22;
    af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s0,&uStack_34);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),unaff_s0,(int)&uStack_34 + 2);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),unaff_s0,&uStack_30);
    af_read_le32(*(undefined4 *)(param_1 + 0x24),unaff_s0,&uStack_2c);
    if ((uStack_34 & 1) != 0) goto _L0;
  }
  if (unaff_s1 < auStack_22[0]) {
    uVar5 = 0x80;
  }
  else {
    pbVar4 = (byte *)ota_upgrade_get_file_table(*(undefined1 *)(param_1 + 0x15));
    uVar1 = 0;
    iVar6 = 1;
    while (pbVar4 != (byte *)0x0) {
      if (*pbVar4 <= uVar1) {
        uVar1 = 0;
        uVar2 = 0;
        goto _L0;
      }
      iVar3 = *(int *)(pbVar4 + 4) + uVar1 * 0x4c;
      if (((*(short *)(iVar3 + 10) == uStack_34._2_2_) &&
          (*(short *)(iVar3 + 0xc) == (short)uStack_30)) &&
         ((((uStack_34 & 1) == 0 || ((*(ushort *)(iVar3 + 8) & 4) == 0)) ||
          (((*(uint *)(iVar3 + 0x40) >> 8 & 0xffff) <= (uStack_28 & 0xffff) &&
           ((uStack_28 & 0xffff) <= (uint)*(ushort *)(iVar3 + 0x43))))))) {
        uStack_48._0_3_ = CONCAT12(*(undefined1 *)(param_1 + 0x14),*(undefined2 *)(param_1 + 2));
        sStack_44 = uStack_34._2_2_;
        sStack_42 = (short)uStack_30;
        uStack_40 = uStack_2c;
        uStack_3c = (undefined2)uStack_28;
        uStack_38 = *(undefined4 *)(iVar3 + 0xe);
        iVar6 = zcl_message_ota_upgrade_server_progress(param_1,0,&uStack_48,0);
        if (iVar6 == 0) {
          uVar1 = *(uint *)(iVar3 + 0xe);
          uVar2 = *(uint *)(iVar3 + 0x34);
          goto _L0;
        }
        if (iVar6 == 0xfe) {
          uVar1 = 0;
          uVar2 = 0;
          goto _L0;
        }
      }
      uVar1 = uVar1 + 1 & 0xff;
    }
    uVar1 = 0;
    uVar2 = 0;
_L0:
    if (iVar6 == 0x7e) {
      uStack_48 = CONCAT31(uStack_48._1_3_,0x7e);
      iVar6 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_48);
      if (iVar6 == 0) {
_L0:
        zcl_packet_setup_response_with_extension(param_2,param_1,2,0,1);
        return;
      }
      uVar5 = 0x7e;
    }
    else if (uVar2 == 0) {
      uStack_48 = CONCAT31(uStack_48._1_3_,0x98);
      iVar6 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_48);
      if (iVar6 == 0) goto _L0;
      uVar5 = 0x89;
    }
    else {
      uStack_48 = uStack_48 & 0xffffff00;
      iVar6 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_48);
      if (iVar6 == 0) {
        uStack_48 = CONCAT22(uStack_48._2_2_,uStack_34._2_2_);
        iVar6 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_48);
        if (iVar6 == 0) {
          uStack_48 = CONCAT22(uStack_48._2_2_,(short)uStack_30);
          iVar6 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_48);
          if (iVar6 == 0) {
            uStack_48 = uVar1;
            iVar6 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_48);
            if (iVar6 == 0) {
              uStack_48 = uVar2;
              iVar6 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_48);
              if (iVar6 == 0) goto _L0;
              uVar5 = 0x89;
            }
            else {
              uVar5 = 0x89;
            }
          }
          else {
            uVar5 = 0x89;
          }
        }
        else {
          uVar5 = 0x89;
        }
      }
      else {
        uVar5 = 0x89;
      }
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar5);
  return;
}

