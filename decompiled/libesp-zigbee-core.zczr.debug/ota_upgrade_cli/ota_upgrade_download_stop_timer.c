/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_download_stop_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool ota_upgrade_download_stop_timer(ota_upgrade_downloading_context_t *context)

{
  int unaff_s1;
  milli_timer_t *unaff_s2;
  
  if (context == (ota_upgrade_downloading_context_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",
                  0x194,"ota_upgrade_download_stop_timer","context");
  }
  else {
    unaff_s2 = &(context->error).req.timer;
    unaff_s1 = milli_timer_is_running(unaff_s2);
    if (unaff_s1 == 0) goto _L0;
  }
  milli_timer_stop(unaff_s2);
  zcl_packet_free(&(context->error).req.packet);
  (context->error).req.retry_count = '\0';
_L0:
  return SUB41(unaff_s1,0);
}

