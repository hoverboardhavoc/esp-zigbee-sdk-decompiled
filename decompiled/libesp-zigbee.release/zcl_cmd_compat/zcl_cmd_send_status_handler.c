/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zcl_cmd_send_status_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_cmd_send_status_handler(ezb_af_user_cnf_t *info,void *param_2)

{
  esp_zb_zcl_command_send_status_callback_t p_Var1;
  undefined1 auStack_50 [44];
  uint uStack_24;
  esp_zb_zcl_command_send_status_message_t message;
  
  p_Var1 = s_cmd_send_status_cb;
  message.dst_addr.addr_type = '\0';
  message.dst_addr._1_3_ = 0;
  message.dst_addr.u.src_id = 0;
  if (s_cmd_send_status_cb != (esp_zb_zcl_command_send_status_callback_t)0x0) {
    uStack_24 = (uint)info->status;
    message.status = CONCAT13(0,CONCAT12(info->src_ep,CONCAT11(info->dst_ep,info->tsn)));
    message.dst_endpoint = '\0';
    message.src_endpoint = '\0';
    message._7_1_ = 0;
    message.tsn = (info->dst_addr).addr_mode;
    memcpy(&message.dst_addr,&(info->dst_addr).u,8);
    memcpy(auStack_50,&uStack_24,0x14);
    (*p_Var1)(eRam00000010);
  }
  return;
}

