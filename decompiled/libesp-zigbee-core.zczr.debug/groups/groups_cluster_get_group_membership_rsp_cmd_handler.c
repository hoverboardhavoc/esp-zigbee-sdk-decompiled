/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_get_group_membership_rsp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
groups_cluster_get_group_membership_rsp_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint uVar1;
  ezb_zcl_status_t eVar2;
  uint16_t *group_list;
  byte local_24;
  uint8_t uStack_23;
  uint16_t uStack_22;
  uint8_t group_count;
  uint8_t capacity;
  uint16_t offset;
  
  uStack_22 = 0;
  uStack_23 = '\0';
  local_24 = 0;
  af_read_le8(packet->payload,&uStack_22,&uStack_23);
  af_read_le8(packet->payload,&uStack_22,&local_24);
  uVar1 = (uint)local_24;
  group_list = (uint16_t *)calloc(uVar1,2);
  if (uVar1 != 0) {
    if (group_list == (uint16_t *)0x0) {
      eVar2 = 0x89;
      goto _L0;
    }
    uVar1 = 0;
  }
  for (; uVar1 < local_24; uVar1 = uVar1 + 1 & 0xff) {
    af_read_le16(packet->payload,&uStack_22,group_list + uVar1);
  }
  uVar1 = zmsg_get_length(packet->payload);
  if (uVar1 < uStack_22) {
    eVar2 = 0x80;
  }
  else {
    eVar2 = zcl_message_groups_get_group_membership_resp(packet,uStack_23,local_24,group_list);
  }
  if (group_list != (uint16_t *)0x0) {
    mm_free(group_list);
  }
_L0:
  eVar2 = zcl_packet_setup_default_response(rsp,packet,eVar2);
  return eVar2;
}

