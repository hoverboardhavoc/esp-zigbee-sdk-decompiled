/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_data_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ota_upgrade_data_confirm_handler
               (zcl_packet_cnf_t *cnf,ota_upgrade_downloading_context_t *context)

{
  uint8_t ep_id;
  ota_upgrade_downloading_context_t *poVar1;
  ota_upgrade_downloading_context_t *extraout_a1;
  ota_upgrade_downloading_context_t *in_a5;
  
  if ((cnf == (zcl_packet_cnf_t *)0x0) ||
     (in_a5 = context, context == (ota_upgrade_downloading_context_t *)0x0)) {
    cnf = (zcl_packet_cnf_t *)ota_upgrade_downloading_context_get((uint8_t)cnf);
    context = extraout_a1;
  }
  ep_id = *(uint8_t *)&(((ota_upgrade_downloading_context_t *)cnf)->attr).current_stack_version;
  if (*(uint8_t *)&(((ota_upgrade_downloading_context_t *)cnf)->attr).server_id == '\0') {
    (context->error).req.ep_id = ep_id;
    (context->error).req.tsn =
         *(uint8_t *)((int)&(((ota_upgrade_downloading_context_t *)cnf)->attr).server_id + 1);
    milli_timer_start(&(in_a5->error).req.timeout,5000);
    return;
  }
  poVar1 = ota_upgrade_downloading_context_get(ep_id);
  *(poVar1->attr).upgrade_status = '\0';
  *(poVar1->attr).file_offset = 0;
  memset(&poVar1->file,0,8);
  return;
}

