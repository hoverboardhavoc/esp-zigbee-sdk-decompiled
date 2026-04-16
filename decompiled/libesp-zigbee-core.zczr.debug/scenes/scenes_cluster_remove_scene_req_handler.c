/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_remove_scene_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t scenes_cluster_remove_scene_req_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t ep_id;
  uint16_t group_id_00;
  ezb_zcl_status_t eVar1;
  uint uVar2;
  undefined3 extraout_var;
  zcl_scene_table_entry_t *entry;
  int iVar3;
  uint16_t uStack_28;
  byte local_25;
  uint16_t uStack_24;
  ushort uStack_22;
  uint8_t scene_id;
  uint16_t group_id;
  uint16_t offset;
  
  ep_id = (packet->header).dst_ep;
  uStack_22 = 0;
  uStack_24 = 0;
  local_25 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x2fc,
                  "scenes_cluster_remove_scene_req_handler","packet && rsp");
  }
  else {
    af_read_le16(packet->payload,&stack0xffffffde,&uStack_24);
    af_read_le8(packet->payload,&stack0xffffffde,&local_25);
    uVar2 = zmsg_get_length(packet->payload);
    group_id_00 = uStack_24;
    if (uStack_22 <= uVar2) {
      eVar1 = scenes_check_group_id(uStack_24);
      iVar3 = CONCAT31(extraout_var,eVar1);
      if (iVar3 == 0) {
        entry = scene_table_find_entry(ep_id,group_id_00,(ushort)local_25);
        if (entry == (zcl_scene_table_entry_t *)0x0) {
          iVar3 = 0x8b;
        }
        else {
          scene_table_remove_entry(ep_id,entry);
        }
      }
      goto _L0;
    }
  }
  iVar3 = 0x80;
_L0:
  if ((packet->header).dst_addr.u.short_addr < 0xfff8) {
    uStack_28 = CONCAT11(uStack_28._1_1_,(char)iVar3);
    zmsg_append_bytes(rsp->payload,1,&uStack_28);
    uStack_28 = uStack_24;
    zmsg_append_bytes(rsp->payload,2,&uStack_28);
    uStack_28 = CONCAT11(uStack_28._1_1_,local_25);
    zmsg_append_bytes(rsp->payload,1,&uStack_28);
    eVar1 = zcl_packet_setup_response(rsp,packet,2);
  }
  else {
    eVar1 = 0xfe;
  }
  return eVar1;
}

