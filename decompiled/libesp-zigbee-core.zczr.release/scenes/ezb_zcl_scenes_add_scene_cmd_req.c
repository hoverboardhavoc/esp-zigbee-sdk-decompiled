/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> ezb_zcl_scenes_add_scene_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: packet */
/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_scenes_add_scene_cmd_req(ezb_zcl_scenes_add_scene_cmd_t *cmd_req)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  ezb_zcl_scenes_extension_field_t *peVar5;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if ((cmd_req == (ezb_zcl_scenes_add_scene_cmd_t *)0x0) ||
     (iVar2 = zcl_packet_init(auStack_38,0), iVar2 != 0)) {
    iVar2 = -1;
  }
  else {
    memcpy(auStack_50,cmd_req,10);
    iVar2 = zcl_cmd_to_packet(auStack_38,0,0,(cmd_req->cmd_ctrl).dis_default_rsp,0,0,5);
    if ((((iVar2 == 0) &&
         (iVar2 = zmsg_append_le16((zmsg_t *)packet._32_4_,(cmd_req->payload).group_id), iVar2 == 0)
         ) && (iVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,(cmd_req->payload).scene_id),
              iVar2 == 0)) &&
       (iVar2 = zmsg_append_le16((zmsg_t *)packet._32_4_,(cmd_req->payload).transition_time),
       uVar1 = packet._32_4_, iVar2 == 0)) {
      pcVar4 = (cmd_req->payload).scene_name;
      uVar3 = ezb_zcl_get_attr_value_size(0x42,pcVar4);
      iVar2 = zmsg_append_bytes(uVar1,uVar3,pcVar4);
      if (iVar2 == 0) {
        for (peVar5 = (cmd_req->payload).extension_field;
            peVar5 != (ezb_zcl_scenes_extension_field_t *)0x0; peVar5 = peVar5->next) {
          iVar2 = zmsg_append_le16((zmsg_t *)packet._32_4_,peVar5->cluster_id);
          if (((iVar2 != 0) ||
              (iVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,peVar5->length), iVar2 != 0)) ||
             (iVar2 = zmsg_append_bytes(packet._32_4_,peVar5->length,peVar5->value), iVar2 != 0))
          goto _L0;
        }
        zcl_packet_send(auStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
        iVar2 = zcl_status_to_err();
        if (iVar2 == 0) {
          return 0;
        }
      }
    }
  }
_L0:
  zcl_packet_free(auStack_38);
  return iVar2;
}

