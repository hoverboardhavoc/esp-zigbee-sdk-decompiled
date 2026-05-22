/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ezb_zcl_ota_upgrade_query_next_image_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_ota_upgrade_query_next_image_cmd_req
                    (ezb_zcl_ota_upgrade_query_next_image_req_cmd_t *cmd_req)

{
  int iVar1;
  undefined1 auStack_50 [20];
  uint32_t uStack_3c;
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if ((cmd_req == (ezb_zcl_ota_upgrade_query_next_image_req_cmd_t *)0x0) ||
     (iVar1 = zcl_packet_init(auStack_38,0), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    memcpy(auStack_50,cmd_req,10);
    iVar1 = zcl_cmd_to_packet(auStack_38,0,0,(cmd_req->cmd_ctrl).dis_default_rsp,0,1,0x19);
    if (iVar1 == 0) {
      uStack_3c = CONCAT31(uStack_3c._1_3_,(cmd_req->payload).fc);
      iVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_3c);
      if (((iVar1 == 0) &&
          (iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,(cmd_req->payload).manuf_code),
          iVar1 == 0)) &&
         (iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,(cmd_req->payload).image_type),
         iVar1 == 0)) {
        uStack_3c = (cmd_req->payload).file_version;
        iVar1 = zmsg_append_bytes(packet._32_4_,4,&uStack_3c);
        if ((iVar1 == 0) &&
           ((((cmd_req->payload).fc & 1) == 0 ||
            (iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,(cmd_req->payload).hw_version),
            iVar1 == 0)))) {
          zcl_packet_send(auStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
          iVar1 = zcl_status_to_err();
          if (iVar1 == 0) {
            return 0;
          }
        }
      }
    }
  }
  zcl_packet_free(auStack_38);
  return iVar1;
}

