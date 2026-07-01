/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_download_retry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: packet */
/* WARNING: Unknown calling convention */

void ota_upgrade_download_retry(ota_upgrade_downloading_context_t *context)

{
  byte bVar1;
  zcl_packet_t *pzVar2;
  ota_upgrade_downloading_context_t *poVar3;
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  auStack_38 = (undefined1  [4])0x0;
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
  if (context == (ota_upgrade_downloading_context_t *)0x0) {
    poVar3 = (ota_upgrade_downloading_context_t *)
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c"
                           ,0x182,"ota_upgrade_download_retry","context");
  }
  else {
    bVar1 = (context->error).req.retry_count;
    poVar3 = context;
    if (bVar1 < (context->config).retry_num) {
      (context->error).req.retry_count = bVar1 + 1;
      zcl_packet_move((zcl_packet_t *)auStack_38,&(context->error).req.packet);
      ota_upgrade_packet_send((zcl_packet_t *)auStack_38);
      goto _L0;
    }
  }
  pzVar2 = &(poVar3->error).req.packet;
  zcl_packet_setup_response
            ((zcl_packet_t *)auStack_38,pzVar2,(poVar3->error).req.packet.header.cmd_id);
  zcl_message_ota_upgrade_downloading_progress((zcl_packet_t *)auStack_38,'\x06',context);
  zcl_packet_free(pzVar2);
  (context->error).req.retry_count = '\0';
_L0:
  log_write(2,"ZCL_OTA_UPGRADE_CLI","Downloading retry [%d/%d], timeout: %lu ms",
            (context->error).req.retry_count,(context->config).retry_num,
            (context->config).retry_timeout);
  return;
}

