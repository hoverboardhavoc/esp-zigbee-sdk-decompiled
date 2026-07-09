/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ota_upgrade_cluster_srv_upgrade_end_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ota_upgrade_cluster_srv_upgrade_end_req_handler(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_28;
  ushort auStack_22 [7];
  
  auStack_22[0] = 0;
  uStack_28 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_srv.c",
                  0x18d,"ota_upgrade_cluster_srv_upgrade_end_req_handler","packet && rsp");
  }
  else {
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_34);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_34 + 2);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_30);
    af_read_le32(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_2c);
    if (auStack_22[0] <= uVar1) {
      zcl_message_ota_upgrade_server_progress(param_1,5,&uStack_34,&uStack_28);
      if ((char)uStack_34 == '\0') {
        uStack_38 = CONCAT22(uStack_38._2_2_,uStack_34._2_2_);
        iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_38);
        if (iVar2 == 0) {
          uStack_38 = CONCAT22(uStack_38._2_2_,(undefined2)uStack_30);
          iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_38);
          if (iVar2 == 0) {
            uStack_38 = uStack_2c;
            iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_38);
            if (iVar2 == 0) {
              uStack_38 = uStack_28 & 0xffff;
              iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_38);
              if (iVar2 == 0) {
                uStack_38 = uStack_28 >> 0x10;
                zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_38);
              }
            }
          }
        }
      }
      if ((uStack_34 & 0xff) != 0) {
        zcl_packet_setup_default_response(param_2,param_1,0);
        return;
      }
      zcl_packet_setup_response_with_extension(param_2,param_1,7,0,1);
      return;
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,0x80);
  return;
}

