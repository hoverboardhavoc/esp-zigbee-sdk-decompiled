/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ias_wd.o -> ias_wd_cluster_squawk_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: squawk_byte */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_wd_cluster_squawk_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint uVar2;
  undefined4 uStack_28;
  ezb_zcl_ias_wd_squawk_message_t message;
  uint8_t squawk_byte;
  uint16_t offset;
  
  message._18_2_ = 0;
  message._17_1_ = 0;
  uStack_28 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload = (ezb_zcl_ias_wd_squawk_payload_t)0x0;
  message.in._5_3_ = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_wd.c",0x7f,
                  "ias_wd_cluster_squawk_cmd_handler","packet && rsp");
  }
  else {
    af_read_le8(packet->payload,(uint16_t *)&message.field_0x12,&message.field_0x11);
    uVar2 = zmsg_get_length(packet->payload);
    if (uVar2 < (ushort)message._18_2_) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  message.in.header =
       (ezb_zcl_cmd_hdr_t *)
       CONCAT31((int3)((uint)message.in.header >> 8),
                message._17_1_ & 0xf0 | (byte)(((byte)message._17_1_ >> 2 & 3) << 2) |
                message._17_1_ & 3);
  uVar2 = zcl_packet_to_message(&uStack_28,packet);
  if (uVar2 == 0) {
    message.in.payload = (ezb_zcl_ias_wd_squawk_payload_t)0xfe;
    message._4_4_ = packet;
    zcl_core_action_schedule(0x2d,&uStack_28);
    uVar2 = message.in._4_4_ & 0xff;
    if (uVar2 == 0xfe) {
      uVar2 = 1;
    }
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar2);
  return eVar1;
}

