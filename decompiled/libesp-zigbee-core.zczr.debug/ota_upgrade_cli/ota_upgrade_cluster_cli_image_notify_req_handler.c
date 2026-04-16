/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_cluster_cli_image_notify_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ota_upgrade_cluster_cli_image_notify_req_handler
          (zcl_packet_t *packet,zcl_packet_t *rsp,zcl_packet_cnf_ctx_t *rsp_cnf)

{
  ezb_zcl_status_t eVar1;
  uint uVar2;
  undefined3 extraout_var;
  int iVar3;
  uint uVar4;
  ota_upgrade_downloading_context_t *unaff_s2;
  uint16_t *puVar5;
  undefined1 local_30 [4];
  ota_upgrade_image_notify_t payload;
  uint16_t offset;
  
  payload.file_version._2_2_ = 0;
  local_30 = (undefined1  [4])0xffff0000;
  payload.type = 0xff;
  payload.query_jitter = 0xff;
  payload.manuf_code = 0;
  payload.image_type = 0xffff;
  payload._6_2_ = 0xffff;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",0x278,
                  "ota_upgrade_cluster_cli_image_notify_req_handler","packet && rsp");
  }
  else {
    unaff_s2 = ota_upgrade_downloading_context_get((packet->header).dst_ep);
    if (*(unaff_s2->attr).upgrade_status != '\0') {
      iVar3 = 0x95;
      goto _L0;
    }
  }
  uVar2 = zmsg_get_length(packet->payload);
  puVar5 = (uint16_t *)((int)&payload.file_version + 2);
  af_read_le8(packet->payload,puVar5,local_30);
  af_read_le8(packet->payload,puVar5,local_30 + 1);
  uVar4 = (uint)local_30 & 0xff;
  if (uVar4 == 3) {
    af_read_le16(packet->payload,puVar5,(uint16_t *)(local_30 + 2));
    af_read_le16(packet->payload,puVar5,(uint16_t *)&payload);
    af_read_le32(packet->payload,puVar5,(uint32_t *)&payload.image_type);
  }
  else if (uVar4 == 2) {
    puVar5 = (uint16_t *)((int)&payload.file_version + 2);
    af_read_le16(packet->payload,puVar5,(uint16_t *)(local_30 + 2));
    af_read_le16(packet->payload,puVar5,(uint16_t *)&payload);
  }
  else {
    if (uVar4 != 1) {
      iVar3 = 0x81;
      goto _L0;
    }
    af_read_le16(packet->payload,(uint16_t *)((int)&payload.file_version + 2),
                 (uint16_t *)(local_30 + 2));
  }
  if (uVar2 < payload.file_version._2_2_) {
    iVar3 = 0x80;
  }
  else {
    eVar1 = ota_upgrade_handle_image_notify
                      (unaff_s2,(packet->header).dst_addr.u.short_addr,
                       (ota_upgrade_image_notify_t *)local_30);
    iVar3 = CONCAT31(extraout_var,eVar1);
    if (iVar3 == 0) {
      ota_upgrade_add_confirm_cb(rsp_cnf,unaff_s2);
      eVar1 = ota_upgrade_setup_query_next_image_request(rsp,packet,unaff_s2);
      return eVar1;
    }
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,iVar3);
  return eVar1;
}

