/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_download_stop_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool ota_upgrade_download_stop_timer(ota_upgrade_downloading_context_t *context)

{
  int iVar1;
  milli_timer_t *pmVar2;
  
  if (context == (ota_upgrade_downloading_context_t *)0x0) {
    context = ota_upgrade_downloading_context_get('\0');
  }
  pmVar2 = &(context->error).req.timer;
  iVar1 = milli_timer_is_running(pmVar2);
  if (iVar1 != 0) {
    milli_timer_stop(pmVar2);
    zcl_packet_free(&(context->error).req.packet);
    (context->error).req.retry_count = '\0';
  }
  return SUB41(iVar1,0);
}

