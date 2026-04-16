/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_downloading_stop_rsp_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool ota_upgrade_downloading_stop_rsp_timeout
                (ota_upgrade_downloading_context_t *context,uint8_t tsn)

{
  int unaff_s1;
  undefined3 in_register_0000202d;
  milli_timer_t *unaff_s3;
  
  if (context == (ota_upgrade_downloading_context_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",0x164,
                  "ota_upgrade_downloading_stop_rsp_timeout","context");
  }
  else {
    unaff_s3 = &(context->error).req.timeout;
    unaff_s1 = milli_timer_is_running(unaff_s3);
    if (unaff_s1 == 0) {
      return true;
    }
    if ((uint)(context->error).req.tsn != CONCAT31(in_register_0000202d,tsn)) {
      return false;
    }
  }
  milli_timer_stop(unaff_s3);
  return (_Bool)(char)unaff_s1;
}

