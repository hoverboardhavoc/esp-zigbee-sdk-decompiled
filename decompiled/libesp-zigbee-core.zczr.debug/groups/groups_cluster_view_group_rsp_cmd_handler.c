/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_view_group_rsp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t groups_cluster_view_group_rsp_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint16_t uVar1;
  ezb_zcl_status_t eVar2;
  uint16_t uVar3;
  uint uVar4;
  uint16_t uStack_26;
  uint8_t uStack_23;
  uint16_t group_id;
  uint8_t status;
  uint16_t offset;
  
  group_id = 0;
  uStack_23 = '\0';
  uStack_26 = 0xffff;
  uVar4 = zmsg_get_length(packet->payload);
  af_read_le8(packet->payload,&group_id,&uStack_23);
  af_read_le16(packet->payload,&group_id,&uStack_26);
  uVar1 = group_id;
  if (group_id <= uVar4) {
    uVar3 = groups_read_group_name(packet->payload,group_id,(void *)0x0);
    group_id = uVar1 + uVar3;
  }
  if (uVar4 < group_id) {
    eVar2 = 0x80;
  }
  else {
    eVar2 = zcl_message_groups_view_group_resp(packet,uStack_23,uStack_26,(char *)0x0);
  }
  eVar2 = zcl_packet_setup_default_response(rsp,packet,eVar2);
  return eVar2;
}

