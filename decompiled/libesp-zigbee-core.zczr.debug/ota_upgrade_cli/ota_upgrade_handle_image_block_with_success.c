/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_handle_image_block_with_success
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ota_upgrade_handle_image_block_with_success
          (ota_upgrade_downloading_context_t *context,ota_upgrade_image_block_rsp_t *payload)

{
  ezb_zcl_status_t eVar1;
  uint32_t downloading_version;
  uint image_size;
  
  if (*(context->attr).manuf_code == (payload->field_1).success.manuf_code) {
    if (*(context->attr).image_type == (payload->field_1).success.image_type) {
      downloading_version = (payload->field_1).success.file_version;
      if ((context->file).downloading_version == downloading_version) {
        image_size = (context->file).total_size;
        if ((image_size == 0) ||
           (*(context->attr).file_offset + (uint)(payload->field_1).success.data_size < image_size))
        {
          ota_upgrade_set_upgrade_status_in_progress
                    (context,(uint)(payload->field_1).success.data_size +
                             *(context->attr).file_offset,downloading_version,image_size);
          eVar1 = 0x99;
        }
        else {
          ota_upgrade_set_upgrade_status_complete(context);
          eVar1 = '\0';
        }
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
    eVar1 = 0xfe;
  }
  return eVar1;
}

