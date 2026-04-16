/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_store_scene_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t scenes_cluster_store_scene_req_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint uVar2;
  undefined3 extraout_var;
  zcl_scene_table_t *pzVar3;
  zcl_attr_desc_t *pzVar4;
  undefined3 extraout_var_00;
  zcl_scene_table_entry_t *pzVar5;
  int iVar6;
  uint8_t unaff_s3;
  uint16_t uStack_28;
  byte local_25;
  uint16_t uStack_24;
  ushort uStack_22;
  uint8_t scene_id;
  uint16_t group_id;
  uint16_t offset;
  
  uStack_22 = 0;
  uStack_24 = 0;
  local_25 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x364,
                  "scenes_cluster_store_scene_req_handler","packet && rsp");
_L0:
    pzVar4 = scenes_srv_get_attr_desc(unaff_s3,3);
    if (pzVar4 != (zcl_attr_desc_t *)0x0) {
      *(undefined1 *)pzVar4->data_p = 0;
      eVar1 = zcl_message_scenes_store_scene(packet,uStack_24,local_25);
      iVar6 = CONCAT31(extraout_var_00,eVar1);
      pzVar5 = scene_table_find_entry(unaff_s3,uStack_24,(ushort)local_25);
      if (pzVar5 == (zcl_scene_table_entry_t *)0x0) {
        iVar6 = 1;
      }
      else if (iVar6 == 0) {
        *(undefined1 *)pzVar4->data_p = 1;
      }
      goto _L0;
    }
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x373,
                  "scenes_cluster_store_scene_req_handler","scene_valid_attr_desc");
  }
  else {
    unaff_s3 = (packet->header).dst_ep;
    af_read_le16(packet->payload,&stack0xffffffde,&uStack_24);
    af_read_le8(packet->payload,&stack0xffffffde,&local_25);
    uVar2 = zmsg_get_length(packet->payload);
    if (uStack_22 <= uVar2) {
      eVar1 = scenes_check_group_id(uStack_24);
      iVar6 = CONCAT31(extraout_var,eVar1);
      if (iVar6 != 0) goto _L0;
      pzVar3 = scene_table_get(unaff_s3);
      if (pzVar3 == (zcl_scene_table_t *)0x0) {
        iVar6 = 0x8b;
        goto _L0;
      }
      if (pzVar3->total <= *pzVar3->count) {
        iVar6 = 0x89;
        goto _L0;
      }
      goto _L0;
    }
  }
  iVar6 = 0x80;
_L0:
  if ((packet->header).dst_addr.u.short_addr < 0xfff8) {
    uStack_28 = CONCAT11(uStack_28._1_1_,(char)iVar6);
    zmsg_append_bytes(rsp->payload,1,&uStack_28);
    uStack_28 = uStack_24;
    zmsg_append_bytes(rsp->payload,2,&uStack_28);
    uStack_28 = CONCAT11(uStack_28._1_1_,local_25);
    zmsg_append_bytes(rsp->payload,1,&uStack_28);
    eVar1 = zcl_packet_setup_response(rsp,packet,4);
  }
  else {
    eVar1 = 0xfe;
  }
  return eVar1;
}

