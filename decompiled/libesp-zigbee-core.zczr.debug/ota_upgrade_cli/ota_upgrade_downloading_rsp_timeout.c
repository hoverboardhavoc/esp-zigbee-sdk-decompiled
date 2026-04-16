/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_downloading_rsp_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ota_upgrade_downloading_rsp_timeout(ota_upgrade_downloading_context_t *context)

{
  char cVar1;
  ota_upgrade_downloading_context_t *context_00;
  char *extraout_a1;
  uint32_t *puVar2;
  
  if (context == (ota_upgrade_downloading_context_t *)0x0) {
    context_00 = (ota_upgrade_downloading_context_t *)
                 __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",0x15e
                               ,"ota_upgrade_downloading_rsp_timeout","context");
    cVar1 = *extraout_a1;
    if (cVar1 == '\0') {
      if ((((*(context_00->attr).manuf_code == *(uint16_t *)(extraout_a1 + 2)) &&
           (*(context_00->attr).image_type == *(uint16_t *)(extraout_a1 + 4))) &&
          ((puVar2 = (context_00->attr).current_file_version, puVar2 == (uint32_t *)0x0 ||
           (*puVar2 != *(uint32_t *)(extraout_a1 + 8))))) &&
         ((puVar2 = (context_00->attr).downloaded_file_version, puVar2 == (uint32_t *)0x0 ||
          (*puVar2 != *(uint32_t *)(extraout_a1 + 8))))) {
        ota_upgrade_set_upgrade_status_in_progress
                  (context_00,0,*(uint32_t *)(extraout_a1 + 8),*(uint32_t *)(extraout_a1 + 0xc));
      }
    }
    else if (cVar1 == '~') {
      ota_upgrade_set_upgrade_status_normal(context_00);
    }
    else if (cVar1 == -0x68) {
      ota_upgrade_set_upgrade_status_normal(context_00);
    }
    return;
  }
  ota_upgrade_downloading_abort((context->error).req.ep_id);
  return;
}

