/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ota_upgrade_cluster_srv_image_block_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ota_upgrade_cluster_srv_image_block_req_handler(int param_1,int param_2)

{
  ushort *unaff_s0;
  int iVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint unaff_s3;
  uint uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  uint uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  ushort auStack_22 [7];
  
  auStack_22[0] = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_srv.c",
                  0x145,"ota_upgrade_cluster_srv_image_block_req_handler","packet && rsp");
_L0:
    af_read_bytes(*(undefined4 *)(param_1 + 0x24),unaff_s0,8,(int)&uStack_30 + 1);
  }
  else {
    unaff_s3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    unaff_s0 = auStack_22;
    af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s0,&uStack_40);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),unaff_s0,(int)&uStack_40 + 2);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),unaff_s0,&uStack_3c);
    af_read_le32(*(undefined4 *)(param_1 + 0x24),unaff_s0,&uStack_38);
    af_read_le32(*(undefined4 *)(param_1 + 0x24),unaff_s0,&uStack_34);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s0,&uStack_30);
    if ((uStack_40 & 1) != 0) goto _L0;
  }
  if ((uStack_40 & 2) != 0) {
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_28 + 2);
  }
  if (unaff_s3 < auStack_22[0]) {
    uVar4 = 0x80;
  }
  else {
    pbVar2 = (byte *)ota_upgrade_get_file_table(*(undefined1 *)(param_1 + 0x15));
    iVar1 = 0;
    for (uVar5 = 0; uVar5 < *pbVar2; uVar5 = uVar5 + 1 & 0xff) {
      iVar1 = *(int *)(pbVar2 + 4) + uVar5 * 0x4c;
      if (((*(short *)(iVar1 + 10) == uStack_40._2_2_) &&
          (*(short *)(iVar1 + 0xc) == (short)uStack_3c)) && (*(uint *)(iVar1 + 0xe) == uStack_38)) {
        if ((uStack_40 & 1) == 0) break;
        if ((*(uint *)(iVar1 + 0x39) == (uStack_2c << 0x18 | uStack_30 >> 8)) &&
           (*(uint *)(iVar1 + 0x3d) == (uStack_28 << 0x18 | uStack_2c >> 8))) break;
      }
    }
    if (iVar1 == 0) {
      uVar4 = 0x98;
    }
    else {
      zcl_message_ota_upgrade_server_progress(param_1,2,&uStack_40,0);
      uVar5 = *(uint *)(iVar1 + 0x34);
      if (uStack_34 < uVar5) {
        if (uVar5 < (uStack_30 & 0xff) + uStack_34) {
          uStack_30 = CONCAT31(uStack_30._1_3_,(char)uVar5 - (char)uStack_34);
        }
        uStack_44 = (uint)uStack_44._1_3_ << 8;
        iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_44);
        if (iVar3 == 0) {
          uStack_44 = CONCAT22(uStack_44._2_2_,uStack_40._2_2_);
          iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_44);
          if (iVar3 == 0) {
            uStack_44 = CONCAT22(uStack_44._2_2_,(short)uStack_3c);
            iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_44);
            if (iVar3 == 0) {
              uStack_44 = uStack_38;
              iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_44);
              if (iVar3 == 0) {
                uStack_44 = uStack_34;
                iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_44);
                if (iVar3 == 0) {
                  uStack_44 = CONCAT31(uStack_44._1_3_,(undefined1)uStack_30);
                  iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_44);
                  if (iVar3 == 0) {
                    iVar1 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),uStack_30 & 0xff,
                                              *(int *)(iVar1 + 0x48) + uStack_34);
                    if (iVar1 == 0) goto _L0;
                    uVar4 = 0x89;
                  }
                  else {
                    uVar4 = 0x89;
                  }
                }
                else {
                  uVar4 = 0x89;
                }
              }
              else {
                uVar4 = 0x89;
              }
            }
            else {
              uVar4 = 0x89;
            }
          }
          else {
            uVar4 = 0x89;
          }
        }
        else {
          uVar4 = 0x89;
        }
      }
      else {
        uStack_44 = CONCAT31(uStack_44._1_3_,0x98);
        iVar1 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_44);
        if (iVar1 == 0) {
_L0:
          zcl_packet_setup_response_with_extension(param_2,param_1,5,0,1);
          return;
        }
        uVar4 = 0x89;
      }
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar4);
  return;
}

