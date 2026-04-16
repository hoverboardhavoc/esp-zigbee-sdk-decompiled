/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_set_upgrade_status_in_progress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ota_upgrade_set_upgrade_status_in_progress
               (ota_upgrade_downloading_context_t *context,uint32_t file_offset,
               uint32_t downloading_version,uint32_t image_size)

{
  *(context->attr).upgrade_status = '\x01';
  *(context->attr).file_offset = file_offset;
  (context->file).downloading_version = downloading_version;
  (context->file).total_size = image_size;
  return;
}

