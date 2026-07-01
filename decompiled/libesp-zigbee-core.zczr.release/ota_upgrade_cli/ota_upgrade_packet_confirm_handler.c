/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_packet_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ota_upgrade_packet_confirm_handler
               (zcl_packet_cnf_t *cnf,ota_upgrade_downloading_context_t *context)

{
  byte bVar1;
  zcl_packet_t *pzVar2;
  ota_upgrade_downloading_context_t *extraout_a1;
  zcl_packet_t zStack_38;
  
  if (cnf == (zcl_packet_cnf_t *)0x0) {
    cnf = (zcl_packet_cnf_t *)ota_upgrade_downloading_context_get('\0');
    context = extraout_a1;
  }
  if (context == (ota_upgrade_downloading_context_t *)0x0) {
    return;
  }
  if (*(uint8_t *)&(((ota_upgrade_downloading_context_t *)cnf)->attr).server_id == '\0') {
    zStack_38.payload = (zcl_packet_payload_t *)&(context->error).req.timer;
    milli_timer_stop();
    milli_timer_start(zStack_38.payload,(context->config).retry_timeout);
    return;
  }
  memset(&zStack_38,0,0x28);
  if (context == (ota_upgrade_downloading_context_t *)0x0) {
    __assert_func(0,0,0,0);
  }
  bVar1 = (context->error).req.retry_count;
  pzVar2 = &(context->error).req.packet;
  if (bVar1 < (context->config).retry_num) {
    (context->error).req.retry_count = bVar1 + 1;
    zcl_packet_move(&zStack_38,pzVar2);
    ota_upgrade_packet_send(&zStack_38);
  }
  else {
    zcl_packet_setup_response(&zStack_38,pzVar2,(context->error).req.packet.header.cmd_id);
    zcl_message_ota_upgrade_downloading_progress(&zStack_38,'\x06',context);
    zcl_packet_free(pzVar2);
    (context->error).req.retry_count = '\0';
  }
  log_write(2,"ZCL_OTA_UPGRADE_CLI","Downloading retry [%d/%d], timeout: %lu ms",
            (context->error).req.retry_count,(context->config).retry_num,
            (context->config).retry_timeout);
  return;
}

