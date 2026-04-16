/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_downloading_upgrade_end_is_accepted
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool ota_upgrade_downloading_upgrade_end_is_accepted
                (ota_upgrade_downloading_context_t *context,ota_upgrade_upgrade_end_rsp_t *payload)

{
  if ((*(context->attr).manuf_code != payload->manuf_code) && (payload->manuf_code != 0xffff)) {
    return false;
  }
  if ((*(context->attr).image_type != payload->image_type) && (payload->image_type != 0xffff)) {
    return false;
  }
  if (((context->file).downloading_version != payload->file_version) &&
     (payload->file_version != 0xffffffff)) {
    return false;
  }
  if (payload->upgrade_time == 0xffffffff) {
    return true;
  }
  if (payload->upgrade_time < payload->current_time) {
    return false;
  }
  return true;
}

