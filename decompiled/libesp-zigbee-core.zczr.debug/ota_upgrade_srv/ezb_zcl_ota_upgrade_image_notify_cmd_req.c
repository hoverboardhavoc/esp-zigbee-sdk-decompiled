/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ezb_zcl_ota_upgrade_image_notify_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_ota_upgrade_image_notify_cmd_req(ezb_zcl_ota_upgrade_image_notify_cmd_t *cmd_req)

{
  uint8_t uVar1;
  int iVar2;
  uint32_t uStack_3c;
  undefined4 uStack_38;
  zcl_packet_t packet;
  
  uStack_38 = 0;
  packet.header.src_addr._0_4_ = 0;
  packet.header.src_addr.u._2_4_ = 0;
  packet.header._8_4_ = 0;
  packet.header.dst_addr.u._0_2_ = 0;
  packet.header.dst_addr.u._2_2_ = 0;
  packet.header.dst_addr.u._4_4_ = 0;
  packet.header.src_ep = '\0';
  packet.header.dst_ep = '\0';
  packet.header.cluster_id = 0;
  packet.header.profile_id = 0;
  packet.header.fc = '\0';
  packet.header._27_1_ = 0;
  packet.header.manuf_code = 0;
  packet.header.tsn = '\0';
  packet.header.rssi = '\0';
  packet.header.cmd_id = '\0';
  packet.header._33_1_ = 0;
  packet._34_2_ = 0;
  if (cmd_req == (ezb_zcl_ota_upgrade_image_notify_cmd_t *)0x0) {
    iVar2 = -1;
    goto _L0;
  }
  iVar2 = zcl_packet_init(&uStack_38,0);
  if (iVar2 != 0) {
    iVar2 = -1;
    goto _L0;
  }
  iVar2 = zcl_cmd_to_packet(&uStack_38,0,1,(cmd_req->cmd_ctrl).dis_default_rsp,0,0,0x19);
  if (iVar2 != 0) goto _L0;
  uStack_3c = CONCAT31(uStack_3c._1_3_,(cmd_req->payload).type);
  iVar2 = zmsg_append_bytes(packet._32_4_,1,&uStack_3c);
  if (iVar2 != 0) goto _L0;
  uStack_3c = CONCAT31(uStack_3c._1_3_,(cmd_req->payload).query_jitter);
  iVar2 = zmsg_append_bytes(packet._32_4_,1,&uStack_3c);
  if (iVar2 != 0) goto _L0;
  uVar1 = (cmd_req->payload).type;
  if (uVar1 == '\x03') {
    uStack_3c = CONCAT22(uStack_3c._2_2_,(cmd_req->payload).manuf_code);
    iVar2 = zmsg_append_bytes(packet._32_4_,2,&uStack_3c);
    if (iVar2 != 0) goto _L0;
    uStack_3c = CONCAT22(uStack_3c._2_2_,(cmd_req->payload).image_type);
    iVar2 = zmsg_append_bytes(packet._32_4_,2,&uStack_3c);
    if (iVar2 != 0) goto _L0;
    uStack_3c = (cmd_req->payload).file_version;
    iVar2 = zmsg_append_bytes(packet._32_4_,4,&uStack_3c);
joined_r0x00010f2a:
    if (iVar2 != 0) goto _L0;
  }
  else {
    if (uVar1 == '\x02') {
      uStack_3c = CONCAT22(uStack_3c._2_2_,(cmd_req->payload).manuf_code);
      iVar2 = zmsg_append_bytes(packet._32_4_,2,&uStack_3c);
      if (iVar2 != 0) goto _L0;
      uStack_3c = CONCAT22(uStack_3c._2_2_,(cmd_req->payload).image_type);
      iVar2 = zmsg_append_bytes(packet._32_4_,2,&uStack_3c);
      goto joined_r0x00010f2a;
    }
    if (uVar1 == '\x01') {
      uStack_3c = CONCAT22(uStack_3c._2_2_,(cmd_req->payload).manuf_code);
      iVar2 = zmsg_append_bytes(packet._32_4_,2,&uStack_3c);
      goto joined_r0x00010f2a;
    }
  }
  zcl_packet_send(&uStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
  iVar2 = zcl_status_to_err();
  if (iVar2 == 0) {
    return 0;
  }
_L0:
  zcl_packet_free(&uStack_38);
  return iVar2;
}

