/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_store_scene_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: status */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t scenes_cluster_store_scene_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint uVar2;
  uint8_t uStack_17;
  uint16_t uStack_16;
  uint8_t scene_id;
  uint16_t group_id;
  uint8_t status;
  uint16_t offset;
  
  group_id = 0;
  scene_id = '\0';
  uStack_16 = 0;
  uStack_17 = '\0';
  af_read_le8(packet->payload,&group_id,&scene_id);
  af_read_le16(packet->payload,&group_id,&uStack_16);
  af_read_le8(packet->payload,&group_id,&uStack_17);
  uVar2 = zmsg_get_length(packet->payload);
  if (uVar2 < group_id) {
    eVar1 = 0x80;
  }
  else {
    eVar1 = zcl_message_scenes_op_scene_resp(packet,scene_id,uStack_16,uStack_17);
  }
  eVar1 = zcl_packet_setup_default_response(rsp,packet,eVar1);
  return eVar1;
}

