/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_zone_id_map_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_ace_cluster_get_zone_id_map_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  int unaff_s0;
  ezb_zcl_status_t eVar1;
  uint uVar2;
  undefined4 uStack_44;
  ezb_zcl_ias_ace_get_zone_id_map_rsp_message_t message;
  uint16_t offset;
  
  message._46_2_ = 0;
  uStack_44 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.zone_id_map[0] = 0;
  message.in.zone_id_map[1] = 0;
  message.in.zone_id_map[2] = 0;
  message.in.zone_id_map[3] = 0;
  message.in.zone_id_map[4] = 0;
  message.in.zone_id_map[5] = 0;
  message.in.zone_id_map[6] = 0;
  message.in.zone_id_map[7] = 0;
  message.in.zone_id_map[8] = 0;
  message.in.zone_id_map[9] = 0;
  message.in.zone_id_map[10] = 0;
  message.in.zone_id_map[0xb] = 0;
  message.in.zone_id_map[0xc] = 0;
  message.in.zone_id_map[0xd] = 0;
  message.in.zone_id_map[0xe] = 0;
  message.in.zone_id_map[0xf] = 0;
  if ((packet != (zcl_packet_t *)0x0) && (rsp != (zcl_packet_t *)0x0)) {
    uVar2 = zmsg_get_length(packet->payload);
    if (uVar2 < 0x20) {
      uVar2 = 0x80;
    }
    else {
      for (unaff_s0 = 0; unaff_s0 < 0x10; unaff_s0 = unaff_s0 + 1) {
_L0:
        af_read_le16(packet->payload,(uint16_t *)&message.field_0x2e,
                     message.in.zone_id_map + unaff_s0 + -2);
      }
      uVar2 = zcl_packet_to_message(&uStack_44,packet);
      if (uVar2 == 0) {
        message.in.zone_id_map[0xe]._0_1_ = 0xfe;
        message._4_4_ = packet;
        zcl_core_action_schedule(0x24,&uStack_44);
        if ((message.in.zone_id_map._28_4_ & 0xff) != 0xfe) {
          uVar2 = message.in.zone_id_map._28_4_ & 0xff;
        }
      }
    }
    eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar2);
    return eVar1;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x210,
                "ias_ace_cluster_get_zone_id_map_rsp_handler","packet && rsp");
  goto _L0;
}

