/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_srv.o -> ezb_zcl_ota_upgrade_image_notify_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: packet */
/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_ota_upgrade_image_notify_cmd_req(ezb_zcl_ota_upgrade_image_notify_cmd_t *cmd_req)

{
  uint8_t uVar1;
  uint16_t val;
  int iVar2;
  undefined1 auStack_50 [23];
  uint8_t uStack_39;
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if ((cmd_req == (ezb_zcl_ota_upgrade_image_notify_cmd_t *)0x0) ||
     (iVar2 = zcl_packet_init(auStack_38,0), iVar2 != 0)) {
    iVar2 = -1;
    goto _L0;
  }
  memcpy(auStack_50,cmd_req,10);
  iVar2 = zcl_cmd_to_packet(auStack_38,1,0,1,(cmd_req->cmd_ctrl).dis_default_rsp,0,0,0x19);
  if (iVar2 != 0) goto _L0;
  uStack_39 = (cmd_req->payload).type;
  iVar2 = zmsg_append_bytes(packet._32_4_,1,&uStack_39);
  if (iVar2 != 0) goto _L0;
  uStack_39 = (cmd_req->payload).query_jitter;
  iVar2 = zmsg_append_bytes(packet._32_4_,1,&uStack_39);
  if (iVar2 != 0) goto _L0;
  uVar1 = (cmd_req->payload).type;
  if (uVar1 == '\x03') {
    iVar2 = zmsg_append_le16((zmsg_t *)packet._32_4_,(cmd_req->payload).manuf_code);
    if ((iVar2 != 0) ||
       (iVar2 = zmsg_append_le16((zmsg_t *)packet._32_4_,(cmd_req->payload).image_type), iVar2 != 0)
       ) goto _L0;
    iVar2 = zmsg_append_le32((zmsg_t *)packet._32_4_,(cmd_req->payload).file_version);
_L187:
    if (iVar2 != 0) goto _L0;
  }
  else {
    if (uVar1 == '\x02') {
      iVar2 = zmsg_append_le16((zmsg_t *)packet._32_4_,(cmd_req->payload).manuf_code);
      if (iVar2 != 0) goto _L0;
      val = (cmd_req->payload).image_type;
_L0:
      iVar2 = zmsg_append_le16((zmsg_t *)packet._32_4_,val);
      goto _L187;
    }
    if (uVar1 == '\x01') {
      val = (cmd_req->payload).manuf_code;
      goto _L0;
    }
  }
  zcl_packet_send(auStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
  iVar2 = zcl_status_to_err();
  if (iVar2 == 0) {
    return 0;
  }
_L0:
  zcl_packet_free(auStack_38);
  return iVar2;
}

