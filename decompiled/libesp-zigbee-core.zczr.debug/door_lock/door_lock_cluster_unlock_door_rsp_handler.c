/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> door_lock.o -> door_lock_cluster_unlock_door_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t door_lock_cluster_unlock_door_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  int iVar2;
  uint uVar3;
  undefined4 uStack_28;
  ezb_zcl_door_lock_unlock_door_rsp_message_t message;
  uint16_t offset;
  
  message._18_2_ = 0;
  uStack_28 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.req_status = '\0';
  message.in._5_3_ = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/door_lock.c",0xa7,
                  "door_lock_cluster_unlock_door_rsp_handler","packet && rsp");
  }
  else {
    iVar2 = zmsg_get_length(packet->payload);
    if (iVar2 == 0) {
      uVar3 = 0x80;
      goto _L0;
    }
  }
  af_read_le8(packet->payload,(uint16_t *)&message.field_0x12,(uint8_t *)&message.in);
  uVar3 = zcl_packet_to_message(&uStack_28,packet);
  if (uVar3 == 0) {
    message.in.req_status = 0xfe;
    message._4_4_ = packet;
    zcl_core_action_schedule(0x19,&uStack_28);
    if ((message.in._4_4_ & 0xff) != 0xfe) {
      uVar3 = message.in._4_4_ & 0xff;
    }
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar3);
  return eVar1;
}

