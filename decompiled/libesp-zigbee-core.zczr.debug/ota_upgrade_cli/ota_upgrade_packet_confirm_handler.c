/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_packet_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ota_upgrade_packet_confirm_handler
               (zcl_packet_cnf_t *cnf,ota_upgrade_downloading_context_t *context)

{
  milli_timer_t *pmVar1;
  ota_upgrade_downloading_context_t *poVar2;
  
  if (cnf == (zcl_packet_cnf_t *)0x0) {
    poVar2 = (ota_upgrade_downloading_context_t *)
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c"
                           ,0x15c,"ota_upgrade_packet_confirm_handler",&_L0);
  }
  else {
    if (context == (ota_upgrade_downloading_context_t *)0x0) {
      return;
    }
    poVar2 = context;
    if (cnf->status != '\0') {
      ota_upgrade_download_retry(context);
      return;
    }
  }
  pmVar1 = &(poVar2->error).req.timer;
  milli_timer_stop(pmVar1);
  milli_timer_start(pmVar1,(context->config).retry_timeout);
  return;
}

