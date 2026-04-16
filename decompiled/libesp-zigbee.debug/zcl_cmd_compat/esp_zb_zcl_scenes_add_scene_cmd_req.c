/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_scenes_add_scene_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t esp_zb_zcl_scenes_add_scene_cmd_req(esp_zb_zcl_scenes_add_scene_cmd_t *cmd_req)

{
  undefined3 uVar1;
  uint8_t uVar2;
  int iVar3;
  undefined1 auStack_44 [4];
  ezb_zcl_scenes_add_scene_cmd_t req;
  
  auStack_44 = (undefined1  [4])0x0;
  req.cmd_ctrl.dst_addr._0_4_ = 0;
  req.cmd_ctrl.dst_addr.u._2_4_ = 0;
  req.cmd_ctrl._8_4_ = 0;
  req.cmd_ctrl.dis_default_rsp = false;
  req.cmd_ctrl._13_3_ = 0;
  req.cmd_ctrl.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  req.cmd_ctrl.cnf_ctx.user_ctx = (void *)0x0;
  req.payload.group_id = 0;
  req.payload.scene_id = '\0';
  req.payload._3_1_ = 0;
  req.payload.transition_time = 0;
  req.payload.scene_name[0] = '\0';
  req.payload.scene_name[1] = '\0';
  req.payload.scene_name[2] = '\0';
  req.payload.scene_name[3] = '\0';
  req.payload.scene_name[4] = '\0';
  req.payload.scene_name[5] = '\0';
  req.payload.scene_name[6] = '\0';
  req.payload.scene_name[7] = '\0';
  req.payload.scene_name[8] = '\0';
  req.payload.scene_name[9] = '\0';
  req.payload.scene_name[10] = '\0';
  req.payload.scene_name[0xb] = '\0';
  req.payload.scene_name[0xc] = '\0';
  req.payload.scene_name[0xd] = '\0';
  req.payload.scene_name[0xe] = '\0';
  req.payload.scene_name[0xf] = '\0';
  req.payload.scene_name[0x10] = '\0';
  req.payload._23_1_ = 0;
  if (cmd_req == (esp_zb_zcl_scenes_add_scene_cmd_t *)0x0) {
    esp_log(0x11,"ZCL_CMD_COMPAT","%s(%d): Invalid Argument","esp_zb_zcl_scenes_add_scene_cmd_req",
            0x307);
    uVar2 = 0xff;
  }
  else {
    convert_to_ezb_specific_cmd_ctrl
              ((ezb_zcl_cluster_cmd_ctrl_t *)auStack_44,(esp_zb_zcl_specific_cmd_header_t *)cmd_req)
    ;
    auStack_44[0] = '\x02';
    uVar1._0_2_ = cmd_req->group_id;
    uVar1._2_1_ = cmd_req->scene_id;
    req.cmd_ctrl.cnf_ctx.user_ctx = (void *)CONCAT13(req.cmd_ctrl.cnf_ctx.user_ctx._3_1_,uVar1);
    req.payload.group_id = cmd_req->transition_time;
    req.payload._20_4_ = cmd_req->extension_field;
    iVar3 = ezb_zcl_scenes_add_scene_cmd_req((ezb_zcl_cluster_cmd_ctrl_t *)auStack_44);
    if (iVar3 == 0) {
      uVar2 = zcl_get_current_tsn();
    }
    else {
      uVar2 = 0xff;
    }
  }
  return uVar2;
}

