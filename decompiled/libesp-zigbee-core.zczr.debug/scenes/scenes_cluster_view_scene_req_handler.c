/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_view_scene_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t scenes_cluster_view_scene_req_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t ep_id;
  uint16_t group_id_00;
  zcl_scene_table_entry_t *unaff_s0;
  ezb_zcl_scenes_extension_field_t *peVar1;
  ezb_zcl_status_t eVar2;
  _Bool _Var3;
  uint uVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 uVar5;
  int unaff_s3;
  zcl_packet_payload_t *pzVar6;
  ushort uStack_28;
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
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x2bd,
                  "scenes_cluster_view_scene_req_handler","packet && rsp");
_L0:
    uStack_28 = uStack_28 & 0xff00;
    zmsg_append_bytes(rsp->payload,1,&uStack_28);
  }
  else {
    af_read_le16(packet->payload,&stack0xffffffde,&uStack_24);
    af_read_le8(packet->payload,&stack0xffffffde,&local_25);
    uVar4 = zmsg_get_length(packet->payload);
    group_id_00 = uStack_24;
    if (uVar4 < uStack_22) {
      unaff_s3 = 0x80;
      goto _L0;
    }
    eVar2 = scenes_check_group_id(uStack_24);
    unaff_s3 = CONCAT31(extraout_var,eVar2);
    if (unaff_s3 != 0) goto _L0;
    unaff_s0 = scene_table_find_entry(ep_id,group_id_00,(ushort)local_25);
    if (unaff_s0 == (zcl_scene_table_entry_t *)0x0) {
      unaff_s3 = 0x8b;
      goto _L0;
    }
    uStack_28 = uStack_28 & 0xff00;
    zmsg_append_bytes(rsp->payload,1,&uStack_28);
    uStack_28 = unaff_s0->group_id;
    zmsg_append_bytes(rsp->payload,2,&uStack_28);
    uStack_28 = CONCAT11(uStack_28._1_1_,unaff_s0->scene_id);
    zmsg_append_bytes(rsp->payload,1,&uStack_28);
    uStack_28 = unaff_s0->transition_time;
    zmsg_append_bytes(rsp->payload,2,&uStack_28);
    _Var3 = scene_name_is_supported(ep_id);
    if (CONCAT31(extraout_var_00,_Var3) == 0) goto _L0;
    pzVar6 = rsp->payload;
    uVar5 = ezb_zcl_get_attr_value_size(0x42,unaff_s0->scene_name);
    zmsg_append_bytes(pzVar6,uVar5,unaff_s0->scene_name);
  }
  for (peVar1 = unaff_s0->extension_field; peVar1 != (ezb_zcl_scenes_extension_field_t *)0x0;
      peVar1 = peVar1->next) {
    uStack_28 = peVar1->cluster_id;
    zmsg_append_bytes(rsp->payload,2,&uStack_28);
    uStack_28 = CONCAT11(uStack_28._1_1_,peVar1->length);
    zmsg_append_bytes(rsp->payload,1,&uStack_28);
    if (peVar1->length != '\0') {
      zmsg_append_bytes(rsp->payload,peVar1->value);
    }
  }
_L0:
  if ((packet->header).dst_addr.u.short_addr < 0xfff8) {
    if (unaff_s3 != 0) {
      uStack_28 = CONCAT11(uStack_28._1_1_,(char)unaff_s3);
      zmsg_append_bytes(rsp->payload,1,&uStack_28);
      uStack_28 = uStack_24;
      zmsg_append_bytes(rsp->payload,2,&uStack_28);
      uStack_28 = CONCAT11(uStack_28._1_1_,local_25);
      zmsg_append_bytes(rsp->payload,1,&uStack_28);
    }
    eVar2 = zcl_packet_setup_response(rsp,packet,1);
  }
  else {
    eVar2 = 0xfe;
  }
  return eVar2;
}

