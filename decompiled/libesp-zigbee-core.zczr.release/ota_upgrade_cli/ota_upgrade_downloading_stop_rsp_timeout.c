/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_downloading_stop_rsp_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool ota_upgrade_downloading_stop_rsp_timeout
                (ota_upgrade_downloading_context_t *context,uint8_t tsn)

{
  int iVar1;
  undefined3 in_register_0000202d;
  uint uVar2;
  uint extraout_a1;
  milli_timer_t *pmVar3;
  
  uVar2 = CONCAT31(in_register_0000202d,tsn);
  if (context == (ota_upgrade_downloading_context_t *)0x0) {
    context = ota_upgrade_downloading_context_get('\0');
    uVar2 = extraout_a1;
  }
  pmVar3 = &(context->error).req.timeout;
  iVar1 = milli_timer_is_running(pmVar3);
  if (iVar1 != 0) {
    if ((context->error).req.tsn != uVar2) {
      return false;
    }
    milli_timer_stop(pmVar3);
  }
  return true;
}

