/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_arm_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_ace_cluster_arm_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint16_t *unaff_s1;
  uint uVar1;
  ezb_zcl_status_t eVar2;
  undefined3 extraout_var;
  int iVar3;
  uint8_t uStack_31;
  undefined4 uStack_30;
  ezb_zcl_ias_ace_arm_message_t message;
  uint16_t offset;
  
  message._26_2_ = 0;
  uStack_30 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.arm_mode = '\0';
  message.in.payload.arm_disarm_code[0] = '\0';
  message.in.payload.arm_disarm_code[1] = '\0';
  message.in.payload.arm_disarm_code[2] = '\0';
  message.in.payload.arm_disarm_code[3] = '\0';
  message.in.payload.arm_disarm_code[4] = '\0';
  message.in.payload.arm_disarm_code[5] = '\0';
  message.in.payload.arm_disarm_code[6] = '\0';
  message.in.payload.arm_disarm_code[7] = '\0';
  message.in.payload.arm_disarm_code[8] = '\0';
  message.in.payload.zone_id = '\0';
  message.in._15_1_ = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0xd2,
                  "ias_ace_cluster_arm_cmd_handler","packet && rsp");
_L0:
    af_read_le8(packet->payload,unaff_s1,message.in.payload.arm_disarm_code + 5);
    uVar1 = zmsg_get_length(packet->payload);
    if (uVar1 < (ushort)message._26_2_) {
      uVar1 = 0x80;
    }
    else if ((byte)message.in.header < 4) {
      if (((uint)message.in.payload.arm_disarm_code._3_4_ >> 0x10 & 0xff) == 0xff) {
        uVar1 = 0x87;
      }
      else {
        uVar1 = zcl_packet_to_message(&uStack_30,packet);
        if (uVar1 == 0) {
          message.in.payload.arm_disarm_code[7] = 0xfe;
          message._4_4_ = packet;
          zcl_core_action_schedule(0x1c,&uStack_30);
          uVar1 = message.in._12_4_ & 0xff;
          if (uVar1 == 0xfe) {
            uVar1 = 1;
          }
          else if (uVar1 == 0) {
            uStack_31 = message.in.payload.arm_disarm_code[8];
            iVar3 = zmsg_append_bytes(rsp->payload,1,&uStack_31);
            if (iVar3 == 0) {
              uVar1 = zcl_packet_setup_response(rsp,packet,0);
              if (uVar1 == 0) goto _L0;
            }
            else {
              uVar1 = 0x89;
            }
          }
        }
      }
    }
    else {
      uVar1 = 0x87;
    }
  }
  else {
    unaff_s1 = (uint16_t *)&message.field_0x1a;
    af_read_le8(packet->payload,unaff_s1,(uint8_t *)&message.in);
    eVar2 = read_zcl_string(packet->payload,unaff_s1,(uint8_t *)((int)&message.in.header + 1),'\t');
    if (CONCAT31(extraout_var,eVar2) == 0) goto _L0;
    uVar1 = 0x80;
  }
  uVar1 = zcl_packet_setup_default_response(rsp,packet,uVar1);
_L0:
  return (ezb_zcl_status_t)uVar1;
}

