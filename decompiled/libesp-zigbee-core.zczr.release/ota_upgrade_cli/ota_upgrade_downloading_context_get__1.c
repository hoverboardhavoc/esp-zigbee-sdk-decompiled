/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_downloading_context_get__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ota_upgrade_downloading_context_t * ota_upgrade_downloading_context_get(uint8_t ep_id)

{
  ota_upgrade_downloading_context_t *poVar1;
  uint16_t in_a1;
  
  poVar1 = (ota_upgrade_downloading_context_t *)ota_upgrade_cli_get_attr_desc(ep_id,in_a1);
  if (poVar1 == (ota_upgrade_downloading_context_t *)0x0) {
    poVar1 = ota_upgrade_downloading_context_get('\0');
  }
  return (ota_upgrade_downloading_context_t *)(poVar1->attr).current_file_version;
}

