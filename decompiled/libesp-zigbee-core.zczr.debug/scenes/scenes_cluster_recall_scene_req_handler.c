/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_recall_scene_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: group_id */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t scenes_cluster_recall_scene_req_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint uVar2;
  uint16_t uStack_18;
  uint8_t local_15;
  uint16_t transition_time;
  ushort uStack_12;
  uint8_t scene_id;
  uint16_t group_id;
  uint16_t offset;
  
  uStack_12 = 0;
  transition_time = 0;
  local_15 = '\0';
  uStack_18 = 0xffff;
  af_read_le16(packet->payload,&stack0xffffffee,&transition_time);
  af_read_le8(packet->payload,&stack0xffffffee,&local_15);
  uVar2 = zmsg_get_length(packet->payload);
  if (uStack_12 < uVar2) {
    af_read_le16(packet->payload,&stack0xffffffee,&uStack_18);
  }
  uVar2 = zmsg_get_length(packet->payload);
  if (uVar2 < uStack_12) {
    eVar1 = 0x80;
  }
  else {
    eVar1 = zcl_scenes_recall_scene(packet,transition_time,local_15,uStack_18);
  }
  if ((packet->header).dst_addr.u.short_addr < 0xfff8) {
    eVar1 = zcl_packet_setup_default_response(rsp,packet,eVar1);
  }
  else {
    eVar1 = 0xfe;
  }
  return eVar1;
}

