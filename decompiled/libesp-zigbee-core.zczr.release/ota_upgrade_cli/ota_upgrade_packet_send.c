/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_packet_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ota_upgrade_packet_send(zcl_packet_t *packet)

{
  ota_upgrade_downloading_context_t *poVar1;
  code *pcStack_18;
  zcl_packet_cnf_ctx_t cnf_ctx;
  
  if (packet != (zcl_packet_t *)0x0) goto _L15;
  do {
    packet = (zcl_packet_t *)__assert_func(0,0,0,0);
_L15:
    pcStack_18 = (code *)0x0;
    cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
    poVar1 = ota_upgrade_downloading_context_get((packet->header).src_ep);
  } while (poVar1 == (ota_upgrade_downloading_context_t *)0x0);
  pcStack_18 = ota_upgrade_packet_confirm_handler;
  cnf_ctx.cb = (ezb_af_user_cnf_callback_t)poVar1;
  zcl_packet_clone(&(poVar1->error).req.packet,packet);
  zcl_packet_send(packet,&pcStack_18);
  return;
}

