/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_remove_all_scenes_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
scenes_cluster_remove_all_scenes_req_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t ep_id;
  uint16_t group_id_00;
  ezb_zcl_status_t eVar1;
  byte bVar2;
  uint uVar3;
  undefined3 extraout_var;
  uint16_t uStack_26;
  uint16_t uStack_24;
  uint16_t uStack_22;
  uint16_t group_id;
  uint16_t offset;
  
  ep_id = (packet->header).dst_ep;
  uStack_22 = 0;
  uStack_24 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x31b,
                  "scenes_cluster_remove_all_scenes_req_handler","packet && rsp");
  }
  else {
    af_read_le16(packet->payload,&uStack_22,&uStack_24);
    uVar3 = zmsg_get_length(packet->payload);
    group_id_00 = uStack_24;
    if (uStack_22 <= uVar3) {
      eVar1 = scenes_check_group_id(uStack_24);
      uVar3 = CONCAT31(extraout_var,eVar1);
      if (uVar3 == 0) {
        bVar2 = scene_table_remove_all_associated_scene(ep_id,group_id_00);
        uVar3 = (uint)bVar2;
      }
      goto _L0;
    }
  }
  uVar3 = 0x80;
_L0:
  uStack_26 = CONCAT11(uStack_26._1_1_,(char)uVar3);
  zmsg_append_bytes(rsp->payload,1,&uStack_26);
  uStack_26 = uStack_24;
  zmsg_append_bytes(rsp->payload,2,&uStack_26);
  if ((packet->header).dst_addr.u.short_addr < 0xfff8) {
    eVar1 = zcl_packet_setup_response(rsp,packet,3);
  }
  else {
    eVar1 = 0xfe;
  }
  return eVar1;
}

