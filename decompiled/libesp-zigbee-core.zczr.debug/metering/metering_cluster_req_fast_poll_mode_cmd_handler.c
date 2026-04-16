/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> metering_cluster_req_fast_poll_mode_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
metering_cluster_req_fast_poll_mode_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint uVar1;
  uint uVar2;
  uint16_t uVar3;
  undefined2 extraout_var;
  int iVar4;
  ezb_zcl_metering_request_fast_poll_mode_rsp_t eStack_34;
  uint uStack_2c;
  uint16_t offset;
  ezb_zcl_metering_request_fast_poll_mode_req_message_t message;
  
  uStack_2c = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.period = '\0';
  message.in.payload.duration = '\0';
  message.in._6_2_ = 0;
  message.out.result = '\0';
  message.out._1_3_ = 0;
  message.out.payload.period = '\0';
  message.out.payload._1_3_ = 0;
  eStack_34.end_time._2_2_ = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/metering.c",0x135,
                  "metering_cluster_req_fast_poll_mode_cmd_handler","packet && rsp");
_L0:
    uVar2 = zmsg_get_length(packet->payload);
    if (uVar2 < eStack_34.end_time._2_2_) {
      uVar2 = 0x80;
    }
    else {
      uVar2 = zcl_packet_to_message(&stack0xffffffd4,packet);
      if (uVar2 == 0) {
        message.in.payload.period = 0xfe;
        message._4_4_ = packet;
        zcl_core_action_schedule(0x44,&stack0xffffffd4);
        uVar1 = message.in._4_4_ & 0xff;
        if ((message.in._4_4_ & 0xff) == 0xfe) {
          uVar1 = uVar2;
        }
        uVar2 = uVar1;
        if ((uStack_2c & 0xff) == 0xfe) {
          uVar2 = 1;
        }
        else if (uVar2 == 0) {
          eStack_34.period = message.out.result;
          iVar4 = zmsg_append_bytes(rsp->payload,1,&eStack_34);
          if (iVar4 == 0) {
            eStack_34.period = message.out.payload.period;
            eStack_34._1_3_ = message.out.payload._1_3_;
            iVar4 = zmsg_append_bytes(rsp->payload,4,&eStack_34);
            if (iVar4 == 0) {
              uVar2 = zcl_packet_setup_response(rsp,packet,3);
              if (uVar2 == 0) goto _L0;
            }
            else {
              uVar2 = 0x89;
            }
          }
          else {
            uVar2 = 0x89;
          }
        }
      }
    }
  }
  else {
    uVar3 = af_read_bytes(packet->payload,(uint16_t *)((int)&eStack_34.end_time + 2),2,
                          (uint8_t *)&message.in);
    if (CONCAT22(extraout_var,uVar3) != 0) goto _L0;
    uVar2 = 0x80;
  }
  uVar2 = zcl_packet_setup_default_response(rsp,packet,uVar2);
_L0:
  return (ezb_zcl_status_t)uVar2;
}

