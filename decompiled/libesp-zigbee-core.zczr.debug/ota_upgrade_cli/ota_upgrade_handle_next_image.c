/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_handle_next_image
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ota_upgrade_handle_next_image
          (ota_upgrade_downloading_context_t *context,ota_upgrade_query_next_image_rsp_t *payload)

{
  ezb_zcl_status_t eVar1;
  uint32_t *puVar2;
  
  eVar1 = payload->status;
  if (eVar1 == '\0') {
    if (*(context->attr).manuf_code == payload->manuf_code) {
      if (*(context->attr).image_type == payload->image_type) {
        puVar2 = (context->attr).current_file_version;
        if ((puVar2 == (uint32_t *)0x0) || (*puVar2 != payload->file_version)) {
          puVar2 = (context->attr).downloaded_file_version;
          if ((puVar2 == (uint32_t *)0x0) || (*puVar2 != payload->file_version)) {
            ota_upgrade_set_upgrade_status_in_progress
                      (context,0,payload->file_version,payload->image_size);
          }
          else {
            eVar1 = 0xfe;
          }
        }
        else {
          eVar1 = 0xfe;
        }
      }
      else {
        eVar1 = 0x96;
      }
    }
    else {
      eVar1 = 0x96;
    }
  }
  else if (eVar1 == '~') {
    ota_upgrade_set_upgrade_status_normal(context);
  }
  else if (eVar1 == 0x98) {
    ota_upgrade_set_upgrade_status_normal(context);
  }
  else {
    eVar1 = 0xfe;
  }
  return eVar1;
}

